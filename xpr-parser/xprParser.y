%{
	#include <stdio.h>
%}

%token	BOOLEAN
%token	BREAK
%token	CALLOUT
%token	CLASS
%token	CONTINUE
%token	ELSE
%token	FALSE
%token	FOR
%token	INT
%token	IF
%token	RETURN
%token	TRUE
%token	VOID
%token	EOL
%token	COMMENT
%token	ADD
%token	SUB
%token	MUL
%token	DIV
%token	MOD
%token	LT
%token	GT
%token	LE
%token	GE
%token	EE
%token	NE
%token	AND
%token	OR
%token	ALNUM
%token	ALPHA
%token	DIGIT
%token	HEXDGT
%token	DECLIT
%token	HEXLIT
%token	STRINGLIT
%token	CHARLIT
%token	ID
%token	NOT
%token 	OPENCIRC
%token 	CLOSECIRC
%token	OPENSQR 
%token	CLOSESQR
%token	OPENFLWR 
%token	CLOSEFLWR
%token COMMA

%%

//start symbol
start	:	
		|	start expr EOL
		;

//expression
expr	:	location
		|	methodcall
		|	literal
		|	expr binop expr
		|	SUB expr
		| 	NOT expr
		|	OPENCIRC expr CLOSECIRC
		;

//location means identifier

location	:	ID
			|	ID OPENSQR expr CLOSESQR
			;

//method call

methodname	:	ID
			;

methodcall	:	methodname OPENCIRC CLOSECIRC
			|	methodname OPENCIRC arguments CLOSECIRC
			|	methodname OPENCIRC STRINGLIT CLOSECIRC
			|	methodname OPENCIRC STRINGLIT calloutarguments CLOSECIRC
			;

arguments	:	expr
			|	expr COMMA arguments
			;


calloutarguments	:	COMMA expr
					|	COMMA STRINGLIT
					|	COMMA multiexpr
					;

multiexpr	:	expr COMMA multiexpr
			|	STRINGLIT COMMA multiexpr
			|	expr
			|	STRINGLIT
			;


literal		:	intlit
			|	CHARLIT
			| 	boollit
			;

intlit		:	DECLIT 
			|	HEXLIT
			;

boollit		:	TRUE
			|	FALSE
			;

binop		:	arithop
			|	relop
			|	equiop
			|	condop
			;

arithop		:	ADD
			|	SUB
			|	MUL
			|	DIV
			|	MOD
			;

relop		:	LT		
			|	GT
			|	LE
			|	GE
			;

equiop		:	EE
			|	NE
			;

condop		:	AND
			|	OR
			;	

%%

int main(int argc, char **argv)
{
	yyparse();
	return 0;
}


yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}