#ifndef EFUNCTION
#define EFUNCTION

#include "expression.cpp"
#include "threead.cpp"
#include <string>

class EFunction: public Expression{
public:
Expression *argument;
string fname;
 EFunction(string fncname,Expression *arg): fname(fncname),argument(arg),Expression(NULL,NULL){
 }
 string convert(BBlock *current){
 	string last=argument->name;
    string myoriginal=this->newName();
 	string value="%["+myoriginal+"]";
 	if(fname=="io.read"){
 	Expression::table.insert(myoriginal);	
 	}
 	else Expression::table.insert(last);
 	string k= argument->type;
 	ThreeAd a=ThreeAd(value,"",last, fname + " 0");
 	current->instructions.push_back(a);  
 	return value;
 }
};
#endif