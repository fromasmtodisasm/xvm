#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


char *proj_dir = "../virtual_machine/";
char out_path[256];

typedef struct gen_command {
	char *name;
	char *func_body;
	int op_size;
}gen_command;

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
			"_command(vm_t *vm) {\n\tprintf(\"%%04x: %%s\\n\", vm->cpu->regs[PC] - 1, __func__);\n\t%s%s}\n", 
			commands[i].func_body ? commands[i].func_body : inc_pc,
			commands[i].func_body ? inc_pc : ""
		);
	}
}

void make_command(gen_command commands[], size_t cnt, FILE * table_c, FILE *table_h, FILE *fnc_proto, FILE* fnc_def) {

	fprintf(table_h, "#pragma once\n");
	fprintf(table_h, "#include <stdint.h>\n");
	make_enum(commands, cnt, table_h);
	fprintf(table_h, "typedef struct vm_t vm_t;\n");
	fprintf(table_h, 
"typedef struct command\
{\n\
	char *name;\n\
	enum OPCODES opcode;\n\
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
		fprintf(table_c, "\"%s\", %s, %s_command },\n", curr_cmd[0],curr_cmd[1],curr_cmd[0]);
	}
	fprintf(table_c, "};");
}

int main(int argc, char *argv[]) {

	size_t tw = 0x10; /* tab width */
	size_t th = 0x10; /* tab height */
	if (argc < 2) return -1;

	char *fout = "table.h";
	char *fin = argv[1];// "commands.txt";
	FILE *old_stdin = freopen(fin, "r+", stdin);

	int len = sprintf(out_path,"%s/%s", proj_dir, "table.h");
	out_path[len] = 0;
	FILE *table_h = fopen(out_path, "w+");

	len = sprintf(out_path,"%s/%s", proj_dir, "table.c");
	out_path[len] = 0;
	FILE *table_c = fopen(out_path, "w+");

	len = sprintf(out_path,"%s/%s", proj_dir, "commands.h");
	out_path[len] = 0;
	FILE *fnc_proto_h = fopen(out_path, "w+");
	len = sprintf(out_path,"%s/%s", proj_dir, "commands.c");
	out_path[len] = 0;
	FILE *fnc_def = fopen(out_path, "w+");

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
	for (int i = 0; fp = ftell(stdin), (test = scanf("\t%[A-z]:%d%n%[^\n]", cmd, &op_size, &bbs, buffer)) != EOF; i++) {
		char *sharp; int offset, len = 0;
			//while (ch = getchar(), isspace(ch) && ch != EOF);
		if (test == 0) {
			skip_to('\n');
			continue;
		}
		if (sharp = strchr(buffer, '#')) {
			offset = sharp - buffer;
			offset += bbs + 1;// +(len = strlen(cmd)); // 2 - # and :
			fseek(stdin, fp+=offset, SEEK_SET);
			scanf(" %[^#]", buffer);
			commands[line_cnt].func_body = strdup(buffer);
		}
		else {
			commands[line_cnt].func_body = 0;
		}
		commands[line_cnt].name = strdup(cmd);
		commands[line_cnt].op_size = op_size;
		line_cnt++;
		skip_to('\n');
	}

	printf("Begin generating...\n");
	make_command(commands, line_cnt, table_c, table_h, fnc_proto_h, fnc_def);
	

}