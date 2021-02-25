#include <iostream>
#include "ex7_57.h"

int main(){
	//access static class members 
	Account a;
	std::cout << a.rate() << std::endl;	//via class object
	a.rate(0.5);
	std::cout << Account::rate() << std::endl;	//scope operator
	return 0;
}
