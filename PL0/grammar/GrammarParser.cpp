
// Generated from ./grammar/Grammar.g4 by ANTLR 4.8


#include "GrammarListener.h"
#include "GrammarVisitor.h"

#include "GrammarParser.h"


using namespace antlrcpp;
using namespace antlr4;

GrammarParser::GrammarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

GrammarParser::~GrammarParser() {
  delete _interpreter;
}

std::string GrammarParser::getGrammarFileName() const {
  return "Grammar.g4";
}

const std::vector<std::string>& GrammarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& GrammarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

GrammarParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::UnitContext* GrammarParser::ProgramContext::unit() {
  return getRuleContext<GrammarParser::UnitContext>(0);
}


size_t GrammarParser::ProgramContext::getRuleIndex() const {
  return GrammarParser::RuleProgram;
}

void GrammarParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void GrammarParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any GrammarParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::ProgramContext* GrammarParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, GrammarParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    unit();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

GrammarParser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::UnitContext::Program() {
  return getToken(GrammarParser::Program, 0);
}

GrammarParser::IdentifierContext* GrammarParser::UnitContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::Sub_programContext* GrammarParser::UnitContext::sub_program() {
  return getRuleContext<GrammarParser::Sub_programContext>(0);
}


size_t GrammarParser::UnitContext::getRuleIndex() const {
  return GrammarParser::RuleUnit;
}

void GrammarParser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void GrammarParser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}


antlrcpp::Any GrammarParser::UnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitUnit(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::UnitContext* GrammarParser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 2, GrammarParser::RuleUnit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(40);
    match(GrammarParser::Program);
    setState(41);
    identifier();
    setState(42);
    sub_program();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sub_programContext ------------------------------------------------------------------

GrammarParser::Sub_programContext::Sub_programContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Statement_sectionContext* GrammarParser::Sub_programContext::statement_section() {
  return getRuleContext<GrammarParser::Statement_sectionContext>(0);
}

GrammarParser::Const_var_declaresContext* GrammarParser::Sub_programContext::const_var_declares() {
  return getRuleContext<GrammarParser::Const_var_declaresContext>(0);
}

GrammarParser::Var_declaresContext* GrammarParser::Sub_programContext::var_declares() {
  return getRuleContext<GrammarParser::Var_declaresContext>(0);
}


size_t GrammarParser::Sub_programContext::getRuleIndex() const {
  return GrammarParser::RuleSub_program;
}

void GrammarParser::Sub_programContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSub_program(this);
}

void GrammarParser::Sub_programContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSub_program(this);
}


antlrcpp::Any GrammarParser::Sub_programContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitSub_program(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::Sub_programContext* GrammarParser::sub_program() {
  Sub_programContext *_localctx = _tracker.createInstance<Sub_programContext>(_ctx, getState());
  enterRule(_localctx, 4, GrammarParser::RuleSub_program);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::Const) {
      setState(44);
      const_var_declares();
    }
    setState(48);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::Var) {
      setState(47);
      var_declares();
    }
    setState(50);
    statement_section();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_var_declaresContext ------------------------------------------------------------------

GrammarParser::Const_var_declaresContext::Const_var_declaresContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Const_var_declaresContext::Const() {
  return getToken(GrammarParser::Const, 0);
}

std::vector<GrammarParser::Def_const_varContext *> GrammarParser::Const_var_declaresContext::def_const_var() {
  return getRuleContexts<GrammarParser::Def_const_varContext>();
}

GrammarParser::Def_const_varContext* GrammarParser::Const_var_declaresContext::def_const_var(size_t i) {
  return getRuleContext<GrammarParser::Def_const_varContext>(i);
}

tree::TerminalNode* GrammarParser::Const_var_declaresContext::Semi() {
  return getToken(GrammarParser::Semi, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::Const_var_declaresContext::Comma() {
  return getTokens(GrammarParser::Comma);
}

tree::TerminalNode* GrammarParser::Const_var_declaresContext::Comma(size_t i) {
  return getToken(GrammarParser::Comma, i);
}


size_t GrammarParser::Const_var_declaresContext::getRuleIndex() const {
  return GrammarParser::RuleConst_var_declares;
}

void GrammarParser::Const_var_declaresContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_var_declares(this);
}

void GrammarParser::Const_var_declaresContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_var_declares(this);
}


antlrcpp::Any GrammarParser::Const_var_declaresContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitConst_var_declares(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::Const_var_declaresContext* GrammarParser::const_var_declares() {
  Const_var_declaresContext *_localctx = _tracker.createInstance<Const_var_declaresContext>(_ctx, getState());
  enterRule(_localctx, 6, GrammarParser::RuleConst_var_declares);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(GrammarParser::Const);
    setState(53);
    def_const_var();
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::Comma) {
      setState(54);
      match(GrammarParser::Comma);
      setState(55);
      def_const_var();
      setState(60);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(61);
    match(GrammarParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Def_const_varContext ------------------------------------------------------------------

GrammarParser::Def_const_varContext::Def_const_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::IdentifierContext* GrammarParser::Def_const_varContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

tree::TerminalNode* GrammarParser::Def_const_varContext::Eq() {
  return getToken(GrammarParser::Eq, 0);
}

GrammarParser::Unsigned_intContext* GrammarParser::Def_const_varContext::unsigned_int() {
  return getRuleContext<GrammarParser::Unsigned_intContext>(0);
}


size_t GrammarParser::Def_const_varContext::getRuleIndex() const {
  return GrammarParser::RuleDef_const_var;
}

void GrammarParser::Def_const_varContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDef_const_var(this);
}

void GrammarParser::Def_const_varContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDef_const_var(this);
}


antlrcpp::Any GrammarParser::Def_const_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitDef_const_var(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::Def_const_varContext* GrammarParser::def_const_var() {
  Def_const_varContext *_localctx = _tracker.createInstance<Def_const_varContext>(_ctx, getState());
  enterRule(_localctx, 8, GrammarParser::RuleDef_const_var);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    identifier();
    setState(64);
    match(GrammarParser::Eq);
    setState(65);
    unsigned_int();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unsigned_intContext ------------------------------------------------------------------

GrammarParser::Unsigned_intContext::Unsigned_intContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Unsigned_intContext::IntNum() {
  return getToken(GrammarParser::IntNum, 0);
}


size_t GrammarParser::Unsigned_intContext::getRuleIndex() const {
  return GrammarParser::RuleUnsigned_int;
}

void GrammarParser::Unsigned_intContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnsigned_int(this);
}

void GrammarParser::Unsigned_intContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnsigned_int(this);
}


antlrcpp::Any GrammarParser::Unsigned_intContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitUnsigned_int(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::Unsigned_intContext* GrammarParser::unsigned_int() {
  Unsigned_intContext *_localctx = _tracker.createInstance<Unsigned_intContext>(_ctx, getState());
  enterRule(_localctx, 10, GrammarParser::RuleUnsigned_int);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(GrammarParser::IntNum);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declaresContext ------------------------------------------------------------------

GrammarParser::Var_declaresContext::Var_declaresContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Var_declaresContext::Var() {
  return getToken(GrammarParser::Var, 0);
}

std::vector<GrammarParser::IdentifierContext *> GrammarParser::Var_declaresContext::identifier() {
  return getRuleContexts<GrammarParser::IdentifierContext>();
}

GrammarParser::IdentifierContext* GrammarParser::Var_declaresContext::identifier(size_t i) {
  return getRuleContext<GrammarParser::IdentifierContext>(i);
}

tree::TerminalNode* GrammarParser::Var_declaresContext::Semi() {
  return getToken(GrammarParser::Semi, 0);
}

tree::TerminalNode* GrammarParser::Var_declaresContext::Comma() {
  return getToken(GrammarParser::Comma, 0);
}


size_t GrammarParser::Var_declaresContext::getRuleIndex() const {
  return GrammarParser::RuleVar_declares;
}

void GrammarParser::Var_declaresContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declares(this);
}

void GrammarParser::Var_declaresContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declares(this);
}


antlrcpp::Any GrammarParser::Var_declaresContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitVar_declares(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::Var_declaresContext* GrammarParser::var_declares() {
  Var_declaresContext *_localctx = _tracker.createInstance<Var_declaresContext>(_ctx, getState());
  enterRule(_localctx, 12, GrammarParser::RuleVar_declares);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(GrammarParser::Var);
    setState(70);
    identifier();

    setState(71);
    match(GrammarParser::Comma);
    setState(72);
    identifier();
    setState(74);
    match(GrammarParser::Semi);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

GrammarParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::IdentifierContext::Id() {
  return getToken(GrammarParser::Id, 0);
}


size_t GrammarParser::IdentifierContext::getRuleIndex() const {
  return GrammarParser::RuleIdentifier;
}

void GrammarParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void GrammarParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


antlrcpp::Any GrammarParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::IdentifierContext* GrammarParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 14, GrammarParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    match(GrammarParser::Id);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_sectionContext ------------------------------------------------------------------

GrammarParser::Statement_sectionContext::Statement_sectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::StatementContext* GrammarParser::Statement_sectionContext::statement() {
  return getRuleContext<GrammarParser::StatementContext>(0);
}

GrammarParser::Compound_statementsContext* GrammarParser::Statement_sectionContext::compound_statements() {
  return getRuleContext<GrammarParser::Compound_statementsContext>(0);
}


size_t GrammarParser::Statement_sectionContext::getRuleIndex() const {
  return GrammarParser::RuleStatement_section;
}

void GrammarParser::Statement_sectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_section(this);
}

void GrammarParser::Statement_sectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_section(this);
}


antlrcpp::Any GrammarParser::Statement_sectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitStatement_section(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::Statement_sectionContext* GrammarParser::statement_section() {
  Statement_sectionContext *_localctx = _tracker.createInstance<Statement_sectionContext>(_ctx, getState());
  enterRule(_localctx, 16, GrammarParser::RuleStatement_section);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(80);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(78);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(79);
      compound_statements();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_statementsContext ------------------------------------------------------------------

GrammarParser::Compound_statementsContext::Compound_statementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Compound_statementsContext::Begin() {
  return getToken(GrammarParser::Begin, 0);
}

tree::TerminalNode* GrammarParser::Compound_statementsContext::End() {
  return getToken(GrammarParser::End, 0);
}

std::vector<GrammarParser::StatementContext *> GrammarParser::Compound_statementsContext::statement() {
  return getRuleContexts<GrammarParser::StatementContext>();
}

GrammarParser::StatementContext* GrammarParser::Compound_statementsContext::statement(size_t i) {
  return getRuleContext<GrammarParser::StatementContext>(i);
}


size_t GrammarParser::Compound_statementsContext::getRuleIndex() const {
  return GrammarParser::RuleCompound_statements;
}

void GrammarParser::Compound_statementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statements(this);
}

void GrammarParser::Compound_statementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statements(this);
}


antlrcpp::Any GrammarParser::Compound_statementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitCompound_statements(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::Compound_statementsContext* GrammarParser::compound_statements() {
  Compound_statementsContext *_localctx = _tracker.createInstance<Compound_statementsContext>(_ctx, getState());
  enterRule(_localctx, 18, GrammarParser::RuleCompound_statements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(GrammarParser::Begin);
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::Begin)
      | (1ULL << GrammarParser::While)
      | (1ULL << GrammarParser::If)
      | (1ULL << GrammarParser::Id)
      | (1ULL << GrammarParser::Semi))) != 0)) {
      setState(83);
      statement();
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
    match(GrammarParser::End);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

GrammarParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Assign_statementContext* GrammarParser::StatementContext::assign_statement() {
  return getRuleContext<GrammarParser::Assign_statementContext>(0);
}

tree::TerminalNode* GrammarParser::StatementContext::Semi() {
  return getToken(GrammarParser::Semi, 0);
}

GrammarParser::If_statementContext* GrammarParser::StatementContext::if_statement() {
  return getRuleContext<GrammarParser::If_statementContext>(0);
}

GrammarParser::While_statementContext* GrammarParser::StatementContext::while_statement() {
  return getRuleContext<GrammarParser::While_statementContext>(0);
}

GrammarParser::Compound_statementsContext* GrammarParser::StatementContext::compound_statements() {
  return getRuleContext<GrammarParser::Compound_statementsContext>(0);
}


size_t GrammarParser::StatementContext::getRuleIndex() const {
  return GrammarParser::RuleStatement;
}

void GrammarParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void GrammarParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any GrammarParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::StatementContext* GrammarParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 20, GrammarParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(91);
        assign_statement();
        setState(92);
        match(GrammarParser::Semi);
        break;
      }

      case GrammarParser::If: {
        enterOuterAlt(_localctx, 2);
        setState(94);
        if_statement();
        break;
      }

      case GrammarParser::While: {
        enterOuterAlt(_localctx, 3);
        setState(95);
        while_statement();
        break;
      }

      case GrammarParser::Begin: {
        enterOuterAlt(_localctx, 4);
        setState(96);
        compound_statements();
        break;
      }

      case GrammarParser::Semi: {
        enterOuterAlt(_localctx, 5);
        setState(97);
        match(GrammarParser::Semi);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_statementContext ------------------------------------------------------------------

GrammarParser::Assign_statementContext::Assign_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::IdentifierContext* GrammarParser::Assign_statementContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

tree::TerminalNode* GrammarParser::Assign_statementContext::Assign() {
  return getToken(GrammarParser::Assign, 0);
}

GrammarParser::ExpressionContext* GrammarParser::Assign_statementContext::expression() {
  return getRuleContext<GrammarParser::ExpressionContext>(0);
}


size_t GrammarParser::Assign_statementContext::getRuleIndex() const {
  return GrammarParser::RuleAssign_statement;
}

void GrammarParser::Assign_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign_statement(this);
}

void GrammarParser::Assign_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign_statement(this);
}


antlrcpp::Any GrammarParser::Assign_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitAssign_statement(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::Assign_statementContext* GrammarParser::assign_statement() {
  Assign_statementContext *_localctx = _tracker.createInstance<Assign_statementContext>(_ctx, getState());
  enterRule(_localctx, 22, GrammarParser::RuleAssign_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(100);
    identifier();
    setState(101);
    match(GrammarParser::Assign);
    setState(102);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

GrammarParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::ItemContext* GrammarParser::ExpressionContext::item() {
  return getRuleContext<GrammarParser::ItemContext>(0);
}

tree::TerminalNode* GrammarParser::ExpressionContext::Add() {
  return getToken(GrammarParser::Add, 0);
}

tree::TerminalNode* GrammarParser::ExpressionContext::Sub() {
  return getToken(GrammarParser::Sub, 0);
}

GrammarParser::ExpressionContext* GrammarParser::ExpressionContext::expression() {
  return getRuleContext<GrammarParser::ExpressionContext>(0);
}


size_t GrammarParser::ExpressionContext::getRuleIndex() const {
  return GrammarParser::RuleExpression;
}

void GrammarParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void GrammarParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any GrammarParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


GrammarParser::ExpressionContext* GrammarParser::expression() {
   return expression(0);
}

GrammarParser::ExpressionContext* GrammarParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GrammarParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  GrammarParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, GrammarParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(106);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::Add

    || _la == GrammarParser::Sub) {
      setState(105);
      _la = _input->LA(1);
      if (!(_la == GrammarParser::Add

      || _la == GrammarParser::Sub)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(108);
    item(0);
    _ctx->stop = _input->LT(-1);
    setState(115);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(110);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(111);
        _la = _input->LA(1);
        if (!(_la == GrammarParser::Add

        || _la == GrammarParser::Sub)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(112);
        item(0); 
      }
      setState(117);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ItemContext ------------------------------------------------------------------

GrammarParser::ItemContext::ItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::FactorContext* GrammarParser::ItemContext::factor() {
  return getRuleContext<GrammarParser::FactorContext>(0);
}

GrammarParser::ItemContext* GrammarParser::ItemContext::item() {
  return getRuleContext<GrammarParser::ItemContext>(0);
}

tree::TerminalNode* GrammarParser::ItemContext::Mul() {
  return getToken(GrammarParser::Mul, 0);
}

tree::TerminalNode* GrammarParser::ItemContext::Div() {
  return getToken(GrammarParser::Div, 0);
}


size_t GrammarParser::ItemContext::getRuleIndex() const {
  return GrammarParser::RuleItem;
}

void GrammarParser::ItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterItem(this);
}

void GrammarParser::ItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitItem(this);
}


antlrcpp::Any GrammarParser::ItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitItem(this);
  else
    return visitor->visitChildren(this);
}


GrammarParser::ItemContext* GrammarParser::item() {
   return item(0);
}

GrammarParser::ItemContext* GrammarParser::item(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GrammarParser::ItemContext *_localctx = _tracker.createInstance<ItemContext>(_ctx, parentState);
  GrammarParser::ItemContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 26;
  enterRecursionRule(_localctx, 26, GrammarParser::RuleItem, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(119);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(126);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ItemContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleItem);
        setState(121);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(122);
        _la = _input->LA(1);
        if (!(_la == GrammarParser::Mul

        || _la == GrammarParser::Div)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(123);
        factor(); 
      }
      setState(128);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

GrammarParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::IdentifierContext* GrammarParser::FactorContext::identifier() {
  return getRuleContext<GrammarParser::IdentifierContext>(0);
}

GrammarParser::Unsigned_intContext* GrammarParser::FactorContext::unsigned_int() {
  return getRuleContext<GrammarParser::Unsigned_intContext>(0);
}

tree::TerminalNode* GrammarParser::FactorContext::LParen() {
  return getToken(GrammarParser::LParen, 0);
}

GrammarParser::ExpressionContext* GrammarParser::FactorContext::expression() {
  return getRuleContext<GrammarParser::ExpressionContext>(0);
}

tree::TerminalNode* GrammarParser::FactorContext::RParen() {
  return getToken(GrammarParser::RParen, 0);
}


size_t GrammarParser::FactorContext::getRuleIndex() const {
  return GrammarParser::RuleFactor;
}

void GrammarParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void GrammarParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


antlrcpp::Any GrammarParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::FactorContext* GrammarParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 28, GrammarParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(135);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::Id: {
        enterOuterAlt(_localctx, 1);
        setState(129);
        identifier();
        break;
      }

      case GrammarParser::IntNum: {
        enterOuterAlt(_localctx, 2);
        setState(130);
        unsigned_int();
        break;
      }

      case GrammarParser::LParen: {
        enterOuterAlt(_localctx, 3);
        setState(131);
        match(GrammarParser::LParen);
        setState(132);
        expression(0);
        setState(133);
        match(GrammarParser::RParen);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

GrammarParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::If_statementContext::If() {
  return getToken(GrammarParser::If, 0);
}

GrammarParser::CondContext* GrammarParser::If_statementContext::cond() {
  return getRuleContext<GrammarParser::CondContext>(0);
}

tree::TerminalNode* GrammarParser::If_statementContext::Then() {
  return getToken(GrammarParser::Then, 0);
}

GrammarParser::StatementContext* GrammarParser::If_statementContext::statement() {
  return getRuleContext<GrammarParser::StatementContext>(0);
}


size_t GrammarParser::If_statementContext::getRuleIndex() const {
  return GrammarParser::RuleIf_statement;
}

void GrammarParser::If_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_statement(this);
}

void GrammarParser::If_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_statement(this);
}


antlrcpp::Any GrammarParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::If_statementContext* GrammarParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 30, GrammarParser::RuleIf_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(GrammarParser::If);
    setState(138);
    cond();
    setState(139);
    match(GrammarParser::Then);
    setState(140);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_statementContext ------------------------------------------------------------------

GrammarParser::While_statementContext::While_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::While_statementContext::While() {
  return getToken(GrammarParser::While, 0);
}

GrammarParser::CondContext* GrammarParser::While_statementContext::cond() {
  return getRuleContext<GrammarParser::CondContext>(0);
}

tree::TerminalNode* GrammarParser::While_statementContext::Do() {
  return getToken(GrammarParser::Do, 0);
}

GrammarParser::StatementContext* GrammarParser::While_statementContext::statement() {
  return getRuleContext<GrammarParser::StatementContext>(0);
}


size_t GrammarParser::While_statementContext::getRuleIndex() const {
  return GrammarParser::RuleWhile_statement;
}

void GrammarParser::While_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_statement(this);
}

void GrammarParser::While_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_statement(this);
}


antlrcpp::Any GrammarParser::While_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitWhile_statement(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::While_statementContext* GrammarParser::while_statement() {
  While_statementContext *_localctx = _tracker.createInstance<While_statementContext>(_ctx, getState());
  enterRule(_localctx, 32, GrammarParser::RuleWhile_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    match(GrammarParser::While);
    setState(143);
    cond();
    setState(144);
    match(GrammarParser::Do);
    setState(145);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

GrammarParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::ExpressionContext *> GrammarParser::CondContext::expression() {
  return getRuleContexts<GrammarParser::ExpressionContext>();
}

GrammarParser::ExpressionContext* GrammarParser::CondContext::expression(size_t i) {
  return getRuleContext<GrammarParser::ExpressionContext>(i);
}

GrammarParser::Relational_operatorsContext* GrammarParser::CondContext::relational_operators() {
  return getRuleContext<GrammarParser::Relational_operatorsContext>(0);
}


size_t GrammarParser::CondContext::getRuleIndex() const {
  return GrammarParser::RuleCond;
}

void GrammarParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void GrammarParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


antlrcpp::Any GrammarParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::CondContext* GrammarParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 34, GrammarParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    expression(0);
    setState(148);
    relational_operators();
    setState(149);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Relational_operatorsContext ------------------------------------------------------------------

GrammarParser::Relational_operatorsContext::Relational_operatorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Relational_operatorsContext::Eq() {
  return getToken(GrammarParser::Eq, 0);
}

tree::TerminalNode* GrammarParser::Relational_operatorsContext::LtGt() {
  return getToken(GrammarParser::LtGt, 0);
}

tree::TerminalNode* GrammarParser::Relational_operatorsContext::Lt() {
  return getToken(GrammarParser::Lt, 0);
}

tree::TerminalNode* GrammarParser::Relational_operatorsContext::Le() {
  return getToken(GrammarParser::Le, 0);
}

tree::TerminalNode* GrammarParser::Relational_operatorsContext::Gt() {
  return getToken(GrammarParser::Gt, 0);
}

tree::TerminalNode* GrammarParser::Relational_operatorsContext::Ge() {
  return getToken(GrammarParser::Ge, 0);
}


size_t GrammarParser::Relational_operatorsContext::getRuleIndex() const {
  return GrammarParser::RuleRelational_operators;
}

void GrammarParser::Relational_operatorsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational_operators(this);
}

void GrammarParser::Relational_operatorsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational_operators(this);
}


antlrcpp::Any GrammarParser::Relational_operatorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GrammarVisitor*>(visitor))
    return parserVisitor->visitRelational_operators(this);
  else
    return visitor->visitChildren(this);
}

GrammarParser::Relational_operatorsContext* GrammarParser::relational_operators() {
  Relational_operatorsContext *_localctx = _tracker.createInstance<Relational_operatorsContext>(_ctx, getState());
  enterRule(_localctx, 36, GrammarParser::RuleRelational_operators);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::Eq)
      | (1ULL << GrammarParser::LtGt)
      | (1ULL << GrammarParser::Gt)
      | (1ULL << GrammarParser::Ge)
      | (1ULL << GrammarParser::Lt)
      | (1ULL << GrammarParser::Le))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool GrammarParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 13: return itemSempred(dynamic_cast<ItemContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GrammarParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool GrammarParser::itemSempred(ItemContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> GrammarParser::_decisionToDFA;
atn::PredictionContextCache GrammarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN GrammarParser::_atn;
std::vector<uint16_t> GrammarParser::_serializedATN;

std::vector<std::string> GrammarParser::_ruleNames = {
  "program", "unit", "sub_program", "const_var_declares", "def_const_var", 
  "unsigned_int", "var_declares", "identifier", "statement_section", "compound_statements", 
  "statement", "assign_statement", "expression", "item", "factor", "if_statement", 
  "while_statement", "cond", "relational_operators"
};

std::vector<std::string> GrammarParser::_literalNames = {
  "", "'PROGRAM'", "'BEGIN'", "'END'", "'CONST'", "'VAR'", "'WHILE'", "'DO'", 
  "'IF'", "'THEN'", "", "", "'+'", "'-'", "'*'", "'/'", "':='", "'='", "'<>'", 
  "'>'", "'>='", "'<'", "'<='", "'('", "')'", "';'", "','"
};

std::vector<std::string> GrammarParser::_symbolicNames = {
  "", "Program", "Begin", "End", "Const", "Var", "While", "Do", "If", "Then", 
  "Id", "IntNum", "Add", "Sub", "Mul", "Div", "Assign", "Eq", "LtGt", "Gt", 
  "Ge", "Lt", "Le", "LParen", "RParen", "Semi", "Comma", "Ws"
};

dfa::Vocabulary GrammarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> GrammarParser::_tokenNames;

GrammarParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1d, 0x9c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x5, 0x4, 0x30, 
    0xa, 0x4, 0x3, 0x4, 0x5, 0x4, 0x33, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x3b, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x3e, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x53, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x57, 0xa, 
    0xb, 0xc, 0xb, 0xe, 0xb, 0x5a, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0x65, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x5, 0xe, 0x6d, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x7, 0xe, 0x74, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x77, 0xb, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 
    0x7f, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x82, 0xb, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x8a, 0xa, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x2, 0x4, 0x1a, 0x1c, 
    0x15, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x2, 0x5, 0x3, 0x2, 0xe, 0xf, 
    0x3, 0x2, 0x10, 0x11, 0x3, 0x2, 0x13, 0x18, 0x2, 0x96, 0x2, 0x28, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2f, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x36, 0x3, 0x2, 0x2, 0x2, 0xa, 0x41, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0xe, 0x47, 0x3, 0x2, 0x2, 0x2, 0x10, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x52, 0x3, 0x2, 0x2, 0x2, 0x14, 0x54, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x64, 0x3, 0x2, 0x2, 0x2, 0x18, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x89, 0x3, 0x2, 0x2, 0x2, 0x20, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x90, 0x3, 0x2, 0x2, 0x2, 0x24, 0x95, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x5, 0x4, 0x3, 0x2, 0x29, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x3, 0x2, 0x2, 0x2b, 0x2c, 0x5, 
    0x10, 0x9, 0x2, 0x2c, 0x2d, 0x5, 0x6, 0x4, 0x2, 0x2d, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x30, 0x5, 0x8, 0x5, 0x2, 0x2f, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x31, 0x33, 0x5, 0xe, 0x8, 0x2, 0x32, 0x31, 0x3, 0x2, 0x2, 0x2, 0x32, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 
    0x5, 0x12, 0xa, 0x2, 0x35, 0x7, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 
    0x6, 0x2, 0x2, 0x37, 0x3c, 0x5, 0xa, 0x6, 0x2, 0x38, 0x39, 0x7, 0x1c, 
    0x2, 0x2, 0x39, 0x3b, 0x5, 0xa, 0x6, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x3c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x1b, 0x2, 0x2, 0x40, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x5, 0x10, 0x9, 0x2, 0x42, 0x43, 0x7, 
    0x13, 0x2, 0x2, 0x43, 0x44, 0x5, 0xc, 0x7, 0x2, 0x44, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x46, 0x7, 0xd, 0x2, 0x2, 0x46, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x47, 0x48, 0x7, 0x7, 0x2, 0x2, 0x48, 0x49, 0x5, 0x10, 0x9, 0x2, 
    0x49, 0x4a, 0x7, 0x1c, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0x10, 0x9, 0x2, 0x4b, 
    0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x1b, 0x2, 0x2, 0x4d, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0xc, 0x2, 0x2, 0x4f, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x53, 0x5, 0x16, 0xc, 0x2, 0x51, 0x53, 0x5, 0x14, 
    0xb, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x13, 0x3, 0x2, 0x2, 0x2, 0x54, 0x58, 0x7, 0x4, 0x2, 0x2, 
    0x55, 0x57, 0x5, 0x16, 0xc, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x5c, 0x7, 0x5, 0x2, 0x2, 0x5c, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x5e, 0x5, 0x18, 0xd, 0x2, 0x5e, 0x5f, 0x7, 0x1b, 0x2, 
    0x2, 0x5f, 0x65, 0x3, 0x2, 0x2, 0x2, 0x60, 0x65, 0x5, 0x20, 0x11, 0x2, 
    0x61, 0x65, 0x5, 0x22, 0x12, 0x2, 0x62, 0x65, 0x5, 0x14, 0xb, 0x2, 0x63, 
    0x65, 0x7, 0x1b, 0x2, 0x2, 0x64, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x64, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x61, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x67, 0x5, 0x10, 0x9, 0x2, 0x67, 0x68, 0x7, 0x12, 0x2, 
    0x2, 0x68, 0x69, 0x5, 0x1a, 0xe, 0x2, 0x69, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6c, 0x8, 0xe, 0x1, 0x2, 0x6b, 0x6d, 0x9, 0x2, 0x2, 0x2, 0x6c, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0x1c, 0xf, 0x2, 0x6f, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x71, 0xc, 0x3, 0x2, 0x2, 0x71, 0x72, 0x9, 0x2, 
    0x2, 0x2, 0x72, 0x74, 0x5, 0x1c, 0xf, 0x2, 0x73, 0x70, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x77, 0x3, 0x2, 0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 
    0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x75, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x8, 0xf, 0x1, 0x2, 0x79, 0x7a, 
    0x5, 0x1e, 0x10, 0x2, 0x7a, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0xc, 
    0x3, 0x2, 0x2, 0x7c, 0x7d, 0x9, 0x3, 0x2, 0x2, 0x7d, 0x7f, 0x5, 0x1e, 
    0x10, 0x2, 0x7e, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x83, 
    0x8a, 0x5, 0x10, 0x9, 0x2, 0x84, 0x8a, 0x5, 0xc, 0x7, 0x2, 0x85, 0x86, 
    0x7, 0x19, 0x2, 0x2, 0x86, 0x87, 0x5, 0x1a, 0xe, 0x2, 0x87, 0x88, 0x7, 
    0x1a, 0x2, 0x2, 0x88, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x89, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x84, 0x3, 0x2, 0x2, 0x2, 0x89, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0xa, 0x2, 0x2, 
    0x8c, 0x8d, 0x5, 0x24, 0x13, 0x2, 0x8d, 0x8e, 0x7, 0xb, 0x2, 0x2, 0x8e, 
    0x8f, 0x5, 0x16, 0xc, 0x2, 0x8f, 0x21, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 
    0x7, 0x8, 0x2, 0x2, 0x91, 0x92, 0x5, 0x24, 0x13, 0x2, 0x92, 0x93, 0x7, 
    0x9, 0x2, 0x2, 0x93, 0x94, 0x5, 0x16, 0xc, 0x2, 0x94, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x95, 0x96, 0x5, 0x1a, 0xe, 0x2, 0x96, 0x97, 0x5, 0x26, 0x14, 
    0x2, 0x97, 0x98, 0x5, 0x1a, 0xe, 0x2, 0x98, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x9a, 0x9, 0x4, 0x2, 0x2, 0x9a, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x2f, 0x32, 0x3c, 0x52, 0x58, 0x64, 0x6c, 0x75, 0x80, 0x89, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

GrammarParser::Initializer GrammarParser::_init;
