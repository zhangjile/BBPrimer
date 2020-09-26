//CppNuts
#include <iostream>
#define ADD(x, y) x+y	//macro

int main(){
	std::cout << "We love C++\n";
	std::cout << ADD(1,2);
	return 0;
	
}

/*
g++ Nuts0926Compilation.cpp --save -temps
vi Nuts0926Compilation.ii	//code after preprocessing, 
							//comments are gone, ADD expression processed
vi Nuts0926Compilation.s	//assembly code, the real low-level code
vi
*/