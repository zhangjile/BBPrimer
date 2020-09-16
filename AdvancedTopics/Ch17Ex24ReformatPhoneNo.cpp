//Section 17.3.4 Using regex_replace
//Ex17.24, p744, Write your own version of the program to reformat phone numbers

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>

using std::cout; using std::endl; using std::vector;
using std::string; using std::getline; using std::sregex_iterator;
using std::regex; using std::regex_replace;using std::smatch;

int main (){
	string phone("(\\()?(\\d{3})(\\))?([-. ]?)(\\d{3})([-. ]?)(\\d{4})");
	regex r(phone);
	string fmt = "$2-$5-$7 ";
	std::ifstream f("phones");
	string str;
	while(getline(f, str)){
		cout <<regex_replace(str, r, fmt) <<endl;
	}
	
	return 0;
}



