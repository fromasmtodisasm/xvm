#include <vm.h>
#include <string.h>


#define PROG_SIZE 128
typedef uint32_t uint;

int main() {

	vm_t *vm;

	size_t size_of_prog = 256;
	//uint8_t *program = malloc(PROG_SIZE*sizeof(uint8_t));
	uint8_t program[PROG_SIZE];
	int pc = 1;
	memset(program, 0, PROG_SIZE);

	int res = 0;
	char *greating = "Hello, World!\n";

	uint str_offset = PROG_SIZE - strlen(greating) - 1;
	program[pc++] = 0x2;
	*((uint*)&(program[pc])) = PROG_SIZE - strlen(greating) - 1;
	pc += (sizeof(uint));
	program[pc++] = 0xf0;
	program[str_offset -1] = 0xff;
	
	memcpy(&program[str_offset], greating, strlen(greating) + 1);

	memory_t *mem = vm_createMemory(program, PROG_SIZE);
	vm = vm_create(mem,128);
	vm_reset(vm);

	res = vm_run(vm);
	return  res;
}