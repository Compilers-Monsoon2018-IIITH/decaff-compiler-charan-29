xpr:	scanner.l	parser.y  visitor.h visitable_nodes.h  irgenerator.cpp
	bison -d -t --debug --verbose --locations --report=all parser.y
	flex -d scanner.l
	g++ -w  -std=c++11 -o $@ parser.tab.c lex.yy.c irgenerator.cpp -lfl `llvm-config --cxxflags --ldflags --system-libs --libs core`  -ltinfo -lpthread -ldl
