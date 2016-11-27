#include<iostream>
#include<string.h>
#include<sstream>
int main() 
{
std::string nlong= "%ld\n";std::string nst= "%s\n";std::string st= "%s";std::string llong= "%ld";long _t0=0; long _t1=0; long _t2=0; long _t3=0; 
 asm(
	"block0 : \n\t"
	"movq $22, %%rax\n\t"
	"movq $11, %%rbx\n\t"
	"subq %%rbx, %%rax\n\t"
	"movq %%rax, %[_t0]\n\t"
	"movq %[_t0], %%rax\n\t"
	"movq $1, %%rbx\n\t"
	"xor %%rdx, %%rdx \n\t"
	"divq %%rbx\n\t"
	"movq %%rax, %[_t1]\n\t"
	"movq %[_t1], %%rax\n\t"
	"movq $44, %%rbx\n\t"
	"mulq %%rbx\n\t"
	"movq %%rax, %[_t2]\n\t"
	"movq $13, %%rax\n\t"
	"movq %[_t2], %%rbx\n\t"
	"addq %%rbx, %%rax\n\t"
	"movq %%rax, %[_t3]\n\t"
	"movq %[_t3], %%rsi \n\t"
	"movq %[nlong], %%rdi \n\t"
	"movq  $0, %%rax \n\t"
	"call  printf \n\t"
	"movq  $0, %%rax \n\t"
:
:
	 [_t0] "g"(_t0),
	 [_t1] "g"(_t1),
	 [_t2] "g"(_t2),
	 [_t3] "g"(_t3),
	 [st] "g"(st),
	 [nlong] "g"(nlong),
	 [nst] "g"(nst),
	 [llong] "g"(llong)

:
);
}
