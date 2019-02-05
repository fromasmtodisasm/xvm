#include "vm.h"
//format = opcode:operands_size[function body]
AAA:4
AAD:4
AAM:4
AAS:4
ADC:4
ADD:4 #
	uint res = 0;
	uint left, right;
	right = pop_dword(vm);
	left = pop_dword(vm);
	push_dword(vm, left + right);

#
AND:4
CALL:4
CBW:4
CLC:4
CLD:4
CLI:4
CMC:4
CMP:4 #
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

#
CMPSB:4
CMPSW:4
CWD:4
DAA:4
DAS:4
DEC:4
DIV:4
HLT:4 #
	
	vm->cpu->is_running = false;
#
IDIV:4
IMUL:4
IN:4
INC:4
INT:4
INTO:4
IRET:4
JA:4 #
	uint res = 0;
	uint left, right, address;
	address = pop_dword(vm);
	right = pop_dword(vm);
	left = pop_dword(vm);
	if (address <= vm->memory->size - vm->cpu->regs[PC])
	if (left > right)
		vm->cpu->regs[PC] += address;
#
JAE:4
JB:4
JBE:4
JC:4
JCXZ:4
JE:4
JG:4
JGE:4
JL:4
JLE:4
JMP:4 #
	uint address = pop_dword(vm);
	if (address <= vm->memory->size - vm->cpu->regs[PC])
		vm->cpu->regs[PC] = address;
#
JNA:4
JNAE:4
JNB:4
JNBE:4
JNC:4
JNE:4
JNG:4
JNGE:4
JNL:4
JNLE:4
JNO:4
JNP:4
JNS:4
JNZ:4
JO:4
JP:4
JPE:4
JPO:4
JS:4
JZ:4
LAHF:4
LDS:4
LEA:4
LES:4
LODSB:4
LODSW:4
LOOP:4
LOOPE:4
LOOPNE:4
LOOPNZ:4
LOOPZ:4
MOV:4 #
	cpu_t *cpu = vm->cpu;
	uint8_t operands = ++cpu->regs[PC];
#
MOVSB:4
MOVSW:4
MUL:4
NEG:4
NOP:0 #
	//
#
NOT:4
OR:4
OUT:4
POP:0 #
	vm->cpu->regs[AX] = pop_dword(vm);
#
POPA:4
POPF:4
PRT:1 #
	int offset = pop_dword(vm);
	char *str = (char*)peek_ptr(vm, offset);
#
PUSH:3 #
	uint value = fetch_dword(vm);
	push_dword(vm, value);
#
PUSHA:4
PUSHF : 4
RCL : 4
RCR : 4
REP : 4
REPE : 4
REPNE : 4
REPNZ : 4
REPZ : 4
RET : 4 #
	uint address = pop_dword(vm);
    SET_PC(vm, address);
#
RETF:4
ROL:4
ROR:4
SAHF:4
SAL:4
SAR:4
SBB:4
SCASB:4
SCASW:4
SHL:4
SHR:4
STC:4
STD:4
STI:4
STOSB:4
STOSW:4
SUB:4
TEST:4
XCHG:4
XLATB:4
XOR:4
