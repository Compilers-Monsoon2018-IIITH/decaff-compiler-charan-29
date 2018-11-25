#include "visitor.h"
#include <bits/stdc++.h>
using namespace std;




class CalloutArgsNode
{
public:
	CalloutArgsNode();
	~CalloutArgsNode();

	
};


class LiteralNode
{
public:
	LiteralNode();
	~LiteralNode();

	BoolNode booval;
	IntNode	 intval;
	LiteralNode(BoolNode booval)
	{
		this->booval = booval;
	}

	LiteralNode(IntNode intval)
	{
		this->intval = intval;
	}
	
};

class BoolNode	:	public	LiteralNode
{
	public:
		BoolNode();
		~BoolNode();
		bool val;
		BoolNode(bool val)
		{
			this->val = val;
		}
};

class IntNode	:	public	LiteralNode
{
	public:
	int val;
	IntNode(int val)
	{
		this->val = val;
	}
};


class StringNode	:	public	LiteralNode, public	CalloutArgsNode
{
	public:
	StringNode();
	~StringNode();
	char* str;
	StringNode(char* str)
	{
		this->str=str;
	}	
};

class CharNode	:	public	LiteralNode
{
	public:
		CharNode();
		~CharNode();
		char ch;
		CharNode(char ch);
		{
			this->ch=ch;
		}
	
};

class Identifier
{
	public:
		char* name;
		IntNode* intliteral;
		bool isArr;

		//constructor for normal identifiers like a,b,c
		Identifier(char* name)
		{
			this->name = name;
			isArr = false;
		}


		//constructor for array identifiers like a[5],b[5]
		Identifier(char* name,IntNode* intliteral)
		{
			this->name = name;
			this->intliteral = intliteral;
			isArr = true;
		}

//
};


// int a, b, c;
class FieldDeclNode
{
	public:
		std::vector<Identifier*>* idList;
		char* dataType;

		FieldDeclNode(char* dataType,std::vector<Identifier*>* idList)
		{
			this->dataType=dataType;
			this->idList=idList;
		}
};


// someFunc (int a, char abc)
class MethodArgsNode
{

	public:
		char* dataType;
		char* argName;

		MethodArgsNode(char* dataType,	char* argName)
		{
			this->dataType=dataType;
			this->argName=argName;
		}
	};

class VarDeclNode
{
	public:
	char* type;
	vector<Identifier*>* blockVars;
	VarDeclNode(char* type, vector<Identifier*>* blockVars)
	{
		this->type = type;
		this-> blockVars = blockVars;
	}
};



class MethodCallNode
{
public:
	MethodCallNode();
	~MethodCallNode();

	MethodCallNode()
	
};

class ExpressionNode : public CalloutArgsNode
{
public:
	ExpressionNode();
	~ExpressionNode();

	LocationNode* location;
	MethodCallNode* methodcall;
	LiteralNode* literal;

	ExpressionNode(LocationNode* location)
	{
		this->location = location;
	}

	ExpressionNode(MethodCallNode* methodcall)
	{
		this->methodcall = location;
	}

	ExpressionNode(LiteralNode* literal)
	{
		this->literal = location;
	}


	
};


class LocationNode
{
	public:
		LocationNode();
		~LocationNode();

		char* ID;
		ExpressionNode* expr;


		LocationNode(char* ID)
		{
			this->ID = ID;
		}

		LocationNode(char* ID, ExpressionNode* expr)
		{
			this->ID = ID;
			this->expr = expr;
		}
};



class StatementNode
{
	public:
	StatementNode();
	~StatementNode();
	
};

class BlockNode
{
	public:
	BlockNode();
	~BlockNode();
	vector<VarDeclNode*>* varDecl;
	vector<StatementNode*>* statement;
	BlockNode(vector<VarDeclNode*>* varDecl, vector<StatementNode*>* statement)
	{
		this->varDecl=varDecl;
		this->statement = statement;
	}
};

// int funcName ( arguments ) {//block}
class MethodDeclNode
{

	public:
		char* returnType;
		char* methodName;

		std::vector<MethodArgsNode*>* argsList;
		BlockNode* block;

		MethodDeclNode(char* returnType,	char* methodName,	std::vector<MethodArgsNode*>* argsList,	BlockNode* block)
		{
			this->returnType=returnType;
			this->methodName=methodName;
			this->argsList=argsList;
			this->block=block;
		}
};

class ProgramNode
{
	public:
		std::vector<FieldDeclNode*	>*	fdList;
		std::vector<MethodDeclNode*	>*	mdList;

		ProgramNode(std::vector<FieldDeclNode*	>*	fdList,	std::vector<MethodDeclNode* >* mdList)
		{
			this->fdList = fdList;
			this->mdList = mdList;
		}
};