#ifndef COMPILER_HOMEWORK_AST_H
#define COMPILER_HOMEWORK_AST_H

#include "common.h"
#include "ast_visitor.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Identifier;

/// AST的根节点
class Node {

protected:

    
public:
    virtual void accept(AstVisitor &v) = 0;

public:
    Node() = default;

public:
    virtual NodeId getClassId() = 0;
};

class ConstDecl;
class ConstDef;
class VarDecl;

///Program的AST
class Program : public Node {
private:
    std::string ProgName;
    ConstDecl *CDecl = nullptr;
    VarDecl   *VDecl = nullptr;
    Node      *Stmt = nullptr;
public:
    INSERT_ENUM(ProgramId)
    INSERT_ACCEPT
public:
    explicit Program(const std::string& name) : Node(), ProgName(name) {}

    ConstDecl *getCDecl() const {
        return CDecl;
    }

    void setCDecl(ConstDecl *cDecl) {
        CDecl = cDecl;
    }

    VarDecl *getVDecl() const {
        return VDecl;
    }

    void setVDecl(VarDecl *vDecl) {
        VDecl = vDecl;
    }

    Node *getStmt() const {
        return Stmt;
    }

    void setStmt(Node *stmt) {
        Stmt = stmt;
    }

    const std::string &getProgName() const {
        return ProgName;
    }

    void setProgName(const std::string &progName) {
        ProgName = progName;
    }
};

/// 常量声明
class ConstDecl : public Node {
private:
    std::unordered_map<std::string, ConstDef *> ConstDefs;
public:
    ConstDecl() : Node() {}
public:
    INSERT_ENUM(ConstDeclId)
    INSERT_ACCEPT

    const std::unordered_map<std::string, ConstDef *> &getConstDefs() const {
        return ConstDefs;
    }

    void setConstDefs(const std::unordered_map<std::string, ConstDef *> &constDefs) {
        ConstDefs = constDefs;
    }

    void addConstDef(ConstDef *def);

    ConstDef *getConstDef(Identifier *);
};

/// 常量定义
struct ConstDef {
    Identifier *id;
    unsigned long value;
};

/// 变量声明
class VarDecl : public Node {
private:
    std::unordered_map<std::string, Identifier *> VarDefs;
public:
    VarDecl() : Node() {}
public:
    INSERT_ENUM(VarDeclId)
    INSERT_ACCEPT

    const std::unordered_map<std::string, Identifier *> &getVarDefs() const {
        return VarDefs;
    }

    void setVarDefs(const std::unordered_map<std::string, Identifier *> &varDefs) {
        VarDefs = varDefs;
    }

    void addVarDef(Identifier *id);

    bool hasThisVarDef(Identifier *id);
};

/// 一元表达式
class UnaryExpr : public Node {
private:
    Operator  Op;
    Node *Expr;
public:
    INSERT_ENUM(UnaryExprId)
    INSERT_ACCEPT
public:
    UnaryExpr(Operator op, Node *expr)
     : Node(), Op(op), Expr(expr)
    {}

    void setOperator    (Operator op)   { this->Op = op; }
    void setUnaryExpr   (Node *expr) { this->Expr = expr; }

    Operator getExprOp   () const { return Op; }
    Node *getUnaryExpr()       { return Expr; }
};

/// 二元表达式
class BinaryExpr : public Node {
private:
    Operator  Op;            // T <== The operator of the expression
    Node  *Lhs;
    Node  *Rhs;
public:
    INSERT_ENUM(BinExprId)
    INSERT_ACCEPT
public:
    BinaryExpr(Operator op, Node *lhs, Node *rhs)
        : Node(), Op(op), Lhs(lhs), Rhs(rhs) {}

    void setOperator(Operator op)      { Op = op; }
    void setLhs     (Node *lhs)     { Lhs = lhs; }
    void setRhs     (Node *rhs)     { Rhs = rhs; }

    Operator  getExprOp () const { return Op; }
    Node  *getLhs    ()       { return Lhs; }
    Node  *getRhs    ()       { return Rhs; }

};

/// 标识符
class Identifier : public Node {
private:
    std::string Id;
public:
    INSERT_ENUM(IdentifierId)
    INSERT_ACCEPT
public:
    Identifier(const std::string &id)
        : Node(), Id(id) {}

    const std::string &getId() const {
        return Id;
    }

    void setId(const std::string &id) {
        Id = id;
    }
};

/// 无符号整形AST节点
class UInt : public Node {
private:
    unsigned long Num;
public:
    INSERT_ENUM(UnsignedIntId)
    INSERT_ACCEPT
public:
    UInt(unsigned long num)
            : Node(), Num(num) {}

    unsigned long getNum() const {
        return Num;
    }

    void setNum(unsigned long num) {
        Num = num;
    }
};


/// 条件语句
class IfStatement : public Node {
private:
    Node *Cond;
    Node *Then;
public:
    INSERT_ENUM(IfStmtId)
    INSERT_ACCEPT
public:
    IfStatement() = default;
    IfStatement(Node *cond, Node *stmt)
        : Cond(cond), Then(stmt) {}
public:
    Node *getCond() const {
        return Cond;
    }

    void setCond(Node *cond) {
        Cond = cond;
    }

    Node *getThen() const {
        return Then;
    }

    void setThen(Node *then) {
        Then = then;
    }
};

/// 循环语句
class WhileStatement : public Node {
private:
    Node *Cond;
    Node *Body;
public:
    INSERT_ENUM(WhileStmtId)
    INSERT_ACCEPT
public:
    WhileStatement() = default;
    WhileStatement(Node *cond, Node *stmt)
            : Cond(cond), Body(stmt) {}

    Node *getCond() const {
        return Cond;
    }

    void setCond(Node *cond) {
        Cond = cond;
    }

    Node *getBody() const {
        return Body;
    }

    void setBody(Node *body) {
        Body = body;
    }

};

/// 赋值语句
class AssignStatement : public Node {
private:
    Identifier  *Lhs;
    Node  *Rhs;
public:
    INSERT_ENUM(AssignStmtId)
    INSERT_ACCEPT
public:
    AssignStatement(Identifier *lhs, Node *rhs)
            : Node(), Lhs(lhs), Rhs(rhs) {}

    void setLhs     (Identifier *lhs)     { Lhs = lhs; }
    void setRhs     (Node *rhs)     { Rhs = rhs; }

    Identifier  *getLhs    ()       { return Lhs; }
    Node  *getRhs    ()       { return Rhs; }

};

/// 复合语句
class BlockStatement : public Node {
private:
    std::vector<Node *> Stmts;
public:
    INSERT_ENUM(BlockStmtId)
    INSERT_ACCEPT
public:
    explicit BlockStatement() : Node() {}
public:
    const std::vector<Node *> &getStmts() const {
        return Stmts;
    }

    void setStmts(const std::vector<Node *> &stmts) {
        Stmts = stmts;
    }

    void addStmt(Node *stmt) {
        if (stmt == nullptr) return;
        Stmts.push_back(stmt);
    }
};


#endif //COMPILER_HOMEWORK_AST_H
