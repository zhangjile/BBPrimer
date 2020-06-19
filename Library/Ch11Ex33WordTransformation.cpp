//Section 11 problem: replace initials with complete words

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

using std::ifstream; using std::map; using std::string; using std:: istringstream;

map<string, string> BuildMap (ifstream &is){
	map<string, string> Pattern;
	string key, value;
	while(is >>key && getline(is, value)){
		Pattern[key] = value;
	}
	return Pattern;
}

const string &Transform (map<string, string> m, const string &s){
	auto it = m.find(s); 
	if(it != m.end()){
		return it->second;
	}else {
		return s;
	}
}

void WordTransfor(ifstream &rule, ifstream &input){
	auto Pattern = BuildMap(rule);
	string text;
	while(input >> text){
		std::cout << Transform(Pattern, text) << std::endl;
		//the friend is just around the corner. 'std::endl' solves the problem.
	}
}


int main ()
{
	ifstream Pairing("rules");
	ifstream Input ("text");
	WordTransfor(Pairing, Input);
	return 0;
}
