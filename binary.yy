%skeleton "lalr1.cc" 
%defines 
%define api.value.type variant 
%define api.token.constructor 
%code requires
{
  #include "node.h"
  #include "call.cpp"
  #include "sequence.cpp"
  #include "expression.cpp"
  #include "costant.cpp"
  #include "variable.cpp"
  #include "assign.cpp"
  #include "binoperation.cpp"
  #include "ifcondition.cpp"
  #include "myfunction.cpp"
  #include "comparitor.cpp"
  #include "fornode.cpp"
  #include "mystring.cpp"
}
%code{ 
unsigned int total = 0; 
Sequence *root;
unsigned int counter=0;
#include <string> 
#define YY_DECL yy::parser::symbol_type yylex() 
YY_DECL; 
} 

%token <std::string> SEMICOLON
%token <std::string> NAME
%token <std::string> BREAK
%token <std::string> RETURN
%token <std::string> EQUAL
%token <std::string> COMMA
%token <std::string> OSBRACKET
%token <std::string> CSBRACKET
%token <std::string> POINT
%token <std::string> OPARENTHESIS
%token <std::string> CPARENTHESIS
%token <std::string> COLON
%token <std::string> STRING
%token <std::string> OBRACKET
%token <std::string> CBRACKET

%token <std::string> DO
%token <std::string> END1

%token <std::string> WHILE
%token <std::string> REPEAT
%token <std::string> UNTIL

%token <std::string> IF
%token <std::string> THEN
%token <std::string> ELSEIF
%token <std::string> ELSE
%token <std::string> FOR
%token <std::string> IN
%token <std::string> FUNCTION
%token <std::string> LOCAL
%token <std::string> THREEPOINT
%token <std::string> PLUS
%token <std::string> MINUS
%token <std::string> ASTERISK
%token <std::string> FSLASH
%token <std::string> HASH
%token <std::string> ARCH
%token <std::string> PERCENTAGE
%token <std::string> LOWER
%token <std::string> GREATER
%token <std::string> NOT
%token <std::string> AND
%token <std::string> OR
%token <std::string> ELOWER
%token <std::string> EGREATER
%token <std::string> ETILDA
%token <std::string> DEQUAL
%token <std::string> TWOPOINT
%token <std::string> SDQUOTE
%token <std::string> SQUOTE

%token <std::string> NIL
%token <std::string> FALSE
%token <std::string> TRUE
%token <std::string> NUMBER
%left PLUS MINUS
%left ARCH ASTERISK FSLASH PERCENTAGE TWOPOINT LOWER GREATER ELOWER EGREATER ETILDA DEQUAL AND OR 
%left NOT 
%left HASH

%type <Sequence*> program
%type <Sequence*> chunk
%type <Sequence*> stats
%type <Statement*> stat
%type <std::string> laststatment
//%type <Node> optional_semicolon
%type <Expression*> varlist
%type <Expression*> var
%type <Expression*> explist
%type <Expression*> exp
%type <Expression*> oexplist
%type <Sequence*> block
%type <Expression*> prefixexp
%type <EFunction*> functioncall
%type <Expression*> args
%type <std::string> tableconstructor
%type <std::string> ofieldlist
%type <std::string> field
//%type <Node> fieldsep
//%type <Node> ofieldsep
%type <std::string> fieldlist
%type <std::string> elseif_statement
%type <Sequence*> else_statement
%type <std::string> oexpcomma
%type <std::string> namelist
%type <std::string> funcname
%type <std::string> ofuncname
%type <std::string> funcbody
%type <std::string> parlist
%type <std::string> oparlist
%type <std::string> opt_parlist
%type <std::string> function

//aggiungere robe optionali
//sistemare else if
//sistemare binary 
//ERRORI: FIELDLIST UNOP BINOP
//functioncall
//creare token per i diversi numeri 
//aggiungere regole per i diversi number
//--[.]*commenti
// aggiungere nel bison che la stringa può contenere numeri indicanti caratteri
// aggiungere tutti i caratteri escssappati
//new line
//regex non prende stringa vuota
//cercare commenti con uguali
//program rule for root
//controllare elseif crea nodo anke se vuoto
%token END 0 "end of file" 
%%           
           




           program: chunk {root = $1;}
                  ;

             chunk:stats{$$=$1;}
                  |stats laststatment optional_semicolon{}
                   //$$ = Node("chunk","",counter++);
                   //$$.children.push_back($1);$$.children.push_back($2);} 
                  ;

             stats:{$$=new Sequence();}
                  |stats stat optional_semicolon {$$ = $1;$$->addStatement($2); } 
                  ;

optional_semicolon:{}
                  |SEMICOLON
                  ;

             block: chunk{$$=$1;}
                  ;
                  
      laststatment:RETURN oexplist {}//$$=Node("Returnexp ","",counter++);$$.children.push_back($2);}
                  |BREAK {}//$$=Node("BREAK ",$1,counter++);}
                  ;
              
             stat:varlist EQUAL explist  {$$=new Assign($1,$3);}
                  | functioncall           {$$=new Call($1);}
                  | DO block END1           {}//$$=Node("DoNode","",counter++);$$.children.push_back($2);}
                  | WHILE exp DO block END1 {}//$$=Node("WhileNode","",counter++);$$.children.push_back($2);
                                             //$$.children. push_back($4);}
                  | REPEAT block UNTIL exp  {}//$$=Node("RepeatNode","",counter++);$$.children.push_back($2);
                                             //$$.children.push_back($4);}
                  | IF exp THEN block elseif_statement else_statement END1 {$$=new IfCnd($2,$4,$6);}
                  | FOR NAME EQUAL exp COMMA exp oexpcomma DO block END1  
                                       {$$=new ForNode(new Variable($2),$4,$6,$9);};
                                                                            
                  | FOR namelist IN explist DO block END1                  {}//$$=Node("CForNode:","",counter++);
                                                                            //$$.children.push_back($2);
                                                                            //$$.children.push_back($4);
                                                                            //$$.children.push_back($6); 
                  | FUNCTION funcname funcbody                    {}//$$=Node("FuncNode:","",counter++); 
                                                                  //$$.children.push_back($2);
                                                                  //$$.children.push_back($3);                     
                  | LOCAL FUNCTION NAME funcbody {}//$$=Node("SmpLocalFunc","",counter++);
                                                  //$$.children.push_back(Node("singlevalue",$3,counter++));
                                                  //$$.children.push_back($4);}
                  | LOCAL namelist               {}//$$=Node("nameListLocalFunc","",counter++);
                                                 //$$.children.push_back($2);}
                  | LOCAL namelist EQUAL explist {}//$$=Node("asgmLocalFunc","",counter++);
                                                   //$$.children.push_back($2);
                                                  //$$.children.push_back($4);}
                  ;

         oexpcomma: {}//$$=Node("emptycommaexp","",counter++);}
                  | COMMA exp //{$$=$2;}
                  ;
          
  elseif_statement: {}//$$=Node("elseif","",counter++);}
                  | elseif_statement ELSEIF exp THEN block {}//$$=$1;$$.children.push_back($3);
                  ;                                         //$$.children.push_back($5);}
                                                       
    else_statement: {$$= NULL;}
                  | ELSE block{$$=$2;}
                  ;

          funcname: NAME {}//$$=Node("funcName",$1,counter++);}
                  | funcname POINT NAME ofuncname {}//$$=$1; 
                                                    //$$.children.push_back(Node("singlevalue",$3,counter++));
                                                   //$$.children.push_back($4);}
                  ;

        ofuncname:{}//$$=Node("emptyfunc","",counter++);}
                  |COLON NAME {}//$$=Node("pointfunc",$2,counter++);}
                  ;

          varlist : var {$$=$1;}
                  | varlist COMMA var //{$$=$1;$$.children.push_back($3);}
                  ;

               var: NAME{$$= new Variable($1);}
                  | prefixexp OSBRACKET exp CSBRACKET {}
                  | prefixexp POINT NAME {$$= new Variable("io."+$3);}
                  ;

          namelist: NAME {}//$$=Node("nameList","",counter++);
                          //$$.children.push_back(Node("singlevalue",$1,counter++));}
                  | namelist COMMA NAME{}//$$=$1;$$.children.push_back(Node("singlevalue",$3,counter++)); }
                  ;
                  
           
           explist:exp {$$=$1;}
                  |explist COMMA exp {}//$$=$1;$$.children.push_back($3);}
                  ;
              
          
          oexplist:{}//$$=Node("emptyList","",counter++);}
                  |explist {$$=$1;}
                  ;

               exp: NIL               {}//$$=Node("NIL","",counter++);}
                  | FALSE             {}//$$=Node("FALSE","",counter++);}
                  | TRUE              {}//$$=Node("TRUE","",counter++);}
                  | NUMBER            {$$=new Constant($1);}
                  | STRING            {$$=new MyString($1);}
                  | THREEPOINT        {}//$$=Node("TREEPOINT","",counter++);}
                  | function          {}//{$$=$1;}
                  | prefixexp         {$$=$1;}
                  | tableconstructor  {}//{$$=$1;}
                  | exp MINUS exp     {$$=new BinOp($1,$3,$2);}
                  | exp PLUS exp      {$$=new BinOp($1,$3,$2);}
                  | exp ASTERISK exp  {$$=new BinOp($1,$3,$2);}
                  | exp FSLASH exp    {$$=new BinOp($1,$3,$2);}
                  | exp ARCH exp      {}//$$=Node("archexp","",counter++);$$.children.push_back($1);
                                       //$$.children.push_back($3);}
                  | exp TWOPOINT exp  {}//$$=Node("twopointexp","",counter++);$$.children.push_back($1);
                                       //$$.children.push_back($3);}
                  | exp PERCENTAGE exp{$$=new BinOp($1,$3,$2);}
                                       //$$.children.push_back($3);}
                  | exp LOWER exp     {$$=new Comparitor($1,$3,$2);}
                  | exp ELOWER exp    {$$=new Comparitor($1,$3,$2);}
                  | exp GREATER exp   {$$=new Comparitor($1,$3,$2);}
                  | exp EGREATER exp  {$$=new Comparitor($1,$3,$2);}
                  | exp DEQUAL exp    {$$=new Comparitor($1,$3,$2);}
                  | exp ETILDA exp    {}//$$=Node("equaltiladaexp","",counter++);$$.children.push_back($1);
                                       //$$.children.push_back($3);}
                  | exp AND exp       {}//$$=Node("andexp","",counter++);$$.children.push_back($1);
                                       //$$.children.push_back($3);}
                  | exp OR exp        {}//$$=Node("orexp","",counter++);$$.children.push_back($1);
                                       //$$.children.push_back($3);}
                  | MINUS exp         {}//$$=Node("uminus","",counter++);$$.children.push_back($2);}
                  | NOT exp           {}//$$=Node("unot","",counter++);$$.children.push_back($2);}
                  | HASH exp          {}//$$=Node("uhash","",counter++);$$.children.push_back($2);}
                  ; 
                  

              
         prefixexp:var {$$=$1;}
                  |functioncall {$$=$1;}
                  |OPARENTHESIS exp CPARENTHESIS {$$=$2;}
                  ;

       functioncall:prefixexp args          {$$=new EFunction($1->name,$2);}
                  | prefixexp COLON NAME args {}//{$$=new EFunction($1->name,$4);}
                  ;                           

              args:OPARENTHESIS oexplist CPARENTHESIS {$$=$2;}
                                                         
                  | tableconstructor{}//{$$=$1;}
                  | STRING {$$=new MyString($1);} 
                  ;

          function: FUNCTION funcbody {std::cout<<"FUNCTION: ";}
         
          funcbody:OPARENTHESIS opt_parlist CPARENTHESIS block END1{}//$$=Node("Funcbody","",counter++)   ;
                                                                    //$$.children.push_back($2);
                                                                    //$$.children.push_back($4);}
                  ;

          parlist :namelist oparlist {}//$$=Node("parlist","",counter++);$$.children.push_back($1);
                                      //$$.children.push_back($2);}
                  |THREEPOINT        {}//$$=Node("threepointparlist","",counter++);}
                  ;

          oparlist:{}//$$=Node("emptyparlist","",counter++);}
                  |COMMA THREEPOINT {}//$$=Node("optparlist","",counter++);}
                  ;

       opt_parlist:{}//$$=Node("emptyparlist","",counter++);}
                  |parlist {$$=$1;}
                  ;

  tableconstructor:OBRACKET ofieldlist CBRACKET {}//$$=Node("bracketList","",counter++);$$.children.push_back($2);}
                  ;
         
         fieldlist: field {}//$$=Node("fieldList","",counter++);$$.children.push_back($1);}
                  | fieldlist fieldsep field {}//$$=$1;$$.children.push_back($3);}
                  ;
 
        ofieldlist: {}//$$=Node("emptyFieldList","",counter++);}
                  | fieldlist ofieldsep{$$=$1;}
                  ; 

            
             field: OSBRACKET exp CSBRACKET EQUAL exp {}//$$=Node("bracketfield","",counter++);
                                                       // $$.children.push_back($2);
                                                       //$$.children.push_back($5);}
                  | NAME EQUAL exp                    {}//$$=Node("assignfield","",counter++);
                                                      //$$.children.push_back(Node("singlevalue",$1,counter++));
                                                      //$$.children.push_back($3);}
                  | exp                               {}//$$=Node("expfield","",counter++);
                                                      //$$.children.push_back($1);}
                  ;

          fieldsep:COMMA 
                  |SEMICOLON
                  ;
         ofieldsep:{}
                  |fieldsep{}
                  ;
          