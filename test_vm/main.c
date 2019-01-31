#include <vm.h>


int main() {

	vm_t *vm;

	//uint8_t program[256] = { [255] = 1 };
	uint8_t program[256] = { 0 };
	program[255] = 1;

	int res = 0;

	vm = vm_create();
	vm_reset(vm->cpu);

	vm_SetProgram(vm, program, sizeof(program));

	res = vm_run(vm);
	return  res;
}