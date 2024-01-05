
lexer grammar Token;

options{ language = Cpp;}

/// Token Define

/// 关键字
Program: 'PROGRAM';
Begin:   'BEGIN';
End:     'END';
Const:   'CONST';
Var:     'VAR';
While:   'WHILE';
Do:      'DO';
If:      'IF';
Then:    'THEN';

/// 标识符
Id:      [A-Za-z][A-Za-z0-9]*;
IntNum:  [0-9]+;

/// 算符、界符
Add:    '+';
Sub:    '-';
Mul:    '*';
Div:    '/';
Assign: ':=';
Eq:     '=';
LtGt:   '<>';
Gt:     '>';
Ge:     '>=';
Lt:     '<';
Le:     '<=';
LParen: '(';
RParen: ')';
Semi:   ';';
Comma:  ',';


// white space
Ws:             [ \r\n\t]+ -> skip;
