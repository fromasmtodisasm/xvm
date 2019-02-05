#pragma once
#include <stdint.h>
typedef enum OPCODES {
	AAA = 0x00,
	AAD = 0x01,
	AAM = 0x02,
	AAS = 0x03,
	ADC = 0x04,
	ADD = 0x05,
	AND = 0x06,
	CALL = 0x07,
	CBW = 0x08,
	CLC = 0x09,
	CLD = 0x0a,
	CLI = 0x0b,
	CMC = 0x0c,
	CMP = 0x0d,
	CMPSB = 0x0e,
	CMPSW = 0x0f,
	CWD = 0x10,
	DAA = 0x11,
	DAS = 0x12,
	DEC = 0x13,
	DIV = 0x14,
	HLT = 0x15,
	IDIV = 0x16,
	IMUL = 0x17,
	IN = 0x18,
	INC = 0x19,
	INT = 0x1a,
	INTO = 0x1b,
	IRET = 0x1c,
	JA = 0x1d,
	JAE = 0x1e,
	JB = 0x1f,
	JBE = 0x20,
	JC = 0x21,
	JCXZ = 0x22,
	JE = 0x23,
	JG = 0x24,
	JGE = 0x25,
	JL = 0x26,
	JLE = 0x27,
	JMP = 0x28,
	JNA = 0x29,
	JNAE = 0x2a,
	JNB = 0x2b,
	JNBE = 0x2c,
	JNC = 0x2d,
	JNE = 0x2e,
	JNG = 0x2f,
	JNGE = 0x30,
	JNL = 0x31,
	JNLE = 0x32,
	JNO = 0x33,
	JNP = 0x34,
	JNS = 0x35,
	JNZ = 0x36,
	JO = 0x37,
	JP = 0x38,
	JPE = 0x39,
	JPO = 0x3a,
	JS = 0x3b,
	JZ = 0x3c,
	LAHF = 0x3d,
	LDS = 0x3e,
	LEA = 0x3f,
	LES = 0x40,
	LODSB = 0x41,
	LODSW = 0x42,
	LOOP = 0x43,
	LOOPE = 0x44,
	LOOPNE = 0x45,
	LOOPNZ = 0x46,
	LOOPZ = 0x47,
	MOV = 0x48,
	MOVSB = 0x49,
	MOVSW = 0x4a,
	MUL = 0x4b,
	NEG = 0x4c,
	NOP = 0x4d,
	NOT = 0x4e,
	OR = 0x4f,
	OUT = 0x50,
	POP = 0x51,
	POPA = 0x52,
	POPF = 0x53,
	PRT = 0x54,
	PUSH = 0x55,
	PUSHA = 0x56,
	PUSHF = 0x57,
	RCL = 0x58,
	RCR = 0x59,
	REP = 0x5a,
	REPE = 0x5b,
	REPNE = 0x5c,
	REPNZ = 0x5d,
	REPZ = 0x5e,
	RET = 0x5f,
	UINT = 0x60,
	SET_PC = 0x61,
	RETF = 0x62,
	ROL = 0x63,
	ROR = 0x64,
	SAHF = 0x65,
	SAL = 0x66,
	SAR = 0x67,
	SBB = 0x68,
	SCASB = 0x69,
	SCASW = 0x6a,
	SHL = 0x6b,
	SHR = 0x6c,
	STC = 0x6d,
	STD = 0x6e,
	STI = 0x6f,
	STOSB = 0x70,
	STOSW = 0x71,
	SUB = 0x72,
	TEST = 0x73,
	XCHG = 0x74,
	XLATB = 0x75,
	XOR = 0x76,
}OPCODES;
typedef struct vm_t vm_t;
typedef struct command{
	char *name;
	enum OPCODES opcode;
	void(*function) (vm_t*);
}command;
extern command cmd_tab[0x77];
