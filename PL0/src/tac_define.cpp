#include "tac_define.h"
#include <iostream>
#include <fstream>
#include <map>

/// ---------------------------------------------------------------- ///
static std::map<TacOpType, std::string> OpToStr = {
        {TacAdd, "+"}, {TacSub, "-"}, {TacMul, "*"}, {TacDiv, "/"},
        {TacEq, "=="}, {TacNeq, "!="}, {TacGt, ">"}, {TacGe, ">="},
        {TacLt, "<"}, {TacLe, "<="}, {TacAssign, "="}, {TacCondJmp, "cjmp"},
        {TacJmp, "jmp"}
};

std::string TacInst::toString() {
    std::string inst;
    inst.append("(");
    inst.append(OpToStr[TacOp]);
    inst.append(" ,");

    if(Op1 == nullptr) {
        inst.append("_");
    }
    else {
        inst.append(Op1->toString());
    }
    inst.append(" ,");

    if(Op2 == nullptr) {
        inst.append("_");
    }
    else {
        inst.append(Op2->toString());
    }
    inst.append(" ,");

    if(Op3 == nullptr) {
        inst.append("_");
    }
    else {
        inst.append(Op3->toString());
    }
    inst.append(")");
    inst.append(";");

    return inst;
}
/// ---------------------------------------------------------------- ///


/// ---------------------------------------------------------------- ///
unsigned int Reg::RetIndex = 0;

Reg::Reg() : Idx(RetIndex++) {}

std::string Reg::toString() {
    return "_T" + std::to_string(Idx);
}
/// ---------------------------------------------------------------- ///


/// ---------------------------------------------------------------- ///
Imm::Imm(unsigned int i) : ImmValue(i) {}

std::string Imm::toString() { return std::to_string(ImmValue); }
/// ---------------------------------------------------------------- ///


/// ---------------------------------------------------------------- ///
std::string Var::toString() { return name; }
/// ---------------------------------------------------------------- ///


/// ---------------------------------------------------------------- ///
std::string Bblk::toString() { return label_name; }
/// ---------------------------------------------------------------- ///


/// ---------------------------------------------------------------- ///
TacProg::TacProg() : Index(0), CurBblk(nullptr) {}

Bblk *TacProg::getNewBblk() {
    auto bblk = new Bblk(std::string("BB") + std::to_string(Index++));
    BbLists.push_back(bblk);
    return bblk;
}

void TacProg::addInst(TacInst *inst) {
    CurBblk->insts.push_back(inst);
}

void TacProg::setCurBbil(Bblk *blk) {
    CurBblk = blk;
}

Bblk *TacProg::getCurBbil() {
    return CurBblk;
}

void TacProg::dumpInstToFile(const char *filepath) {
    std::ofstream out{filepath, std::ios::trunc};
    if (!out.is_open()) {
        std::cerr << "Can not open file" << filepath << std::endl;
        exit(1);
    }
    for (auto bblk : BbLists) {
        out << bblk->label_name << ":\n";
        for (auto inst : bblk->insts) {
            out << "\t" << inst->toString() << "\n";
        }
    }
}
/// ---------------------------------------------------------------- ///


