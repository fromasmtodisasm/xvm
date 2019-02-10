// table_dll.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "table.h"

#define EXTERN __declspec(dllexport)
EXTERN command *get_table() {
	return cmd_tab;
}

EXTERN int get_size() {
	return TAB_SIZE;
}


