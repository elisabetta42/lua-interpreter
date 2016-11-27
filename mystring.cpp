#ifndef MYSTRING
#define MYSTRING

#include <string>
#include <fstream>
#include "expression.cpp"


class MyString : public Expression {
public:
	string value;
  
	MyString (string myvalue): value(myvalue), Expression(NULL,NULL) {
		setName(value);
    type="string";
	}
void dump(){
	//cout<<value;
}
void namePass( map<Expression*,string> &nameMap){
 
          if(right==NULL && left==NULL){
            nameMap[this]=name;
          }
  }

 void emitPass(map<Expression*,string> &nameMap, BBlock *out){

        /* ThreeAd a=ThreeAd(nameMap[this], "", name, "");
         out->instructions.push_back(a);  */
                                        
      }
};

#endif