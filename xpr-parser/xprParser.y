%{
	#include <stdio.h>
	int yylex();
int yyerror(char *s);
	extern FILE *yyin;

	
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
%token	PROGRAM

%right '=' PLUSEQ MINUSEQ
%left	AND OR

%left	EE NE

%left	'<' '>' LE GE
	
%left	'+' '-' 
%left	'*' '/' '%'
%nonassoc '!'

	



%token	DECLIT
%token	HEXLIT
%token	ID
%token	'!'
%token 	'('
%token 	')'
%token	'[' 
%token	']'
%token	'{' 
%token	'}'
%token  ','
%token	';'


// 

%%


//start symbol
start	:	
		|	start classBegin
		;

classBegin	:	CLASS PROGRAM '{' '}'
			|	CLASS PROGRAM '{' fieldDec methodDec '}'
			|	CLASS PROGRAM '{' methodDec '}'
			|	CLASS PROGRAM '{' fieldDec '}'
			;

// fieldDec	:	type ID ';' 
// 			|	type ID ',' 
// 			|	type ID '[' intlit ']' ';'
// 			|	type ID '[' intlit ']' ',' fieldDec
// 			;

fieldDec	:	type fieldArgs ';'
			|	fieldDec type fieldArgs ';' 
			;

fieldArgs	:	ID ',' fieldArgs
			|	ID
			|	ID '[' intlit ']' ',' fieldArgs
			|	ID '[' intlit ']'
			;


methodDecList	:	type ID '(' methodArgs ')' block 	{printf("hereeeee1\n");}
			|	type ID '('  ')' block	{printf("hereeeee2\n");}
			| 	VOID ID '(' methodArgs ')' block	{printf("hereeeee3\n");}
			|	VOID ID '('  ')' block	{printf("hereeeee4\n");}

methodDec 	:	methodDecList
			|	methodDec methodDecList
			;

methodArgs	:	type ID
			|	type ID ',' methodArgs
			;

block		:	'{'  '}'
			|	'{' varDecl  '}'
			|	'{' statement '}'
			|	'{' varDecl statement '}'
			;

varDecl		:	type vars ';' varDecl
			|	type vars ';'
			;

vars		:	vars ',' ID		
			|	ID 							
			;

statementContents	:	location '=' expr ';' {printf("yo man\n");}
					|	location PLUSEQ expr ';'
					|	location MINUSEQ expr ';'
					|	methodcall ';'
					|	IF '(' expr ')' block 
					|   IF '(' expr ')' block ELSE block
					|	FOR ID '=' expr ',' expr block
					|	RETURN ';'
					| 	RETURN expr ';'
					| 	BREAK ';'
					| 	CONTINUE ';'
					| 	block
					;

statement 	:	statementContents
			|	statement statementContents
			;


type	:	INT
		|	BOOLEAN
		;

//expression
expr	:	location 		{printf("expr location\n");}
		|	methodcall 		{printf("expr methodcall\n");}
		|	literal 		{printf("expr literal\n");}
		|	'-' expr 		{printf("expr '-' expr\n");}
		| 	'!' expr 		{printf("expr '!' expr\n");}
		|	expr '*' expr 	{printf("expr plus\n");}
		|	expr '/' expr 	{printf("expr plus\n");}
		|	expr '%' expr 	{printf("expr plus\n");}
		|	expr '+' expr 	{printf("expr plus\n");}
		|	expr '-' expr 	{printf("expr plus\n");}
		|	expr '<' expr 	{printf("expr plus\n");}
		|	expr '>' expr 	{printf("expr plus\n");}
		|	expr LE expr 	{printf("expr plus\n");}
		|	expr GE expr 	{printf("expr plus\n");}
		|	expr EE expr 	{printf("expr plus\n");}
		|	expr NE expr 	{printf("expr plus\n");}
		|	expr AND expr 	{printf("expr plus\n");}
		|	expr OR expr 	{printf("expr plus\n");}
		|	'(' expr ')'	{printf("bal parans\n");}
		;

//location means identifier
location	:	ID
			|	ID '[' expr ']'
			;

//method call
methodname	:	ID
			;

methodcall	:	methodname '(' ')'
			|	methodname '(' arguments ')'
			;

arguments	:	expr
			|	expr ',' arguments
			;

literal		:	intlit
			| 	boollit
			;

intlit		:	DECLIT 
			|	HEXLIT
			;

boollit		:	TRUE
			|	FALSE
			;

%%

int main(int argc, char **argv)
{
	// open a file handle to a particular file:

	FILE *myfile = fopen("test.dcf", "r");
	// make sure it's valid:
	if (!myfile) {
		printf("I can't open the file!\n");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	

	yyparse();
	return 0;
}


// int yyerror(char *s)
// {
// 	fprintf(stderr, "error: %s @ line %d\n", s, yylineno);
// }




//callout (string lit)
//comments
