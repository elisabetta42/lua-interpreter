#ifndef BBLOCK
#define BBLOCK

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <vector>
#include <set>
#include "threead.cpp"


class BBlock
{
public:
static int blockCounter;
list<ThreeAd> instructions;
BBlock *trueExit, *falseExit;
int mycounter=0;

  
  BBlock()
    :  trueExit(NULL), falseExit(NULL)  {
      mycounter=blockCounter;
      blockCounter++;
    }

  void dump()
  {
    cout << "BBlock " << mycounter << endl;
    for(auto i : instructions)
      i.dump();
    if(trueExit!=NULL)cout << "True: " << trueExit->mycounter<< endl;
    if(trueExit!=NULL)cout << "False: " << falseExit->mycounter << endl;
    
  }
  void convertInstructions(ofstream &file){
   
    //aggiungere ++ qunado si cancella il dump method
    file<<"\t\"block"<<mycounter<<" : \\n\\t\""<<endl;
    for(auto i : instructions){
      if(i.rhs=="io.read 0"){
    file<<"\t\"leaq "<<i.result<<", %%rsi \\n\\t\"\n\t"<<
        "\"movq %[llong], %%rdi\\n\\t\"\n\t"<<
        "\"call scanf\\n\\t\"\n";
      }
      else if(i.rhs=="print 0"||i.rhs=="io.write 0"){
    if(i.op=="costant"||i.op=="variable"){
    file<<"\t\"movq "<< i.lhs<<", %%rsi \\n\\t\""<<"\n\t";
       if(i.rhs=="print 0"){
       file <<"\"movq %[nlong], %%rdi \\n\\t\""<<"\n\t";
       }
       else if (i.rhs=="io.write 0"){
       file <<"\"movq %[llong], %%rdi \\n\\t\""<<"\n\t";
       }      
    file<<"\"movq  $0, %%rax \\n\\t\""<<"\n\t" 
        <<"\"call  printf \\n\\t\""<<"\n\t" 
        <<"\"movq  $0, %%rax \\n\\t\""<<endl;
    }
    else if(i.op=="string"){
      file<<"\t\"movq "<< i.result<<", %%rsi \\n\\t\""<<"\n\t";
      if(i.rhs=="print 0"){
      file <<"\"movq %[nst], %%rdi \\n\\t\""<<"\n\t";
      }
      else if (i.rhs=="io.write 0"){
      file <<"\"movq %[st], %%rdi \\n\\t\""<<"\n\t";
      }
     file <<"\"movq  $0, %%rax \\n\\t\""<<"\n\t" 
          <<"\"call  printf \\n\\t\""<<"\n\t" 
          <<"\"movq  $0, %%rax \\n\\t\""<<endl;
        }  
      }
    else if( i.op=="jne"){
    
    file<<"\t\"movq "<< i.lhs<< ", %%rax\\n\\t\""<<"\n"<<
          "\t\"movq "<< i.rhs<< ", %%rbx\\n\\t\""<<"\n"<<
          "\t\"subq %%rax, %%rbx\\n\\t\""<<"\n"<<
          "\t\""<<i.op<<" block"<<falseExit->mycounter<<"\\n\\t\""<<"\n"
          "\t\""<<"jmp block"<<trueExit->mycounter<<"\\n\\t\""<<endl;
    }
    else if(i.op=="jge"||i.op=="jg"){
    file<< "\t\"movq "<< i.lhs<< ", %%rax\\n\\t\""<<"\n"<<
          "\t\"movq "<< i.rhs<< ", %%rbx\\n\\t\""<<"\n"<<
          "\t\"subq %%rbx, %%rax\\n\\t\""<<"\n"<<
          "\t\""<<i.op<<" block"<<falseExit->mycounter<<"\\n\\t\""<<"\n"
          "\t\""<<"jmp block"<<trueExit->mycounter<<"\\n\\t\""<<endl;
    }
    else {
      i.convertAssembly(file);
    }
    }
  }

};
#endif