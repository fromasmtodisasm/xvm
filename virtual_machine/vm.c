#include "vm.h"

#include <stdlib.h> 
#include <stdbool.h>
#include <string.h> 
#include <stdio.h>

typedef uint32_t uint;

command cmd_tab[256] = {
	/*      0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, */
	/*0x0*/ nop, nop, psh, pop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
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
	/*0xf*/ prt, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, hlt,
};

void nop(vm_t *vm) {
	vm->cpu->PC++;
	printf("%s executed\n", __func__);
}

void hlt(vm_t *vm) {
	vm->cpu->flags[FSTOP] = true;
	printf("%s executed\n", __func__);
}

void psh(vm_t *vm) {
	uint value = *((uint*)&(vm->memory->ram[++(vm->cpu->PC)]));
	*((uint*)&(vm->stack->ram[(vm->cpu->SP++)])) = value;
	vm->cpu->PC += 4;
}

void pop(vm_t *vm) {
	vm->cpu->AX = *((uint*)&(vm->stack->ram[--(vm->cpu->SP)]));
	vm->cpu->PC++;
}

void prt(vm_t *vm) {
	//int offset = *((uint*)&(vm->memory->ram[++(vm->cpu->PC)]));
	//char *str = (char*)&(vm->memory->ram[offset]);
	//pop(vm);
	int offset = *((uint*)&(vm->stack->ram[--(vm->cpu->SP)]));
	char *str = *((uint*)&(vm->memory->ram[offset]));
	printf("%s", str);
	vm->cpu->PC += 4;
}

void vm_reset(vm_t *vm) {
	cpu_t *cpu = vm->cpu;

	cpu->AX = 0;
	cpu->PC = 0; 	
	cpu->SP = 0;// vm->stack->size - 1;
	cpu->SI = 0; 
	cpu->DI = 0; 
	memset(cpu->flags, 0, sizeof(cpu->flags[0])*SIZE_OF_FLAGS);
}

void vm_SetProgram(vm_t *vm, uint8_t *program, size_t size) {
	vm->memory->ram = program;
	vm->memory->size = size;
	//vm->cpu->SP = size - 1;
}

cpu_t *vm_createCpu() {
	cpu_t *cpu = malloc(sizeof(cpu));
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

vm_t *vm_create(size_t stack_size) {
	cpu_t *cpu = NULL;
	memory_t *mem = NULL;
	vm_t *vm = NULL;

	if ((cpu = vm_createCpu()) != NULL) {
		if ((mem = vm_createMemory(NULL, 0)) != NULL) {
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

	while (cpu->flags[FSTOP] != true) {
		cmd_tab[mem->ram[cpu->PC]](vm);
	}
	return 0;
}