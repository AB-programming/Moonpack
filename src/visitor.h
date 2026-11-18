#include "enums.h"

class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;

    virtual void visit(ASTNode *node) {
        if (!node)
            return;

        for (auto &child: node->children) {
            visit(child.get());
        }
    }
};