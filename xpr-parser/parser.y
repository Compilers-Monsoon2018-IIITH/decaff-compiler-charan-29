%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <bits/stdc++.h>
	using namespace std;

	#include "ast.h"

	extern "C" int yylex();
	extern "C" int yyerror(char *s);
	extern "C" int yyparse();

	ProgramNode *strt = NULL;

	extern FILE *yyin;
	#define YYDEBUG 1

	
%}




%union
{
	int ival;
	char* sval;

	ProgramNode* 		     	prgnodetype;

	vector<FieldDeclNode*>*  	fieldDecType;

	MethodDeclNode* 	     	methodDecType;
	vector<MethodDeclNode*>* 	methodDecListType;

	Identifier*			     	idType;
	vector<Identifier*>*	 	fieldArgsType;

	IntNode* 					intlitType;
	MethodArgsNode* 			methodArgType;
	vector<MethodArgsNode*>* 	methodArgsType;

	BlockNode*					blockType;
};


%start	classBegin


%type	<prgnodetype>		classBegin

%type 	<fieldDecType>		fieldDec

%type 	<methodDecType> 		methodDec
%type 	<methodDecListType>		methodDecList

%type 	<methodArgType> 	methodArg
%type 	<methodArgsType> 	methodArgs

%type 	<sval>				type
%type 	<fieldArgsType> 	fieldArgs
%type 	<intlitType> 		intlit //to be changed to expression node

%type 	<blockType> 		block

%token	<sval>	BOOLEAN
%token	<sval>	BREAK
%token	<sval>	CALLOUT
%token	<sval>	CLASS
%token	<sval>	CONTINUE
%token	<sval>	ELSE
%token	<sval>	FALSE
%token	<sval>	FOR
%token	<sval>	INT
%token	<sval>	IF
%token	<sval>	RETURN
%token	<sval>	TRUE
%token	<sval> 	VOID
%token	EOL
%token	<sval>	PROGRAM

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
			|	CLASS PROGRAM '{' fieldDec methodDecList '}'	{	strt = new ProgramNode($4,$5); 		}
			|	CLASS PROGRAM '{' methodDecList '}'				{	strt = new ProgramNode(NULL,$4);	}
			|	CLASS PROGRAM '{' fieldDec '}'				{	strt = new ProgramNode($4,NULL);	}
			;

fieldDec	:	type fieldArgs ';'							{	$$ = new vector<FieldDeclNode*>;
																$$->push_back(new FieldDeclNode($1,$2));	}
			|	fieldDec type fieldArgs ';' 				{	$$ = $1;
																$$->push_back(new FieldDeclNode($2,$3));	}																								
			;

fieldArgs	:	ID 											{	Identifier* idfr = new Identifier($1);
																$$ = new vector<Identifier*>;
																$$->push_back(idfr);						}
			
			|	ID ',' fieldArgs							{	Identifier* idfr = new Identifier($1);
																$$ = $3;
																$$->push_back(idfr);						}

			|	ID '[' intlit ']' 							{	Identifier* idfr = new Identifier($1,$3);
																$$ = new vector<Identifier*>; 
																$$->push_back(idfr);						}

			|	ID '[' intlit ']' ',' fieldArgs				{	Identifier* idfr = new Identifier($1,$3);
																$$ = $6;
																$$->push_back(idfr);						}
			;




methodDec	:		type ID '(' methodArgs ')' block 	{	$$ = new MethodDeclNode($1,$2,$4,$6);	}
				|	type ID '('  ')' block				{	$$ = new MethodDeclNode($1,$2,NULL,$5);	}	
				| 	VOID ID '(' methodArgs ')' block	{	$$ = new MethodDeclNode($1,$2,$4,$6);	}			
				|	VOID ID '('  ')' block				{	$$ = new MethodDeclNode($1,$2,NULL,$5);	}	

methodDecList 	:	methodDec					{	$$ = new vector<MethodDeclNode*>;
												 	$$->push_back($1);				}

				|	methodDecList methodDec		{	$$ = $1;
												  	$$->push_back($2);				}
				;

methodArg 	:	type ID 						{	$$ = new MethodArgsNode($1,$2);	}
			;

methodArgs	:	methodArg						{ 	$$ = new vector<MethodArgsNode*>;		
												   	$$->push_back($1); 				}

			|	methodArg ',' methodArgs 		{ 	$$ = $3;
												  	$$->push_back($1);				}
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

intlit		:	DECLIT 	{	$$ = new IntNode($1);	}
			|	HEXLIT 	{	$$ = new IntNode($1);	}
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
