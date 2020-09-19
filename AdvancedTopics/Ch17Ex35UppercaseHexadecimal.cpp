
//Section 17.5.1 Formatted Input and Output
//Ex17.35, p 760, write a version of the program from page 758, that printed the square root of 2 but this time print hexadecimal digits in uppercase

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>	//EOF, end of file

using std::cout; 

int main(){
	cout<<std::left 
	<<std::setw(20) << "decimal: "<<std::setw(20) <<100 * sqrt(2) <<"\n"
	<<std::setw(20) << "scientific: " << std::scientific<<std::setw(20) <<100 * sqrt(2) <<"\n"	//02
	<<std::setw(20) << "fixed: " << std::fixed <<std::setw(20) <<100 * sqrt(2) <<"\n"
	<<std::setw(20) <<"hexadecimal: "<<std::uppercase <<std::hexfloat <<100*sqrt(2)<<"\n\n";	
	//A, the result is wrong, test it on desktop
	
	int ch;
	while((ch = std::cin.get()) != EOF){
		cout.put(ch);
	}
	return 0;
}
