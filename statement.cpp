#ifndef STATEMENT
#define STATEMENT

#include<string>
#include<iostream>
#include<sstream>
#include<list>
#include<map>
#include<vector>
#include<set>
#include "expression.cpp"
#include "block.cpp"


class Statement
{
public:
vector<Expression*> expressions;
vector<Statement*> children;


  Statement(){ }  
  virtual void convertStatement(BBlock **current){}
  virtual void dump(){}
};
#endif