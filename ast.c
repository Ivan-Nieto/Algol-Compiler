/*   

	Ivan Nieto
	CS370
	4-10-19
	Lab7


	Abstract syntax tree code

     This code is used to define an AST node, 
    routine for printing out the AST
    defining an enumerated type so we can figure out what we need to
    do with this.  The ENUM is basically going to be every non-terminal
    and terminal in our language.

    Prints nodes, recursively if need be.

*/

#include<stdio.h>
#include<malloc.h>
#include "ast.h"

/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode *ASTCreateNode(enum ASTtype mytype)
{
    ASTnode *p;
    if (mydebug) fprintf(stderr,"Creating AST Node \n");
    p=(ASTnode *)malloc(sizeof(ASTnode));
    p->type=mytype;
    p->name=NULL;
    p->str=NULL;
    p->next=NULL;
    p->s1=NULL;
    p->s2=NULL;
    p->value=0;
    return(p);
}

/*  Helper function to print tabbing */

void PT(int howmany)
{
	while(howmany > 0){
		printf(" ");
		howmany = howmany - 1;
	} 
}//end PT

void printType(ASTnode *n){
    switch(n->operator){/*Prints apropriate operator name*/
        case INTTYPE:  printf("INT ")    ;break;
        case VOIDTYPE: printf("VOID ")   ;break;
        case BOOLTYPE: printf("BOOLEAN ");break;
        default: printf("OPERATOR NOT FOUND ");
    }//end switch
}//end printType

/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p)
{
   int i;
   if (p == NULL ) return;
   else
     { 
       PT(level); /*indent */
       switch (p->type) {
               
        case VARDEC :  printf("Variable ");
               printType(p);
		  
		   printf(" %s",p->name);
		   if (p->value > 0)
		         printf("[%d]",p->value);
			
		   printf("\n");
		   ASTprint(level,p->s1);/*Pointer to another VARDEC*/
		   break;

           case FUNCTIONDEC :
                   
               printType(p);
               
                   printf("FUNCTION %s \n",p->name);
                   /* print out the parameter list */
                   if (p->s1 == NULL )
                   { PT(level+2);
                       printf (" (VOID) "); }
                   else
                   {
                       PT(level+2);
                       printf( "( \n");
                       ASTprint(level+2, p->s1);
                       PT(level+2);
                       printf( ") ");
                   }
                   printf("\n");
                   ASTprint(level+2, p->s2); // print out the block
                   break;

           case PARAM :  printf("PARAMETER ");
                   
                   printType(p);
                   printf (" %s",p->name);
                   if (p->value == -1 )
                   printf("[]");
                   printf("\n");
                   ASTprint(level,p->s1);/*Print PARAMLIST*/
                   break;

           case EXPR : 
                  
                   printf("EXPR ");
                   switch(p->operator) {/*Prints apropriate operator name*/
                          case PLUS :       printf(" + ");break;
                          case MINUS:       printf(" - ");break;
                          case MULT:        printf(" * "); break;
                          case DIV :        printf(" / "); break;
                          case AND :        printf(" and "); break;
                          case OR  :        printf(" or ") ; break;
                          case myNOT:       printf(" not ");break;
                          case greaterthan: printf(" > ");break;
                          case lessthan:    printf(" < ");break;
                          case notq:        printf(" != ");break;
                          case qt:          printf(" >= ");break;
                          case eq:          printf(" == ");break;
                          case lessq:       printf(" <= ");break;
                          default:          printf("*OPERATOR NOT FOUND* ");
                      }//end switch

                   
                   printf("\n");

                   if(p->s1 == NULL){
                        PT(level);
			printf(" empty expression");		   
			}//end if                   
                   if(p->s1 != NULL){
                   ASTprint(level+1, p->s1);
                   if (p->operator != myNOT) /*When myNot is the operator then s2 was not used.*/
                   ASTprint(level+1, p->s2);}//end if
		   else{printf("\n");}//end else
                   break;

           case BLOCK :  printf("BLOCK STATEMENT  \n",p->name);
                   ASTprint(level+1, p->s1);/*Printing LOCALDEC*/
                   ASTprint(level+1, p->s2);/*Printing STATELIST*/
                   break;

           case WHILESTMT :  printf("WHILE STATEMENT \n");
                   ASTprint(level+1, p->s1);/*Printing EXP*/
                   ASTprint(level+2, p->s2);/*Printing STATE*/
                   break;

           case NUMBER :  printf("NUMBER with value %d\n",p->value);
                   ASTprint(level+1, p->s1);
                   break;

           case WRITE :  printf("WRITE STATEMENT\n");
                    if(p->name != NULL){
                        PT(level+1);
                        printf("%s\n",p->name);
                    }//end if
                   ASTprint(level+1, p->s1); /*Prining EXP*/
                   break;

	   case myRETURN: printf("RETURN STATEMENT\n");
		   ASTprint(level+1, p->s1); /*Printing EXP*/
		   break;

	   case READ: printf("READ STATEMENT\n");
		   ASTprint(level+1, p->s1);/*Printing VAR*/
		   break;

           case ASST :  printf("ASSIGNMENT STATEMENT \n");
                   ASTprint(level+1, p->s1);/*Printing VAR*/
                   PT(level+1);
                   printf("EXPRSTMT\n");
                   ASTprint(level+2, p->s2);/*Printing SIMEXP*/
                   break;

	   case IDENT :  printf("IDENT ");
                   printf("%s\n",p->name);
                   if(p->s1!=NULL){/*check to see if it's an array.*/
                   PT(level);
                   printf("Array Reference [\n");
		   ASTprint(level+1, p->s1);/*Printing EXP*/
                   PT(level);
		   printf("] end array\n");}//end if	                   
		   break;


	   case IFSTMT : printf("IF STATEMENT \n");
		   ASTprint(level+1,p->s1);/*Printing the if EXP*/
		   ASTprint(level+1,p->s2);/*Printing the STATE(s)*/
		   break;

	   case IFSTMT1 :printf("Then\n");
		   ASTprint(level+1, p->s1);
		   if(p->s2!=NULL){/*Checking if there is an else.*/
		   PT(level);
		   printf("Else \n");
		   ASTprint(level+1, p->s2);/*Printing the else STATE.*/
           }//end if
		   break;


       case Call: printf("CALL ");
		   printf("%s\n",p->name);
		   ASTprint(level+1, p->s1);/*Printing ARGS.*/
		   break;

        case ARG: printf("Arg List ");
               ASTprint(level+1,p->s1);
               ASTprint(level+2,p->s2);
            break;
               
               
        default: printf("unknown type in ASTprint\n");


       }
       ASTprint(level, p->next);
     }//end else

}//end ASTprint




/* dummy main program so I can compile for syntax error independently   
main()
{
}
/* */
