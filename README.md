# decaf compiler
A compiler for a toy language "decaf"

## structure
scanner.l accepts the language tokens and gives them to parser
parser.y tallies the incoming tokens w.t.t. grammar and initializs nodes.
test-files contains some files of decaf language to test our compiler
ast.h contains all the nodes and it's constructors of ast in the compiler (just a model, not integrated into code)
visitor.h contains the parent visitor class to perform any actions on nodes of AST
visitable_nodes.h contains the nodes that has accept method in it 
irgenerator.cpp contains the generation code for IR using AST

## run

open a console in compiler folder
run make
then ./xpr

## description

here's the flow
scanner.l 
> parser.y constructs nodes in 
> visitable_nodes.h the nodes accept a IR generator object, which visits appropriate node 
> irgenerator.cpp generates ir by visiting nodes.
## To be implemented

Handle scope for variables
IR generation for some nodes if, for, method call etc.,






