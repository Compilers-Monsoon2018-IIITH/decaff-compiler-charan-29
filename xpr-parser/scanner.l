/* just like Unix wc */


%{
#include <bits/stdc++.h>

using namespace std;
// #include "ast.h"
#include "visitable_nodes.h"
#include "parser.tab.h"



#define YY_DECL extern "C" int yylex()

int comment();
extern "C" int yyerror(char *s);
%}
/*boolean break callout class continue else false for if int return true void*/
/* to be escaped characters .^$*+?()[{\|-]    

	[ \t\r\n]+  	{	/*eat up white space } 
*/





%option yylineno

%%

"/*"			{ comment(); }
"//".*\n 		{}

"boolean"		{char* str = (yytext); yylval.sval = str; return BOOLEAN; 	}
"break"			{char* str = (yytext); yylval.sval = str; return BREAK; 	}
"callout"		{char* str = (yytext); yylval.sval = str; return CALLOUT; 	}
"class"			{char* str = (yytext); yylval.sval = str; return CLASS; 	}
"continue"		{char* str = (yytext); yylval.sval = str; return CONTINUE; 	}
"else"			{char* str = (yytext); yylval.sval = str; return ELSE; 	 	}
"false"			{char* str = (yytext); yylval.sval = str; return FALSE;		}
"for"			{char* str = (yytext); yylval.sval = str; return FOR;		}
"int"			{char* str = (yytext); yylval.sval = str; return INT;		}
"if"			{char* str = (yytext); yylval.sval = str; return IF;		}
"return"		{char* str = (yytext); yylval.sval = str; return RETURN;	}
"true"			{char* str = (yytext); yylval.sval = str; return TRUE;		}
"void"			{char* str = (yytext); yylval.sval = str; return VOID;		}
"Program"		{char* str = (yytext); yylval.sval = str; return PROGRAM;	}

"+"		{char* str = (yytext); yylval.sval = str; return '+';}
"-"		{char* str = (yytext); yylval.sval = str; return '-';}
"*"		{char* str = (yytext); yylval.sval = str; return '*';}
"/"		{char* str = (yytext); yylval.sval = str; return '/';}
"%"		{char* str = (yytext); yylval.sval = str; return '%';}

"<"		{char* str = (yytext); yylval.sval = str; return '<';}
">"		{char* str = (yytext); yylval.sval = str; return '>';}
"="		{char* str = (yytext); yylval.sval = str; return '=';}
"<="	{char* str = (yytext); yylval.sval = str; return LE;}
">="	{char* str = (yytext); yylval.sval = str; return GE;}

"=="	{char* str = (yytext); yylval.sval = str; return EE;}
"!="	{char* str = (yytext); yylval.sval = str; return NE;}

"!"		{char* str = (yytext); yylval.sval = str; return '!';}
"&&"	{char* str = (yytext); yylval.sval = str; return AND;}
"||"	{char* str = (yytext); yylval.sval = str; return OR;}

"+="	{char* str = (yytext); yylval.sval = str; return PLUSEQ;}
"-="	{char* str = (yytext); yylval.sval = str; return MINUSEQ;}

"("		{char* str = (yytext); yylval.sval = str; return '(';}
")"		{char* str = (yytext); yylval.sval = str; return ')';}
"{"		{char* str = (yytext); yylval.sval = str; return '{';}
"}"		{char* str = (yytext); yylval.sval = str; return '}';}
"["		{char* str = (yytext); yylval.sval = str; return '[';}
"]"		{char* str = (yytext); yylval.sval = str; return ']';}
","		{char* str = (yytext); yylval.sval = str; return ',';}
";"		{char* str = (yytext); yylval.sval = str; return ';';}
'\"' 	{char* str = (yytext); yylval.sval = str; return DOUBLEQ;}
'\'' 	{char* str = (yytext); yylval.sval = str; return SINGLEQ;}

[0-9][0-9]* 					{yylval.ival = atoi(yytext); 	return DECLIT;}
"0x"[0-9a-fA-F][0-9a-fA-F]*		{yylval.ival = atoi(yytext); 	return HEXLIT;}
[a-zA-Z_][a-zA-Z0-9_]* 			{char* id = (yytext); yylval.sval = id; 	return ID;}

[a-zA-Z_]?\"(\\.|[^\\"])*\"		{ char* str = (yytext); yylval.sval = str;  return STRINGLIT;}


[ \t\v\n\f]+					{}

.								{printf( "Unrecognized character: %s\n", yytext );}
%%


int comment()
{
	char c, c1;

loop:
	while ((c = getchar()) != '*' && c != 0)
		putchar(c);

	if ((c1 = getchar()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}


int yyerror(char *s)
{
	fprintf(stderr, "error: %s @ line %d\n", s, yylineno);
}
