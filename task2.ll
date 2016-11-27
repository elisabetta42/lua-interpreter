%top{
#include "binary.tab.hh"
#define YY_DECL yy::parser::symbol_type yylex()
}
%option noyywrap nounput batch noinput
%%
[^\n]*       { cout << "LINE:" + yy::parser::make_NEWLINE(yytext); }
\n           cout << "NL:"
<<EOF>>       return yy::parser::make_END();
%%