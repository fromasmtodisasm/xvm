#include "vm.h"
//format = opcode:operands_size[function body]

ADD : 5 #{
	uint res = 0;
	uint left, right;
	right = pop_dword(vm);
	left = pop_dword(vm);
	push_dword(vm, left + right);

}#
AND:0
CALL:0
CMP(st left, st right):0 #{
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

}#
DEC:0
DIV:0
HLT:0 #{
	
	vm->cpu->is_running = false;
}#
IDIV:0
IMUL:0
INC:0
INT:0
INTO:0
JA(st left, st right, st address):0 #{

	if (address <= vm->memory->size - vm->cpu->regs[PC])
	if (left > right)
		vm->cpu->regs[PC] += address;
}#
JMP(cmd address):0 #{
	uint address = pop_dword(vm);
	if (address <= vm->memory->size - vm->cpu->regs[PC])
		vm->cpu->regs[PC] = address;
}#
JZ:0
LEA:0
LOOP:0
LOOPE:0
LOOPNE:0
MUL:0
NEG:0
NOP():0 #{
	//
}#
NOT:0
OR:0
POP(st val):0 #{
	vm->cpu->regs[AX] = val;
}#
PRT(st offset):0 #{
	char *str = (char*)peek_ptr(vm, offset);
}#
PUSH(cmd val):0 #{
	push_dword(vm, val);
}#
RET(st address): 4 #{
    SET_PC(vm, address);
}#
ROL:0
ROR:0
SAHF:0
SAL:0
SAR:0
SHL:0
SHR:0
SUB:0
TEST:0
XCHG:0
XOR:0
