#include "visitor.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"

#include <bits/stdc++.h>

using namespace std;
using namespace llvm;

static llvm::LLVMContext &Context = llvm::getGlobalContext();
static llvm::Module *module = new llvm::Module("decaf-compiler-1.0", Context);
;

static llvm::IRBuilder<> Builder(Context);
static std::map<std::string, llvm::AllocaInst *> symbolTable;

class Identifier
{
  public:
	char *name;
	IntNode *intliteral;
	bool isArr;

	//constructor for normal identifiers like a,b,c
	Identifier(char *name)
	{
		this->name = name;
		isArr = false;
	}

	//constructor for array identifiers like a[5],b[5]
	Identifier(char *name, IntNode *intliteral)
	{
		this->name = name;
		this->intliteral = intliteral;
		isArr = true;
	}

	Value *accept(IRfactory *irf)
	{
		return irf->visit(name, this);
	}
};

// int a, b, c;
//!
class FieldDeclNode
{
  	public:
		std::vector<Identifier *> *idList;
		char *dataType;

		FieldDeclNode(char *dataType, std::vector<Identifier *> *idList)
		{
			
			this->dataType = dataType;
			this->idList = idList;
		}

		Value *accept(IRfactory *irf)
		{
			return irf->visit(this);
		}
};

class CalloutArgsNode
{

  public:
	CalloutArgsNode() {}
	~CalloutArgsNode() {}
};

class ExpressionNode : public CalloutArgsNode
{
  public:
	ExpressionNode() {}
	virtual ~ExpressionNode() {}

	// LocationNode* location;
	// MethodCallNode* methodcall;
	// LiteralNode* literal;

	// ExpressionNode(LocationNode* location)
	// {
	// 	this->location = location;
	// }

	// ExpressionNode(MethodCallNode* methodcall)
	// {
	// 	this->methodcall = methodcall;
	// }

	// ExpressionNode(LiteralNode* literal)
	// {
	// 	this->literal = literal;
	// }
};

class LocationNode : public ExpressionNode
{
  public:
	LocationNode(){};
	~LocationNode() {}

	char *ID;
	ExpressionNode *expr;

	LocationNode(char *ID)
	{
		this->ID = ID;
	}

	LocationNode(char *ID, ExpressionNode *expr)
	{
		this->ID = ID;
		this->expr = expr;
	}
};

// someFunc (int a, char abc)
class MethodArgsNode
{

  public:
	char *dataType;
	char *argName;

	MethodArgsNode(char *dataType, char *argName)
	{
		this->dataType = dataType;
		this->argName = argName;
	}
};

class VarDeclNode
{
  public:
	char *type;
	vector<Identifier *> *blockVars;
	VarDeclNode(char *type, vector<Identifier *> *blockVars)
	{
		this->type = type;
		this->blockVars = blockVars;
	}

	Value *accept(IRfactory *irf)
	{
		return irf->visit(this);
	}
};

class StatementNode
{
  public:
	StatementNode() {}
	virtual ~StatementNode() {}
};

class BlockNode : public StatementNode
{
  public:
	BlockNode() {}
	~BlockNode() {}
	vector<VarDeclNode *> *varDecl;
	vector<StatementNode *> *statement;

	BlockNode(vector<VarDeclNode *> *varDecl, vector<StatementNode *> *statement)
	{
		this->varDecl = varDecl;
		this->statement = statement;
	}
	Value* accept(IRfactory *irf)
	{
		return irf->visit(this);
	}
};

// int funcName ( arguments ) {//block}
class MethodDeclNode
{

	public:
		char *returnType;
		char *methodName;

		std::vector<MethodArgsNode *>* argsList;
		BlockNode* block;

		MethodDeclNode(char *returnType, char *methodName, std::vector<MethodArgsNode *> *argsList, BlockNode *block)
		{
			this->returnType = returnType;
			this->methodName = methodName;
			this->argsList = argsList;
			this->block = block;
		}

		Value* accept(IRfactory *irf)
		{
			return irf->visit(this);
		}
};

class ProgramNode
{
  public:
	std::vector<FieldDeclNode *> *fdList;
	std::vector<MethodDeclNode *> *mdList;

	ProgramNode(std::vector<FieldDeclNode *> *fdList, std::vector<MethodDeclNode *> *mdList)
	{
		this->fdList = fdList;
		this->mdList = mdList;
	}

	Value *accept(IRfactory *irf)
	{
		return irf->visit(this);
	}
};

class AssignmentNode : public StatementNode
{
  public:
	AssignmentNode() {}
	~AssignmentNode() {}

	LocationNode *loc;
	char *asstoperator;
	ExpressionNode *expr;

	AssignmentNode(LocationNode *loc, char *asstoperator, ExpressionNode *expr)
	{
		this->loc = loc;
		this->asstoperator = asstoperator;
		this->expr = expr;
	}
};

class IfNode : public StatementNode
{
  public:
	IfNode() {}
	~IfNode() {}

	ExpressionNode *cond;
	BlockNode *ifbloc;
	BlockNode *elsebloc;

	IfNode(ExpressionNode *cond,
		   BlockNode *ifbloc,
		   BlockNode *elsebloc)
	{
		this->cond = cond;
		this->ifbloc = ifbloc;
		this->elsebloc = elsebloc;
	}
};

class ForNode : public StatementNode
{
  public:
	ForNode() {}
	~ForNode() {}

	char *id;
	ExpressionNode *condexpr;
	ExpressionNode *increxpr;
	BlockNode *forbloc;

	ForNode(char *id,
			ExpressionNode *condexpr,
			ExpressionNode *increxpr,
			BlockNode *forbloc)
	{
		this->id = id;
		this->condexpr = condexpr;
		this->increxpr = increxpr;
		this->forbloc = forbloc;
	}
};

class ReturnNode : public StatementNode
{
  public:
	ReturnNode() {}
	~ReturnNode() {}

	ExpressionNode *retexp;
	ReturnNode(ExpressionNode *retexp)
	{
		this->retexp = retexp;
	}
};

class BreakNode : public StatementNode
{
  public:
	BreakNode() {}
	~BreakNode() {}
};

class ContinueNode : public StatementNode
{
  public:
	~ContinueNode() {}
	ContinueNode() {}
};

class LiteralNode : public ExpressionNode
{
  public:
	LiteralNode() {}
	~LiteralNode() {}

	BoolNode *booval;
	IntNode *intval;
	CharNode *charval;

	LiteralNode(BoolNode *booval)
	{
		this->booval = booval;
	}

	LiteralNode(IntNode *intval)
	{
		this->intval = intval;
	}

	LiteralNode(CharNode *charval)
	{
		this->charval = charval;
	}
};

class StringNode : public CalloutArgsNode
{
  public:
	StringNode() {}
	~StringNode() {}
	char *str;
	StringNode(char *str)
	{
		this->str = str;
	}
};

class MethodNode : public StatementNode, public ExpressionNode
{
  public:
	MethodNode() {}
	~MethodNode() {}
};

class MethodCallNode : public MethodNode
{
  public:
	MethodCallNode() {}
	~MethodCallNode() {}
	vector<ExpressionNode *> *argts;
	char *mname;
	MethodCallNode(char *mname, vector<ExpressionNode *> *argts)
	{
		this->argts = argts;
		this->mname = mname;
	}
};

class CalloutNode : public MethodNode
{
  public:
	CalloutNode() {}
	~CalloutNode() {}

	vector<CalloutArgsNode *> *callargs;
	StringNode *strg;

	CalloutNode(StringNode *strg, vector<CalloutArgsNode *> *callargs)
	{
		this->callargs = callargs;
		this->strg = strg;
	}
};

class BinaryNode : public ExpressionNode
{
  public:
	ExpressionNode *expr1;
	char *op;
	ExpressionNode *expr2;
	BinaryNode(ExpressionNode *expr1, char *op, ExpressionNode *expr2)
	{
		this->expr1 = expr1;
		this->expr2 = expr2;
		this->op = op;
	}
};

class UnaryNode : public ExpressionNode
{
  public:
	ExpressionNode *expr1;
	char *op;
	UnaryNode(char *op, ExpressionNode *expr1)
	{
		this->expr1 = expr1;
		this->op = op;
	}
};

class IntNode : public LiteralNode
{
  public:
	int val;
	IntNode(int val)
	{
		this->val = val;
	}
};

class CharNode : public LiteralNode
{
  public:
	CharNode() {}
	~CharNode() {}
	char ch;
	CharNode(char che)
	{
		this->ch = che;
	}
};

class BoolNode : public LiteralNode
{
  public:
	BoolNode() {}
	~BoolNode() {}
	bool val;
	BoolNode(bool val)
	{
		this->val = val;
	}
};
