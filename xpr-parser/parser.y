%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <bits/stdc++.h>
	using namespace std;

	#include "ast.h"

	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" int yyerror(char *s);

	ProgramNode *strt = NULL;

	extern FILE *yyin;
	#define YYDEBUG 1

	
%}





%union
{
	int ival;
	char* sval;
	char cval;

	ProgramNode* 		     	prgnodetype;

	vector<FieldDeclNode*>*  	fieldDecType;

	MethodDeclNode* 	     	methodDecType;
	vector<MethodDeclNode*>* 	methodDecListType;

	Identifier*			     	idType;
	vector<Identifier*>*	 	idListType;


	IntNode* 					intlitType;
	MethodArgsNode* 			methodArgType;
	vector<MethodArgsNode*>* 	methodArgsType;


	VarDeclNode* 				varDeclSingleType;
	vector<VarDeclNode*>* 		varDeclType;

	LiteralNode*				literalType;
	BoolNode* 					boollitType;

	MethodCallNode* 			methodcallType;
	CalloutNode* 				methodcallType;

	BlockNode*					blockType;
	LocationNode* 				locationType;

	ExpressionNode* 			exprType;
	vector<ExpressionNode*>* 	argumentsType;

	StringNode* 				stringlitType;



	CalloutArgsNode* 			calloutArgsType
	vector<CalloutArgsNode*>* 	calloutArgsListType;

	StatementNode* 				statementContentsType;
	vector<StatementNode*> 		statementType;
};



%start	classBegin


%type	<prgnodetype>		classBegin

%type 	<fieldDecType>		fieldDec

%type 	<methodDecType> 		methodDec
%type 	<methodDecListType>		methodDecList

%type 	<methodArgType> 	methodArg
%type 	<methodArgsType> 	methodArgs

%type 	<sval>				type
%type 	<idListType> 		fieldArgs

%type 	<intlitType> 		intlit //to be changed to expression node
%type 	<boollitType> 		boollit
%type 	<literalType> 		literal

%type 	<locationType> 		location

%type 	<methodcallType> 	methodcall

%type 	<varDeclType> 		varDecl

%type 	<exprType> 			expr
%type 	<argumentsType> 	arguments

%type 	<blockType> 		block
%type 	<idListType> 		blockVars

%type 	<stringlitType> 	stringlit


%type 	<calloutArgsListType>	calloutArgsList

%type 	<statementContentsType> statementContents
%type 	<statementType> 		statement	

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

%right		<sval> '=' PLUSEQ MINUSEQ
%left		<sval>	AND OR

%left		<sval>	EE NE

%left		<sval>	'<' '>' LE GE
	
%left		<sval>	'+' '-' 
%left		<sval>	'*' '/' '%'
%nonassoc	'!'

	


%token 	<sval> STRINGLIT
%token 	<cval> CHARLIT
%token	<ival> DECLIT
%token	<ival> HEXLIT
%token	<sval> ID
%token	<sval> '!'
%token 	 '('
%token 	 ')'
%token	 '[' 
%token	 ']'
%token	 '{' 
%token	 '}'
%token   ','
%token	 ';'



// 

%%


//start symbol
//start	:	
//		|	start classBegin	
//		;

classBegin	:	CLASS PROGRAM '{' '}'							{	strt = new ProgramNode(NULL,NULL);	}
			|	CLASS PROGRAM '{' fieldDec methodDecList '}'	{	strt = new ProgramNode($4,$5); 		}
			|	CLASS PROGRAM '{' methodDecList '}'				{	strt = new ProgramNode(NULL,$4);	}
			|	CLASS PROGRAM '{' fieldDec '}'					{	strt = new ProgramNode($4,NULL);	}
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
												 	$$->push_back($1);					}

				|	methodDecList methodDec		{	$$ = $1;
												  	$$->push_back($2);					}
				;

methodArg 	:	type ID 						{	$$ = new MethodArgsNode($1,$2);		}
			;

methodArgs	:	methodArg						{ 	$$ = new vector<MethodArgsNode*>;		
												   	$$->push_back($1); 					}

			|	methodArg ',' methodArgs 		{ 	$$ = $3;
												  	$$->push_back($1);					}
			;

block		:	'{'  '}' 						{ 	$$ = new BlockNode(NULL,NULL);	}
			|	'{' varDecl  '}'				{	$$ = new BlockNode($2,NULL);	}
			|	'{' statement '}'				{	$$ = new BlockNode(NULL,$2);	}
			|	'{' varDecl statement '}'		{	$$ = new BlockNode($2,$3);		}
			;

varDecl		:	type blockVars ';'					{	VarDeclNode* temp = new VarDeclNode($1,$2);
													 	$$ = new vector<VarDeclNode*>;
													 	$$->push_back(temp);						} 		

			|	type blockVars ';' varDecl 			{	$$ = $4;
													 	VarDeclNode* temp = new VarDeclNode($1,$2);
													 	$$->push_back(temp);						}
			;

blockVars		:	ID								{	$$ = new vector<Identifier*>;
														Identifier* temp = new Identifier($1);
												 		$$->push_back(temp);					}

				|	blockVars ',' ID 				{	$$ = $1;
														Identifier* temp = new Identifier($3);
														$$->push_back(temp);					}																		
				;



statementContents	:	location '=' expr ';'     	{	$$ = new AssignmentNode($1,$2,$3);	}		   				
					|	location PLUSEQ expr ';'	{	$$ = new AssignmentNode($1,$2,$3);	}				
					|	location MINUSEQ expr ';'	{	$$ = new AssignmentNode($1,$2,$3);	}				
					|	methodcall ';'				{	$$ = new MethodNode(); $$ = $1;		}			
					|	IF '(' expr ')' block 		{	$$ = new IfNode($3,$5,NULL);}			
					|   IF '(' expr ')' block ELSE block {	$$ = new IfNode($3,$5,$7);}		
					|	FOR ID '=' expr ',' expr block 	{$$ = new ForNode($2,$4,$6,$7);}			
					|	RETURN ';'					{	$$ = new ReturnNode(NULL);}
					| 	RETURN expr ';'				{	$$ = new ReturnNode($2);}			
					| 	BREAK ';'					{ 	$$ = new BreakNode();}			
					| 	CONTINUE ';'				{	$$ = new ContinueNode();}			
					| 	block 						{	$$ = new BlockNode(); $$ = $1;}					
					;

statement 	:	statementContents 			      { $$ = new vector<StatementNode*>;
													StatementNode* temp = new StatementNode($1);
													$$->push_back(temp);	}	

			|	statement statementContents  	  {	$$ = $1;
													StatementNode* temp = new StatementNode($2);
													$$->push_back(temp);	}
			;


type	:	INT
		|	BOOLEAN
		;

//expression
expr	:	location 		 		{$$ = new ExpressionNode($1);	   }	
		|	methodcall 			 	{$$ = new ExpressionNode($1);	   }		
		|	literal 		   		{$$ = new ExpressionNode($1);	   }
		|	'-' expr 	 			{$$ = new ExpressionNode($1,$2);   }	
		| 	'!' expr 				{$$ = new ExpressionNode($1,$2);   }
		|	expr '*' expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr '/' expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr '%' expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr '+' expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr '-' expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr '<' expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr '>' expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr LE expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr GE expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr EE expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr NE expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr AND expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	expr OR expr 			{$$ = new ExpressionNode($1,$2,$3);}
		|	'(' expr ')'			{$$ = new ExpressionNode($2); 	   }
		;

//location means identifier
location	:	ID  				{$$ = new LocationNode($1);		}
			|	ID '[' expr ']' 	{$$ = new LocationNode($1,$3);	}
			;


methodname	:	ID 					
			;
//method call
methodcall	:	methodname '(' ')'	 		 	 							{$$ = new MethodCallNode();		}
			|	methodname '(' arguments ')'								{$$ = new MethodCallNode($3);	}
			|	CALLOUT '(' stringlit ',' calloutArgsList ')'	 			{$$ = new CalloutNode($3,$5);		}
			| 	CALLOUT '(' stringlit ')'									{$$ = new CalloutNode($3);	} 
			;

calloutArgsList	:	 	expr 						 	{$$ = new vector<CalloutArgsNode*>;
														 CalloutArgsNode* temp = new CalloutArgsNode($1);
														 $$->push_back(temp);}	

				|	stringlit 							{$$ = new vector<CalloutArgsNode*>;
														 CalloutArgsNode* temp = new CalloutArgsNode($1);
														 $$->push_back(temp);}	

				| 	expr ',' calloutArgsList 			{$$ = $3;
														 $$->push_back($1);}		


				|	stringlit ',' calloutArgsList 		{$$ = $3;
														 $$->push_back($1);}

												
				;


arguments	:	expr  						{	$$ = new vector<ExpressionNode*>;
												ExpressionNode* temp = ExpressionNode($1);
											 	$$->push_back(temp);					}

			|	expr ',' arguments			{	$$ = $1;
											 	$$->push_back($3);					}
			;

literal		:	intlit    			{ $$ = new LiteralNode($1);	}
			| 	boollit 			{ $$ = new LiteralNode($1);	}
			; 

intlit		:	DECLIT 	{	$$ = new IntNode($1);	}
			|	HEXLIT 	{	$$ = new IntNode($1);	}
			;

boollit		:	TRUE 	{	$$ = new BoolNode($1);	}
			|	FALSE	{ 	$$ = new BoolNode($1);	}
			;

stringlit 	:	STRINGLIT 	{$$ = new StringNode($1);}
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
