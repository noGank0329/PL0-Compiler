
// Generated from ./grammar/Grammar.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "GrammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by GrammarParser.
 */
class  GrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(GrammarParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(GrammarParser::ProgramContext *ctx) = 0;

  virtual void enterUnit(GrammarParser::UnitContext *ctx) = 0;
  virtual void exitUnit(GrammarParser::UnitContext *ctx) = 0;

  virtual void enterSub_program(GrammarParser::Sub_programContext *ctx) = 0;
  virtual void exitSub_program(GrammarParser::Sub_programContext *ctx) = 0;

  virtual void enterConst_var_declares(GrammarParser::Const_var_declaresContext *ctx) = 0;
  virtual void exitConst_var_declares(GrammarParser::Const_var_declaresContext *ctx) = 0;

  virtual void enterDef_const_var(GrammarParser::Def_const_varContext *ctx) = 0;
  virtual void exitDef_const_var(GrammarParser::Def_const_varContext *ctx) = 0;

  virtual void enterUnsigned_int(GrammarParser::Unsigned_intContext *ctx) = 0;
  virtual void exitUnsigned_int(GrammarParser::Unsigned_intContext *ctx) = 0;

  virtual void enterVar_declares(GrammarParser::Var_declaresContext *ctx) = 0;
  virtual void exitVar_declares(GrammarParser::Var_declaresContext *ctx) = 0;

  virtual void enterIdentifier(GrammarParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(GrammarParser::IdentifierContext *ctx) = 0;

  virtual void enterStatement_section(GrammarParser::Statement_sectionContext *ctx) = 0;
  virtual void exitStatement_section(GrammarParser::Statement_sectionContext *ctx) = 0;

  virtual void enterCompound_statements(GrammarParser::Compound_statementsContext *ctx) = 0;
  virtual void exitCompound_statements(GrammarParser::Compound_statementsContext *ctx) = 0;

  virtual void enterStatement(GrammarParser::StatementContext *ctx) = 0;
  virtual void exitStatement(GrammarParser::StatementContext *ctx) = 0;

  virtual void enterAssign_statement(GrammarParser::Assign_statementContext *ctx) = 0;
  virtual void exitAssign_statement(GrammarParser::Assign_statementContext *ctx) = 0;

  virtual void enterExpression(GrammarParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(GrammarParser::ExpressionContext *ctx) = 0;

  virtual void enterItem(GrammarParser::ItemContext *ctx) = 0;
  virtual void exitItem(GrammarParser::ItemContext *ctx) = 0;

  virtual void enterFactor(GrammarParser::FactorContext *ctx) = 0;
  virtual void exitFactor(GrammarParser::FactorContext *ctx) = 0;

  virtual void enterIf_statement(GrammarParser::If_statementContext *ctx) = 0;
  virtual void exitIf_statement(GrammarParser::If_statementContext *ctx) = 0;

  virtual void enterWhile_statement(GrammarParser::While_statementContext *ctx) = 0;
  virtual void exitWhile_statement(GrammarParser::While_statementContext *ctx) = 0;

  virtual void enterCond(GrammarParser::CondContext *ctx) = 0;
  virtual void exitCond(GrammarParser::CondContext *ctx) = 0;

  virtual void enterRelational_operators(GrammarParser::Relational_operatorsContext *ctx) = 0;
  virtual void exitRelational_operators(GrammarParser::Relational_operatorsContext *ctx) = 0;


};

