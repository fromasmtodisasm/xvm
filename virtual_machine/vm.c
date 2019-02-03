#include "vm.h"

#include <stdlib.h> 
#include <stdbool.h>
#include <string.h> 
#include <stdio.h>

#define IS_BIT_SET(n,b) n >> b

typedef uint32_t uint;


command cmd_tab[256] = {
	/*      0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, */
	/*0x0*/ nop, nop, psh, pop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
	/*0x1*/ jmp, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop, nop,
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

void nop(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
}

void hlt(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	vm->cpu->is_running = false;
}

void psh(vm_t *vm) {
	uint value = fetch_dword(vm);
	push_dword(vm, value);
	vm->cpu->regs[PC] += 3;
}

void pop(vm_t *vm) {
	vm->cpu->regs[AX] = pop_dword(vm);
}

void mov(vm_t *vm) {
	cpu_t *cpu = vm->cpu;
	uint8_t operands = ++cpu->regs[PC];
	//uint8_t src, dst;
}

void prt(vm_t *vm) {
	int offset = pop_dword(vm);
	char *str = (char*)peek_ptr(vm, offset);
	printf("%s", str);
	vm->cpu->regs[PC]++;
}

void jmp(vm_t *vm) {
	vm->cpu->regs[PC] = pop_dword(vm);
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
	command cmd = NULL;

	while (cpu->is_running == true) {
		//execute(vm, decode(fetch(vm), cmd_tab));
		fetch(vm);
		decode(vm, cmd_tab);
		execute(vm);
	}
	return 0;
}