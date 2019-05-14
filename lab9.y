%{
/*
	Ivan Nieto
	CS370
	5-3-19
	Lab9
 

	This program declares a grammar that takes ALGOL code and 
	checks it for syntax errors. This program also requires a lex
	program to return tokens that will be checked against the program. 
	
	The lex program returns tokens to this yacc program and then the tokens are 
	checked to be syntacticly correct. 

	The program then creates nodes in the semantic action linking them together to arrive at a  single node returned in the pointer program. 
*/






	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "symtable.h"
#include "ast.h"
#include <stdlib.h>
#include "emit.h"

int yylex();

int GTEMP = 0, goffset = 0, offset = 0, maxoffset = 2, level = 0;
int debugg = 0;
int display = 0;
struct SymbTab *p = NULL;

extern FILE *f;
extern int linecount;//counts lines in lex
enum OPERATORS Cur_Type;

int base, debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s %d\n", s,linecount);
}
int count = 0; 
%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start  P

/*Allows lex to return the variable name as a companion value to the token MYID
  as well as allowing the same for MYNUM*/
%union{
int value;
char *string;
struct ASTnodetype *node;
enum ASTtype op;
enum OPERATORS operator;
}

%token <value> MYNUM
%token <string> MYID STRING
%token  MYINT MYVOID MYBOOLEAN  MYTRUE MYFALSE  MYBEG MYEND MYIF MYTHEN MYELSE MYWHILE MYDO MYRETURN MYREAD MYWRITE MYAND MYOR MYNOT EQ LT QT NE 

%type <node> DECLIST DEC VARDEC VARLIST FUNDEC PARAMS PARAMLIST PARAM COMPSTMT LOCALDEC STATELIST STATE EXPSTMT SELSTMT ITERSTMT RETURNSTMT READSTMT WRITESTMT ASSSTMT EXP VAR SIMEXP ADDEXP TERM FACTOR CALL ARGS ARGLIST

%type <operator>  TYPESPEC RELOP MULTOP ADDOP




%%	/* end specs, begin rules */


P        : DECLIST              {program = $1;}
	 ;

DECLIST  : DEC                  {$$ = $1;}
	 | DEC DECLIST 
				{$1->next = $2;
				$$ = $1;}
	 ;

DEC      : VARDEC               {$$ = $1;}
	 | FUNDEC               {$$ = $1; }
	 ;

VARDEC   : TYPESPEC VARLIST ';' {if(debugg)printf("In VARDEC\n");
                               $$ = $2;
                               struct ASTnodetype *p = $2;
                               
                               //iterating through the varlist and 
                               //setting the type of the variables
                               //now that we have seen the type.
                               while(p != NULL){
                                    p->operator=$1;
                                    p->symbol->Type=$1;
                                    p->symType=$1;
                                    
                                    p = p->s1;
                               }//end while
                               
                               }
	 ;

/*Create a VARDEC node and set operator to Cur_Type since TYPESPEC is not included.*/
VARLIST  : MYID               { if(debugg)printf("In VARLIST 1\n");
                
                               //var cannot already be in the symtable
                               if(Search($1, level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", $1);
                               exit(1);
                               }//end if

                               $$ = ASTCreateNode(VARDEC);
                               $$->name=$1;
                               //Inseting the var into the symtable and setting the 
                               //SymbTab pointer in the ASTnodetype to the returned 
                               //SymbTab from insert.
                               $$->symbol = Insert($$->name, 0, 0, level, 1, offset, $$);
                               offset++;}

	 | MYID '[' MYNUM ']' { if(debugg)printf("In VARLIST 2\n");

                               if(Search($1, level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", $1);
                               exit(1);
                               }//end if
                               
                               $$ = ASTCreateNode(VARDEC);
                               $$->name=$1;
                               $$->value=$3;
                               
                               $$->symbol =Insert($1, 0, 0, level, $$->value, offset, $$);
                               //offset incremented by size of array.
                               offset+=$3;} 

	 | MYID ',' VARLIST   { if(debugg)printf("In VARLIST 3\n");
		
                
                               if(Search($1, level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", $1);
                               exit(1);
                               }//end if
                               
                               $$ = ASTCreateNode(VARDEC);
                               $$->name=$1;
                               $$->s1=$3;
                               
                               $$->symbol =Insert($$->name, 0, 0, level, 1, offset, $$);
                               offset++;}

	 | MYID '[' MYNUM ']' ',' VARLIST 
                               {if(debugg)printf("In VARLIST 4\n");


                               if(Search($1, level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", $1);
                               exit(1);
                               }//end if
                               $$ = ASTCreateNode(VARDEC);
                               $$->name=$1; 
                               $$->value=$3; 
                               $$->s1=$6;
                               
                               $$->symbol =Insert($1, 0, 0, level, $$->value, offset, $$);
                               offset+=$3;}
	 ;

/*Set $$ to the apropriate operator and set Cur_Type to the same. Cur_Type
 is later used to set operator in nodes.*/
TYPESPEC : MYINT               {$$=INTTYPE; Cur_Type=$$;}
	 | MYVOID              {$$=VOIDTYPE; Cur_Type=$$;}
	 | MYBOOLEAN           {$$=BOOLTYPE; Cur_Type=$$;}
	 ;

/*Create a FUNCTIONDEC node and connect PARAMS and COMPSTMT to it
 with s1 and s2.*/
FUNDEC   : TYPESPEC MYID '(' {if(debugg)printf("In FUNDEC\n");
                               //Saving offset before we go in a level.
                               goffset = offset;
                               offset=2;
                               maxoffset = offset;
                               
                               //error check; a function cannot be declared more than once. 
                               if(Search($2, level, 1) != NULL){
                                   printf("Error, %s already in the symbol table.\n", $2);
                                   exit(1);
                               }//end if
                               
                               //Parameters will be part of the increased level.
                               level++;
                               }
                PARAMS ')'
                               {level--;Insert($2, $1, 1 , level, 0, 0, $5);}
                COMPSTMT
                                
                               {$$=ASTCreateNode(FUNCTIONDEC);
                               $$->name=$2;
                               $$->operator=$1;
                               $$->s1=$5;
                               $$->s2=$8;
                               
                               $$->symType = $1;
                               
                               //setting fundecs symbol to the SymbTab of the functions name.
                               $$->symbol = Search($2, level, 1);
                               
                               //Saving the params list in the SymbTab so we can check them in function call.
                               $$->symbol->fparms = $5;
                               offset-=Delete(1);
                               level=0;
                               offset=goffset;
                               
                                
                               $$->value = maxoffset;
                               $$->symbol->maxoffset = maxoffset;
                               
                
                               }
	 ;

PARAMS   : MYVOID              {if(debugg)printf("In PARAMS\n");$$ = NULL;}
	     | PARAMLIST           {if(debugg)printf("In PARAMS\n");$$ = $1; }
	 ;

/*Same logic as STATELIST.*/
PARAMLIST: PARAM ',' PARAMLIST             {if(debugg)printf("In PARAMLIST\n");$$ = $1; $$->next=$3;}
	 | PARAM                               {if(debugg)printf("In PARAMLIST\n");$$ = $1;}
	 ;

/*Create PARAM node and set it's value to 1 if it has brakets.*/
PARAM    : TYPESPEC MYID 
                               {if(debugg)printf("In PARAM\n");

                               //error check; parameter cant be declared more than once.
                               if(Search($2, level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", $2);
                               exit(1);
                               }//end if

                               $$=ASTCreateNode(PARAM);
                               $$->name=$2; 
                               $$->symType=$1;

                               //inserting the param in the symtable and setting the SymbTab
                               //pointer in the ASTnodetype to the returned SymbTab from insert.
                               $$->symbol = Insert($$->name, $1, 0, level, 1, offset, $$);
                               offset++;
                               
                               }
	 | TYPESPEC MYID '[' ']' 
                               {if(debugg)printf("In PARAM\n");
                                  

                               if(Search($2, level, 0) != NULL){
                               printf("Error, %s already in the symbol table.\n", $2);
                               exit(1);
                               }//end if
				 
				               $$=ASTCreateNode(PARAM);
                               $$->name=$2; 
                               $$->symType=$1;
                               $$->value=-1;
                               
                               $$->symbol =Insert($$->name, $1, 0, level ,1, offset, $$);
                               offset++;}
	 ;

/*Create a BLOCK node and connect LOCALDEC and STATELIST with s1 and s2.*/
/*Level must be incremented when you enter a COMPSTMT and is not done so in FUNDEC
because we can have multiple COMPSTMT's in one function.*/
COMPSTMT : MYBEG{level++;} LOCALDEC STATELIST MYEND
                               {if(debugg)printf("In COMPSTMT\n");
                               $$=ASTCreateNode(BLOCK);
                               $$->s1=$3;
                               $$->s2=$4;
                               //Printing the symtable after we finish adding all the 
                               //nessasary elements from the COMPSTMT.
                               if(display)Display();

                               //Deleting all the variables that we added to the symtable 
                               //while in the COMPSTMT. Level goes back to what it previously was.
                               if(offset > maxoffset)
                                 maxoffset = offset;
                               
                               
                               offset-=Delete(level);
                               level--;
                                
                               }
	 ;

/*Same logic as STATELIST*/
LOCALDEC : VARDEC LOCALDEC     {$1->next=$2; $$=$1;}
| /* empty */         {$$=NULL;}
	 ;

/*If empty STATELIST is null, else set STATELSIT to STATE and connect
 the right STATELIST to the left STATELIST with next.*/
STATELIST:  STATE STATELIST    {$$=$1; $$->next=$2;}
	 | /*empty*/           {$$=NULL;}
	 ;

/*Pass everything along.*/
STATE:     EXPSTMT             {$$ = $1;}
	 | COMPSTMT            {$$ = $1;}
	 | SELSTMT             {$$ = $1;}
	 | ITERSTMT            {$$ = $1;}
	 | ASSSTMT             {$$ = $1;}
	 | RETURNSTMT          {$$ = $1;}
	 | READSTMT            {$$ = $1;}
	 | WRITESTMT           {$$ = $1;}
	 ;

/*If empty expression s1 points to nothing, else point to the EXP.*/
EXPSTMT  : EXP ';'             {if(debugg)printf("In EXPSTMT\n");
                                $$=ASTCreateNode(EXPR);$$->s1=$1;}
                                
	 | ';'                     {if(debugg)printf("In EXPSTMT\n");$$=ASTCreateNode(EXPR);$$->s1=NULL;}
	 ;

/*Create a IFSTMT node with its s1 pointing to another node that holds
 both the first and optional second STATE. The second STATE comes
 from the else statement.*/
SELSTMT  : MYIF EXP MYTHEN STATE
                               {if(debugg)printf("In SELSTMT\n");
                               $$=ASTCreateNode(IFSTMT);
                               $$->s1=$2;
                               $$->s2=ASTCreateNode(IFSTMT1);
                               $$->s2->s1=$4;}

	 | MYIF EXP MYTHEN STATE MYELSE STATE 
                               {if(debugg)printf("In SELSTMT\n");
                               $$=ASTCreateNode(IFSTMT);$$->s1=$2;
                               $$->s2=ASTCreateNode(IFSTMT1);
                               $$->s2->s1=$4;
                               $$->s2->s2=$6;}
	 ;

/*Create a WHILESTMT node and connect the EXP and STATE nodes to it.*/
ITERSTMT : MYWHILE EXP MYDO STATE
                               {if(debugg)printf("In ITERSTMT\n");
                               $$=ASTCreateNode(WHILESTMT);
                               $$->s1=$2;
                               $$->s2=$4;}
	 ;

/*If there is something specific to return connect it with s1.*/
RETURNSTMT: MYRETURN ';'       {if(debugg)printf("In RETURNSTMT\n");$$=ASTCreateNode(myRETURN);}
	  | MYRETURN  EXP  ';'     {if(debugg)printf("In RETURNSTMT\n");$$=ASTCreateNode(myRETURN);$$->s1=$2;}
	  ;

READSTMT : MYREAD VAR ';'      {if(debugg)printf("In READSTMT\n");$$=ASTCreateNode(READ);$$->s1=$2;}
	 ;

WRITESTMT: MYWRITE EXP ';'     {if(debugg)printf("In WRITESTMT\n");$$=ASTCreateNode(WRITE);$$->s1=$2;}
     |     MYWRITE STRING ';'  {if(debugg)printf("In WRITESTMT\n");
                                $$=ASTCreateNode(WRITE);
                                $$->name = $2;
                                
                                }
	 ;

/*Create ASST node to connect VAR and SIMEXP*/
ASSSTMT  : VAR '=' SIMEXP ';'  {if(debugg)printf("In ASSSTMT\n");
                               
                                
                               //error checking; Both types must match.
                              
                               if($1->symType != $3->symType)
                               {
                               printf("Operators for %s and %s do not match line %d\n", $1,$3->symbol->name, linecount);
                               exit(1);
                               }//end if
                               
                               $$=ASTCreateNode(ASST);
                               $$->s1=$1;
                               $$->s2=$3;
                               
                               $$->symbol=Insert(CreateTemp(),$3->symType, 0,level,1,offset,NULL);
                               offset++;
                               
                               }//do type checking
	 ;

/*Pass along SIMEXP*/
EXP      : SIMEXP              {$$=$1;}
	 ;

/*Create IDENT node and set s1 if it is an array*/
VAR      : MYID                {if(debugg)printf("In VAR\n");
                               
                               //checking if the var was already declared. 
                               p = Search($1,level, 1);

                               if(p == NULL){
                               printf("ID %s not found.\n", $1);
                               exit(1);
                               }//end if
                               
                               
                               if(p->mysize != 1)
                                {
                                   printf("VAR %s is not a scalar.", $1);
                                   exit(1);
                                }//end if
                               
                               
                               $$=ASTCreateNode(IDENT);
                               $$->name=$1;
                               //setting VAR's type to id's type.
                               $$->symType = p->Type;
                               $$->symbol = p;
                                }
                                
	 | MYID '[' EXP ']'    {   if(debugg)printf("In VAR\n");
                               
                    
                               p = Search($1,level, 1);
                               
                               if(p == NULL || p->mysize <= 0){
                               printf("ID %s not found.\n", $1);
                               exit(1);
                               }//end if
                               
                               
                               if(p->mysize < 1)
                                {
                                   printf("VAR %s is not an array.", $1);
                                   exit(1);
                                }//end if
                               
                               
                               
                               $$=ASTCreateNode(IDENT);
                               $$->name=$1;
                               $$->s1=$3;
                               $$->symType = p->Type;
                               $$->symbol = p;
                               }
	 ;

/*If a single expression pass it up, if not create a new node to link the two expresions.*/
/*Same logic applies to ADDEXP and TERM*/
SIMEXP   : ADDEXP              {if(debugg)printf("In SIMEXP\n");$$=$1;
				}

	 | ADDEXP RELOP ADDEXP {if(debugg)printf("In SIMEXP\n");
                               $$=ASTCreateNode(EXPR);//do type checking
                               $$->s1=$1;
                               $$->s2=$3;
                               $$->name = CreateTemp();
                               $$->operator=$2;
                               
                               
                               $$->symbol = Insert($$->name,$1->symType, 0,level,1,offset,0);
                              offset++;
                               
                               //Both types must match
                               if($1->symType != $3->symType)				
                               {
                               printf("Operators for %s and %s do not match line %d\n", $1->symbol->name,$3->symbol->name, linecount);
                               exit(1);
                               }//end if
                               //Set SIMEXP's type to the type of both $1 and $3.
                               $$->symType = $1->symType;
                               }/*RELOP is an operator*/
	 ;

/*Relop becomes an operator*/
RELOP    : QT                   {$$=qt;}
	 | '<'                  {$$=lessthan;}
	 | '>'                  {$$=greaterthan;}
	 | LT                   {$$=lessq;}
	 | EQ                   {$$=eq;}
	 | NE                   {$$=notq;}
	 ;

/*Term becomes ADDEXP or we create a new expr node to link the expression and give it to ADDEXP.*/
ADDEXP   : TERM                 {if(debugg)printf("In ADDEXP\n");$$=$1;
				}
	 | ADDEXP ADDOP TERM 
                               {if(debugg)printf("In ADDEXP\n");
                               $$=ASTCreateNode(EXPR);
                               $$->s1=$1;
                               $$->s2=$3;
                               $$->operator=$2;
                               $$->symType = $3->operator;
                               $$->name = CreateTemp();
                               
                               
                               $$->symbol = Insert($$->name,$3->symType, 0,level,1,offset,0);
                               offset++;
                               
                               if($1->symType != $3->symType)
                               {printf("Operators for %s and %s do not match line %d\n", $1->symbol->name,$3->symbol->name, linecount);
                               exit(1);}//end if
			
                               $$->symType = $3->symType;
                             
                               }
	 ;

/*Setting ADDOP to the apropriate operator.*/
ADDOP    : '+'                           {$$=PLUS;}
	 | '-'                               {$$=MINUS;}
	 ;

/*Factor becomes term or we create a new expr node and give it to term.*/
TERM     : FACTOR               {if(debugg)printf("In TERM\n");$$=$1;
				}                
	 | TERM MULTOP FACTOR 
                               {if(debugg)printf("In TERM\n");
                               $$=ASTCreateNode(EXPR);
                               $$->s1=$1;
                               $$->operator=$2;
                               $$->s2=$3;
                               $$->name = CreateTemp();
                               
                              
                               
                               $$->symbol = Insert($$->name,$1->symType, 0,level,1,offset,0);
                               offset++;
                               
                               if($1->symType != $3->symType)
                               {printf("Operators for %s and %s do not match line %d\n",$1->symbol->name,$3->symbol->name, linecount);
                               exit(1);}//end if
                                
                               $$->symType = $3->symType;			
                              
                               }
	 ;

/*Setting multop to the apropriate operator*/
MULTOP   : '*'                 {$$=MULT;}
	 | '/'                     {$$=DIV;}
	 | MYAND                   {$$=AND;}
	 | MYOR                    {$$=OR;}
	 ;
 
FACTOR   : '(' EXP ')'          {if(debugg)printf("In FACTOR\n");$$=$2;}/*exp becomes factor*/

	 | MYNUM                {if(debugg)printf("In FACTOR\n");
                               $$=ASTCreateNode(NUMBER);$$->value=$1;$$->operator=INTTYPE;$$->symType=INTTYPE;
                               }

	 | VAR                  {if(debugg)printf("In FACTOR\n");$$=$1;}/*Var becomes factor*/

	 | CALL                 {if(debugg)printf("In FACTOR\n");$$=$1;}/*Call becomes factor*/

	 | MYTRUE               {if(debugg)printf("In FACTOR\n");$$=ASTCreateNode(NUMBER);
                               $$->value=1;$$->symType=BOOLTYPE;}/*Creating 'true' number node*/

	 | MYFALSE              {if(debugg)printf("In FACTOR\n");$$=ASTCreateNode(NUMBER);
                               $$->value=0;$$->symType=BOOLTYPE;}/*Creating 'false' number node*/

	 | MYNOT FACTOR         
                               {if(debugg)printf("In FACTOR\n");
                               $$=ASTCreateNode(EXPR);/*Creating expr node with operator MYNOT*/
                               $$->operator=myNOT;
                               $$->s1=$2;
                               $$->symbol = Insert(CreateTemp(),$2->symType, 0,level,1,offset,0);
                              offset++;
                               $$->symType=VOIDTYPE;}/*Linking the factor to the node with s1*/
	 ;

CALL     : MYID '(' ARGS ')'    /*Creating Call node with MYID as name and s1 connecting args*/
                               {if(debugg)printf("In CALL\n");
                               
                               struct SymbTab *p = Search($1,level, 1);
                               
                               //Type checking 
                               if(p == NULL){
                               printf("ID %s not found.\n", $1);
                               exit(1);
                               }//end if
				
                               if(p->IsAFunc == 0){
                               printf("Function %s not found.\n",$1);
                               exit(1);
                               }//end if
                                
                               //comparing $3 to the original declaration of $1.
                               if(!compare(p->fparms,$3))
                                    {
                                    printf("Function call using wrong params.\n");
                                    exit(1);
                                    }//end if
                                
                               $$=ASTCreateNode(Call);
                               $$->s1=$3;
                               $$->name=$1;
                               $$->symbol= p;
                               $$->symType = p->Type;
                
                
                               }//check if id at level 0, if not a function braf.
					     //if it is then check if the params are the same. 
	 ;

ARGS     : ARGLIST             {$$=$1;}/*args becomes argslist*/
	 |                         {$$=NULL;}
	 ;

ARGLIST  : EXP                 {if(debugg)printf("In ARGLIST\n");
                               $$=ASTCreateNode(ARG);
                               $$->s1=$1;
                               $$->symType = $$->s1->symType;
                               $$->symbol = Insert(CreateTemp(),$1->symType, 0,level,1,offset,0);
                              offset++;
                               }/*arglist becomes expresion*/
                               
| EXP ',' ARGLIST     {if(debugg)printf("In ARGLIST\n");
                                $$=ASTCreateNode(ARG);
                                $$->s1=$1;
                                $$->s2=$3;
                                $$->symType = $$->s1->symType;
                                $$->next=$3;
                                $$->symbol = Insert(CreateTemp(),$1->symType, 0,level,1,offset,0);
                              offset++;}
	;


%%	/* end of rules, start of program */



int main(int argc, char *argv[])
{ 


    for(int j = 0; j < argc; j++){
    
        if(strcmp(argv[j],"-o") == 0){
        
            printf("%s\n", argv[j+1]); 
            f = fopen(argv[j+1],"w");
            
            
        }//end if
            
        if(strcmp(argv[j], "-d") == 0)
            debugg = 1;
            
    
    }//end for

    if(f == NULL)
      f = fopen("emitOutput.asm", "w");
    
    
    yyparse();
    emitAST(program);
    //Display();
    
    if(debugg)
       ASTprint(1,program);
    
    if(display){
        printf("\n        Final Print");
        Display();
    }//end if 
    
    
    
}
