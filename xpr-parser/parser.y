%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <bits/stdc++.h>
	#include "ast.h"
	using namespace std;
	extern "C" int yylex();
	extern "C" int yyerror(char *s);
	int yyparse();

	ProgramNode *strt = NULL;

	extern FILE *yyin;
	#define YYDEBUG 1
	
	
%}



%union
{
	int ival;
	char* sval;

	ProgramNode* 			prgNodeType;
	FieldDeclNode*			fldDecNodeType;

	vector<FieldDeclNode*> 	fldDecListType;
	MethodDeclNode* 		mthdDecNodeType;

	vector<Identifier*>		idListType;
	Identifier*				idType;
}


%start	classBegin


%type	<prgNodeType>		classBegin
%type 	<fldDecListType>	fieldDec
%type 	<mthdDecNodeType> 	methodDec
%type 	<sval>				type
%type 	<idListType> 		fieldArgs
%type 	<ival> 				intlit //to be changed to expression node

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

	


%token 	<sval> STRINGLIT
%token	<ival> DECLIT
%token	<ival> HEXLIT
%token	<sval> ID
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
//start	:	
//		|	start classBegin	
//		;

classBegin	:	CLASS PROGRAM '{' '}'						{	strt = new ProgramNode(NULL,NULL);	}
			|	CLASS PROGRAM '{' fieldDec methodDec '}'	{	strt = new ProgramNode($4,$5); 	}
			|	CLASS PROGRAM '{' methodDec '}'				{	strt = new ProgramNode(NULL,$4);	}
			|	CLASS PROGRAM '{' fieldDec '}'				{	strt = new ProgramNode($4,NULL);	}
			;

fieldDec	:	type fieldArgs ';'							{	$$ = new vector<FieldDeclNode*>;
																$$.push_back(new FieldDeclNode($1,$2));	}
			|	fieldDec type fieldArgs ';' 				{	$$ = $1;
																$$.push_back(new FieldDeclNode($1,$2));	}																								
			;

fieldArgs	:	ID 											{	Identifier* idfr = new Identifier($1);
																$$ = new vector<Identifier*>;
																$$.push_back(idfr);						}
			
			|	ID ',' fieldArgs							{	Identifier* idfr = new Identifier($1);
																$$ = $3;
																$$.push_back(idfr);						}

			|	ID '[' intlit ']' 							{	Identifier* idfr = new Identifier($1,$3);
																$$ = new vector<Identifier*>; 
																$$.push_back(idfr);						}

			|	ID '[' intlit ']' ',' fieldArgs				{	Identifier* idfr = new Identifier($1,$3);
																$$ = $6
																$$.push_back(idfr);						}
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
			|	CALLOUT '(' stringLiteral ')' 
			| 	CALLOUT '(' stringLiteral ',' calloutArgsList ')' 
			;

calloutArgsList	:	expr 
			|	stringLiteral 
			|	expr ',' calloutArgsList 
			|	stringLiteral ',' calloutArgsList 
			;

stringLiteral 	:	STRINGLIT
arguments	:	expr
			|	expr ',' arguments
			;

literal		:	intlit  
			| 	boollit
			;

intlit		:	DECLIT 	{	$$ = new Int($1);}
			|	HEXLIT 	{	$$ = new Int($1);}
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
		printf("trouble opening given file\n");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:

	yyin = myfile;
	yyparse();
	return 0;
}







//callout (string lit)
//comments