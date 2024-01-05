#ifndef COMPILER_HOMEWORK_COMMON_H
#define COMPILER_HOMEWORK_COMMON_H

/// 每一个AST节点对应的枚举ID
enum NodeId {
    ProgramId,      // 整个程序
    ConstDeclId,    // 常量声明
    ConstDefId,     // 常量定义
    VarDeclId,      // 变量声明
    VarDefId,       // 变量定义
    UnaryExprId,    // 一元表达式
    BinExprId,      // 二元表达式
    IdentifierId,   // 标识符
    UnsignedIntId,  // 无符号整数
    IfStmtId,       // 条件语句
    WhileStmtId,    // 循环语句
    AssignStmtId,   // 赋值语句
    BlockStmtId,    // 复合语句
};


/// 操作符对应的枚举类型
enum Operator {
    Add = 20,           /* operator +   */
    Sub,                /* operator -   */
    Mul,                /* operator *   */
    Div,                /* operator /   */
    Eq,                 /* operator =  */
    Neq,                /* operator <>  */
    Gt,                 /* operator >   */
    Ge,                 /* operator >=  */
    Lt,                 /* operator <   */
    Le,                 /* operator <=  */
};


//// 对应的词法单元标识符
enum Token: int {
    TOK_EOF = -1,       // 文件结尾 EOF
    TOK_UNKNOWN = 0,    // 未知字符
    TOK_PROGRAM = 1,    // 关键字 PROGRAM
    TOK_BEGIN,          // 关键字 BEGIN
    TOK_END,            // 关键字 END
    TOK_CONST,          // 关键字 CONST
    TOK_VAR,            // 关键字 VAR
    TOK_WHILE,          // 关键字 WHILE
    TOK_DO,             // 关键字 DO
    TOK_IF,             // 关键字 IF
    TOK_THEN,           // 关键字 THEN
    TOK_ID,             // 标识符
    TOK_INT,            // 无符号整型
    TOK_ADD = 20,       // 运算符 +
    TOK_SUB,            // 运算符 -
    TOK_MUL,            // 运算符 *
    TOK_DIV,            // 运算符 /
    TOK_EQ,             // 运算符 =
    TOK_NE,             // 运算符 <>
    TOK_GT,             // 运算符 >
    TOK_GE,             // 运算符 >=
    TOK_LT,             // 运算符 <
    TOK_LE,             // 运算符 <=
    TOK_ASSIGN,         // 运算符 :=
    TOK_LPAREN,         // 符号 (
    TOK_RPAREN,         // 符号 )
    TOK_SEMI,           // 符号 ;
    TOK_COMMA           // 符号 ,
};

#define INSERT_ACCEPT void accept(AstVisitor &v) override { v.visit(this); }
#define INSERT_ENUM(X) NodeId getClassId() override { return X; } \
                       static NodeId classId() { return X; }
#define INSERT_ENUM_NAME(X) const char* getAstName() override {return #X;}

#define ADD_VISITOR_OVERRIDE(X) void visit(X *node) override;

#define ADD_VISITOR(X) virtual void visit(X *node);
#define ADD_VISITOR_OVERRIDE(X) void visit(X *node) override;

#define TRAVERS_NODE(X) if(X != nullptr) { X->accept(*this); }
#define TRAVERS_ARRAY(X) for(auto node : X) { if (node != nullptr) { node->accept(*this); } }

#endif //COMPILER_HOMEWORK_COMMON_H
