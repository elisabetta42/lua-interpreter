#ifndef VARIABLE
#define VARIABLE


#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <vector>
#include <set>
#include "expression.cpp"
#include <string>

class Variable : public Expression {
public:
 string value;
 
	Variable(string myvalue): value(myvalue), Expression(NULL,NULL){		
		setName(value);
    type="variable";
	}
	void namePass( map<Expression*,string> &nameMap){
          if(right==NULL && left==NULL){       
            table.insert(name);
            nameMap[this]="%["+name+"]";
          }
  }  
   void emitPass(map<Expression*,string> &nameMap, BBlock *out){
 /*
         ThreeAd a=ThreeAd(nameMap[this], "", name, "");
         out->instructions.push_back(a);    */                              
      }
};
#endif