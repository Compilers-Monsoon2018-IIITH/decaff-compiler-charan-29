/* just like Unix wc */


%{
#include "xprParser.tab.h"
%}

/*boolean break callout class continue else false for if int return true void*/

%%


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

[ \t]			{ /* ignore whitespace */ }
\n				{ return EOL; 		}
"//"			{return COMMENT;	}




"+"	{return ADD;}
"-"	{return SUB;}
"*"	{return MUL;}
"/"	{return DIV;}
"%"	{return MOD;}

"<"	{return LT;}
">"	{return GT;}
"<="	{return LE;}
">="	{return GE;}

"=="	{return EE;}
"!="	{return NE;}

"&&"	{return AND;}
"||"	{return OR;}
"!"		{return NOT;}


[a-zA-Z0-9]\{1\} {return ALNUM;}
[a-zA-Z]\{1\} {return ALPHA;} 
[0-9]\{1\} {return DIGIT;}
([[0-9][a-fA-F]])\{1\} {return HEXDGT;}


"("		{return OPENCIRC;}
")"		{return CLOSECIRC;}
"{"		{return OPENFLWR;}
"}"		{return CLOSEFLWR;}
"["		{return OPENSQR;}
"]"		{return CLOSESQR;}
","		{return COMMA;}


[0-9]([0-9]*) {return DECLIT;}
0x([[0-9][a-fA-F]])([[0-9][a-fA-F]])*	{return HEXLIT;}

('[\x20-\x7E]{-}['|"|\\|\\"|\\'|\\\\|\\t|\\n]')\{1\} {return CHARLIT;}
("[\x20-\x7E]{-}['|"|\\|\\"|\\'|\\\\|\\t|\\n]*")\{1\} {return STRINGLIT;}


[a-zA-Z]\{1\}([a-zA-Z0-9]*) {return ID;}




%%



