#include "vm.h"
//format = opcode:operands_size[function body]

ADD(st left, st right) : 0 #{
	uint res = 0;
	push_dword(vm, left + right);
}#
AND(st left, st right) : 0 #{
	uint res = left & right;
}#
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
DEC(cmd_inderect arg):3 #{
	*arg = *arg - 1;
}#
DIV:0
HLT:0 #{
	vm->cpu->is_running = false;
}#
IDIV:0
IMUL:0
INC(cmd_inderect arg):3 #{
	*arg = *arg + 1;
}#

INT:0
INTO:0
JA(st left, st right, st address):0 #{
	if (left > right)
		vm->cpu->regs[PC] += address;
}#
JMP(cmd address):0 #{
	//if (address <= vm->memory->size - vm->cpu->regs[PC])
		vm->cpu->regs[PC] = address;
}#
JZ(st left, st right, st address):0 #{
	if (left == right)
		SET_PC(vm,address);
}#
JNZ(st left, st right, st address):0 #{
	if (left != right)
		SET_PC(vm,address);
}#
JC(cmd address):0 #{
	if (vm->cpu->flags[CF])
		SET_PC(vm,address);
}#
LEA:0
LOOP:0
LOOPE:0
LOOPNE:0
LOAD(cmd addr) : 3 #{
	
	uint val = peek_dword(vm, addr);
	push_dword(vm, val);
}#
SAVE(cmd addr) : 3 #{
	
	uint val = peek_dword(vm, addr);
	*get_ref(vm, addr) = val;
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
PRT(inderect str):0 #{
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
SUB(st left, st right) : 0 #{
	uint res = 0;
	push_dword(vm, left - right);
	if (left < right)
		vm->cpu->flags[CF] = 1;
	else 
		vm->cpu->flags[CF] = 0;

}#
TEST:0
XCHG:0
XOR:0

DUP(st_peek duplicate) : 0 #{
	push_dword(vm, duplicate);
}#
OVER(st_over over) : 0 #{
	push_dword(vm, over);
}#

SUPERPUPERCOMMAND():0 #{

	//
		
}#
