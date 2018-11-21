#include "visitor.h"
#include <bits/stdc++.h>
using namespace std;

class Int
{

};

class Identifier
{
	public:
		char* name;
		IntLiteralNode* intliteral;
		bool isArr;
		Identifier(char* name)
		{
			this->name = name;
			isArr = false;
		}


		Identifier(char* name,IntLiteralNode* intliteral)
		{
			this->name = name;
			this->intliteral = intliteral;
			isArr = true;
		}

		bool isArray()
		{
			return isArr;
		}

	
};

class FieldDeclNode
{
	public:
		std::vector<Identifier*> idList;
		char* dataType;

		FieldDeclNode(char* dataType,std::vector<Identifier*> idList)
		{
			this->dataType=dataType;
			this->idList=idList;
		}
};

class MethodDeclNode
{

};
class ProgramNode
{
	public:
		std::vector<FieldDeclNode*	>	fdList;
		std::vector<MethodDeclNode*	>	mdList;

		ProgramNode(std::vector<FieldDeclNode*	>	fdList,	std::vector<MethodDeclNode* > mdList)
		{
			this->fdList = fdList;
			this->mdList = mdList;
		}
};