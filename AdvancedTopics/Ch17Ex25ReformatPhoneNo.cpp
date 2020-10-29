//Section 17.3.4 Using regex_replace
//Ex17.25, p744, ReWrite your phone program so that it writes only the first phone number for each person
//second implementation

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>

using std::cout; using std::endl; using std::vector;
using std::string; using std::getline; using std::sregex_iterator;
using std::regex; using std::regex_replace;using std::smatch;
using namespace std::regex_constants;

int main (){
	string phone("(\\()?(\\d{3})(\\))?([-. ]?)(\\d{3})([-. ]?)(\\d{4})");
	regex r(phone);
	string fmt = "$2-$5-$7 ";
	std::ifstream f("phones");
	string str;
	while(getline(f, str)){
		auto pos = str.find(" ");
		cout << str.substr(0,pos) <<": "; //wow!
		cout <<regex_replace(str, r, fmt,format_first_only|format_no_copy) <<endl;
	}
	
	return 0;
}



