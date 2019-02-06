#ifndef _EXP_H_ /* Protect against multiple inclusion */
#define _EXP_H_ 
/***************************************************************************/
/************************** Other Includes *********************************/
/***************************************************************************/
#include "lexer.h"
//#include "tree.h"
#include "debug.h"

/***************************************************************************/
/***************************** Defines *************************************/
/***************************************************************************/
#define GET_TOKEN() (DEBUG_TRACE("Get from %s\n", __FUNCTION__), get_token())

/***************************************************************************/
/*********************** Typedefs/Structures *******************************/
/***************************************************************************/
typedef enum variable_type
{
	VAR_INT,
	VAR_STRING,
	VAR_BOOL,
	VAR_CONST,
	VAR_SONST_LITERAL
}variable_type;

typedef struct _variable
{
	char *name;
	int value;
	int type;
	struct _variable *next;
}variable;


int block(char ** buffer);

int assignment_expression();

int lookup(char *name, int * val);

int assign_value(char *name, int val);

int primary_expression();

int multiplicative_expression();

int additive_expression();

int exp_parser_init();


#endif