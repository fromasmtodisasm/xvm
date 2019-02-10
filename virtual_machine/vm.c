#include "vm.h"

#include <stdlib.h> 
#include <stdbool.h>
#include <string.h> 
#include <stdio.h>

#define WIN32_LEAN_AND_MEAN  
#include <Windows.h>

typedef command *(*GetTable)();
typedef int(*GetSize)();

static GetTable get_table;
static GetSize get_size;

command *cmd_tab;
int TAB_SIZE;

void print_commands() {
	for (int i = 0; i < TAB_SIZE; i++)
		printf(
			"command %s with opcode %d and %d arguments\n", 
			cmd_tab[i].name,
			cmd_tab[i].opcode,
			cmd_tab[i].op_cnt
		);
}
int load_table(char *name) {
	HMODULE table_lib = LoadLibrary(name);
	if (!table_lib) return FALSE;
	get_table = (GetTable)GetProcAddress(table_lib, "get_table");
	get_size = (GetSize)GetProcAddress(table_lib, "get_size");
	if (!get_table || !get_size) {
		return FALSE;
	}
	return TRUE;
}

void dump_cpu(vm_t *vm) {
	int i = 0;
	printf("Reg%d=0x%04x", i, vm->cpu->regs[i]);
	for (i++; i < REGS_COUNT; i++) {
		printf(" Reg%d=0x%04x", i, vm->cpu->regs[i]);
	}
	printf("\n");

	i = 0;
	printf("flag%d = [%1d]", i, vm->cpu->flags[i]);
	for (i++; i < SIZE_OF_FLAGS; i++) {
		printf("\nflag%d = [%1d]", i, vm->cpu->flags[i]);
	}
	printf("\n");
}


int vm_init(char *table_name) {
	if (load_table(table_name)) {
		cmd_tab = get_table();
		TAB_SIZE = get_size();
	}
	else {
		return FALSE;
	}
	return TRUE;
}

void vm_reset(vm_t *vm) {
	cpu_t *cpu = vm->cpu;

	cpu->is_running = true;
	memset(cpu->regs, 0, sizeof(cpu->regs[0])*REGS_COUNT);
	memset(cpu->flags, 0, sizeof(cpu->flags[0])*SIZE_OF_FLAGS);
}

void vm_setProgram(vm_t *vm, uint8_t *program, size_t size) {
	vm->memory->ram = program;
	vm->memory->size = size;
}

cpu_t *vm_createCpu() {
	cpu_t *cpu = malloc(sizeof(cpu_t));
	return cpu;
}

memory_t *vm_createMemory(uint8_t *ram, size_t size) {
	memory_t *mem = malloc(sizeof(memory_t));
	if (mem != NULL) {
		if (ram != NULL)
			mem->ram = ram;
		else
			mem->ram = malloc(size);
		mem->size = size;
	}
	return mem;
}

vm_t *vm_create(memory_t * program, size_t stack_size) {
	cpu_t *cpu = NULL;
	memory_t *mem = NULL;
	vm_t *vm = NULL;

	if ((cpu = vm_createCpu()) != NULL) {
		if ((mem = vm_createMemory(program->ram, program->size)) != NULL) {
			vm = malloc(sizeof(vm));
			vm->cpu = cpu;
			vm->memory = mem;
			vm->stack = vm_createMemory(NULL, stack_size);
		}
	}
	return vm;
}

int vm_run(vm_t *vm) {
	cpu_t *cpu = vm->cpu;
	memory_t *mem = vm->memory;
	uint8_t opcode = 0;
	//command *cmd;// = NULL;

	while (cpu->is_running == true) {

		//execute(vm, decode(fetch(vm), cmd_tab));
		fetch(vm);
		decode(vm, cmd_tab);
		execute(vm);
	}
	return 0;
}