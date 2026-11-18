#include "visitor.h"
#include "enums.h"

class FunctionCollector : public ASTVisitor {
public:
    std::vector<FunctionDeclaration*> functions;

    void visit(ASTNode* node) override {
        if (!node)
            return;

        if (node->type == NodeType::FunctionDeclaration) {
            auto* func = dynamic_cast<FunctionDeclaration*>(node);

            if (func)
                functions.push_back(func);
        }

        ASTVisitor::visit(node);
    }
};