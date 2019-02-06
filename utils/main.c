#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "parser.h"

char *proj_dir = "../virtual_machine/";
char out_path[256];


struct file_map {
	FILE *fp;
	char *name;
}fm[] = {
	{NULL, "table.c"},
	{NULL, "table.h"},
	{NULL, "commands.h"},
	{NULL, "commands.c"},
	{NULL, NULL}
};

FILE *get_file(file_map *fm, char *name);



void skip_to(int c) {
	int ch;
	while ((ch = getc(stdin)) != c && ch != EOF);
}

void make_enum(gen_command commands[], size_t cnt, FILE *fout) {
	fprintf(fout,"typedef enum OPCODES {\n");

	for (int i = 0; i < cnt; i++) {
		
		fprintf(fout,"\t");
		for (int j = 0; commands[i].name[j] != '\0'; j++)
			fprintf(fout, "%c", toupper( commands[i].name[j]));
		fprintf(fout, " = 0x%02x,\n", i);
	}
	fprintf(fout,"}OPCODES;\n");
}

void make_func(gen_command commands[], size_t cnt, FILE * proto, FILE* def) {

	char inc_pc[256];
	
	fprintf(proto, "/* Function prototypes for cpu commands */\n");
	fprintf(def, "#include \"vm.h\"\n");
	//fprintf(def, "#include \"fnc_proto.h\"\n");
	fprintf(def, "#include <stdio.h>\n\n");
	fprintf(def, "#define LOG_FUNC(vm) printf(\"%%04x: %%s\\n\", vm->cpu->regs[PC] - 1, __func__)\n\n");

	for (int i = 0; i < cnt; i++) {
		
		if (commands[i].op_size > 0)
			sprintf(inc_pc, "/* Skip operands and shift to next opcode */\n\tvm->cpu->regs[PC] += %d;\n", commands[i].op_size);
		else *inc_pc = 0;

		/*TODO: REMOVE NEXT STRING*/
		//*inc_pc = 0;

		fprintf(proto, "void ");
		fprintf(def, "void ");
		for (int j = 0; commands[i].name[j] != '\0'; j++) {
			fprintf(proto, "%c", tolower(commands[i].name[j]));
			fprintf(def, "%c", tolower(commands[i].name[j]));

		}
		fprintf(proto, "_command(vm_t *vm);\n");
		fprintf(def,
			"_command(vm_t *vm) {\n"); 
		for (int j = commands[i].op_cnt - 1; j >= 0 ; j--) {
			switch (commands[i].ops[j].type)
			{
			case opMEMORY:
				fprintf(def, "\tuint %s = fetch_dword(vm);\n", commands[i].ops[j].name);
				break;
			case opSTACK:
				fprintf(def, "\tuint %s = pop_dword(vm);\n", commands[i].ops[j].name);
				break;
			default:
				break;
			}
		}

		
		fprintf(def, "\n\tLOG_FUNC(vm);\n\t%s%s}\n",
			commands[i].func_body ? commands[i].func_body : inc_pc,
			commands[i].func_body ? inc_pc : ""
		);
	}
}

void make_command(gen_command commands[], size_t cnt, file_map *fm) {
	FILE 
		*table_h = get_file(fm, "table.h"),
		*table_c = get_file(fm, "table.c"), 
		*fnc_proto = get_file(fm, "commands.h"), 
		*fnc_def = get_file(fm, "commands.c");

	fprintf(table_h, "#pragma once\n");
	fprintf(table_h, "#include <stdint.h>\n");
	fprintf(table_h, "#define TAB_SIZE %d\n", cnt);
	make_enum(commands, cnt, table_h);
	fprintf(table_h, "typedef struct vm_t vm_t;\n");
	fprintf(table_h, 
"typedef struct command\
{\n\
	char *name;\n\
	enum OPCODES opcode;\n\
	int op_cnt;\n\
	void(*function) (vm_t*);\n\
}command;\n");
	
	fprintf(table_h, "extern command cmd_tab[0x%02x];\n\n", cnt);

	//printf("generated typedefs and externs\n");
	//make_enum(commands, cnt, table_h);
	make_func(commands, cnt, fnc_proto, fnc_def);

	fprintf(table_c, "#include \"table.h\"\n");
	fprintf(table_c, "#include \"vm.h\"\n");
	//fprintf(table_c, "#include \"fnc_proto.h\"\n");
	fprintf(table_c, "\ncommand cmd_tab[0x%02x] = {\n", cnt);

	char curr_cmd[2][64];
	for (size_t i = 0; i < cnt; i++) {
		fprintf(table_c, "\t/*0x%02x*/\t", i);
		fprintf(table_c, "{");
		for (int j = 0; commands[i].name[j] != '\0'; j++) {
			sprintf(&curr_cmd[0][j], "%c", tolower(commands[i].name[j]));
			sprintf(&curr_cmd[1][j], "%c", toupper(commands[i].name[j]));
		}
		fprintf(table_c, "\"%s\", %s, %d, %s_command },\n", curr_cmd[0],curr_cmd[1], commands[i].in_cmd_ops, curr_cmd[0]);
	}
	fprintf(table_c, "};");
}

int get_func_body(gen_command commands[], FILE *fp, int line_cnt) {
	char* sharp;int offset;
	static char buffer[1024];
	//skip_to("{")
	scanf(" %[^#]", buffer);
	commands[line_cnt].func_body = strdup(buffer);
}


FILE *get_file(file_map *fm, char *name) {
	for (int i = 0; fm[i].name != NULL; i++)
	{
		if (!strcmp(fm[i].name, name)) {
			return fm[i].fp;
		}
	}
	return NULL;
}

int init(file_map *fm, int cnt) {
	for (int i = 0; i < cnt; i++) {
		int len = sprintf(out_path, "%s/%s", proj_dir, fm[i].name);
		out_path[len] = 0;
		fm[i].fp = fopen(out_path, "w+");
	}
}

int test_main(int argc, char *argv[]) {

	size_t tw = 0x10; /* tab width */
	size_t th = 0x10; /* tab height */
	if (argc < 2) return -1;

	char *fout = "table.h";
	char *fin = argv[1];// "commands.txt";
	FILE *old_stdin = freopen(fin, "r+", stdin);

	init(fm, 4);

	size_t command_cnt = 0x100;
	gen_command commands[0x100];

	char *buffer = malloc(2048);
	*buffer = 0;
	char cmd[16];
	
	int line_cnt = 0;
	printf("Start of parse...\n");
	int ch = 0;

	int fp;
	int test = 0;
	int op_size = 0; // size of operands of command
	int bbs = 0; // before buffer size
	for (int i = 0; 
		fp = ftell(stdin), (test = scanf("\t%[A-z]:%d%n%[^\n]", cmd, &op_size, &bbs, buffer)) != EOF; 
		i++) 
	{
		char *sharp; int offset, len = 0;
			//while (ch = getchar(), isspace(ch) && ch != EOF);
		if (test == 0) {
			;
		}
		switch (test)
		{
		case 1: //Only cmd is present
		case 2:

			commands[line_cnt].func_body = 0;
			break;
		case 3:

			//commands[line_cnt].func_body = 0;
			get_func_body(commands, buffer, line_cnt, bbs, fp);
			break;
		case 4:
			get_func_body(commands, buffer, line_cnt, bbs, fp);
			break;
		default:
			fprintf(stderr, "Imposible!!!\n");
			skip_to('\n');
			break;
		}
		

		commands[line_cnt].name = strdup(cmd);
		commands[line_cnt].op_size = op_size;
		line_cnt++;
		skip_to('\n');
	}

	printf("Begin generating...\n");
	make_command(commands, line_cnt, fm);
	

}

operand_type get_optype(char *type, char *name) {
	if (!strcmp(type, "st")) {
		printf("Operand %s in stack\n", name);
		return  opSTACK;
	}
	else if (!strcmp(type, "cmd")) {
		printf("Operand %s in command\n", name);
		return opMEMORY;
	}
	else {
		fprintf(stderr,"Syntax error, wrong operand type\n");
		return opWRONG;
	}
}
int get_operands(FILE *fp, gen_command *cmds) {
	char type[32];
	char name[32];
	int status = 0;
	cmds->op_cnt = 0;
	switch (fscanf(fp, " %[A-z] %[A-z]", type, name))
	{
	case 2:
		cmds->ops[0].type = get_optype(type, name);
		cmds->ops[0].name = strdup(name);
		if (cmds->ops[0].type == opMEMORY) {
			cmds->in_cmd_ops++;
		}
		cmds->op_cnt++;
		break;
	default:
		break;
	}
	for (int i = 1; status = fscanf(fp, " , %[A-z] %[A-z]", type, name); i++)
	{
		if (status == 2) {
			cmds->ops[i].type = get_optype(type, name);
			cmds->ops[i].name = strdup(name);
			if (cmds->ops[i].type == opWRONG)
				return 0;
			if (cmds->ops[i].type == opMEMORY) {
				cmds->in_cmd_ops++;
			}
			cmds->op_cnt++;
		}
		else return 0;
	}
	if (!match(stdin, ")")) {
		fprintf(stderr, "Trash at end of operand list\n");
		return 0;
	}
	return 1;
}
parse_result *parse(FILE *fp) {
	static gen_command commands[0x100];
	static parse_result pr = { commands,0 };
	char cmd[16];
	printf("Start of parse...\n");
	int ch = 0;

	char *cmd_str;
	int op_size;
	char *fnc_body;
	int i; // line count
	int errors = 0;

	for ( i = 0; !feof(fp); ) {
		int smb = 0;
		printf("%s\n", !(cmd_str = get_cmd(fp)) ? "" : cmd_str);
		if (!cmd_str) { skip_to('\n'); continue; }

		commands[i].name = cmd_str;// strdup(cmd_str);
		fscanf(fp," %c", &smb);
		if (smb == '(') {
			if (!get_operands(fp, &commands[i])) {
				fprintf(stderr, "Fail get operands\n");
				errors++;
				skip_to('\n');
				continue;
			}
			fscanf(fp," %c", &smb);
		}
		if (smb != ':') {
			fprintf(stderr, "Syntax error, expected parametrs or :\n");
			skip_to('\n');
			errors++;
			continue;
		}
		else {
			get_number(fp, &op_size);
			printf("op_size = %d\n", op_size);
			commands[i].op_size = op_size;
		}
		if (match(fp, "#")) {
			get_func_body(commands, fp, i);
			printf("func body is present\n");
			//skip_to('#');
		}
		i++;
		printf("=======================================\n");
	}
	printf("Error conunt = %d\n", errors);
	pr.cnt = i;
	return &pr;
}

int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
	gen_command *cmd1, *cmd2;
	cmd1 = (gen_command*)x1;
	cmd2 = (gen_command*)x2;
	return strcmp(cmd1->name, cmd2->name);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main(int argc, char *argv[]) {
	if (argc < 2) return -1;

	char *fout = "table.h";
	char *fin = argv[1];// "commands.txt";
	FILE *old_stdin = freopen(fin, "r+", stdin);

	init(fm, 4);
	parse_result *commands = parse(stdin);

	qsort(commands->cmds, commands->cnt, sizeof(gen_command), compare);
	make_command(commands->cmds, commands->cnt, fm);
}