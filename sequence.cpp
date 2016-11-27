#ifndef SEQUENCE
#define SEQUENCE

#include <string>
#include <iostream>
#include  <sstream>
#include  <fstream>
#include <list>
#include <map>
#include <vector>
#include <set>
#include "statement.cpp"

class Sequence : public Statement{
public:
	vector<Statement*> children;
	Sequence(){}

void addStatement(Statement *s){
    children.push_back(s);
	}
void printnode(BBlock **current){
	for(auto i: this->children){
		i->convertStatement(current);
	} 
}
void dotBlock(BBlock *start,ofstream &out){
out<<"Block"<<start->mycounter<<"[label="<<"\"{<h>Block"<<start->mycounter<<"|";
for(auto i: start->instructions){
if(i.op=="string")out<<i.result<<":= "<<" "<<i.op<<" "<<i.rhs<<" |";
else if(i.rhs=="io.read 0")out<<i.result<<":= "<<i.rhs<<" |";
else out<<i.result<<":= "<<i.lhs<<" "<<i.op<<" "<<i.rhs<<" |";
}
if(start->trueExit!=NULL) out<<"<t>True: Block"<<start->trueExit->mycounter<<" |";
else out<<"<t>True: Block"<<" NULL"<<" |";
if(start->falseExit!=NULL) out<<"<f>False: Block"<<start->falseExit->mycounter<<"}\""<<"];\n";
else out<<"<f>False: Block"<<" NULL"<<"}\""<<"];\n";
if(start->trueExit!=NULL) out<<"Block"<<start->mycounter<<":t ->Block"<<start->trueExit->mycounter<<":h;\n";
if(start->falseExit!=NULL) out<<"Block"<<start->mycounter<<":f ->Block"<<start->falseExit->mycounter<<":h;\n";
}
void dumpCFG(BBlock *start,ofstream &file,ofstream &out)
{
set<BBlock *> done, todo;
  todo.insert(start);
  while(todo.size()>0)
  {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);
    next->convertInstructions(file);
    next->dump();
    dotBlock(next, out);
    done.insert(next);
    if(next->trueExit!=NULL && done.find(next->trueExit)==done.end())
      todo.insert(next->trueExit);
    if(next->falseExit!=NULL && done.find(next->falseExit)==done.end())
      todo.insert(next->falseExit);
  }
}
};
#endif