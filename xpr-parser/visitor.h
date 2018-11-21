#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ProgramNode;
class visitor
{
public:
	visitor();
	~visitor();


	virtual int visit(ProgramNode*){};
	
};

class ASTvisitor : public visitor
{
	int visit(ProgramNode*);
};