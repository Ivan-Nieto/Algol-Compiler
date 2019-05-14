/*   
 * 
 *	Ivan Nieto
 *	CS370
 *	5-3-19
 *	Lab9
 * 
 * 
 *	Prints a NASM program from a provided ASTnode tree structure.  
 * 
 * 
 */
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "symtable.h"
#include "emit.h"

FILE *f;
int  debugg1 = 0;
char *temp;
char *temp2;



//-----------------------------------------------------------------------------
//Start of emit.
//Prints global variables and strings then calls emitPrint
void emitAST(ASTnode *p){
    if(debugg1 != 0)printf("IN emitAST\n");
    
    fprintf(f,"%%include \"io64.inc\"\n\n");
    fprintf(f,"\nsection .data\n\n");
    
    gVars();
    fprintf(f,"\n");
    wStrings(p);
    
    fprintf(f,"\nsection .text\n\tglobal main\n\n");
    
    emitPrint(p);
    
}//end emitAST



//-----------------------------------------------------------------------------
//Precondition: p is an ASTnode of type EXPR
//Postcondition: Answer to the expression will be in RAX
void emit_exp(ASTnode *p){
    if(debugg1 != 0)printf("IN emit_exp\n");
    
    if(p == NULL)//base case
        return;
    
    //Precondition: An ASTnode of type NUMBER, IDENT, EXPR OR CALL
    // that needs NASM code generated from it depending on it's type.
    //Postcondition: Result will be in RAX.
    repeated_switch(p->s1);
    
    if(p->symbol != NULL)
        fprintf(f,"\tMOV\t[RSP + %d], RAX\t;Saving RAX in memory\n", p->symbol->offset * WSIZE);
    
    
    
    if(p->operator == myNOT){
        fprintf(f,"\tCMP\tRAX, 0\n");
        fprintf(f,"\tSETE\tAL\n");
        fprintf(f,"\tMOV\tRBX, 1\n");
        fprintf(f,"\tAND\tRAX, RBX\n");
        return;
    }//end if
    
    //Can happen when EXPR is just a single number
    if(p->s2 == NULL)return;
    
    
    //Precondition: An ASTnode of type NUMBER, IDENT, EXPR OR CALL
    // that needs NASM code generated from it depending on it's type.
    //Postcondition: Result will be in RAX.
    repeated_switch(p->s2);
    
    //Alredy done in the switch
    fprintf(f,"\tMOV\tRBX, RAX\t\t;Moving RAX obtained from LHS to RBX.\n");
    
    
    if(p->symbol != NULL)
        fprintf(f,"\tMOV\tRAX, [RSP + %d]\t;Moving RHS into RAX\n", p->symbol->offset * WSIZE);
    
    
    
    switch (p->operator) {
        case PLUS:
            fprintf(f,"\tADD\tRAX, RBX\n");
            break;
            
        case MINUS:
            fprintf(f,"\tSUB\tRAX, RBX\t\t;Subtracting RHS and LHS\n");
            break;
            
        case MULT:
            fprintf(f,"\tIMUL\tRBX\n");
            break;
            
        case DIV:
            fprintf(f,"\tXOR\tRDX, RDX\n");
            fprintf(f,"\tIDIV\tRBX\n");
            break;
            
        case qt: //greater than or equal to
            fprintf(f,"\tCMP\tRAX, RBX\n");
            fprintf(f,"\tSETGE\tAL\n");
            fprintf(f,"\tMOV\tRBX, 1\n");
            fprintf(f,"\tAND\tRAX, RBX\n");
            break;
            
        case lessthan:
            fprintf(f,"\tCMP\tRAX, RBX\n");
            fprintf(f,"\tSETL\tAL\n");
            fprintf(f,"\tMOV\tRBX, 1\n");
            fprintf(f,"\tAND\tRAX, RBX\n");
            break;
            
        case greaterthan:
            fprintf(f,"\tCMP\tRAX, RBX\n");
            fprintf(f,"\tSETG\tAL\n");
            fprintf(f,"\tMOV\tRBX, 1\n");
            fprintf(f,"\tAND\tRAX, RBX\n");
            break;
            
        case lessq: //Less than or equal to
            fprintf(f,"\tCMP\tRAX, RBX\n");
            fprintf(f,"\tSETLE\tAL\n");
            fprintf(f,"\tMOV\tRBX, 1\n");
            fprintf(f,"\tAND\tRAX, RBX\n");
            break;
            
        case eq:   //Equal to
            fprintf(f,"\tCMP\tRAX, RBX\n");
            fprintf(f,"\tSETE\tAL\n");
            fprintf(f,"\tMOV\tRBX, 1\n");
            fprintf(f,"\tAND\tRAX, RBX\n");
            break;
            
        case notq:  //Not equal to
            fprintf(f,"\tCMP\tRAX, RBX\n");
            fprintf(f,"\tSETNE\tAL\n");
            fprintf(f,"\tMOV\tRBX, 1\n");
            fprintf(f,"\tAND\tRAX, RBX\n");
            break;
            
        case AND:
            fprintf(f,"\tCMP\tRAX, 0\n");
            fprintf(f,"\tSETNE\tAL\n");
            fprintf(f,"\tMOV\tRCX, 1\n");
            fprintf(f,"\tAND\tRAX, RCX\n");
            fprintf(f,"\tCMP\tRBX, 0\n");
            fprintf(f,"\tSETNE\tBL\n");
            fprintf(f,"\tAND\tRBX, RCX\n");
            fprintf(f,"\tAND\tRAX, RBX\n");
            break;
            
        case OR:
            fprintf(f,"\tOR\tRAX, RBX\n");
            break;
            
        default:
            fprintf(f,"\t;ERROR: emit_exp: operator not found.\n");
            break;
    }//end switch
    
}//end emit_exp



//-----------------------------------------------------------------------------
/*  Print out the abstract syntax tree */
void emitPrint(ASTnode *p)
{
    if(debugg1 != 0)printf("IN emitPrint\n");
    
    if (p == NULL ) return;//Base case
    
    
    switch (p->type) {
        
        case FUNCTIONDEC : fprintf(f,"%s:\n",p->name);
        if(strcmp(p->name,"main") == 0)
            fprintf(f,"\tmov\trbp, rsp\t\t;SPECIAL RSP to RSB for MAIN only\n");
        
        fprintf(f,"\tmov\tr8, rsp\t\t;FUNC header RSP has to be at most RBP\n");
        fprintf(f,"\tadd\tr8, -%d\t\t;adjust Stack Pointer for Activation record\n",p->value * WSIZE);//p->value holds maxoffset
        fprintf(f,"\tmov\t[r8], rbp\t;FUNC header stored old BP\n");
        fprintf(f,"\tmov\t[r8+8], rsp\t;FUNC header store old BP\n");
        fprintf(f,"\tmov\trsp, r8\t\t;FUNC header new SP\n\n");
        
        
        emitPrint(p->s2);
        
        
        fprintf(f,"\tmov\trbp,[rsp]\t;FUNC end restore old BP\n");
        fprintf(f,"\tmov\trsp,[rsp+8]\t;FUNC end restore old SP\n");
        
        if(strcmp(p->name,"main") == 0)
            fprintf(f,"\tmov\trsp,rbp\t\t;stack and BP need to be same on exit for main\n");
        
        fprintf(f,"\txor\trax, rax\t\t; no value specificed, then it is 0\n");
        fprintf(f,"\tret\n");
        break;
        
        case EXPR :
            emit_exp(p);
            fprintf(f,"\n");
            break;
            
        case BLOCK :
            //Printing STATELIST
            emitPrint(p->s2);
            break;
            
        case WHILESTMT : 
            
            //Creating label to jump back to before the exp.
            p->name = CreateL();
            
            //Creating label to jump to end of statement
            temp = CreateL();
            fprintf(f,"%s:\t;Begin while loop\n\n",p->name);
            
            //WHILE
            emit_exp(p->s1);
            fprintf(f,"\n\tCMP\tRAX, 0\n");
            fprintf(f,"\tJE\t%s\n\n", temp);//Skipping DO statement.
            
            //DO
            emitPrint(p->s2);
            fprintf(f,"\n\tJMP\t%s\n", p->name);
            
            fprintf(f,"%s:\n",temp);
            fprintf(f,"\t;End while loop.\n\n");
            break;
            
        case WRITE:
            
            if(p->s1 == NULL)//true if writeing a string
            {
                fprintf(f, "\tPRINT_STRING %s\t\t;printing a string\n", p->str);
                fprintf(f, "\tNEWLINE\n\n");
                
            }//end if
            
            else{
                //Precondition: An ASTnode of type NUMBER, IDENT, EXPR OR CALL
                // that needs NASM code generated from it depending on it's type.
                //Postcondition: Result will be in RAX.
                repeated_switch(p->s1);
                fprintf(f,"\tPRINT_DEC  8, RAX\t;Printing a number.\n");
                fprintf(f, "\tNEWLINE\n\n");
            }//end else
            
            break;
            
        case myRETURN:
            emit_return(p);
            break;
            
        case READ:
            emit_ident(p->s1);
            fprintf(f,"\tGET_DEC 8, [RAX]\t\t;Reading in a variable.\n\n"); 
            
            break;
            
            //Assignment statement
        case ASST : 
            
            //Precondition: An ASTnode of type NUMBER, IDENT, EXPR OR CALL
            // that needs NASM code generated from it depending on it's type.
            //Postcondition: Result will be in RAX.
            repeated_switch(p->s2);
            fprintf(f,"\tMOV\tRCX, RAX\n\n");
            emit_ident(p->s1);//Getting var on left side of equal side
            fprintf(f,"\tMOV\t[RAX], RCX\t;Assigning LHS to RHS\n\n", p->s1->symbol->offset * WSIZE);
            
            break;
            
            //If statement
        case IFSTMT: 
            emit_if(p);
            break;
            
        case Call: 
            emit_function_call(p);
            break;
            
        case VARDEC:break;
        
        default: fprintf(f,"unknown type %d in enumPrint\n", p->type);
        
        
    }//end switch
    
    emitPrint(p->next);
}//end enumPrint



//-----------------------------------------------------------------------------
//Creates a leble 
char * CreateL()
{   if(debugg1 != 0)printf("IN CreatL\n");
    char hold[100];
    char *s;
    sprintf(hold,"_L%d",GTEMP++);
    s=strdup(hold);
    return (s);
    
}



//-----------------------------------------------------------------------------
//Precondition: p is an ASTnode
//Postcondition: Declares global strings
void wStrings(ASTnode *p){
    if(debugg1 != 0)printf("IN wStrings\n");
    
    if(p == NULL)
        return;
    
    if(p->type == WRITE)
        if(p->s1 == NULL){
            
            p->str = CreateL();
            fprintf(f,"\t%s:\tdb %s, 0  ;define a global string\n",p->str, p->name);
            
        }//end if
        
        wStrings(p->s1);
    wStrings(p->s2);
    wStrings(p->next);
    
}//end wStrings



//-----------------------------------------------------------------------------
//Precondition: N/A
//Postcondition: All variables in the symbol table with level 0 will be printed
void gVars(){
    if(debugg1 != 0)printf("IN gVars\n");
    
    struct SymbTab *p = getFirst();
    
    while(p != NULL){
        
        if(p->level == 0 && p->mysize != 0)
            fprintf(f,"\tcommon\t%s %d\t; define a global variabl\n", p->name,p->mysize * WSIZE);
        
        
        p = p->next;
        
    }//end while
}//end gVars


//-----------------------------------------------------------------------------
//Precondition: p is a CALL ASTnode
//Postcondition: Function has been called. Any result will be in RAX.
void emit_function_call(ASTnode *p){
    if(debugg1 != 0)printf("IN emit_function_call\n");
    
    
    int ofst = (p->symbol->maxoffset + 1) * WSIZE;
    
    //Not messing with p in order to print the function name later.
    ASTnode *k = p->s1;
    
    while(k != NULL){
        
        //Precondition: An ASTnode of type NUMBER, IDENT, EXPR OR CALL
        // that needs NASM code generated from it depending on it's type.
        //Postcondition: Result will be in RAX.
        repeated_switch(k->s1);
        
       fprintf(f,"\tMOV\t[RSP + %d], RAX\t;Saving RAX in memory\n\n", k->symbol->offset * WSIZE);
            
    
        k = k->next;
    }//end while
    
    fprintf(f,"\n\tMOV\tRBX, RSP\n");
    fprintf(f,"\tSUB\tRBX, %d\t\t;RBX is the new target for the function call\n", ofst);
    
    k = p;
    ASTnode *sp = p->symbol->fparms; //Getting original parameters of function.
    
    while(sp != NULL){
        
        //Setting RAX to argument answer.
        fprintf(f,"\tMOV\tRAX, [RSP + %d]\t;Copy actual to RAX\n", k->s1->symbol->offset * WSIZE);
        
        //Placing RAX in memory location of original functions parameters. 
        fprintf(f,"\tMOV\t[RBX + %d], RAX\t;Copy RAX to RBX target\n", sp->symbol->offset * WSIZE);
        
        sp = sp->next;
        k->s1 = k->s1->next;
        
    }//end while
    
   fprintf(f,"\tCALL\t%s\n\n", p->name);
    
}//end end emit_function_call


//-----------------------------------------------------------------------------
//Precondition: p is an IDENT ASTnode.
//Postcondition: RAX has the memory address of the variable.
void emit_ident(ASTnode *p){
    if(debugg1 != 0)printf("IN emit_ident\n");
    
    //This line will be printed multiple times one after another when doing something 
    // like this x[x[x[x[x[0]]]]]; 
    fprintf(f,"\tMOV\tRAX, 0\t\t;Clearing RAX\n");
    
    //An array
    if(p->s1 != NULL){
        //Precondition: An ASTnode of type NUMBER, IDENT, EXPR OR CALL
        // that needs NASM code generated from it depending on it's type.
        //Postcondition: Result will be in RAX.
        repeated_switch(p->s1);
        
        fprintf(f,"\tSHL\tRAX, %d\t\t;Multiplying offset by WSIZE\n", LOGSHIFT);
    }//end if
    
    
    
    //A global variable
    if(p->symbol->level == 0 )
        fprintf(f,"\tADD\tRAX, %s\t\t;Moving variable into RAX\n\n", p->name);
    //Not a global variable
    else{
        fprintf(f, "\tADD\tRAX, %d\t\t;Getting ident offset\n", p->symbol->offset * WSIZE);
        fprintf(f,"\tADD\tRAX, RSP\t\t;Identifier offset + stack pointer\n\n");
    }//end else
    
}//end emit_ident



//-----------------------------------------------------------------------------
//Function takes a return node and solves the return EXPR if applicable then 
// prints 'RET'
void emit_return(ASTnode *p){
    if(debugg1 != 0)printf("IN repeated_return\n");
    
    if(p->s1 != NULL)
        repeated_switch(p->s1);
    //Precondition: An ASTnode of type NUMBER, IDENT, EXPR OR CALL
    // that needs NASM code generated from it depending on it's type.
    //Postcondition: Result will be in RAX.
    
    
    fprintf(f,"\n\tmov\trbp,[rsp]\t;FUNC end restore old BP\n");
    fprintf(f,"\tmov\trsp,[rsp+8]\t;FUNC end restore old SP\n");
    
    fprintf(f,"\tRET\n\n");
    return;
}//end emit_return



//-----------------------------------------------------------------------------
void emit_if(ASTnode *p){
    if(debugg1 != 0)printf("IN repeated_if\n");
    
    temp = CreateL(); //Label used to skip to end of then statement
    temp2= CreateL(); //Label used to skip to end of else statement
    fprintf(f,"\t;IF\n\n");
    
    //IF
    emit_exp(p->s1);
    fprintf(f,"\n\tCMP\tRAX, 0\n");
    fprintf(f,"\tJE\t%s\t\t;Goto else\n\n", temp);
    
    //THEN
    fprintf(f,"\n\t;Then\n\n");
    emitPrint(p->s2->s1);//statement
    fprintf(f,"\tJMP\t%s\t\t;Skiping else\n", temp2);
    
    //ELSE
    fprintf(f,"%s:\n", temp);
    fprintf(f,"\n\t;Else\n\n");
    if(p->s2->s2 != NULL) //True if IF has an else.
        emitPrint(p->s2->s2);
    
    
    fprintf(f,"%s:\n", temp2);
    fprintf(f,"\t;End if.\n\n");    
}//end emit_if



//-----------------------------------------------------------------------------
//I found that this switch was repeated many times in my code so I made it a function.
//This function takes an ASTnode and prints the appropriate NASM code or calls another 
// function if need be. The result is stored in RAX
void repeated_switch(ASTnode *p){
    if(debugg1 != 0)printf("IN repeated_switch\n");
    
    if(p == NULL)return;//Error case
    
    switch (p->type){
        case NUMBER:
            fprintf(f,"\tMOV\tRAX, %d\t\t;Moving RHS to RAX\n", p->value);
            break;
            
        case IDENT:
            emit_ident(p);
            fprintf(f,"\tMOV\tRAX, [RAX]\n");
            break;
            
        case EXPR:
            emit_exp(p);
            break;
            
        case Call:
            emit_function_call(p);
            break;
            
        default: fprintf(f,"\tERROR: type %d not found\n", p->type);
        break;
    }//end switch
    
}//end repeated_switch












