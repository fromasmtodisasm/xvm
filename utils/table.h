enum OPCODES {
	aaa_opcode = 0x00,
	aad_opcode = 0x01,
	aam_opcode = 0x02,
	aas_opcode = 0x03,
	adc_opcode = 0x04,
	add_opcode = 0x05,
	and_opcode = 0x06,
	call_opcode = 0x07,
	cbw_opcode = 0x08,
	clc_opcode = 0x09,
	cld_opcode = 0x0a,
	cli_opcode = 0x0b,
	cmc_opcode = 0x0c,
	cmp_opcode = 0x0d,
	cmpsb_opcode = 0x0e,
	cmpsw_opcode = 0x0f,
	cwd_opcode = 0x10,
	daa_opcode = 0x11,
	das_opcode = 0x12,
	dec_opcode = 0x13,
	div_opcode = 0x14,
	hlt_opcode = 0x15,
	idiv_opcode = 0x16,
	imul_opcode = 0x17,
	in_opcode = 0x18,
	inc_opcode = 0x19,
	int_opcode = 0x1a,
	into_opcode = 0x1b,
	iret_opcode = 0x1c,
	ja_opcode = 0x1d,
	jae_opcode = 0x1e,
	jb_opcode = 0x1f,
	jbe_opcode = 0x20,
	jc_opcode = 0x21,
	jcxz_opcode = 0x22,
	je_opcode = 0x23,
	jg_opcode = 0x24,
	jge_opcode = 0x25,
	jl_opcode = 0x26,
	jle_opcode = 0x27,
	jmp_opcode = 0x28,
	jna_opcode = 0x29,
	jnae_opcode = 0x2a,
	jnb_opcode = 0x2b,
	jnbe_opcode = 0x2c,
	jnc_opcode = 0x2d,
	jne_opcode = 0x2e,
	jng_opcode = 0x2f,
	jnge_opcode = 0x30,
	jnl_opcode = 0x31,
	jnle_opcode = 0x32,
	jno_opcode = 0x33,
	jnp_opcode = 0x34,
	jns_opcode = 0x35,
	jnz_opcode = 0x36,
	jo_opcode = 0x37,
	jp_opcode = 0x38,
	jpe_opcode = 0x39,
	jpo_opcode = 0x3a,
	js_opcode = 0x3b,
	jz_opcode = 0x3c,
	lahf_opcode = 0x3d,
	lds_opcode = 0x3e,
	lea_opcode = 0x3f,
	les_opcode = 0x40,
	lodsb_opcode = 0x41,
	lodsw_opcode = 0x42,
	loop_opcode = 0x43,
	loope_opcode = 0x44,
	loopne_opcode = 0x45,
	loopnz_opcode = 0x46,
	loopz_opcode = 0x47,
	mov_opcode = 0x48,
	movsb_opcode = 0x49,
	movsw_opcode = 0x4a,
	mul_opcode = 0x4b,
	neg_opcode = 0x4c,
	nop_opcode = 0x4d,
	not_opcode = 0x4e,
	or_opcode = 0x4f,
	out_opcode = 0x50,
	pop_opcode = 0x51,
	popa_opcode = 0x52,
	popf_opcode = 0x53,
	push_opcode = 0x54,
	pusha_opcode = 0x55,
	pushf_opcode = 0x56,
	rcl_opcode = 0x57,
	rcr_opcode = 0x58,
	rep_opcode = 0x59,
	repe_opcode = 0x5a,
	repne_opcode = 0x5b,
	repnz_opcode = 0x5c,
	repz_opcode = 0x5d,
	ret_opcode = 0x5e,
	retf_opcode = 0x5f,
	rol_opcode = 0x60,
	ror_opcode = 0x61,
	sahf_opcode = 0x62,
	sal_opcode = 0x63,
	sar_opcode = 0x64,
	sbb_opcode = 0x65,
	scasb_opcode = 0x66,
	scasw_opcode = 0x67,
	shl_opcode = 0x68,
	shr_opcode = 0x69,
	stc_opcode = 0x6a,
	std_opcode = 0x6b,
	sti_opcode = 0x6c,
	stosb_opcode = 0x6d,
	stosw_opcode = 0x6e,
	sub_opcode = 0x6f,
	test_opcode = 0x70,
	xchg_opcode = 0x71,
	xlatb_opcode = 0x72,
	xor_opcode = 0x73,
	xor_opcode = 0x74,
};
/* Function prototypes for cpu commands */
void aaa_command(vm_t *vm);
void aad_command(vm_t *vm);
void aam_command(vm_t *vm);
void aas_command(vm_t *vm);
void adc_command(vm_t *vm);
void add_command(vm_t *vm);
void and_command(vm_t *vm);
void call_command(vm_t *vm);
void cbw_command(vm_t *vm);
void clc_command(vm_t *vm);
void cld_command(vm_t *vm);
void cli_command(vm_t *vm);
void cmc_command(vm_t *vm);
void cmp_command(vm_t *vm);
void cmpsb_command(vm_t *vm);
void cmpsw_command(vm_t *vm);
void cwd_command(vm_t *vm);
void daa_command(vm_t *vm);
void das_command(vm_t *vm);
void dec_command(vm_t *vm);
void div_command(vm_t *vm);
void hlt_command(vm_t *vm);
void idiv_command(vm_t *vm);
void imul_command(vm_t *vm);
void in_command(vm_t *vm);
void inc_command(vm_t *vm);
void int_command(vm_t *vm);
void into_command(vm_t *vm);
void iret_command(vm_t *vm);
void ja_command(vm_t *vm);
void jae_command(vm_t *vm);
void jb_command(vm_t *vm);
void jbe_command(vm_t *vm);
void jc_command(vm_t *vm);
void jcxz_command(vm_t *vm);
void je_command(vm_t *vm);
void jg_command(vm_t *vm);
void jge_command(vm_t *vm);
void jl_command(vm_t *vm);
void jle_command(vm_t *vm);
void jmp_command(vm_t *vm);
void jna_command(vm_t *vm);
void jnae_command(vm_t *vm);
void jnb_command(vm_t *vm);
void jnbe_command(vm_t *vm);
void jnc_command(vm_t *vm);
void jne_command(vm_t *vm);
void jng_command(vm_t *vm);
void jnge_command(vm_t *vm);
void jnl_command(vm_t *vm);
void jnle_command(vm_t *vm);
void jno_command(vm_t *vm);
void jnp_command(vm_t *vm);
void jns_command(vm_t *vm);
void jnz_command(vm_t *vm);
void jo_command(vm_t *vm);
void jp_command(vm_t *vm);
void jpe_command(vm_t *vm);
void jpo_command(vm_t *vm);
void js_command(vm_t *vm);
void jz_command(vm_t *vm);
void lahf_command(vm_t *vm);
void lds_command(vm_t *vm);
void lea_command(vm_t *vm);
void les_command(vm_t *vm);
void lodsb_command(vm_t *vm);
void lodsw_command(vm_t *vm);
void loop_command(vm_t *vm);
void loope_command(vm_t *vm);
void loopne_command(vm_t *vm);
void loopnz_command(vm_t *vm);
void loopz_command(vm_t *vm);
void mov_command(vm_t *vm);
void movsb_command(vm_t *vm);
void movsw_command(vm_t *vm);
void mul_command(vm_t *vm);
void neg_command(vm_t *vm);
void nop_command(vm_t *vm);
void not_command(vm_t *vm);
void or_command(vm_t *vm);
void out_command(vm_t *vm);
void pop_command(vm_t *vm);
void popa_command(vm_t *vm);
void popf_command(vm_t *vm);
void push_command(vm_t *vm);
void pusha_command(vm_t *vm);
void pushf_command(vm_t *vm);
void rcl_command(vm_t *vm);
void rcr_command(vm_t *vm);
void rep_command(vm_t *vm);
void repe_command(vm_t *vm);
void repne_command(vm_t *vm);
void repnz_command(vm_t *vm);
void repz_command(vm_t *vm);
void ret_command(vm_t *vm);
void retf_command(vm_t *vm);
void rol_command(vm_t *vm);
void ror_command(vm_t *vm);
void sahf_command(vm_t *vm);
void sal_command(vm_t *vm);
void sar_command(vm_t *vm);
void sbb_command(vm_t *vm);
void scasb_command(vm_t *vm);
void scasw_command(vm_t *vm);
void shl_command(vm_t *vm);
void shr_command(vm_t *vm);
void stc_command(vm_t *vm);
void std_command(vm_t *vm);
void sti_command(vm_t *vm);
void stosb_command(vm_t *vm);
void stosw_command(vm_t *vm);
void sub_command(vm_t *vm);
void test_command(vm_t *vm);
void xchg_command(vm_t *vm);
void xlatb_command(vm_t *vm);
void xor_command(vm_t *vm);
void xor_command(vm_t *vm);
#define CMD(n, oc)  { #n, oc, n ## _command }

struct command{
	char *name;
	uint8_t opcode;
	void(*function) (void);
};
command cmd_tab[0x75] = {
	/*0x00*/	CMD(AAA,0x00),
	/*0x01*/	CMD(AAD,0x01),
	/*0x02*/	CMD(AAM,0x02),
	/*0x03*/	CMD(AAS,0x03),
	/*0x04*/	CMD(ADC,0x04),
	/*0x05*/	CMD(ADD,0x05),
	/*0x06*/	CMD(AND,0x06),
	/*0x07*/	CMD(CALL,0x07),
	/*0x08*/	CMD(CBW,0x08),
	/*0x09*/	CMD(CLC,0x09),
	/*0x0a*/	CMD(CLD,0x0a),
	/*0x0b*/	CMD(CLI,0x0b),
	/*0x0c*/	CMD(CMC,0x0c),
	/*0x0d*/	CMD(CMP,0x0d),
	/*0x0e*/	CMD(CMPSB,0x0e),
	/*0x0f*/	CMD(CMPSW,0x0f),
	/*0x10*/	CMD(CWD,0x10),
	/*0x11*/	CMD(DAA,0x11),
	/*0x12*/	CMD(DAS,0x12),
	/*0x13*/	CMD(DEC,0x13),
	/*0x14*/	CMD(DIV,0x14),
	/*0x15*/	CMD(HLT,0x15),
	/*0x16*/	CMD(IDIV,0x16),
	/*0x17*/	CMD(IMUL,0x17),
	/*0x18*/	CMD(IN,0x18),
	/*0x19*/	CMD(INC,0x19),
	/*0x1a*/	CMD(INT,0x1a),
	/*0x1b*/	CMD(INTO,0x1b),
	/*0x1c*/	CMD(IRET,0x1c),
	/*0x1d*/	CMD(JA,0x1d),
	/*0x1e*/	CMD(JAE,0x1e),
	/*0x1f*/	CMD(JB,0x1f),
	/*0x20*/	CMD(JBE,0x20),
	/*0x21*/	CMD(JC,0x21),
	/*0x22*/	CMD(JCXZ,0x22),
	/*0x23*/	CMD(JE,0x23),
	/*0x24*/	CMD(JG,0x24),
	/*0x25*/	CMD(JGE,0x25),
	/*0x26*/	CMD(JL,0x26),
	/*0x27*/	CMD(JLE,0x27),
	/*0x28*/	CMD(JMP,0x28),
	/*0x29*/	CMD(JNA,0x29),
	/*0x2a*/	CMD(JNAE,0x2a),
	/*0x2b*/	CMD(JNB,0x2b),
	/*0x2c*/	CMD(JNBE,0x2c),
	/*0x2d*/	CMD(JNC,0x2d),
	/*0x2e*/	CMD(JNE,0x2e),
	/*0x2f*/	CMD(JNG,0x2f),
	/*0x30*/	CMD(JNGE,0x30),
	/*0x31*/	CMD(JNL,0x31),
	/*0x32*/	CMD(JNLE,0x32),
	/*0x33*/	CMD(JNO,0x33),
	/*0x34*/	CMD(JNP,0x34),
	/*0x35*/	CMD(JNS,0x35),
	/*0x36*/	CMD(JNZ,0x36),
	/*0x37*/	CMD(JO,0x37),
	/*0x38*/	CMD(JP,0x38),
	/*0x39*/	CMD(JPE,0x39),
	/*0x3a*/	CMD(JPO,0x3a),
	/*0x3b*/	CMD(JS,0x3b),
	/*0x3c*/	CMD(JZ,0x3c),
	/*0x3d*/	CMD(LAHF,0x3d),
	/*0x3e*/	CMD(LDS,0x3e),
	/*0x3f*/	CMD(LEA,0x3f),
	/*0x40*/	CMD(LES,0x40),
	/*0x41*/	CMD(LODSB,0x41),
	/*0x42*/	CMD(LODSW,0x42),
	/*0x43*/	CMD(LOOP,0x43),
	/*0x44*/	CMD(LOOPE,0x44),
	/*0x45*/	CMD(LOOPNE,0x45),
	/*0x46*/	CMD(LOOPNZ,0x46),
	/*0x47*/	CMD(LOOPZ,0x47),
	/*0x48*/	CMD(MOV,0x48),
	/*0x49*/	CMD(MOVSB,0x49),
	/*0x4a*/	CMD(MOVSW,0x4a),
	/*0x4b*/	CMD(MUL,0x4b),
	/*0x4c*/	CMD(NEG,0x4c),
	/*0x4d*/	CMD(NOP,0x4d),
	/*0x4e*/	CMD(NOT,0x4e),
	/*0x4f*/	CMD(OR,0x4f),
	/*0x50*/	CMD(OUT,0x50),
	/*0x51*/	CMD(POP,0x51),
	/*0x52*/	CMD(POPA,0x52),
	/*0x53*/	CMD(POPF,0x53),
	/*0x54*/	CMD(PUSH,0x54),
	/*0x55*/	CMD(PUSHA,0x55),
	/*0x56*/	CMD(PUSHF,0x56),
	/*0x57*/	CMD(RCL,0x57),
	/*0x58*/	CMD(RCR,0x58),
	/*0x59*/	CMD(REP,0x59),
	/*0x5a*/	CMD(REPE,0x5a),
	/*0x5b*/	CMD(REPNE,0x5b),
	/*0x5c*/	CMD(REPNZ,0x5c),
	/*0x5d*/	CMD(REPZ,0x5d),
	/*0x5e*/	CMD(RET,0x5e),
	/*0x5f*/	CMD(RETF,0x5f),
	/*0x60*/	CMD(ROL,0x60),
	/*0x61*/	CMD(ROR,0x61),
	/*0x62*/	CMD(SAHF,0x62),
	/*0x63*/	CMD(SAL,0x63),
	/*0x64*/	CMD(SAR,0x64),
	/*0x65*/	CMD(SBB,0x65),
	/*0x66*/	CMD(SCASB,0x66),
	/*0x67*/	CMD(SCASW,0x67),
	/*0x68*/	CMD(SHL,0x68),
	/*0x69*/	CMD(SHR,0x69),
	/*0x6a*/	CMD(STC,0x6a),
	/*0x6b*/	CMD(STD,0x6b),
	/*0x6c*/	CMD(STI,0x6c),
	/*0x6d*/	CMD(STOSB,0x6d),
	/*0x6e*/	CMD(STOSW,0x6e),
	/*0x6f*/	CMD(SUB,0x6f),
	/*0x70*/	CMD(TEST,0x70),
	/*0x71*/	CMD(XCHG,0x71),
	/*0x72*/	CMD(XLATB,0x72),
	/*0x73*/	CMD(XOR,0x73),
	/*0x74*/	CMD(XOR,0x74),
};