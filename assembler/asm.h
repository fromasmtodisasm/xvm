#pragma once
#include <stdio.h>
#include <stdint.h>
#define strdup _strdup

//typedef struct vm_t vm_t;

#ifndef COMMAND_DEFINED
typedef struct {
	char *name;
	int opcode;
	int op_cnt;
	void(*function) (void*);
}command;
#endif

typedef struct Label {
	char *name;
	int addr;
}Label;

Label * process_label(int mode);
typedef struct Program {
	uint8_t *mem;
	size_t size;
}Program;
void disassembly(uint8_t * memory, size_t size, int mode);

Program* assembly(char ** src, FILE * fout);


Program *main_asm(int argc, char ** argv);