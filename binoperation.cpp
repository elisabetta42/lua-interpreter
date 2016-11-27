#ifndef BINOPERATION
#define BINOPERATION

#include <list>
#include <map>
#include <vector>
#include <set>
#include <string>
#include "expression.cpp"


class BinOp : public Expression {
public:
	string op;
	
	BinOp(Expression *l, Expression *r, string operation): op(operation), Expression(l,r){	
    op=operation;
    type="costant";
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
