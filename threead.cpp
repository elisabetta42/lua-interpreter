
#ifndef THREEAD
#define THREEAD

#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <fstream>

using  namespace std;

class ThreeAd
{
public:
  string op;
  string result, lhs, rhs;
  int oper=0;

  ThreeAd(string out, string o, string l, string r)
    :  result(out), op(o), lhs(l), rhs(r)      {convertOperation(o);}
  


  void convertOperation(string op){
  if(op=="+"){oper=1;}
  if(op=="-"){oper=2;}
  if(op=="*"){oper=3;}
  if(op=="/"){oper=4;}
  if(op=="="){oper=5;}
  if(op==""){oper=6;}
  if(op=="%"){oper=7;}
  }
  void dump()
  {
    cout << result << " <- " << lhs << " " 
         << op << " " << rhs << endl;
  }
  void convertAssembly(ofstream &file){
  //cout<<"i: "<<count<<endl;
   switch(oper){
            case 1:   file<<"\t\"movq "<< lhs<< ", %%rax\\n\\t\""<<"\n"<<
                            "\t\"movq "<< rhs<< ", %%rbx\\n\\t\""<<"\n"<<
                            "\t\"addq %%rbx, %%rax\\n\\t\""<<"\n"<<
                            "\t\"movq %%rax" << ", "<<result <<"\\n\\t\""<<endl;break;

            case 2:    file<<"\t\"movq "<< lhs<< ", %%rax\\n\\t\""<<"\n"<<
                             "\t\"movq "<< rhs<< ", %%rbx\\n\\t\""<<"\n"<<
                             "\t\"subq %%rbx, %%rax\\n\\t\""<<"\n"<<
                             "\t\"movq %%rax" << ", "<<result <<"\\n\\t\""<<endl;break;

            case 3:   file<<"\t\"movq "<< lhs << ", %%rax\\n\\t\""<<"\n"<<
                            "\t\"movq "<< rhs << ", %%rbx\\n\\t\""<<"\n"<<
                            "\t\"mulq %%rbx\\n\\t\""<<"\n"<<
                            "\t\"movq %%rax" << ", "<<result <<"\\n\\t\""<<endl;break;

            case 4:   file<<"\t\"movq "<< lhs << ", %%rax\\n\\t\""<<"\n"<<
                            "\t\"movq "<< rhs<< ", %%rbx\\n\\t\""<<"\n"<<
                            "\t\"xor %%rdx, %%rdx \\n\\t\""<<"\n"<<
                            "\t\"divq %%rbx\\n\\t\""<<"\n"<<
                            "\t\"movq %%rax" << ", "<<result <<"\\n\\t\""<<endl;break;

            //case 5:   file<<"\t \"movq %%rax" << ", "<<result <<"\\n\\t\""<<endl;break;

            case 6:   file<<"\t\"movq "<< lhs  << ", %%rax\\n\\t\""<<"\n"
                          <<"\t\"movq %%rax" << ", "<<result <<"\\n\\t\""<<endl;break;

            case 7:   file<<"\t\"movq "<< lhs << ", %%rax\\n\\t\""<<"\n"<<
                            "\t\"movq "<< rhs<< ", %%rbx\\n\\t\""<<"\n"<<
                            "\t\"xor %%rdx, %%rdx \\n\\t\""<<"\n"<<
                            "\t\"divq %%rbx\\n\\t\""<<"\n"<<
                            "\t\"movq %%rdx" << ", "<<result <<"\\n\\t\""<<endl;break;
  }
}
    
};
#endif