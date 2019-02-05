#include "vm.h"
#include <stdio.h>

void aaa_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void aad_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void aam_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void aas_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void adc_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void add_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	uint res = 0;
	uint left, right;
	right = pop_dword(vm);
	left = pop_dword(vm);
	push_dword(vm, left + right);

/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void and_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void call_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void cbw_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void clc_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void cld_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void cli_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void cmc_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void cmp_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	uint res = 0;
	uint left, right;
	right = pop_dword(vm);
	left = pop_dword(vm);
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

/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void cmpsb_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void cmpsw_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void cwd_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void daa_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void das_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void dec_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void div_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void hlt_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	vm->cpu->is_running = false;
/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void idiv_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void imul_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void in_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void inc_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void int_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void into_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void iret_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void ja_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	uint res = 0;
	uint left, right, address;
	address = pop_dword(vm);
	right = pop_dword(vm);
	left = pop_dword(vm);
	if (address <= vm->memory->size - vm->cpu->regs[PC])
	if (left > right)
		vm->cpu->regs[PC] += address;
/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jae_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jb_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jbe_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jc_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jcxz_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void je_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jg_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jge_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jl_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jle_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jmp_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	uint address = pop_dword(vm);
	if (address <= vm->memory->size - vm->cpu->regs[PC])
		vm->cpu->regs[PC] = address;
/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jna_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jnae_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jnb_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jnbe_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jnc_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jne_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jng_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jnge_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jnl_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jnle_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jno_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jnp_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jns_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jnz_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jo_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jp_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jpe_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jpo_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void js_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void jz_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void lahf_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void lds_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void lea_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void les_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void lodsb_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void lodsw_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void loop_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void loope_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void loopne_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void loopnz_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void loopz_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void mov_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	cpu_t *cpu = vm->cpu;
	uint8_t operands = ++cpu->regs[PC];
/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void movsb_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void movsw_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void mul_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void neg_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void nop_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	//
}
void not_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void or_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void out_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void pop_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	vm->cpu->regs[AX] = pop_dword(vm);
}
void popa_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void popf_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void prt_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	int offset = pop_dword(vm);
	char *str = (char*)peek_ptr(vm, offset);
/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 1;
}
void push_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	uint value = fetch_dword(vm);
	push_dword(vm, value);
/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 3;
}
void pusha_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void pushf_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void rcl_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void rcr_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void rep_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void repe_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void repne_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void repnz_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void repz_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void ret_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void uint_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void set_pc_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void retf_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void rol_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void ror_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void sahf_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void sal_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void sar_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void sbb_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void scasb_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void scasw_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void shl_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void shr_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void stc_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void std_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void sti_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void stosb_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void stosw_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void sub_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void test_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void xchg_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void xlatb_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
void xor_command(vm_t *vm) {
	printf("%04x: %s\n", vm->cpu->regs[PC] - 1, __func__);
	/* Skip operands and shift to next opcode */
	vm->cpu->regs[PC] += 4;
}
