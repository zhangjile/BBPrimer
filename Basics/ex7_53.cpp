#include <iostream>
#include "ex7_53.h"

int main(){
	constexpr Debug io(false, true, false);
	constexpr Debug prod(false);
	if(prod.any()) std::cerr << "error" <<"\n";
	return 0;
}
