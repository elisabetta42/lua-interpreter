  #include <string>
  #include <iostream>
  #include <vector>
  #include <fstream>
  #include "value.h" 
  #include "environment.h" 
  #include <math.h>       /* remainder */
using namespace std;

                      //structure integer, floating, String, bolean
                      //hexadecimal
                      //esponential
                      //create an hash map for the name of the function
                      //controllare che quando si assegna stringa a variabile
                      //handle exponential
                      //print con più arguments


class Node{
public:
  std::string tag, value;
  int myid;
  std::vector<Node> children;
  Node(const std::string& t, const std::string& v, int id) : tag(t) , value(v), myid(id){}
  Node() 
  {
    myid=0;
    tag = "uninitialised" ; 
    value = "uninitialised";
  }

  void dump(int depth=0) { 

    for(int i=0; i<depth; i++) 
      std::cout << " "; std::cout << tag << ":" << value <<":" << myid << std::endl; 
    std::vector<Node>::iterator i;
    for(i=children.begin(); i!=children.end(); i++) 
      (*i).dump(depth+1); 

  }
  void dump_tree(int &currentNode, ofstream &out){
                              //create a file stream
    int current=currentNode;
    out<<currentNode<<" [label=\""<<tag<<"\\n"<<value<<"\"];"<<"\n";
    currentNode++;
    std::vector<Node>::iterator i;
    for(i=children.begin(); i!=children.end(); i++) {
      out<<current<<" -> "<<currentNode<<";\n";
      (*i).dump_tree(currentNode,out); 
    }
  }
  void compile(){
}
};