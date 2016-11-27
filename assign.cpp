#ifndef ASSIGN
#define ASSIGN

#include "statement.cpp"
#include "expression.cpp"
#include "variable.cpp"

class Assign : public Statement{
public:
Expression *left;
Expression *right;

 Assign(Expression *l, Expression *r): left(l), right(r){
 }	
void convertStatement(BBlock **current){
  string last; 
  last=right->convert(*current);  
  string myleft=left->convert(*current);
  ThreeAd a=ThreeAd(myleft, "",last,"copy "+last);
  (*current)->instructions.push_back(a);
  //dump(current);
 }
 
void dump(BBlock *current){
 current->dump();
 }
};
#endif