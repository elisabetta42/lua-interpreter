#ifndef IFCONDITION
#define IFCONDITION

#include "statement.cpp"
#include "expression.cpp"
#include "variable.cpp"
#include "sequence.cpp"
#include "block.cpp"
#include <string>


class IfCnd : public Statement{
public:
Expression *condition;
Sequence *code;
Sequence *elseclose;

 IfCnd(Expression *cnd, Sequence *block, Sequence *elsec): condition(cnd), code(block), elseclose(elsec){

 }	
void convertStatement(BBlock **current){
BBlock *btrue;
BBlock *bfalse;
BBlock *newblock;

string last=condition->convert(*current);

//if branch
  btrue=new BBlock();
 
  for(auto i: code->children){
  i->convertStatement(&btrue);  
  }
//else branch
 if(elseclose!=NULL){
  bfalse=new BBlock();
  for(auto i: elseclose->children)
  i->convertStatement(&bfalse); 
  }
  newblock=new BBlock();
   
  (*current)->trueExit=btrue;
  (*current)->falseExit=newblock;
  btrue->falseExit=*current;
  btrue->trueExit=newblock;

  if(elseclose!=NULL){
  bfalse->trueExit=newblock;
  bfalse->falseExit=*current;
 (*current)->falseExit=bfalse; 
  }
  *current=newblock; 
  }
};
#endif