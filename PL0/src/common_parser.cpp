#include "parser.h"
#include "error.h"
#include <map>

static std::map<std::string, Token> KeyWordTkMap = {
        {"PROGRAM", TOK_PROGRAM}, {"BEGIN", TOK_BEGIN}, {"END", TOK_END},
        {"CONST", TOK_CONST}, {"VAR", TOK_VAR}, {"WHILE", TOK_WHILE},
        {"DO", TOK_DO}, {"IF", TOK_IF}, {"THEN", TOK_THEN}
};


CommonAstParser::CommonAstParser()
    : Line(1), Col(0), Num(0), Id(), Fp(), CurToken(TOK_UNKNOWN), LastChar(' ')
{}

Program *CommonAstParser::parse(const char *filepath) {
    Fp.open(filepath, std::ios::in);
    if (!Fp.is_open()) {
        std::cout << "Can not open file " << filepath << std::endl;
        return nullptr;
    }
    auto *prog = parseProgram();
    Fp.close();
    return prog;
}

Program *CommonAstParser::parseProgram() {
    Program *prog;
    getNextToken();
    if (CurToken != TOK_PROGRAM) {
        LOG_ERROR(Line, Col, "Program must begin with keyword 'PROGRAM'")
    }
    getNextToken();
    if(CurToken != TOK_ID) {
        LOG_ERROR(Line, Col, "Not have program id")
    }
    prog = new Program(Id);
    if(lookUp(1)[0] == TOK_CONST) {
        prog->setCDecl(parseConstDecl());
    }
    if(lookUp(1)[0] == TOK_VAR) {
        prog->setVDecl(parseVarDecl());
    }
    prog->setStmt(parseStatement());
    return prog;
}

ConstDecl *CommonAstParser::parseConstDecl() {
    // eat CONST
    getNextToken();
    auto c_decl = new ConstDecl();
    ConstDef *c_def;
    getNextToken();
    // eat ID
    getNextToken();
    if (CurToken != TOK_ID) {
        LOG_ERROR(Line, Col, "Const decl not have id")
    }
    // eat EQ
    getNextToken();
    if (CurToken != TOK_EQ) {
        LOG_ERROR(Line, Col, "Const decl not have '='")
    }
    // eat INT
    getNextToken();
    if(CurToken != TOK_INT) {
        LOG_ERROR(Line, Col, "Const decl not have init const value")
    }
    c_def = new ConstDef();
    c_def->id = new Identifier(Id);
    c_def->value = Num;
    c_decl->addConstDef(c_def);

    while (lookUp(1)[0] == TOK_COMMA) {
        // eat COMMA
        getNextToken();
        getNextToken();
        if (CurToken != TOK_ID) {
            LOG_ERROR(Line, Col, "Const decl not have id")
        }
        // eat EQ
        getNextToken();
        if (CurToken != TOK_EQ) {
            LOG_ERROR(Line, Col, "Const decl not have '='")
        }
        // eat INT
        getNextToken();
        if(CurToken != TOK_INT) {
            LOG_ERROR(Line, Col, "Const decl not have init const value")
        }
        c_def = new ConstDef();
        c_def->id = new Identifier(Id);
        c_def->value = Num;
        c_decl->addConstDef(c_def);
    }
    getNextToken();
    if (CurToken != TOK_SEMI) {
        LOG_ERROR(Line, Col, "Const variable decl must end with ';'")
    }
    return c_decl;
}

VarDecl *CommonAstParser::parseVarDecl() {
    // eat VAR
    getNextToken();
    auto v_decl = new VarDecl();
    // eat ID
    getNextToken();
    if (CurToken != TOK_ID) {
        LOG_ERROR(Line, Col, "Var decl not have id")
    }
    v_decl->addVarDef(new Identifier(Id));
    while (lookUp(1)[0] == TOK_COMMA) {
        // eat COMMA
        getNextToken();
        // eat ID
        getNextToken();
        if (CurToken != TOK_ID) {
            LOG_ERROR(Line, Col, "Var decl not have id")
        }
        v_decl->addVarDef(new Identifier(Id));
    }
    // eat SEMI
    getNextToken();
    if (CurToken != TOK_SEMI) {
        LOG_ERROR(Line, Col, "Assign statement must end with ';'")
    }
    return v_decl;
}

Node *CommonAstParser::parseStatement() {
    auto r = lookUp(1)[0];
    switch (r) {
        case TOK_ID: {
            return parseAssignStmt();
        }
        case TOK_IF: {
            return parseCondStmt();
        }
        case TOK_WHILE: {
            return parseWhileStmt();
        }
        case TOK_BEGIN: {
            return parseBlockStmt();
        }
        case TOK_SEMI: {
            return nullptr;
        }
        default: {
            LOG_ERROR(Line, Col, "Statement parse error!")
        }
    }
}

Node *CommonAstParser::parseAssignStmt() {
    /// eat ID
    getNextToken();
    auto id = Id;
    /// eat ASSIGN
    getNextToken();
    if(CurToken != TOK_ASSIGN) {
        LOG_ERROR(Line, Col, "Assign statement error!")
    }

    auto expr = parseExpr();

    getNextToken();
    if (CurToken != TOK_SEMI) {
        LOG_ERROR(Line, Col, "Const variable decl must end with ';'")
    }
    return new AssignStatement(new Identifier(id), expr);
}

Node *CommonAstParser::parseExpr() {
    auto lhs = parseItem();
    auto tk = lookUp(1)[0];
    if(tk == TOK_ADD || tk == TOK_SUB) {
        /// eat OP
        getNextToken();
        auto rhs = parseItem();
        return new BinaryExpr(getOpByToken(tk), lhs, rhs);
    }
    return lhs;
}

Node *CommonAstParser::parseItem() {
    auto lhs = parseFactor();
    auto tk = lookUp(1)[0];
    if(tk == TOK_MUL || tk == TOK_DIV) {
        /// eat OP
        getNextToken();
        auto rhs = parseFactor();
        return new BinaryExpr(getOpByToken(tk), lhs, rhs);
    }
    return lhs;
}

Node *CommonAstParser::parseFactor() {
    getNextToken();
    switch (CurToken) {
        case TOK_ID: {
            return new Identifier(Id);
        }
        case TOK_INT: {
            return new UInt(Num);
        }
        case TOK_LPAREN: {
            getNextToken();
            auto expr = parseExpr();
            getNextToken();
            if(CurToken != TOK_RPAREN) {
                LOG_ERROR(Line, Col, "Missing ')'")
            }
            return expr;
        }
        default: {
            LOG_ERROR(Line, Col, "Error to parse expr!")
        }
    }
}

Node *CommonAstParser::parseCondStmt() {
    // eat IF
    getNextToken();
    auto cond = parseCond();
    getNextToken();
    if (CurToken != TOK_THEN) {
        LOG_ERROR(Line, Col, "Missing 'THEN' in if statement")
    }
    auto stmt = parseStatement();
    return new IfStatement(cond, stmt);
}

Node *CommonAstParser::parseWhileStmt() {
    // eat WHILE
    getNextToken();
    auto cond = parseCond();
    getNextToken();
    if (CurToken != TOK_DO) {
        LOG_ERROR(Line, Col, "Missing 'DO' in while statement")
    }
    auto stmt = parseStatement();
    return new WhileStatement(cond, stmt);
}

Node *CommonAstParser::parseCond() {
    auto lhs = parseExpr();
    auto tk = lookUp(1)[0];
    switch (tk) {
        case TOK_EQ:
        case TOK_NE:
        case TOK_LE:
        case TOK_LT:
        case TOK_GE:
        case TOK_GT:
        {
            /// eat OP
            getNextToken();
            auto rhs = parseExpr();
            return new BinaryExpr(getOpByToken(tk), lhs, rhs);
        }
        default: {
            return lhs;
        }
    }
}

Node *CommonAstParser::parseBlockStmt() {
    // eat BEGIN
    getNextToken();
    auto block = new BlockStatement();
    auto tk = lookUp(1)[0];
    while (tk != TOK_END && tk != TOK_EOF) {
        block->addStmt(parseStatement());
        tk = lookUp(1)[0];
    }
    // eat END
    getNextToken();
    if(CurToken != TOK_END) {
        LOG_ERROR(Line, Col, "Missing 'END'")
    }
    return block;
}

Token CommonAstParser::getToken() {

    /// jump '\n', ' ', '\r'
    while(isspace(LastChar)) {
        getChar();
    }

    if(LastChar == '#') {
        while (LastChar != GrammarParser::EOF && LastChar != '\n') {
            getChar();
        }
        getChar();
    }

    /// jump '\n', ' ', '\r'
    while(isspace(LastChar)) {
        getChar();
    }

    // identifier: [a-zA-Z][a-zA-Z0-9]*
    if(isalpha(LastChar)) {
        Id = LastChar;
        getChar();
        while(isalnum((LastChar))) {
            Id += LastChar;
            getChar();
        }

        auto it = KeyWordTkMap.find(Id);

        if(it == KeyWordTkMap.end())
            return TOK_ID;
        return KeyWordTkMap[Id];
    }

    if (isdigit(LastChar)) {
        std::string num;
        do {
            num += LastChar;
            getChar();
        } while(isdigit(LastChar));
        Num = (unsigned int)atol(num.c_str());
        return TOK_INT;
    }

    switch(LastChar) {
        case '+': { getChar(); return TOK_ADD; }
        case '-': { getChar(); return TOK_SUB; }
        case '*': { getChar(); return TOK_MUL; }
        case '/': { getChar(); return TOK_DIV; }
        case '=': { getChar(); return TOK_EQ; }
        case '<':{
            getChar();
            if (LastChar == '>') {
                getChar();
                return TOK_NE;
            }
            else if(LastChar == '=') {
                getChar();
                return TOK_LE;
            }
            return TOK_LT;
        }
        case '>':{
            getChar();
            if(LastChar == '=') {
                getChar();
                return TOK_GE;
            }
            return TOK_GT;
        }
        case ':': {
            getChar();
            if(LastChar != '=') return TOK_UNKNOWN;
            getChar();
            return TOK_ASSIGN;
        }
        case '(': { getChar(); return TOK_LPAREN; }
        case ')': { getChar(); return TOK_RPAREN; }
        case ';': { getChar(); return TOK_SEMI; }
        case ',': { getChar(); return TOK_COMMA; }
        default: break;
    }

    if(LastChar == GrammarParser::EOF)
        return TOK_EOF;

    getChar();

    return TOK_UNKNOWN;
}

std::vector<Token> CommonAstParser::lookUp(unsigned int n) {
    std::vector<Token> LookUpToks;
    auto currentLoc = Fp.tellg();
    auto savedChar = LastChar;
    auto preLine = Line;
    auto preCol = Col;

    int i = 0, tok;
    while (i < n) {
        tok = getToken();
        LookUpToks.push_back((Token)tok);
        if(tok == GrammarParser::EOF)
            break;
        i++;
    }

    Fp.seekg(currentLoc);

    LastChar = savedChar;
    Line = preLine;
    Col = preCol;

    return LookUpToks;
}

void CommonAstParser::getChar() {
    Fp.read(&LastChar, 1);
    if(LastChar == '\n') {
        Line++;
        Col = 0;
    }
    else {
        Col++;
    }
}

void CommonAstParser::getNextToken() {
    CurToken = getToken();
}


const static std::map<Token, Operator> TkToOpMap = {
        {TOK_ADD, Add}, {TOK_SUB, Sub}, {TOK_MUL, Mul},
        {TOK_DIV, Div}, {TOK_EQ, Eq}, {TOK_NE, Neq},
        {TOK_LT, Lt}, {TOK_LE, Le}, {TOK_GT, Gt},
        {TOK_GE, Ge}
};

Operator CommonAstParser::getOpByToken(Token tk) const {
    auto it = TkToOpMap.find(tk);
    if (it == TkToOpMap.end()) {
        LOG_ERROR(Line, Col, "Error to use this api 'getOpByToken!'")
    }
    return it->second;
}




