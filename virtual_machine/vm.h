#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "table.h"

/*
#ifdef WIN32
	#ifdef VIRTUALMACHINE_EXPORTS 
		#define VM_API __declspec(dllexport)
	#else
		#define VM_API __declspec(dllimport)
	#endif
#else
	#define VM_API
#endif
*/

/* DEFINES */
#define REGS_COUNT 8

typedef uint32_t uint;

typedef enum FLAGS {
	ZF,
	CF,
	SF,
	SIZE_OF_FLAGS
}FLAGS;

typedef struct vm_t vm_t;
//typedef void (*command)(vm_t*);

enum regs {
	AX,		/* accumulator */
	BX,
	CX,
	DX,
	SI,		/* source index */
	DI,		/* destination index */
	PC,		/* program counter */
	SP		/* stack pointer */
};

/* definition of cpu */
typedef struct cpu_t
{
	uint regs[REGS_COUNT];
	bool is_running;		/* */
	uint8_t opcode;
	command *cmd;
	uint flags[SIZE_OF_FLAGS];  /* */
}cpu_t;

typedef struct memory_t
{
	uint8_t *ram;
	size_t size;
}memory_t;

typedef struct vm_t
{
	cpu_t *cpu;
	memory_t *memory;
	memory_t *stack;
}vm_t;


/* DEFINES */
#define SET_PC(vm,val) (vm->cpu->regs[PC] = val)
#define GET_PC(vm) (vm->cpu->regs[PC])

#define fetch(vm) (vm->cpu->opcode = vm->memory->ram[vm->cpu->regs[PC]++]) 
#define decode(vm, tab) (vm->cpu->cmd = &tab[vm->cpu->opcode])
#define execute(vm) if (vm->cpu->cmd) ( vm->cpu->cmd->function(vm))

#define fetch_dword(vm) (*((uint*)&(vm->memory->ram[(vm->cpu->regs[PC])++])))
#define peek_dword(vm, ofst) (*((uint*)&(vm->memory->ram[ofst])))
#define peek_ptr(vm, ofst) (((uint*)&(vm->memory->ram[ofst])))

#define push_dword(vm, val) ((((uint*)(vm->stack->ram))[(vm->cpu->regs[SP]++)]) = val)
#define pop_dword(vm) (((uint*)(vm->stack->ram))[--(vm->cpu->regs[SP])])

void dump_cpu(vm_t * vm);

/* block of commands for processor */
#include "commands.h"

void vm_reset(vm_t * cpu);

void vm_setProgram(vm_t * vm, uint8_t * program, size_t size);

cpu_t * vm_createCpu();

memory_t * vm_createMemory(uint8_t * ram, size_t size);

vm_t * vm_create(memory_t * program, size_t stack_size);

int vm_run(vm_t * vm);
