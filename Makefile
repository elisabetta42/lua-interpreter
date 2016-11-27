comp: lex.yy.c binary.tab.o main.cc block.cpp statement.cpp expression.cpp threead.cpp sequence.cpp assign.cpp costant.cpp variable.cpp binoperation.cpp ifcondition.cpp myfunction.cpp call.cpp comparitor.cpp fornode.cpp mystring.cpp
		g++ -g -std=c++11 -ocomp binary.tab.o lex.yy.c main.cc block.cpp statement.cpp expression.cpp threead.cpp sequence.cpp assign.cpp costant.cpp variable.cpp binoperation.cpp ifcondition.cpp myfunction.cpp call.cpp comparitor.cpp fornode.cpp mystring.cpp
binary.tab.o: binary.tab.cc 
			  g++ -g -std=c++11 -c binary.tab.cc 
binary.tab.cc: binary.yy 
			   bison --verbose binary.yy 
lex.yy.c: binary.ll binary.tab.cc 
	flex binary.ll 
clean:
	rm -f binary.tab.* lex.yy.c* comp

.PHONY: comp