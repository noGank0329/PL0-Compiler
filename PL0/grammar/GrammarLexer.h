
// Generated from ./grammar/Grammar.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  GrammarLexer : public antlr4::Lexer {
public:
  enum {
    Program = 1, Begin = 2, End = 3, Const = 4, Var = 5, While = 6, Do = 7, 
    If = 8, Then = 9, Id = 10, IntNum = 11, Add = 12, Sub = 13, Mul = 14, 
    Div = 15, Assign = 16, Eq = 17, LtGt = 18, Gt = 19, Ge = 20, Lt = 21, 
    Le = 22, LParen = 23, RParen = 24, Semi = 25, Comma = 26, Ws = 27
  };

  GrammarLexer(antlr4::CharStream *input);
  ~GrammarLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

