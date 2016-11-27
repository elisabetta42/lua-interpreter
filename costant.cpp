#ifndef CONSTANT
#define CONSTANT

#include <string>
#include <fstream>
#include "expression.cpp"


class Constant : public Expression {
public:
	string value;
	Constant(string myvalue): value(myvalue), Expression(NULL,NULL) {
		setName(value);
    type="costant";
	}
void dump(){
	//cout<<value;
}
void namePass( map<Expression*,string> &nameMap){
 
          if(right==NULL && left==NULL){
            nameMap[this]="$"+name;
          }
  }

 void emitPass(map<Expression*,string> &nameMap, BBlock *out){

        /* ThreeAd a=ThreeAd(nameMap[this], "", name, "");
         out->instructions.push_back(a);  */
                                        
      }
};

#endif

