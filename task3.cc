%skeleton "lalr1.cc" 
%defines 
%define api.value.type variant 
%define api.token.constructor 
%code requires
{
	#include "node.h"
}
%code{ 
unsigned int total = 0; 
Node root;
#include <string> 

#define YY_DECL yy::parser::symbol_type yylex() 
YY_DECL; 
} 
%token <std::string> NEWLINE
%token <std::string> TEXT
%token <std::string> SEMICOLON
%token <std::string> PIPE
%token <std::string> DOLLAR
%token <std::string> SPACE
%token <std::string> QUOTE
%token <std::string> DQUOTE
%type <Node> line
%type <Node> optline
%type <Node> anything
%type <Node> stream
%type <Node> units
%type <Node> pipeunit





%token END 0 "end of file" 
%%

            
            stream : optline { $$ = Node("stream",""); 
                             $$.children.push_back($1);
                             root = $$; }
                    | stream NEWLINE optline { $$=$1;
                             $$.children.push_back($3); 
                             root=$$;}
                    ;

            optline : { $$ = Node("optline","");}
                    | line { $$ = Node("optline","has line"); $$.children.push_back($1);}
                    ;

            line : pipeunit {$$ = $1;} 
                   |line SEMICOLON pipeunit {$$=Node("line","") ; 
                   $$.children.push_back($1);$$.children.push_back($3); 
                   }
                   ;
            pipeunit: units{$$=$1;}
            | pipeunit PIPE units{ $$=Node("pipeline","");
            $$.children.push_back($1);$$.children.push_back($3);
            }
            ;   
           
            units : anything {$$=Node("units: ","");
            $$.children.push_back($1);}
                   | units anything {$$=$1;
                   $$.children.push_back($2);} 
                   ;
            anything : 
                   TEXT     { $$ = Node("TEXT", $1);}
            		 | DOLLAR   { $$ = Node("DOLLAR", $1);}
                 | SPACE    { $$ = Node("BLANK", $1);}
                 ;
            