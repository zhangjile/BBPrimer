//it's true that there's some hidden format-related evils that disrupt the output, once again in addition to 4 or 5 troubles of the same reason!
//if 2 files (rules and text) are created using this utility, everything is fine!

#include <iostream>
#include <fstream>
#include <string>

void CreateData(){
	std::string s {};
	std::ofstream of("text");
	while(getline(std::cin, s) && s!="q"){
		of << s <<"\n"; 
	}
	std::cout << std::endl;
}

int main (){
	CreateData();
	return 0;
}
