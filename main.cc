#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include "binary.tab.hh" 
#include "threead.cpp"

extern unsigned int total;
extern Sequence* root;
int Expression::nameCounter=0;	
int BBlock::blockCounter=0;
set<string> Expression::table;
set<string> Expression::input_string;
set<string> Expression::last_input;

using  namespace std;


extern FILE *yyin;

void yy::parser::error(std::string const&err)
{  
std::cout << "It's one of the bad ones... " << err << std::endl;
}        

int main(int argc, char **argv) 
{ 
        
	if (argc < 2)
	{
		std::cout << "Error filename not specified.\n";
		exit(-1);
	}

yyin = fopen(argv[1], "r");

yy::parser parser;
ofstream out;
int count=0;
out.open("output.dot");
out<<"digraph structs { node [shape=record];\n";
if(!parser.parse())
{
//root.dump();
//root.dump_tree(count,out);


BBlock *start = new BBlock();
BBlock *current = start;
root->printnode(&current);

 ofstream file;
 file.open("target.cc");
 file<<"#include<iostream>"<<endl;
 file<<"#include<string.h>"<<endl;
 file<<"#include<sstream>"<<endl;
 file<<"int main() \n{"<<endl;
 file<<"std::string nlong= \"%ld\\n\";";
 file<<"std::string nst= \"%s\\n\";";
 file<<"std::string st= \"%s\";";
 file<<"std::string llong= \"%ld\";";
 for(auto i: Expression::table){
 	file<<"long "<<i<<"="<<"0"<<"; "; 
 	// cout<<"table i"<<i<<endl;
 }
  for(auto i: Expression::input_string){
  	std::stringstream  stream(i);
    std::string  word;
    stream >> word;
    i.erase(i.begin(), i.begin() + word.size());
 	file<<"std::string "<<word<<"="<<i<<";"; 	
 	file<<"long len"<<word<<"="<<word<<".size() ;"; 
 	Expression::last_input.insert(word);	 	
 }
 file<<"\n asm("<<endl;
 root->dumpCFG(start,file,out);
 out<<"}";
file<<":"<<endl;
file<<":"<<endl;
 for(auto i: Expression::table){
 	//: [x] "=g" (x) 	
 	file<<"\t ["<<i<<"] \"g\""<<"("<<i<<"),\n";
 }
 
 for(auto i: Expression::last_input){
 	file<<"\t ["<<i<<"] \"g\""<<"("<<i<<"),\n";
 	file<<"\t ["<<"len"<<i<<"] \"g\""<<"(len"<<i<<"),\n";
 }
  
 file<<"\t [st] \"g\"(st),\n";
 file<<"\t [nlong] \"g\"(nlong),\n";
 file<<"\t [nst] \"g\"(nst),\n";
 file<<"\t [llong] \"g\"(llong)\n";
 file<<"\n:\n);\n}\n";
}

fclose(yyin);
return 0;
}