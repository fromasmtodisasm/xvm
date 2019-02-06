#pragma once

typedef enum
{
	tokCMD,
	tokFNCBODY,	/* Function BODY*/
	tokIDENT,
	tokNUMBER
};

typedef enum {
	opSTACK,
	opMEMORY,
	opWRONG
}operand_type;

typedef struct file_map file_map;

typedef struct operands {
	operand_type type;
	char *name;
}operands;

typedef struct gen_command {
	char *name;
	operands ops[3];
	int op_cnt;			/* count of operands */
	int in_cmd_ops;
	char *func_body;
	int op_size;
}gen_command;

typedef struct parse_result {
	gen_command *cmds;
	int cnt;
}parse_result;

char * get_cmd(FILE * fp);

int match(FILE * fp, char * pattern);
