xpr:	xprScanner.l	xprParser.y
	bison -d --debug --locations --report=all xprParser.y
	flex -d xprScanner.l
	cc -o $@ xprParser.tab.c lex.yy.c -lfl