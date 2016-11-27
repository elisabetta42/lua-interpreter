#ifndef CALL
#define CALL

#include "statement.cpp"
#include "expression.cpp"
#include "variable.cpp"
#include "sequence.cpp"
#include "block.cpp"
#include "myfunction.cpp"
#include <string> 

class Call : public Statement{
public:
EFunction *functioncall;
string original;
 Call(EFunction *fncall): functioncall(fncall){
 }	
void convertStatement(BBlock **current){

string last=functioncall->argument->convert(*current);
string kind=functioncall->argument->type;
original=functioncall->argument->newName();
string value="%["+original+"]";
if(functioncall->fname=="print"||functioncall->fname=="io.write"){
	if(kind=="string"){
Expression::input_string.insert(original+" "+last);
}
}
 ThreeAd a=ThreeAd(value, kind ,last,functioncall->fname+" 0");
//cout<<"dumping a"<<endl;
//a.dump();
(*current)->instructions.push_back(a);

} 
};
#endif