#include "vm.h"

#include <stdlib.h> 
#include <stdbool.h>
#include <string.h> 
#include <stdio.h>

command cmd_tab[256] = {
	/*      0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, */
	/*0x0*/ nop, hlt, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x1*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x2*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x3*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x4*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x5*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x6*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x7*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x8*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x9*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0xa*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0xb*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0xc*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0xd*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0xe*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0xf*/ nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
};

void nop(vm_t *vm) {
	vm->cpu->PC++;
	printf("%s executed\n", __func__);
}

void hlt(vm_t *vm) {
	vm->cpu->flags[FSTOP] = true;
	printf("%s executed\n", __func__);
}

void vm_reset(cpu_t *cpu) {
	cpu->AX = 0;
	cpu->PC = 0; 	
	cpu->SP = 0; 
	cpu->SI = 0; 
	cpu->DI = 0; 
	memset(cpu->flags, 0, sizeof(cpu->flags[0])*SIZE_OF_FLAGS);
}

void vm_SetProgram(vm_t *vm, uint8_t *program, size_t size) {
	vm->memory->ram = program;
	vm->memory->size = size;
}

cpu_t *vm_createCpu() {
	cpu_t *cpu = malloc(sizeof(cpu));
	return cpu;
}

memory_t *vm_createMemory(uint8_t *ram, size_t size) {
	memory_t *mem = malloc(sizeof(memory_t));
	if (mem != NULL) {
		mem->ram = ram;
	}
	mem->size = size;
	return mem;
}

vm_t *vm_create() {
	cpu_t *cpu = NULL;
	memory_t *mem = NULL;
	vm_t *vm = NULL;

	if ((cpu = vm_createCpu()) != NULL) {
		if ((mem = vm_createMemory(NULL, 0)) != NULL) {
			vm = malloc(sizeof(vm));
			vm->cpu = cpu;
			vm->memory = mem;
		}
	}
	return vm;
}

int vm_run(vm_t *vm) {
	cpu_t *cpu = vm->cpu;
	memory_t *mem = vm->memory;

	while (cpu->flags[FSTOP] != true) {
		cmd_tab[mem->ram[cpu->PC]](vm);
	}
	return 0;
}