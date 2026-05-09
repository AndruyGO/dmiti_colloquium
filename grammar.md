program -> statement* EOF

statement -> (print_stmt | assign_stmt | if_stmt | while_stmt | expr_stmt) ";"

print_stmt -> "PRINT" expression
assign_stmt -> TYPE IDENTIFIER "=" expression
if_stmt -> "IF" expression block
while_stmt -> "WHILE" expression block
expr_stmt -> expression

block -> "{" statement* "}"

expression -> term (("+" | "-") term)*
term -> factor (("*" | "/") factor)*
factor -> NUMBER | IDENTIFIER | "(" expression ")"
