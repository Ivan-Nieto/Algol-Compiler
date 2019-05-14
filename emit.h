#include <string.h>
#include <stdlib.h>
#ifndef EMIT_H
#define EMIT_H
#define LOGSHIFT 3
#define WSIZE 8

void emit_ident(ASTnode *p);

void emit_function_call(ASTnode *p);

void emit_exp(ASTnode *p);

void emit_return(ASTnode *p);

void emit_if(ASTnode *p);

void gVars();

void emitPrint(ASTnode *p);

void emitAST(ASTnode *p);

char * CreateL();

void wStrings();

void repeated_switch(ASTnode *p);

#endif
