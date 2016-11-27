#ifndef COMPARITOR
#define COMPARITOR

#include <string>
#include <list>
#include <map>
#include <vector>
#include <set>
#include "expression.cpp"

class Comparitor : public Expression {
public:
	Expression *left;
	Expression *right;
	string op;
	Comparitor(Expression *l, Expression *r, string operation): left(l),right(r) , Expression(l,r){	
  
  if(operation=="==")op="jne";
    else if(operation=="<")op="jge";
    else if(operation==">")op="jle";    
    else if(operation=="=<") op="jg";
    else if(operation=="=>") op="jl";  
  else op=operation;   
	}

	void namePass(map<Expression*,string> &nameMap){
          if(right==NULL && left==NULL){
            nameMap[this]="%["+name+"]";
            table.insert(name);
          }
          else{
             if(right!=NULL)right->namePass(nameMap);
             if(left!=NULL)left->namePass(nameMap);
             name=newName();
             nameMap[this]="%["+name+"]";
             table.insert(name);
          }
  }

  void emitPass(map<Expression*,string> &nameMap, BBlock *out){

  
  if(right==NULL && left==NULL){}
  else{
    if(left!=NULL) left->emitPass(nameMap,out);
    if(right!=NULL)right->emitPass(nameMap,out);
         ThreeAd a=ThreeAd(nameMap[this], op, nameMap[left], nameMap[right]);
         out->instructions.push_back(a);                                
      }
    }
};
#endif

