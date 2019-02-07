#include <vm.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <asm.h> 
#include "fileutils.h"


#define PROG_SIZE 128
typedef uint32_t uint;

int main(int argc, char *argv[]) {
	vm_t *vm;
	int res = -1;

	// = main_asm(argc, argv);
	FILE *fp; 
	fp = fopen("a.out", "rb");
	Program *program = malloc(sizeof(Program));;
	//Program *program = assembly(&prog);
	
	
	fseek(fp, 0, SEEK_END);
	program->size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	program->mem = malloc(program->size);
	fread(program->mem, 1, program->size, fp);
	fclose(fp);

	printf("disassembly\n");
	printf("-----------\n");
	disassembly(program->mem, program->size, 1);
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