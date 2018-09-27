%{
	#include <stdio.h>
%}


%token	NUMBER
%token	ADD SUB MUL DIV ABS
%token	EOL

%%

Calc	:	
		|	Calc Exp EOL	{ printf("= %d\n", $2); }
		;

Exp		:	Factor			
		|	Exp ADD Factor	{ $$=$1+$3; }
		|	Exp SUB Factor	{ $$=$1-$3; }
		;

Factor	: 	Term			
		| 	Factor MUL Term	{ $$=$1*$3; }
		|	Factor DIV Term	{ $$=$1/$3; }
		;

Term 	:	NUMBER 
		| ABS Term  		{ $$ = $2 >= 0? $2 : - $2; }
		;	

%%

main(int argc, char **argv)
{
	yyparse();
}


yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}