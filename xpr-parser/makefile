xpr:	scanner.l	parser.y
	bison -d -t --debug --verbose --locations --report=all parser.y
	flex -d scanner.l
	g++ -w -std=c++11 -o $@ visitor.h ast.h  parser.tab.c lex.yy.c -lfl
