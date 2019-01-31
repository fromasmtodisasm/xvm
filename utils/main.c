#include <stdio.h>

int main() {

	size_t tw = 0x10; /* tab width */
	size_t th = 0x10; /* tab height */
	printf("command cmd_tab[256] = {\n");
	printf("\t/*\t");
	for (int i = 0; i < th; i++) {
		printf("0x%x, ", i);
	}
	printf("*/\n");

	for (int i = 0; i < th; i++) {
		printf("\t/*0x%x*/\t", i);
		for (int j = 0; j < tw; j++) {
			printf("nop, ");
		}
		printf("\n");
	}
	printf("};");

}