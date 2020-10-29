#include <iostream>

int main (){
	unsigned i = 1;
	char* c = (char*)(&i);
	if(c) std::cout <<"Little" << std::endl;
	else std::cout <<"Big" << std::endl;
	return 0;
}
