#ifndef COMPILER_HOMEWORK_AST_VISITOR_H
#define COMPILER_HOMEWORK_AST_VISITOR_H

#include "common.h"

class Node;
class Program;
class ConstDecl;
class VarDecl;
class UnaryExpr;
class BinaryExpr;
class Identifier;
class UInt;
class IfStatement;
class WhileStatement;
class AssignStatement;
class BlockStatement;

/// @class ASTVisitor, 一种设计模式, 通过visit和accept的形式来遍历语法树
///        能够可扩展的处理AST，遍历AST，是一种很常见的设计模式，在编译器设计中
class AstVisitor {
public:
    ADD_VISITOR(Node)
    ADD_VISITOR(Program)
    ADD_VISITOR(ConstDecl)
    ADD_VISITOR(VarDecl)
    ADD_VISITOR(UnaryExpr)
    ADD_VISITOR(BinaryExpr)
    ADD_VISITOR(Identifier)
    ADD_VISITOR(UInt)
    ADD_VISITOR(IfStatement)
    ADD_VISITOR(WhileStatement)
    ADD_VISITOR(AssignStatement)
    ADD_VISITOR(BlockStatement)
private:
    virtual void preAction(Node *node) {};
    virtual void postAction(Node *node) {};
};

#endif //COMPILER_HOMEWORK_AST_VISITOR_H
