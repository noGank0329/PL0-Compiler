#ifndef COMPILER_HOMEWORK_TAC_DEFINE_H
#define COMPILER_HOMEWORK_TAC_DEFINE_H

#include <string>
#include <vector>

/// 三地址码指令定义
enum TacOpType {
    TacAdd = 20,    /// +
    TacSub = 21,    /// -
    TacMul = 22,    /// *
    TacDiv = 23,    /// /
    TacEq = 24 ,    /// ==
    TacNeq = 25,    /// !=
    TacGt = 26,     /// >
    TacGe = 27,     /// >=
    TacLt = 28,     /// <
    TacLe = 29,     /// <=
    TacAssign,      /// =
    TacCondJmp,     /// cond jmp
    TacJmp,         /// jmp
};

class Op;

/// 三地址码指令
struct TacInst {
    TacOpType TacOp;   ///< 三地址码操作符类型
    Op        *Op1;    ///< 操作数1
    Op        *Op2;    ///< 操作数2
    Op        *Op3;    ///< 操作数3

public:
    /// 获取三地址码指令的字符串类型
    std::string toString();
};


/// 操作数基类
class Op {
public:
    /// 获取操作符的类型
    virtual std::string toString() = 0;
};

/// 虚拟寄存器
class Reg : public Op {
    static unsigned int RetIndex;
    unsigned int Idx;
public:
    Reg();
    std::string toString() override;
};

/// 变量名
class Var : public Op {
private:
    std::string name;
public:
    explicit Var(const std::string& n) : name(n) {}
public:
    std::string toString() override;
};

/// 立即数
class Imm : public Op {
private:
    unsigned int ImmValue;
public:
    explicit Imm(unsigned int i);

    std::string toString() override;
};

/// 基本块:
class Bblk : public Op {
    friend class TacProg;
private:
    std::string label_name;
    std::vector<TacInst *> insts;
public:
    explicit Bblk(const std::string &n) : label_name(n), insts() {}
public:
    std::string toString() override;
};


class TacProg {
private:
    std::vector<Bblk *> BbLists;   /// 指令列表
    Bblk *CurBblk;
    unsigned int Index;
public:
    /// 程序
    TacProg();
    /// 添加新的基本块
    Bblk *getNewBblk();
    /// 添加指令
    void addInst(TacInst *inst);
    /// 设置当前Bblk
    void setCurBbil(Bblk *blk);
    /// 获取当前Bblk
    Bblk *getCurBbil();
    /// 将三地址码程序写入到文件
    void dumpInstToFile(const char* filepath);
};

/// 变量







#endif //COMPILER_HOMEWORK_TAC_DEFINE_H
