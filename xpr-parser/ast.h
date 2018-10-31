#include <vector>
#include <string>
#include <iostream>
#include "visitor.h"

using namespace std;

class ASTNode;
class ASTNormalIdentifier;

union Node
{
    vector<ASTNormalIdentifier *> *identifiers;
};

typedef union NODE YYSTYPE;

class ASTNode
{
  public:
    ASTNode() {}
    ~ASTNode() {}
    static string stringFromDataType(DataType d)
    {
        switch (d)
        {
        case DataType::int_type:
            return "integer";
        case DataType::bool_type:
            return "boolean";
        case DataType::void_type:
            return "void";
        }
    }
    virtual void *accept(visitor *v) = 0;
};

class ASTNormalIdentifier : public ASTIdentifier
{
    string id;

  public:
    ASTNormalIdentifier(string id)
    {
        this->id = id;
    }
    ~ASTNormalIdentifier() {}
    string getId()
    {
        return this->id;
    }
    void *accept(Visitor *v)
    {
        v->visit(this);
    }
};