#ifndef FORNODE
#define FORNODE

#include "statement.cpp"
#include "expression.cpp"
#include "variable.cpp"
#include "sequence.cpp"
#include "block.cpp"
#include "assign.cpp"
#include "ifcondition.cpp"
#include "comparitor.cpp"
#include "binoperation.cpp"
#include "costant.cpp"
#include <string>


class ForNode : public Statement{
public:
Expression *variable;
Expression *first;
Expression *second;
Sequence *code;

 ForNode(Expression *var, Expression *f, Expression *s, Sequence *block): variable(var), first(f), second(s), code(block){
 }	
void convertStatement(BBlock **current){
Assign a = Assign(variable,first);
a.convertStatement(current);
Expression *com= new Comparitor(variable, second, "=<");
com->convert(*current);

BBlock *btrue=new BBlock();
BBlock *test=btrue;
(*current)->trueExit=btrue;
btrue->trueExit=btrue;
code->printnode(&btrue);

Constant *c=new Constant("1");
BinOp b= BinOp(variable,c,"+");
string last=b.convert(btrue);//_t1=variable+1    
last.erase (last.begin());  
last.erase (last.begin()); 
last.erase (last.end()-1); 
Variable *v=new Variable(last);
Assign as = Assign(variable,v);//variable=_t1
as.convertStatement(&btrue);
Expression *ex= new Comparitor(variable, second, "=<");
ex->convert(btrue); //revaluate the expression first je second
btrue->trueExit=test;
BBlock *newblock=new BBlock();
btrue->falseExit=newblock;
(*current)->falseExit=newblock;
*current=newblock;

} 
};
#endif