

grammar Grammar;

import Token;

options{language = Cpp;}

program: unit;

unit: Program identifier sub_program;

sub_program: const_var_declares? var_declares? statement_section;

const_var_declares: Const def_const_var (Comma def_const_var)* Semi;

def_const_var: identifier Eq unsigned_int;

unsigned_int: IntNum;

var_declares: Var identifier (Comma identifier) Semi;

identifier: Id;

statement_section: statement
                 | compound_statements;

compound_statements: Begin statement* End;

statement: assign_statement Semi
         | if_statement
         | while_statement
         | compound_statements
         | Semi;

assign_statement: identifier Assign expression;

expression: (Add | Sub)? item
          | expression (Add | Sub) item;

item: factor
    | item (Mul | Div) factor;

factor: identifier
      | unsigned_int
      | LParen expression RParen;

if_statement: If cond Then statement;

while_statement: While cond Do statement;

cond: expression relational_operators expression;

relational_operators: Eq | LtGt | Lt | Le | Gt | Ge;




