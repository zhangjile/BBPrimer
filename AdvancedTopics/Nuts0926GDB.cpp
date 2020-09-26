//CppNuts
//get the hang of gdb, run, breakpoint, next, step, continue, frame, backtrace,info, 

#include <iostream>

void func3(){
	int Func3Variable = 30;
	std::cout << Func3Variable << "\n";
}

void func2(){
	int Func2Variable = 20;
	std::cout << Func2Variable << "\n";
	func3();
}

void func1(){
	int Func1Variable = 10;
	std::cout << Func1Variable << "\n";
	func2();
}

int main(){
	int MainVariable = 1;
	std::cout << MainVariable << "\n";
	func1();
	return 0;
}
