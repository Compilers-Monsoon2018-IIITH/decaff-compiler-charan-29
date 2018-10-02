/* just like Unix wc */


%{
#include "xprParser.tab.h"
int comment();
int yyerror(char *s);
%}
/*boolean break callout class continue else false for if int return true void*/
/* to be escaped characters .^$*+?()[{\|-]    

	[ \t\r\n]+  	{	/*eat up white space } 
*/




%option yylineno

%%

"/*"			{ comment(); }
"//".*\n 		{}

"boolean"		{ return BOOLEAN; 	}
"break"			{ return BREAK; 	}
"callout"		{ return CALLOUT; 	}
"class"			{ return CLASS; 	}
"continue"		{ return CONTINUE; 	}
"else"			{ return ELSE; 	 	}
"false"			{ return FALSE;		}
"for"			{ return FOR;		}
"int"			{ return INT;		}
"if"			{ return IF;		}
"return"		{ return RETURN;	}
"true"			{ return TRUE;		}
"void"			{ return VOID;		}
"Program"		{return PROGRAM;	}

"+"		{return '+';}
"-"		{return '-';}
"*"		{return '*';}
"/"		{return '/';}
"%"		{return '%';}

"<"		{return '<';}
">"		{return '>';}
"="		{return '=';}
"<="	{return LE;}
">="	{return GE;}

"=="	{return EE;}
"!="	{return NE;}

"!"		{return '!';}
"&&"	{return AND;}
"||"	{return OR;}

"+="	{return PLUSEQ;}
"-="	{return MINUSEQ;}

"("		{return '(';}
")"		{return ')';}
"{"		{return '{';}
"}"		{return '}';}
"["		{return '[';}
"]"		{return ']';}
","		{return ',';}
";"		{return ';';}


[0-9][0-9]* 					{return DECLIT;}
"0x"[0-9a-fA-F][0-9a-fA-F]*		{return HEXLIT;}
[a-zA-Z_][a-zA-Z0-9_]* 			{return ID;}


[ \t\v\n\f]+						{}

.								{printf( "Unrecognized character: %s\n", yytext );}
%%


int comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
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