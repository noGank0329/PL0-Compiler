
// Generated from ./grammar/Grammar.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "GrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by GrammarParser.
 */
class  GrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by GrammarParser.
   */
    virtual antlrcpp::Any visitProgram(GrammarParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitUnit(GrammarParser::UnitContext *context) = 0;

    virtual antlrcpp::Any visitSub_program(GrammarParser::Sub_programContext *context) = 0;

    virtual antlrcpp::Any visitConst_var_declares(GrammarParser::Const_var_declaresContext *context) = 0;

    virtual antlrcpp::Any visitDef_const_var(GrammarParser::Def_const_varContext *context) = 0;

    virtual antlrcpp::Any visitUnsigned_int(GrammarParser::Unsigned_intContext *context) = 0;

    virtual antlrcpp::Any visitVar_declares(GrammarParser::Var_declaresContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(GrammarParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitStatement_section(GrammarParser::Statement_sectionContext *context) = 0;

    virtual antlrcpp::Any visitCompound_statements(GrammarParser::Compound_statementsContext *context) = 0;

    virtual antlrcpp::Any visitStatement(GrammarParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitAssign_statement(GrammarParser::Assign_statementContext *context) = 0;

    virtual antlrcpp::Any visitExpression(GrammarParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitItem(GrammarParser::ItemContext *context) = 0;

    virtual antlrcpp::Any visitFactor(GrammarParser::FactorContext *context) = 0;

    virtual antlrcpp::Any visitIf_statement(GrammarParser::If_statementContext *context) = 0;

    virtual antlrcpp::Any visitWhile_statement(GrammarParser::While_statementContext *context) = 0;

    virtual antlrcpp::Any visitCond(GrammarParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitRelational_operators(GrammarParser::Relational_operatorsContext *context) = 0;


};

