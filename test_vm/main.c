#include <vm.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <asm.h> 
#include "fileutils.h"


#define PROG_SIZE 128
typedef uint32_t uint;




uint8_t *make_program(size_t size) {

	
	int pc = 1;
	int res = 0;
	char *greating = "Hello, World!\n";
	uint8_t *program = malloc(PROG_SIZE*sizeof(uint8_t));
	uint start_of_prog = 0x50;

	for (int i = 0; i <= XOR; i++) {
		program[i] = i;
	}
	for (int i = XOR + 1; i < size; i++)
	{
		program[i] = HLT;
	}
	program[HLT] = NOP;
	return program;

	memset(program, NOP, PROG_SIZE);
	uint str_offset = PROG_SIZE - strlen(greating) - 1;
	/*push*/
	program[pc++] = PUSH;
	*((uint*)&(program[pc])) = start_of_prog;
	pc += (sizeof(uint));

	
	program[pc++] = JMP;

	int len = strlen(greating) + 1;
	memcpy(&program[str_offset=pc], greating, strlen(greating) + 1);
	pc += len;

	/*For print */
	pc = start_of_prog;
	program[pc++] = PUSH;
	*((uint*)&(program[pc])) = str_offset;// PROG_SIZE - strlen(greating) - 1;
	pc += (sizeof(uint));
	program[pc++] = PRT;
	program[PROG_SIZE -1] = HLT;
	
	memcpy(&program[str_offset], greating, strlen(greating) + 1);
	return program;
}

int main(int argc, char *argv[]) {
	vm_t *vm;
	int res = -1;

	Program *program = main_asm(argc, argv);
	FILE *fp; 
	fp = fopen("test_prog.txt", "r");
	
	perror(":");
	char *prog = file2str(fp);
	//Program *program = assembly(&prog);
	
	/*
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	fread(program, 1, len, fp);
	fclose(fp);
	*/
	

//	Program *program = main_asm(argc, argv);

	printf("disassembly\n");
	printf("-----------\n");
	//disassembly(program->mem, program->size, 1);
	printf("-----------\n");
	if (1) {
	//if (program = make_program(PROG_SIZE)) {
		memory_t *mem = vm_createMemory(program->mem, program->size);
		vm = vm_create(mem, 128);
		vm_reset(vm);
		res = vm_run(vm);
	}
	dump_cpu(vm);
	return  0;
}