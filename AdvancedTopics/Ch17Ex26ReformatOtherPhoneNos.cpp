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
	for(sregex_iterator it (s.cbegin(),s.cend(),r), end; it != end; ++it){
		v.push_back(*it);
	}	
	return v;
}

int main (){
	string phone("(\\()?(\\d{3})(\\))?([-. ]?)(\\d{3})([-. ]?)(\\d{4})");
	regex r(phone);
	string fmt = "$2-$5-$7 ";
	std::ifstream f("phones");
	string str;
	while(getline(f, str)){
		auto v = valid(r,str);
		if(v.size() == 1) {cout <<regex_replace(v[0].str(), r, fmt); }
		for(size_t i = 1; i < v.size(); ++i){
			cout <<regex_replace(v[i].str(), r, fmt); 
		}
		cout <<endl;		
	}
	
	return 0;
}



