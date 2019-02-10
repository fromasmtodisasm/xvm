#include <vm.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include <asm.h> 
#include "fileutils.h"

#define PROG_SIZE 128
typedef uint32_t uint;

command *cmd_tab;
int TAB_SIZE;



void print_args(uint8_t *memory, command *cmd) {
	int i = 0;
	for (int j = 0; j < cmd->op_cnt; j++)
	{
		printf("%08x ", (uint32_t*)memory[i]);
		i += 4;
	}
}
/* mode: 1 - text mode, 0 - raw numbers */
void disassembly(uint8_t *memory, size_t size, int mode) {
	command *cmd = NULL;
	for (size_t i = 0; i < size; ) {
		uint8_t byte = *((uint8_t*)&(memory[(i)]));

		// print current addres of command
		printf("%04x:\t", i);
		// check if byte is opcode
		if (byte >= 0 && byte <= TAB_SIZE - 1) {// this is opcode
			cmd = &cmd_tab[byte];
			
			printf("%02x ", cmd->opcode);
			i++;
			print_args(&memory[i],cmd);
			if (cmd->op_cnt == 0) printf("%9.8s", " ");
			printf("|");
			printf("\t%s ", cmd->name);
			print_args(&memory[i],cmd);
			puts("");

			i += cmd->op_cnt * 4;
		}
		else {
			uint dword = *((uint32_t*)&(memory[i]));
			if (isprint(dword) || isspace(dword)) printf("%c\n", dword);
			else printf("0x%08x\n", dword);
			i += 4;
		}

	}
}

Program *load_program(char *name) {

	FILE *fp; 
	if ((fp = fopen(name, "rb")) == NULL) { return NULL; }
	Program *program = malloc(sizeof(Program));;
	
	fseek(fp, 0, SEEK_END);
	program->size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	program->mem = malloc(program->size);
	fread(program->mem, 1, program->size, fp);
	fclose(fp);

	return program;
}

int main(int argc, char *argv[]) {
	vm_t *vm;
	int res = -1;

	if (!vm_init("table_dll.dll")) {
		fprintf(stderr, "Fail load table_dll\n");
		return res;
	}
	print_commands();
	Program *program = load_program("a.out");
	if (!program) return res;

	printf("disassembly\n");
	printf("-----------\n");
	disassembly(program->mem, program->size, 1);
	printf("-----------\n");

	memory_t *mem = vm_createMemory(program->mem, program->size);
	vm = vm_create(mem, 128);
	vm_reset(vm);
	res = vm_run(vm);
	
	dump_cpu(vm);
	return  res;
}