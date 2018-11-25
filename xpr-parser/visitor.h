#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Identifier;
class FieldDeclNode;
class CalloutArgsNode;
class ExpressionNode;
class LocationNode;
class MethodArgsNode;
class VarDeclNode;
class StatementNode;
class BlockNode;
class MethodDeclNode;
class ProgramNode;
class AssignmentNode;
class IfNode;
class ForNode;
class ReturnNode;
class BreakNode;
class ContinueNode;
class LiteralNode;
class StringNode;
class MethodNode;
class MethodCallNode;
class CalloutNode;
class BinaryNode;
class UnaryNode;
class IntNode;
class CharNode;
class BoolNode;









// class visitor
// {
// public:
// 	virtual 	int visit(ProgramNode*)=0;
// 	virtual 	int visit(IntLiteralNode*)=0;
// 	virtual	 	int visit(Identifier*)=0;
// 	virtual 	int visit(FieldDeclNode*)=0;
// 	virtual 	int visit(MethodDeclNode*)=0; 

// };

// class ASTvisitor : public visitor
// {
// 	int visit(ProgramNode*);
// 	int visit(IntLiteralNode*);
// 	int visit(Identifier*);
// 	int visit(FieldDeclNode*);
// 	int visit(MethodDeclNode*);
// };