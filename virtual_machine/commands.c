#include "vm.h"
#include <stdio.h>

#define LOG_FUNC(vm) printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__)

void add_command(vm_t *vm) {
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

	LOG_FUNC(vm);
	{
	uint res = 0;
	push_dword(vm, left + right);

}}
void and_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void call_command(vm_t *vm) {
	uint proc = fetch_dword(vm);

	LOG_FUNC(vm);
	{

	uint next_instr = GET_PC(vm) + 3;
	push_dword(vm, next_instr);
	SET_PC(vm, proc);
}}
void cmp_command(vm_t *vm) {
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

	LOG_FUNC(vm);
	{
	uint res = 0;
	res = left - right;
	if (res == 0) {
		vm->cpu->regs[ZF] = 1;
	}
	else {
		if (res < 0) {
			vm->cpu->regs[CF] = 1;
		}
		else {
			vm->cpu->regs[CF] = 0;
		}

		vm->cpu->regs[ZF] = 0;
	}

}}
void dec_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void div_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void hlt_command(vm_t *vm) {

	LOG_FUNC(vm);
	{
	
	vm->cpu->is_running = false;
}}
void idiv_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void imul_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void inc_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void int_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void into_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void ja_command(vm_t *vm) {
	uint address = pop_dword(vm);
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

	LOG_FUNC(vm);
	{

	if (address <= vm->memory->size - vm->cpu->regs[PC])
	if (left > right)
		vm->cpu->regs[PC] += address;
}}
void jmp_command(vm_t *vm) {
	uint address = fetch_dword(vm);

	LOG_FUNC(vm);
	{
	//if (address <= vm->memory->size - vm->cpu->regs[PC])
		vm->cpu->regs[PC] = address;
}}
void jz_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void lea_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void load_command(vm_t *vm) {
	uint addr = fetch_dword(vm);

	LOG_FUNC(vm);
	{
//
}/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void loop_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void loope_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void loopne_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void mul_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void neg_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void nop_command(vm_t *vm) {

	LOG_FUNC(vm);
	{
	//
}}
void not_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void or_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void pop_command(vm_t *vm) {
	uint val = pop_dword(vm);

	LOG_FUNC(vm);
	{
	vm->cpu->regs[AX] = val;
}}
void prt_command(vm_t *vm) {
	uint offset = pop_dword(vm);

	LOG_FUNC(vm);
	{
	char *str = (char*)peek_ptr(vm, offset);
	uint32_t dword;
	int i = 0;
	while (*str != 0)
	{
		printf("%c", *str);
		str = (str + 4);
	}
	puts("");
}}
void push_command(vm_t *vm) {
	uint val = fetch_dword(vm);

	LOG_FUNC(vm);
	{
	push_dword(vm, val);
}/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 3;
}
void ret_command(vm_t *vm) {
	uint address = pop_dword(vm);

	LOG_FUNC(vm);
	{
    SET_PC(vm, address);
}}
void rol_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void ror_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void sahf_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void sal_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void sar_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void shl_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void shr_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void sub_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void test_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void xchg_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
void xor_command(vm_t *vm) {

	LOG_FUNC(vm);
	}
