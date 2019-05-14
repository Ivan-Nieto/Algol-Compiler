/*   Abstract syntax tree code

	Ivan Nieto
	CS370
	4-10-19
	Lab7
 
*/

#include<stdio.h>
#include<malloc.h>

#ifndef AST_H
#define AST_H
static int mydebug;

/* define the enumerated types for the AST.  THis is used to tell us what 
sort of production rule we came across */

enum ASTtype {
  
   PROGRAM,
   VARDEC,
   FUNCTIONDEC,
   IDENT,
   NUMBER,
   EXPR,
   IFSTMT,
   IFSTMT1,
   PARAM,
   BLOCK,
   WHILESTMT,
   WRITE,
   myRETURN,
   READ,
   ASST,
   ARG,
   Call
};


enum OPERATORS {
   PLUS,
   MINUS,
   TIMES,
   MULT,
   DIV,
   AND,
   OR,
   myNOT,
   qt,
   lessthan,
   greaterthan,
   lessq,
   eq,
   notq,
   BOOLTYPE,
   VOIDTYPE,
   INTTYPE,
   STR
};

/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code 
*/
typedef struct ASTnodetype
{
     enum ASTtype type;
     enum OPERATORS operator;
     enum OPERATORS symType;
     char * name;
     char * str;
     int value;
     struct SymbTab *symbol;
     struct ASTnodetype *next;
     struct ASTnodetype *s1,*s2 ; /* used for holding IF and WHILE components -- not very descriptive */
} ASTnode;


/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode *ASTCreateNode(enum ASTtype mytype);

void PT(int howmany);

void ASTattachnext(ASTnode *p,ASTnode *q);

ASTnode *program;

/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p);

#endif // of AST_H
