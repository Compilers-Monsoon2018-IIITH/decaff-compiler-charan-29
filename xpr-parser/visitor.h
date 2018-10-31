class ASTNormalIdentifier;

class visitor
{
    public:
        virtual void* visit(ASTNormalIdentifier*) = 0;
};