#include "visitor.h"
#include <bits/stdc++.h>
using namespace std;

class IntNode
{
public:
	int val;
	IntNode(int val)
	{
		this->val = val;
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


class BlockNode
{
public:
	BlockNode();
	~BlockNode();
	
};
// int funcName ( arguments ) {//block}
class MethodDeclNode
{

	public:
		char* returnType;
		char* methodName;

		std::vector<MethodArgsNode*> argsList;
		BlockNode* block;

		MethodDeclNode(char* returnType,	char* methodName,	std::vector<MethodArgsNode*> argsList,	BlockNode* block)
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