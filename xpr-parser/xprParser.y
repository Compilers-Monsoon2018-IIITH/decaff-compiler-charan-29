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

fieldDec	:	type fieldArgs ';'
			|	fieldDec type fieldArgs ';' 
			;

fieldArgs	:	ID ',' fieldArgs
			|	ID
			|	ID '[' intlit ']' ',' fieldArgs
			|	ID '[' intlit ']'
			;


methodDecList	:	type ID '(' methodArgs ')' block 	
			|	type ID '('  ')' block	
			| 	VOID ID '(' methodArgs ')' block	
			|	VOID ID '('  ')' block	

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

statementContents	:	location '=' expr ';'
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
expr	:	location 		
		|	methodcall 		
		|	literal 		
		|	'-' expr 		
		| 	'!' expr 		
		|	expr '*' expr 	
		|	expr '/' expr 	
		|	expr '%' expr 	
		|	expr '+' expr 	
		|	expr '-' expr 	
		|	expr '<' expr 	
		|	expr '>' expr 	
		|	expr LE expr 	
		|	expr GE expr 	
		|	expr EE expr 	
		|	expr NE expr 	
		|	expr AND expr 	
		|	expr OR expr 	
		|	'(' expr ')'	
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
