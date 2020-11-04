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

vector<smatch> valid(const regex& r, const string& s){
	vector<smatch> v;
	smatch m;
	regex_search(s,m,r);
	v.push_back(m);
	return v;
}

int main (){
	string phone("(\\()?(\\d{3})(\\))?([-. ]?)(\\d{3})([-. ]?)(\\d{4})");
	regex r(phone);
	string fmt = "$2-$5-$7 ";
//	fmt = "($2)$5-$7";	//yeah (201)555-0168
	std::ifstream f("phones");
	string str;
	while(getline(f, str)){
		auto v = valid(r,str);
		for(const auto& ele: v){
			cout <<regex_replace(ele.str(), r, fmt) <<endl;
		}		
	}
	
	return 0;
}



