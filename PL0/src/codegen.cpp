#include "ast.h"
#include "codegen.h"
#include <unordered_map>
#include <string>

CodeGen::~CodeGen() {
    if(Prog) {
        delete Prog;
        Prog = nullptr;
    }
}

TacProg *CodeGen::codegen(Program *prog) {
    Prog = new TacProg();
    Prog->setCurBbil(Prog->getNewBblk());
    AstVisitor::visit(prog);
    return Prog;
}


void CodeGen::visit(Program *node) {
    CDecl = node->getCDecl();
    AstVisitor::visit(node);
}

void CodeGen::visit(UnaryExpr *node) {
    TRAVERS_NODE(node->getUnaryExpr());
    auto op = T;
    T = new Reg();
    Prog->addInst(new TacInst({TacSub, new Imm(0), op, T}));
}


void CodeGen::visit(BinaryExpr *node) {
    TRAVERS_NODE(node->getLhs())
    auto t_lhs = T;
    TRAVERS_NODE(node->getRhs())
    auto t_rhs = T;
    T = new Reg();
    Prog->addInst(new TacInst({(TacOpType)node->getExprOp(), t_lhs, t_rhs, T}));
}

void CodeGen::visit(Identifier *node) {
    if(CDecl) {
        auto const_val = CDecl->getConstDef(node);
        T = new Imm(const_val->value);
    }
    else {
        T = new Var(node->getId());
    }
}

void CodeGen::visit(UInt *node) {
    T = new Imm(node->getNum());
}

void CodeGen::visit(IfStatement *node) {
    auto BBBody = Prog->getNewBblk();
    auto BbThen = Prog->getNewBblk();
    TRAVERS_NODE(node->getCond())
    Prog->addInst(new TacInst({TacCondJmp, new Imm(0), T, BbThen}));
    Prog->setCurBbil(BBBody);
    TRAVERS_NODE(node->getThen())
    Prog->setCurBbil(BbThen);
}

void CodeGen::visit(WhileStatement *node) {
    auto BBCond = Prog->getNewBblk();
    auto BBBody = Prog->getNewBblk();
    auto BbThen = Prog->getNewBblk();
    Prog->addInst(new TacInst({TacJmp, BBCond, nullptr, nullptr}));
    Prog->setCurBbil(BBCond);
    TRAVERS_NODE(node->getCond())
    Prog->addInst(new TacInst({TacCondJmp, new Imm(0), T, BbThen}));
    Prog->setCurBbil(BBBody);
    TRAVERS_NODE(node->getBody())
    Prog->addInst(new TacInst({TacJmp, BBCond, nullptr, nullptr}));
    Prog->setCurBbil(BbThen);
}

void CodeGen::visit(AssignStatement *node) {
    TRAVERS_NODE(node->getLhs())
    auto t_lhs = T;
    TRAVERS_NODE(node->getRhs())
    auto t_rhs = T;
    Prog->addInst(new TacInst({TacAssign, t_lhs, t_rhs, nullptr}));
}


