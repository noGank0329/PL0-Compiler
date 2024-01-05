#include "ast_visitor.h"
#include "ast.h"


void AstVisitor::visit(Node *node) {}

void AstVisitor::visit(Program *node) {
    preAction(node);
    TRAVERS_NODE(node->getCDecl())
    TRAVERS_NODE(node->getVDecl())
    TRAVERS_NODE(node->getStmt())
    postAction(node);
}

void AstVisitor::visit(ConstDecl *node) {
    preAction(node);
    postAction(node);
}

void AstVisitor::visit(VarDecl *node) {
    preAction(node);
    postAction(node);
}

void AstVisitor::visit(UnaryExpr *node) {
    preAction(node);
    TRAVERS_NODE(node->getUnaryExpr())
    postAction(node);
}

void AstVisitor::visit(BinaryExpr *node) {
    preAction(node);
    TRAVERS_NODE(node->getLhs())
    TRAVERS_NODE(node->getRhs())
    postAction(node);
}

void AstVisitor::visit(UInt *node) {
    preAction(node);
    postAction(node);
}

void AstVisitor::visit(Identifier *node) {
    preAction(node);
    postAction(node);
}

void AstVisitor::visit(IfStatement *node) {
    preAction(node);
    TRAVERS_NODE(node->getCond())
    TRAVERS_NODE(node->getThen())
    postAction(node);
}

void AstVisitor::visit(WhileStatement *node) {
    preAction(node);
    TRAVERS_NODE(node->getCond())
    TRAVERS_NODE(node->getBody())
    postAction(node);
}

void AstVisitor::visit(BlockStatement *node) {
    preAction(node);
    TRAVERS_ARRAY(node->getStmts())
    postAction(node);
}

void AstVisitor::visit(AssignStatement *node) {
    preAction(node);
    TRAVERS_NODE(node->getLhs())
    TRAVERS_NODE(node->getRhs())
    postAction(node);
}



