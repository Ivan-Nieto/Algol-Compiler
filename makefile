all:
	yacc -d lab9.y
	lex lab9.l
	gcc -c emit.c
	gcc -c symtable.c
	gcc -c y.tab.c
	gcc -c lex.yy.c
	gcc -c ast.c
	gcc symtable.o y.tab.o lex.yy.o ast.o emit.o -o lab9 
	./lab9 -o lab9Final.asm < test.al 
