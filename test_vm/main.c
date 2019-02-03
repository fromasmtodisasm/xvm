#include <vm.h>
#include <string.h>
#include <stdlib.h>


#define PROG_SIZE 128
typedef uint32_t uint;

uint8_t *make_program(size_t size) {
	int pc = 1;
	int res = 0;
	char *greating = "Hello, World!\n";
	uint8_t *program = malloc(PROG_SIZE*sizeof(uint8_t));
	uint start_of_prog = 0x50;

	memset(program, 0, PROG_SIZE);
	uint str_offset = PROG_SIZE - strlen(greating) - 1;
	/*push*/
	program[pc++] = 0x02;
	*((uint*)&(program[pc])) = start_of_prog;
	pc += (sizeof(uint));

	
	program[pc++] = 0x10;

	int len = strlen(greating) + 1;
	memcpy(&program[str_offset=pc], greating, strlen(greating) + 1);
	pc += len;

	/*For print */
	pc = start_of_prog;
	program[pc++] = 0x2;
	*((uint*)&(program[pc])) = str_offset;// PROG_SIZE - strlen(greating) - 1;
	pc += (sizeof(uint));
	program[pc++] = 0xf0;
	program[PROG_SIZE -1] = 0xff;
	
	memcpy(&program[str_offset], greating, strlen(greating) + 1);
	return program;
}

int main() {
	vm_t *vm;
	int res = -1;
	uint8_t *program = NULL;

	if (program = make_program(PROG_SIZE)) {
		memory_t *mem = vm_createMemory(program, PROG_SIZE);
		vm = vm_create(mem, 128);
		vm_reset(vm);
		res = vm_run(vm);
	}
	dump_cpu(vm);
	return  res;
}