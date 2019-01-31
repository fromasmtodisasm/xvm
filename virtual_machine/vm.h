#pragma once

#include <stdint.h>
#include <stdbool.h>

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

typedef enum FLAGS {
	FSTOP,
	FZ,
	FC,
	SIZE_OF_FLAGS
}FLAGS;

/* definition of cpu */
typedef struct cpu_t
{
	uint32_t AX;		/* accumulator */
	uint32_t PC;		/* program counter */
	uint32_t SP;		/* stack pointer */
	uint32_t SI;		/* source index */
	uint32_t DI;		/* destination index */
	uint32_t flags[SIZE_OF_FLAGS];  /* */
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
}vm_t;

typedef bool (*command)(vm_t*);

/* block of command of processor */
void nop(vm_t *vm);

void hlt(vm_t * vm);

void vm_reset(cpu_t * cpu);

void vm_SetProgram(vm_t * vm, uint8_t * program, size_t size);

cpu_t * vm_createCpu();

memory_t * vm_createMemory(uint8_t * ram, size_t size);

vm_t * vm_create();

int vm_run(vm_t * vm);
