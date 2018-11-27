#include "visitable_nodes.h"
extern IRfactory* irf;

GlobalVariable *createGlob(IRBuilder<> &Builder, Type *dt, std::string Name)
{
    module->getOrInsertGlobal(Name, dt);
    GlobalVariable *gVar = module->getNamedGlobal(Name);
    gVar->setLinkage(GlobalValue::CommonLinkage);
    gVar->setAlignment(4);
    return gVar;
}

static AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, const std::string &VarName, Type *dt)
{
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    return TmpB.CreateAlloca(dt, 0, VarName.c_str());
}

//! ProgramNode* pnode
Value* IRfactory::visit(ProgramNode* pnode)
{

    // Value* val;
    if(pnode->fdList!=NULL)
    {
        vector<FieldDeclNode*> temp = *(pnode->fdList);
        for(int i=0;i<temp.size();i++)
        {
            irf->visit(temp[i]);
        }
    }

    // if(pnode->mdList!=NULL)
    // {
    //     vector<MethodDeclNode*> temp = *(pnode->mdList);
        
    //     for(size_t i = 0; i < temp.size(); i++)
    //     {
    //         irf->visit(temp[i]);
    //     }
        
    // }
}

//! FieldDeclNode* fdnode
Value* IRfactory::visit(FieldDeclNode* fdnode)
{
    cout << "Field Declaration: " << endl;
    cout << "datatype: "<<fdnode->dataType<<endl;
    if(fdnode->idList!=NULL)
    {
        vector <Identifier*> temp = *(fdnode->idList);

        for(int i=0;i<temp.size();i++)
        {
            cout << "var #"<<i<<" :"<<temp[i]<<endl;
            irf->visit(fdnode->dataType, temp[i]);
        }
    }
    cout << "Field Declaration Done " << endl<<endl;
}

// ! Identifier* id
Value* IRfactory::visit(char* dtype, Identifier* id)
{
    Type* type;
    if(dtype=="int")
    {
        type = Builder.getInt32Ty();
    }
    else if(dtype=="bool")
    {
        type = Builder.getInt1Ty();
    }
    else
    {
        cout << "Unknown datatype: "<< dtype << endl;
    }

    if(id->isArr)
    {
        IntNode* num = (id->intliteral);
        ArrayType* ArrayTy = ArrayType::get(type, num->val);
        GlobalVariable* garray = createGlob(Builder, ArrayTy, id->name);
    }
    else
    {
        GlobalVariable* gvar = createGlob(Builder, type, id->name);
    }
}

// Value *IRfactory::visit(MethodDeclNode* mdnode)
// {

// }
