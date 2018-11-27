#include	"llvm/IR/IRBuilder.h"
#include	"llvm/IR/LLVMContext.h"
#include	"llvm/IR/Module.h"
#include	"llvm/IR/Verifier.h"

#include 	<cstdlib>
#include 	<iostream>
#include 	<bits/stdc++.h>

using namespace std;
using namespace llvm;


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


class IRfactory
{
public:
	IRfactory(){}

	Value* visit(ProgramNode*);
	Value* visit(FieldDeclNode*);
	Value* visit(char*,Identifier*);
};





