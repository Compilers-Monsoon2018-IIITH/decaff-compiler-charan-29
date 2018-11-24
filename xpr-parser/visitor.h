#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ProgramNode;
class IntLiteralNode;
class Identifier;
class FieldDeclNode;
class MethodDeclNode;

class visitor
{
public:
	virtual 	int visit(ProgramNode*)=0;
	virtual 	int visit(IntLiteralNode*)=0;
	virtual	 	int visit(Identifier*)=0;
	virtual 	int visit(FieldDeclNode*)=0;
	virtual 	int visit(MethodDeclNode*)=0; 

};

class ASTvisitor : public visitor
{
	int visit(ProgramNode*);
	int visit(IntLiteralNode*);
	int visit(Identifier*);
	int visit(FieldDeclNode*);
	int visit(MethodDeclNode*);
};