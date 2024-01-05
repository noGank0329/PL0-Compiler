#ifndef COMPILER_HOMEWORK_CODEGEN_H
#define COMPILER_HOMEWORK_CODEGEN_H

#include <iostream>
#include "tac_define.h"
#include "ast_visitor.h"


/// ------------------------------------------------------------------------
/// @brief AstVisitor this class is the base class to visit the ast node.
/// ------------------------------------------------------------------------
class CodeGen : public AstVisitor{
private:
    ConstDecl *CDecl;
    Op *T;
    TacProg *Prog;
public:
    explicit CodeGen() : CDecl(nullptr), Prog(nullptr) {}
    ~CodeGen();
public:
    TacProg *codegen(Program *prog);
public:
    ADD_VISITOR_OVERRIDE(Program)
    ADD_VISITOR_OVERRIDE(UnaryExpr)
    ADD_VISITOR_OVERRIDE(BinaryExpr)
    ADD_VISITOR_OVERRIDE(Identifier)
    ADD_VISITOR_OVERRIDE(UInt)
    ADD_VISITOR_OVERRIDE(IfStatement)
    ADD_VISITOR_OVERRIDE(WhileStatement)
    ADD_VISITOR_OVERRIDE(AssignStatement)
};


#endif //COMPILER_HOMEWORK_CODEGEN_H
