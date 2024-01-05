#ifndef COMPILER_HOMEWORK_PARSER_H
#define COMPILER_HOMEWORK_PARSER_H

#include "ast.h"
#include "GrammarBaseVisitor.h"
#include <unordered_map>

class Parser {
public:
    /// 一个虚函数，解析源文件，语法分析得到AST
    virtual Program *parse(const char *filepath) = 0;
};

/// 第二部分，借助ANTLR生成AST
class AntlrAstParser : public Parser, public GrammarBaseVisitor {
private:
    std::unordered_map<std::string, Identifier *> NameToIdMap;

private:
    Identifier *getId(const std::string& name);
public:
    Program *parse(const char* filepath) override;

public:
    antlrcpp::Any visitProgram(GrammarParser::ProgramContext *ctx) override;
    antlrcpp::Any visitUnit(GrammarParser::UnitContext *ctx) override;
    antlrcpp::Any visitSub_program(GrammarParser::Sub_programContext *ctx) override;
    antlrcpp::Any visitConst_var_declares(GrammarParser::Const_var_declaresContext *ctx) override;
    antlrcpp::Any visitDef_const_var(GrammarParser::Def_const_varContext *ctx) override;
    antlrcpp::Any visitUnsigned_int(GrammarParser::Unsigned_intContext *ctx) override;
    antlrcpp::Any visitVar_declares(GrammarParser::Var_declaresContext *ctx) override;
    antlrcpp::Any visitIdentifier(GrammarParser::IdentifierContext *ctx) override;
    antlrcpp::Any visitStatement_section(GrammarParser::Statement_sectionContext *ctx) override;
    antlrcpp::Any visitCompound_statements(GrammarParser::Compound_statementsContext *ctx) override;
    antlrcpp::Any visitStatement(GrammarParser::StatementContext *ctx) override;
    antlrcpp::Any visitAssign_statement(GrammarParser::Assign_statementContext *ctx) override;
    antlrcpp::Any visitExpression(GrammarParser::ExpressionContext *ctx) override;
    antlrcpp::Any visitItem(GrammarParser::ItemContext *ctx) override;
    antlrcpp::Any visitFactor(GrammarParser::FactorContext *ctx) override;
    antlrcpp::Any visitIf_statement(GrammarParser::If_statementContext *ctx) override;
    antlrcpp::Any visitWhile_statement(GrammarParser::While_statementContext *ctx) override;
    antlrcpp::Any visitCond(GrammarParser::CondContext *ctx) override;
    antlrcpp::Any visitRelational_operators(GrammarParser::Relational_operatorsContext *ctx) override;
};

/***
 * 手写的词法语法分析器
 * 采用LL(n)分析算法
 */
class CommonAstParser : public Parser{
private:
    unsigned int Line;      ///< 行信息
    unsigned int Col;       ///< 列信息
    unsigned int Num;       ///< 存储词法分析器识别到的无符号整数的值
    std::string Id;         ///< 存储识别到的标识符对应的字符串
    std::ifstream Fp;       ///< 文件流对象
    char LastChar;          ///< 词法分析器用到的一个记录变量
    Token CurToken;         ///< 当前TOKEN
public:
    explicit CommonAstParser();
public:
    Program * parse(const char *filepath) override;
public:
    /// 语法分析器的部分，分析语法规则，构建对应的AST
    /// 下面的注释的语法糖声明
    ///     1. ? 表示匹配0次或1次
    ///     2. + 表示匹配1次或多次
    ///     3. * 表示匹配0次或多次
    ///     4. | 表示或
    ///     5. () 表示一个匹配组
    /// 下面是具体的文法解析对应的函数定义，每个函数解析一条或多条规则
    /// 并不是纯粹的一个函数对应一条规则，因为有些规则并不是可以对应一个
    /// AST节点的，比如程序首部，它可以直接归纳到Program这个AST节点中
    /// 并不需要为他单独定义一个AST节点。所以基于这样的一种考虑，一个解析
    /// 函数就有可能对应N的规则


    /// @brief: Program :-> PROGRAM ID SubProgram
    ///         SubProgram :-> ConstDecl? VarDecl? Statement
    Program *parseProgram();
    /// @brief: ConstDecl :-> ID EQ INT (COMMA ID EQ INT)* SEMI
    ConstDecl *parseConstDecl();
    /// @brief: VarDecl :-> ID (COMMA ID)* SEMI
    VarDecl *parseVarDecl();
    /// @brief: Statement :-> AssignStmt
    ///                   |   CondStmt
    ///                   |   WhileStmt
    ///                   |   BlockStmt
    ///                   |   SEMI
    Node *parseStatement();
    /// @brief: AssignStmt :-> ID ASSIGN Expr SEMI
    Node *parseAssignStmt();
    /// @brief: Expr :-> (ADD | SUB) Item
    ///              |   Item (ADD | SUB) Item
    Node *parseExpr();
    /// @brief: Item :-> Factor
    ///              |   Factor (MUL | DIV) Factor
    Node *parseItem();
    /// @brief: Factor :-> ID
    ///                |   INT
    ///                |   LPAREN Expr RPAREN
    Node *parseFactor();
    /// @brief: CondStmt :-> IF Cond THEN Statement
    Node *parseCondStmt();
    /// @brief: WhileStmt :-> WHILE Cond DO Statement
    Node *parseWhileStmt();
    /// @brief: Cond :-> Expr (EQ | NE | LE | LT | GE | GT) Expr
    Node *parseCond();
    /// @brief: BlockStmt :-> BEGIN Statement (Statement)* END
    Node *parseBlockStmt();

private:
    /// 词法分析器的部分，负责解析词法单元
    /// @brief: 读取一个Token
    Token getToken();
    /// @brief: 向前看N个Token
    std::vector<Token> lookUp(unsigned int);
    /// @brief: 获取一个字符
    void getChar();
    /// @brief: 获取下一个TOKEN
    void getNextToken();
private:
    /// @brief: 获取TOKEN运算符对应的Operator
    Operator getOpByToken(Token tk) const;
};


#endif //COMPILER_HOMEWORK_PARSER_H
