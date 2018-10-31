xpr:	xprScanner.l	xprParser.y
	bison -d -t --debug --verbose --locations --report=all xprParser.y
	flex -d xprScanner.l
	g++ -o $@ xprParser.tab.c lex.yy.c -lfl