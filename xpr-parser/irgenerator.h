#include 	"visitor.h"

#include	"llvm/IR/IRBuilder.h"
#include	"llvm/IR/LLVMContext.h"
#include	"llvm/IR/Module.h"
#include	"llvm/IR/Verifier.h"

#include 	<bits/stdc++.h>

using namespace std;
using namespace llvm;


static llvm::LLVMContext &Context = llvm::getGlobalContext();
static llvm::Module* module = new llvm::Module("decaf-compiler-1.0",Context);;

static llvm::IRBuilder<> Builder(Context);
static std::map<std::string, llvm::AllocaInst * > symbolTable;


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

		Value* accept(IRfactory* irf)
		{
			return irf->makeIR(this);
		}
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


