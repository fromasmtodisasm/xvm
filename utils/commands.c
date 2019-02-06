#include "vm.h"
//format = opcode:operands_size[function body]

ADD(st left, st right) : 0 #{
	uint res = 0;
	push_dword(vm, left + right);

}#
AND:0
CALL(cmd proc) : 0 #{

	uint next_instr = GET_PC(vm) + 3;
	push_dword(vm, next_instr);
	SET_PC(vm, proc);
}#

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
	//if (address <= vm->memory->size - vm->cpu->regs[PC])
		vm->cpu->regs[PC] = address;
}#
JZ:0
LEA:0
LOOP:0
LOOPE:0
LOOPNE:0
LOAD(cmd addr) : 4 #{
//
}#
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
	uint32_t dword;
	int i = 0;
	while (*str != 0)
	{
		printf("%c", *str);
		str = (str + 4);
	}
	puts("");
}#
PUSH(cmd val):3 #{
	push_dword(vm, val);
}#
RET(st address): 0 #{
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
