calc:	calcScanner.l	calcParser.y
	bison -d calcParser.y
	flex calcScanner.l
	cc -o $@ calcParser.tab.c lex.yy.c -lfl