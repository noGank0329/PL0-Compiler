
// Generated from ./grammar/Grammar.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "GrammarVisitor.h"


/**
 * This class provides an empty implementation of GrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  GrammarBaseVisitor : public GrammarVisitor {
public:

  virtual antlrcpp::Any visitProgram(GrammarParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnit(GrammarParser::UnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSub_program(GrammarParser::Sub_programContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_var_declares(GrammarParser::Const_var_declaresContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDef_const_var(GrammarParser::Def_const_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsigned_int(GrammarParser::Unsigned_intContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_declares(GrammarParser::Var_declaresContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(GrammarParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_section(GrammarParser::Statement_sectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_statements(GrammarParser::Compound_statementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(GrammarParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign_statement(GrammarParser::Assign_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(GrammarParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitItem(GrammarParser::ItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(GrammarParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_statement(GrammarParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_statement(GrammarParser::While_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond(GrammarParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelational_operators(GrammarParser::Relational_operatorsContext *ctx) override {
    return visitChildren(ctx);
  }


};

