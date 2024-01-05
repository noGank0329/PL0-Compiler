#include "parser.h"
#include "GrammarLexer.h"
#include "GrammarParser.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <tuple>

Identifier *AntlrAstParser::getId(const std::string &name) {
    if(NameToIdMap.find(name) == NameToIdMap.end()) {
        NameToIdMap.insert({name, new Identifier(name)});
    }
    return NameToIdMap[name];
}

Program *AntlrAstParser::parse(const char *filepath) {
    std::string code;
    std::stringstream ss;
    std::ifstream in{filepath};

    if(!in.is_open()) {
        std::cout << "Could not open file " << filepath << std::endl;
        return nullptr;
    }

    while (getline(in, code)) {
        ss << code << "\n";
    }

    in.close();

    antlr4::ANTLRInputStream input(ss.str());

    // 词法分析
    GrammarLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);
    // 语法分析
    GrammarParser parser(&tokens);

    auto comp_unit = parser.program();

    if (parser.getNumberOfSyntaxErrors()) {
        std::cerr << "Error! parser error! program exit with code -1" << std::endl;
        return nullptr;
    }

    // AST构造
    return visitProgram(comp_unit).as<Program *>();
}

antlrcpp::Any AntlrAstParser::visitProgram(GrammarParser::ProgramContext *ctx) {
    return visitUnit(ctx->unit()).as<Program *>();
}

antlrcpp::Any AntlrAstParser::visitUnit(GrammarParser::UnitContext *ctx) {
    auto *prog = new Program(ctx->identifier()->getText());
    auto [t1, t2, t3] = visitSub_program(ctx->sub_program()).as<std::tuple<ConstDecl *, VarDecl *, Node *>>();
    prog->setCDecl(t1);
    prog->setVDecl(t2);
    prog->setStmt(t3);
    return prog;
}

antlrcpp::Any AntlrAstParser::visitSub_program(GrammarParser::Sub_programContext *ctx) {
    ConstDecl *t1 = nullptr;
    VarDecl *t2 = nullptr;
    Node *t3;
    if(ctx->const_var_declares()) {
        t1 = visitConst_var_declares(ctx->const_var_declares());
    }
    if (ctx->var_declares()) {
        t2 = visitVar_declares(ctx->var_declares());
    }
    t3 = visitStatement_section(ctx->statement_section());
    return std::tuple<ConstDecl *, VarDecl *, Node *>(t1, t2, t3);
}

antlrcpp::Any AntlrAstParser::visitConst_var_declares(GrammarParser::Const_var_declaresContext *ctx) {
    auto *decl = new ConstDecl();
    for (auto const_def : ctx->def_const_var()) {
        decl->addConstDef(visitDef_const_var(const_def).as<ConstDef *>());
    }
    return decl;
}

antlrcpp::Any AntlrAstParser::visitDef_const_var(GrammarParser::Def_const_varContext *ctx) {
    auto def = new ConstDef();
    def->id = visitIdentifier(ctx->identifier()).as<Identifier *>();
    def->value = visitUnsigned_int(ctx->unsigned_int()).as<unsigned long>();
    return def;
}

antlrcpp::Any AntlrAstParser::visitUnsigned_int(GrammarParser::Unsigned_intContext *ctx) {
    return std::stoul(ctx->getText());
}

antlrcpp::Any AntlrAstParser::visitVar_declares(GrammarParser::Var_declaresContext *ctx) {
    auto decl = new VarDecl();
    for (auto var_def : ctx->identifier()) {
        decl->addVarDef(visitIdentifier(var_def).as<Identifier *>());
    }
    return decl;
}

antlrcpp::Any AntlrAstParser::visitIdentifier(GrammarParser::IdentifierContext *ctx) {
    return getId(ctx->getText());
}

antlrcpp::Any AntlrAstParser::visitStatement_section(GrammarParser::Statement_sectionContext *ctx) {
    if(ctx->statement()) {
        return visitStatement(ctx->statement()).as<Node *>();
    }
    else {
        return visitCompound_statements(ctx->compound_statements()).as<Node *>();
    }
}

antlrcpp::Any AntlrAstParser::visitCompound_statements(GrammarParser::Compound_statementsContext *ctx) {
    auto block = new BlockStatement();
    for (auto stmt : ctx->statement()) {
        block->addStmt(visitStatement(stmt).as<Node *>());
    }
    return dynamic_cast<Node *>(block);
}

antlrcpp::Any AntlrAstParser::visitStatement(GrammarParser::StatementContext *ctx) {
    if(ctx->assign_statement()) {
        return visitAssign_statement(ctx->assign_statement()).as<Node *>();
    }
    else if(ctx->if_statement()) {
        return visitIf_statement(ctx->if_statement()).as<Node *>();
    }
    else if(ctx->while_statement()) {
        return visitWhile_statement(ctx->while_statement()).as<Node *>();
    }
    else if(ctx->compound_statements()) {
        return visitCompound_statements(ctx->compound_statements()).as<Node *>();
    }
    return nullptr;
}

antlrcpp::Any AntlrAstParser::visitAssign_statement(GrammarParser::Assign_statementContext *ctx) {
    auto assign = new AssignStatement(
                visitIdentifier(ctx->identifier()).as<Identifier *>(),
                visitExpression(ctx->expression()).as<Node *>()
            );
    return dynamic_cast<Node *>(assign);
}


antlrcpp::Any AntlrAstParser::visitExpression(GrammarParser::ExpressionContext *ctx) {
    Node *expr;
    if(ctx->expression()) {
        if (ctx->Add()) {
            expr = new BinaryExpr(Add, visitExpression(ctx->expression()).as<Node *>(), visitItem(ctx->item()).as<Node *>());
        }
        else {
            expr = new BinaryExpr(Sub, visitExpression(ctx->expression()).as<Node *>(), visitItem(ctx->item()).as<Node *>());
        }
    }
    else {
        if(ctx->Sub()) {
            expr = new UnaryExpr(Sub, visitItem(ctx->item()).as<Node *>());
        }
        else {
            expr = visitItem(ctx->item()).as<Node *>();
        }
    }
    return expr;
}

antlrcpp::Any AntlrAstParser::visitItem(GrammarParser::ItemContext *ctx) {
    Node *expr;
    if(ctx->item()) {
        if (ctx->Mul()) {
            expr = new BinaryExpr(Mul, visitItem(ctx->item()).as<Node *>(), visitFactor(ctx->factor()).as<Node *>());
        }
        else {
            expr = new BinaryExpr(Div, visitItem(ctx->item()).as<Node *>(), visitFactor(ctx->factor()).as<Node *>());;
        }
    }
    else {
        expr = visitFactor(ctx->factor()).as<Node *>();
    }
    return expr;
}

antlrcpp::Any AntlrAstParser::visitFactor(GrammarParser::FactorContext *ctx) {
    Node *expr;
    if(ctx->identifier()) {
        expr = visitIdentifier(ctx->identifier()).as<Identifier *>();
    }
    else if(ctx->unsigned_int()) {
        expr = new UInt(visitUnsigned_int(ctx->unsigned_int()).as<unsigned long>());
    }
    else {
        expr = visitExpression(ctx->expression()).as<Node *>();
    }
    return expr;
}

antlrcpp::Any AntlrAstParser::visitIf_statement(GrammarParser::If_statementContext *ctx) {
    Node *if_stmt = new IfStatement(
            visitCond(ctx->cond()).as<Node *>(),
            visitStatement(ctx->statement()).as<Node *>()
            );
    return if_stmt;
}

antlrcpp::Any AntlrAstParser::visitWhile_statement(GrammarParser::While_statementContext *ctx) {
    Node *while_stmt = new WhileStatement(
            visitCond(ctx->cond()).as<Node *>(),
            visitStatement(ctx->statement()).as<Node *>()
            );
    return while_stmt;
}

antlrcpp::Any AntlrAstParser::visitCond(GrammarParser::CondContext *ctx) {
    Node *expr = new BinaryExpr(
            visitRelational_operators(ctx->relational_operators()).as<Operator>(),
            visitExpression(ctx->expression(0)).as<Node *>(),
            visitExpression(ctx->expression(1)).as<Node *>()
            );
    return expr;
}

antlrcpp::Any AntlrAstParser::visitRelational_operators(GrammarParser::Relational_operatorsContext *ctx) {
    if (ctx->Eq()) {
        return Eq;
    }
    else if(ctx->LtGt()) {
        return Neq;
    }
    else if(ctx->Lt()) {
        return Lt;
    }
    else if(ctx->Gt()) {
        return Gt;
    }
    else if(ctx->Le()) {
        return Le;
    }
    else {
        return Ge;
    }
}


