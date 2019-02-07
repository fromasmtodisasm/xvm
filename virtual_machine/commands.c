#include "vm.h"
#include <stdio.h>

#define LOG_FUNC(vm) printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__)

void add_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

	{
	uint res = 0;
	push_dword(vm, left + right);
}}
void and_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

	{
	uint res = left & right;
}}
void call_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint proc = fetch_dword(vm);

	{

	uint next_instr = GET_PC(vm) + 3;
	push_dword(vm, next_instr);
	SET_PC(vm, proc);
}}
void cmp_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

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
	uint offset = fetch_dword(vm);
	char *arg = (char*)peek_ptr(vm, offset);
	{
	*arg = *arg - 1;
}/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 3;
}
void div_command(vm_t *vm) {

	LOG_FUNC(vm);

	}
void dup_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint duplicate = peek_stack_dword(vm, 0);

	{
	push_dword(vm, duplicate);
}}
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
	uint offset = fetch_dword(vm);
	char *arg = (char*)peek_ptr(vm, offset);
	{
	*arg = *arg + 1;
}/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 3;
}
void int_command(vm_t *vm) {

	LOG_FUNC(vm);

	}
void into_command(vm_t *vm) {

	LOG_FUNC(vm);

	}
void ja_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint address = pop_dword(vm);
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

	{
	if (left > right)
		vm->cpu->regs[PC] += address;
}}
void jc_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint address = fetch_dword(vm);

	{
	if (vm->cpu->flags[CF])
		SET_PC(vm,address);
}}
void jmp_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint address = fetch_dword(vm);

	{
	//if (address <= vm->memory->size - vm->cpu->regs[PC])
		vm->cpu->regs[PC] = address;
}}
void jnz_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint address = pop_dword(vm);
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

	{
	if (left != right)
		SET_PC(vm,address);
}}
void jz_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint address = pop_dword(vm);
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

	{
	if (left == right)
		SET_PC(vm,address);
}}
void lea_command(vm_t *vm) {

	LOG_FUNC(vm);

	}
void load_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint addr = fetch_dword(vm);

	{
	
	uint val = peek_dword(vm, addr);
	push_dword(vm, val);
}/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 3;
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
void over_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint over = peek_stack_dword(vm, -1);

	{
	push_dword(vm, over);
}}
void pop_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint val = pop_dword(vm);

	{
	vm->cpu->regs[AX] = val;
}}
void prt_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint offset = pop_dword(vm);
	char *str = (char*)peek_ptr(vm, offset);
	{
	while (*str != 0)
	{
		printf("%c", *str);
		str = (str + 4);
	}
	puts("");
}}
void push_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint val = fetch_dword(vm);

	{
	push_dword(vm, val);
}/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 3;
}
void ret_command(vm_t *vm) {

	LOG_FUNC(vm);
	uint address = pop_dword(vm);

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
	uint right = pop_dword(vm);
	uint left = pop_dword(vm);

	{
	uint res = 0;
	push_dword(vm, left - right);
	if (left < right)
		vm->cpu->flags[CF] = 1;
	else 
		vm->cpu->flags[CF] = 0;

}}
void test_command(vm_t *vm) {

	LOG_FUNC(vm);

	}
void xchg_command(vm_t *vm) {

	LOG_FUNC(vm);

	}
void xor_command(vm_t *vm) {

	LOG_FUNC(vm);

	}
