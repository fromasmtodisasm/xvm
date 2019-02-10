#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "parser.h"


char *get_cmd(FILE *fp) {
	int ch;
	char cmd_name[256];
	while (isspace(ch = getc(fp)));
	int i;
	ungetc(ch, fp);
	for ( i = 0; isalpha(ch=getc(fp)); i++)
	{
		cmd_name[i] = ch;
	}
	ungetc(ch, fp);
	cmd_name[i] = 0;
	return i == 0 ? NULL : _strdup(cmd_name);

}

int get_number(FILE *fp, int *n) {
	int status;
	status = fscanf(fp, " %d", n);
	return status;
}
	


int match(FILE *fp, char *pattern) {
	int i = 0;
	int ch;
	while (isspace(ch = getc(fp)));
	ungetc(ch, fp);

	for (i = 0; (pattern[i] == (ch = getc(fp))) && (pattern[i] != 0) && ch != EOF; i++);
	if (ch != EOF) ungetc(ch, fp);
	if (pattern[i] != 0)
		return 0;
	else	
		return 1;
}