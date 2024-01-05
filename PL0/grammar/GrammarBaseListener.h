
// Generated from ./grammar/Grammar.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "GrammarListener.h"


/**
 * This class provides an empty implementation of GrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GrammarBaseListener : public GrammarListener {
public:

  virtual void enterProgram(GrammarParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(GrammarParser::ProgramContext * /*ctx*/) override { }

  virtual void enterUnit(GrammarParser::UnitContext * /*ctx*/) override { }
  virtual void exitUnit(GrammarParser::UnitContext * /*ctx*/) override { }

  virtual void enterSub_program(GrammarParser::Sub_programContext * /*ctx*/) override { }
  virtual void exitSub_program(GrammarParser::Sub_programContext * /*ctx*/) override { }

  virtual void enterConst_var_declares(GrammarParser::Const_var_declaresContext * /*ctx*/) override { }
  virtual void exitConst_var_declares(GrammarParser::Const_var_declaresContext * /*ctx*/) override { }

  virtual void enterDef_const_var(GrammarParser::Def_const_varContext * /*ctx*/) override { }
  virtual void exitDef_const_var(GrammarParser::Def_const_varContext * /*ctx*/) override { }

  virtual void enterUnsigned_int(GrammarParser::Unsigned_intContext * /*ctx*/) override { }
  virtual void exitUnsigned_int(GrammarParser::Unsigned_intContext * /*ctx*/) override { }

  virtual void enterVar_declares(GrammarParser::Var_declaresContext * /*ctx*/) override { }
  virtual void exitVar_declares(GrammarParser::Var_declaresContext * /*ctx*/) override { }

  virtual void enterIdentifier(GrammarParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(GrammarParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterStatement_section(GrammarParser::Statement_sectionContext * /*ctx*/) override { }
  virtual void exitStatement_section(GrammarParser::Statement_sectionContext * /*ctx*/) override { }

  virtual void enterCompound_statements(GrammarParser::Compound_statementsContext * /*ctx*/) override { }
  virtual void exitCompound_statements(GrammarParser::Compound_statementsContext * /*ctx*/) override { }

  virtual void enterStatement(GrammarParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(GrammarParser::StatementContext * /*ctx*/) override { }

  virtual void enterAssign_statement(GrammarParser::Assign_statementContext * /*ctx*/) override { }
  virtual void exitAssign_statement(GrammarParser::Assign_statementContext * /*ctx*/) override { }

  virtual void enterExpression(GrammarParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(GrammarParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterItem(GrammarParser::ItemContext * /*ctx*/) override { }
  virtual void exitItem(GrammarParser::ItemContext * /*ctx*/) override { }

  virtual void enterFactor(GrammarParser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(GrammarParser::FactorContext * /*ctx*/) override { }

  virtual void enterIf_statement(GrammarParser::If_statementContext * /*ctx*/) override { }
  virtual void exitIf_statement(GrammarParser::If_statementContext * /*ctx*/) override { }

  virtual void enterWhile_statement(GrammarParser::While_statementContext * /*ctx*/) override { }
  virtual void exitWhile_statement(GrammarParser::While_statementContext * /*ctx*/) override { }

  virtual void enterCond(GrammarParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(GrammarParser::CondContext * /*ctx*/) override { }

  virtual void enterRelational_operators(GrammarParser::Relational_operatorsContext * /*ctx*/) override { }
  virtual void exitRelational_operators(GrammarParser::Relational_operatorsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

