#pragma once
#include <stdio.h>
#include <stdint.h>
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

Program* assembly(char ** src);


Program *main_asm(int argc, char ** argv);