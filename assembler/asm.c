#include "asm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lexer.h"
#define LABEL_SIZE 256
Label label[LABEL_SIZE];
#include "debug.h"

#include <Windows.h>



int debug_level = DEBUG_ALL;
enum tokens {
	tokName,
	tokNum,
	tokLabel,
	tokOpcode
}tokens;

typedef command *(*GetTable)();
typedef int(*GetSize)();

static GetTable get_table;
static GetSize get_size;

/***************************************************************************/
/***************** Defines used by this module only ************************/
/***************************************************************************/
#define exptected_func(...) DEBUG_TRACE("On line %d for source line = %d\n", __LINE__, get_line());_expected_func( __VA_ARGS__)
#define GET_TOKEN() (DEBUG_TRACE("Get from %s\n", __FUNCTION__), get_token())
command *cmd_tab;
int TAB_SIZE;

token_t *curr_token;

int load_table(char *name) {
	HMODULE table_lib = LoadLibrary(name);
	if (!table_lib) return 0;
	get_table = (GetTable)GetProcAddress(table_lib, "get_table");
	get_size = (GetSize)GetProcAddress(table_lib, "get_size");
	if (!get_table || !get_size) {
		return 0;
	}
	return 1;
}

void putDword(uint8_t *program, int *pc, int dword) {
		*((uint32_t*)&(program[*pc])) = dword;
		(*pc) += 4;
}

void skip_to(FILE *fp,int c) {
	int ch;
	while ((ch = getc(stdin)) != c && ch != EOF);
}

char *get_cmd(char *str) {
	int ch;
	char cmd_name[256];
	while (isspace(ch = *str++));
	int i;
	*str--;
	for (i = 0; isalpha(ch = *str++) || ch == '_'; i++)
	{
		cmd_name[i] = ch;
	}
	cmd_name[i] = 0;
	return i == 0 ? NULL : strdup(cmd_name);

}

int get_number(char *str, int *n) {
	int status;
	status = sscanf(str, " %d", n);
	return status;
}



int match(char *str, char *pattern) {
	int i = 0;
	int ch;
	while (isspace(ch = *str++));

	return strcmp(str, pattern) == 0;
}

int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
	command *cmd2;
	char *key = (char*)x1;
	cmd2 = (command*)x2;
	return strcmp(key, cmd2->name);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

command *is_command(char *name) {

	return bsearch(name, cmd_tab, TAB_SIZE, sizeof(command), compare);
}
uint32_t get_arg(command *cmd) {

	switch (get_token()->type)
	{
	case lcIDENT:
	{
		Label *label;
		label = process_label(0, 0);
		return label ? label->addr : 0;
	}
	break;
	case lcNUMBER:
	{
		return atoi(curr_token->text);
	}
	break;
	default:
		fprintf(stderr, "Wrong argument for %s command!!!", cmd->name);
		exit(-1);
		break;
	}
}


void process_command(uint8_t *program, int *pc, command *cmd) {
	printf("%s: this is command with opcode = %d and have %d operands\n",
	cmd->name, cmd->opcode, cmd->op_cnt);
	program[(*pc)++] = cmd->opcode;
	for (int i = 0; i < cmd->op_cnt; i++)
	{
		*((uint32_t*)&(program[(*pc)])) = get_arg(cmd);
		(*pc) += 4;
	}
	get_token();
}

/* mode: 0 - get, 1 - set*/
Label *process_label(int mode, int pc) {
	if (mode == 0) {
		for (int i = 0; i < LABEL_SIZE; i++) {
			if (label[i].name) {
				if (!strcmp(curr_token->text, label[i].name))
					return &label[i];
			}
			else {
				printf("lable %s yet not defined\n", curr_token->text);
				return NULL;
			}
		}
		return NULL;
	}
	else {
		int i;
		for (i = 0; i < LABEL_SIZE; i++) {
			if (label[i].name) {
				if (!strcmp(curr_token->text, label[i].name)) {
					fprintf(stderr, "Redifinition label");
					exit(-1);
				}
			}
			else  {
				label[i].name = strdup(curr_token->text);
				label[i].addr = pc;
				return &label[i];
			}
		}
	}
}

void get_string(uint8_t *program, int *pc) {
	int len = strlen(curr_token->text);

	for (int i = 0; i < len; i++)
	{
		putDword(program, pc, curr_token->text[i]);
	}
	putDword(program, pc, 0);
	get_token();

}

void get_data(uint8_t *program, int *pc) {
	switch (curr_token->type)
	{
	case lcSTRING:
	{
		get_string(program, pc);
	}
	break;
	case lcNUMBER:
	{
		int number = atoi(curr_token->text);
		putDword(program, pc, number);
		while (get_token()->type == lcCOMMA)
		{
			if (get_token()->type == lcNUMBER) {
				putDword(program, pc, atoi(curr_token->text));
			}
			else {
				fprintf(stderr, "syntax error, expected number but this token is %d\n", curr_token->type);
			}
		}
	}
	break;
	default:
		break;
	}
}

/* mode: 1 - text mode, 0 - raw numbers */
void disassembly(uint8_t *memory, size_t size, int mode) {
	for (int i = 0; i < size; ) {
		uint8_t byte = *((uint8_t*)&(memory[(i)]));
		if (mode) printf("%04x:\t", i);
		if (byte >= 0 && byte <= TAB_SIZE - 1) {// this is opcode
			if (mode) printf("%s ", cmd_tab[byte].name);
			else printf("0x%08x,\n", cmd_tab[byte].opcode);
			i++;
			for (int j = 0; j < cmd_tab[byte].op_cnt; j++)
			{
				if (mode) printf("%08x ", *((uint32_t*)&(memory[i])));
				else printf("0x%08x,\n", *((uint32_t*)&(memory[i])));
				i += 4;
			}
			if (mode) printf("\n");
		}
		else {
			if (mode) printf("0x%08x\n", *((uint32_t*)&(memory[i])));
			else printf("0x%08x,\n", *((uint32_t*)&(memory[i])));
			i += 4;
		}

	}
}
Program *parse(char **buffer, int pass) {

	DEBUG_TRACE("in function %s\n", __FUNCTION__);
	char *ident_name;
	token_type type;
	exp_parser_init();
	command *cmd = NULL;
	//uint8_t *program = malloc(10*1024);
	static uint8_t memory[1024];// = malloc(10 * 1024);
	static Program program = { memory, 0 };
	uint32_t curr_arg;
	int pc = 0;
	if ((lexerInit(*buffer)) != 0) {
		GET_TOKEN(/*NEXT_TOKEN*/);
		while (curr_token->type != lcEND) {
			//DEBUG_TRACE("PARSE EXTERNAL DEFINITION\n");
			/**********************************************/
			type = curr_token->type;
			/**********************************************/
			if (type == lcIDENT) {
				if (cmd = is_command(curr_token->text))
				{
					process_command(memory, &pc, cmd);
				}
				else { // text is label
					// set label
					if (pass == 1) process_label(1, pc);
					if (get_token()->type == lcIDENT) { // Maybe this is command
						if (cmd = is_command(curr_token->text))
						{
							process_command(memory, &pc, cmd);
						}
						else { // Maybe this is data as string or numbers
							get_data(memory, &pc);
						}
					}
					else { // Maybe this is data as string or numbers
							get_data(memory, &pc);
					}
				}
			}

		}
	}
	//dump memory
	printf("%d pass disassembly\n", pass);
	printf("-------------------\n");
	disassembly(memory, pc, 1);
	puts("");
	program.size = pc;
	return &program;
}

Program *assembly(char ** src, FILE * fout) {
	debug_level = 0;

	int pc = 0;
	uint8_t mem[1024];
	
	SET_DEBUG_LVL(DEBUG_PROD);

	load_table("table_dll.dll");
	cmd_tab = get_table();
	TAB_SIZE = get_size();
	parse(src, 1);

	SET_DEBUG_LVL(DEBUG_PROD);

	Program *program = parse(src, 2);

	printf("uint8_t *my_program[] = {\n");
	disassembly(program->mem, program->size, 0);
	/*
	for (int i = 0; i < program->size; i++) {
		printf("0x%02x,\n", program->mem[i]);
	}*/

	//FILE *aout = fopen("a.out", "wb+");
	fwrite(program->mem, 1, program->size, fout);
	fclose(fout);
	printf("};");
	return program;

}