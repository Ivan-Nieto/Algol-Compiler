%{
/*
	Ivan Nieto
	CS370
	5-2-19
	Lab7
	
	This program is used to create tokens for a compiler in the language
	ALGOL. 
*/
#include "ast.h"
#include "y.tab.h"
int linecount=1;
int debug = 0;//Controlls the output to stderr.
%}


%%
void                            {if (debug)fprintf(stderr,"Found void\n");return(MYVOID);}

boolean                         {if (debug)fprintf(stderr,"Found boolean\n");return(MYBOOLEAN);}

true                            {if (debug)fprintf(stderr,"Found true\n");return(MYTRUE);}

false                           {if (debug)fprintf(stderr,"Found false\n");return(MYFALSE);}

begin                           {if (debug)fprintf(stderr,"Found begin\n");return(MYBEG);}

end                             {if (debug)fprintf(stderr,"Found end\n");return(MYEND);}

if                              {if (debug)fprintf(stderr,"Found if\n");return(MYIF);}

then                            {if (debug)fprintf(stderr,"Found then\n");return(MYTHEN);}

else                            {if (debug)fprintf(stderr,"Found else\n");return(MYELSE);}

while                           {if (debug)fprintf(stderr,"Found while\n");return(MYWHILE);}

do                              {if (debug)fprintf(stderr,"Found do\n");return(MYDO);}

return                          {if (debug)fprintf(stderr,"Found return\n");return(MYRETURN);}

read                            {if (debug)fprintf(stderr,"Found read\n");return(MYREAD);}

write                           {if (debug)fprintf(stderr,"Found write\n");return(MYWRITE);}

and                             {if (debug)fprintf(stderr,"Found and\n");return(MYAND);}

or                              {if (debug)fprintf(stderr,"Found or\n");return(MYOR);}

not                             {if (debug)fprintf(stderr,"Found not\n");return(MYNOT);}

int                             {if (debug)fprintf(stderr,"Int found\n"); return(MYINT);}

"=="				            {if (debug)fprintf(stderr,"Found ==\n");return(EQ);}

">="                            {if (debug)fprintf(stderr,"Found >=\n");return(QT);}

"<="                            {if (debug)fprintf(stderr,"Found <=\n");return(LT);}

"!="                            {if (debug)fprintf(stderr,"Found !=\n");return(NE);}

[a-zA-Z][a-zA-Z0-9]*               {if (debug)fprintf(stderr,"Found ID %c\n", *yytext);
				        yylval.string = strdup(yytext);return(MYID);}

[\[\],!=;\-+*/%&|><] 		{if (debug)fprintf(stderr,"return the token %c\n",*yytext); 
                       			return (*yytext);}

[()]            		{if (debug)fprintf(stderr,"Paren found %c\n",*yytext);
					return (*yytext);}

\n 				{if (debug)fprintf(stderr,"Cariage return\n"); linecount++;}

[ \t]				{if (debug)fprintf(stderr,"Whitespace found\n");}

[0-9][0-9]*                     {if (debug)fprintf(stderr,"Found a number %d\n",atoi((const char *)yytext));
					 yylval.value = atoi((const char *)yytext);return(MYNUM);}

\".*\"                      {if(debug)fprintf(stderr,"Found STRING %c\n", *yytext); 
                            yylval.string = strdup(yytext);return(STRING);}

%%

int yywrap(void)
{ return 1;}


