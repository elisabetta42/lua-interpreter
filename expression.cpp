#ifndef EXPRESSION
#define EXPRESSION

#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <vector>
#include <set>
#include "block.cpp"
#include "threead.cpp"
#include <string>

class Expression    
{
public:
Expression *left, *right;
static int nameCounter;
int value;
string name;
string type;
static set<string> table;
static set<string> input_string;
static set<string> last_input;

  Expression( Expression *l, Expression *r)  : left(l), right(r){}

  virtual void dump(/*int depth=0*/)
  {
    /*for(int i=0; i<depth; i++)  
    if(left!=NULL)
      left->dump(depth+1);
    if(right!=NULL)
      right->dump(depth+1);*/
  }
virtual void setName(string newName){
name=newName;
}

string newName()
{
stringstream result;
  result << "_t" << nameCounter++;
  return result.str();
}
  virtual void namePass( map<Expression*,string> &nameMap){
  }

  virtual void emitPass(map<Expression*,string> &nameMap, BBlock *out){                                 
      }
virtual string convert(BBlock *out)
{
map<Expression*,string> naming;
namePass(naming);
emitPass(naming,out);
return naming[this];
}
virtual string rightsign(string variable){ }
virtual void convertInstruction( ofstream &file){}
};
#endif