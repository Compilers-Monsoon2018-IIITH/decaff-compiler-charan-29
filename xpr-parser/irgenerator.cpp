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

Function *createFunc(Type *rt, string mth_id, vector<Type *> args, vector<string> argNames)
{

    FunctionType *FT = FunctionType::get(rt, args, false);

    Function *F = Function::Create(FT, Function::ExternalLinkage, mth_id, module);

    unsigned index = 0;
    for (Function::arg_iterator AI = F->arg_begin(); index != F->arg_size(); ++AI, ++index)
    {
        AI->setName(argNames[index]);
    }

    return F;
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

    if(pnode->mdList!=NULL)
    {
        vector<MethodDeclNode*> temp = *(pnode->mdList);
        
        for(size_t i = 0; i < temp.size(); i++)
        {
            irf->visit(temp[i]);
        }
        
    }

    cout << endl
         << "\033[1;33mIR Code\033[0m\n"
         << endl;
    module->dump();
}

//! FieldDeclNode* fdnode
Value* IRfactory::visit(FieldDeclNode* fdnode)
{
    cout << endl<<"\033[1;36mField Declaration\033[0m\n"<<endl;
    cout << "datatype: "<<fdnode->dataType<<endl;
    if(fdnode->idList!=NULL)
    {
        vector <Identifier*> temp = *(fdnode->idList);
        for(int i=0;i<temp.size();i++)
        {
            cout << "var #" << i << " :" << temp[i]->name << endl;
            irf->visit(fdnode->dataType, temp[i]);
        }
    }
}

// ! Identifier* id
Value* IRfactory::visit(char* dt, Identifier* id)
{
    Type* type;
    string dtype(dt);
    if(dtype=="int")
    {
        type = Builder.getInt32Ty();
    }
    else if(dtype=="boolean")
    {
        type = Builder.getInt1Ty();
    }
    else
    {
        cout << "Unknown datatype: "<< dtype << endl;
        assert(("ERROR: Unknown datatype",0));
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

//! MethodDeclNode
Function*   IRfactory::visit(MethodDeclNode* mdnode)
{
    string retType(mdnode->returnType);
    string methodName(mdnode->methodName);
    Type* irRetType;

    if(retType=="int")
    {
        irRetType = Type::getInt32Ty(Context);
    }
    else if(retType=="boolean")
    {
        irRetType = Type::getInt1Ty(Context);
    }
    else if(retType=="void")
    {
        irRetType = Type::getVoidTy(Context);
    }
    else
    {   
        cout << "Unrecognized return type :" << retType<<endl;
        assert(("ERROR: Unknown datatype", 0));
    }


    vector<string> argumentNames;
    vector<string> argumentGivenTypes;
    vector<Type*>  argumentActualTypes;
    if(mdnode->argsList!=NULL)
    {
        vector<MethodArgsNode *> temp = *(mdnode->argsList);
        for(int i=0;i<temp.size();i++)
        {
            string dataType(temp[i]->dataType);
            string argName(temp[i]->argName);
            if(dataType=="int") 
            {
                argumentActualTypes.push_back(Type::getInt32Ty(Context));
                argumentGivenTypes.push_back(dataType);
            }
            else
            if(dataType=="boolean")
            {
                argumentActualTypes.push_back(Type::getInt1Ty(Context));
                argumentGivenTypes.push_back(dataType);
            }
            else
            {
                cout << "Unrecognized return type :" << retType << endl;
                assert(("ERROR: Unknown datatype", 0));
            }
        }
    }


    Function* func = createFunc(irRetType, methodName, argumentActualTypes, argumentNames );
    BasicBlock *basicbloc = BasicBlock::Create(getGlobalContext(), "entry", func);
    Builder.SetInsertPoint(basicbloc);

    Value* irBlockReturn;// = irf->visit(mdnode->block);
    if(irBlockReturn)
    {
        Builder.CreateRet(irBlockReturn);
        verifyFunction(*func);
        if(func) func->dump();
        return func;
    }

    //it means empty bloc
    func->eraseFromParent();
    return 0;
}

// Value *GenerateIR::codeGen(ASTBlock *node)
// {
//     if (node->block_idenlist)
//     {
//         printit("codeGen-block-Identifiers");

//         if (node->block_idenlist)
//         {
//             vector<ASTBlockVarDecl *> temp = *(node->block_idenlist);
//             for (int i = 0; i < temp.size(); ++i)
//             {
//                 g->codeGen(temp[i]);
//             }
//         }

//         printit("Completed-codeGen-block-Identifiers");
//     }
//     if (node->stmts)
//     {
//         if (node->stmts)
//         {
//             printit("codeGen-Statements");
//             vector<ASTStatements *> temp = *(node->stmts);
//             for (int i = 0; i < temp.size(); ++i)
//             {
//                 g->codeGen(temp[i]);
//             }
//         }

//         printit("Completed-codeGen-Statements");
//     }

//     return 1;
// }
