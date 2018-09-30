xpr:	xprScanner.l	xprParser.y
	bison -d xprParser.y
	flex xprScanner.l
	cc -o $@ xprParser.tab.c lex.yy.c -lfl