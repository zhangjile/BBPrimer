//Section 11 problem: replace initials with complete words

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

map<string, string> BuildMap (ifstream &is){
	map<string, string> Pattern;
	string key, value;
	while(is >>key && getline(is, value)){
		if(value.size() > 1)	//good habit to match if else pair
			Pattern[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key); 
	}
	return Pattern;
}

//gameplay2
//mapping initials to complete phrases
map<string, string> BuildMap2 (ifstream &is){
	map<string, string> Pattern;
	string line;	
	while(getline(is, line)){
		auto it = line.find(' ');
		string key = line.substr(0,it);
		string value = line.substr(++it);
		Pattern[key] = value;
	}
	return Pattern;
}

//from perspective of design, it‘s much better to return something 
const string &TransformWord (const map<string, string> &m, const string &s){
	auto it = m.find(s); 
	if(it != m.cend()){
		return it->second;
	}else {
		return s;
	}
}

void TransformMessage(ifstream &rule, ifstream &input){
	auto Pattern = BuildMap2(rule);
	string text;
	
	//process message text line by line
	while(getline(input,text)){
		std::istringstream ist(text);
		string word;
		while(ist>>word){
			std::cout << TransformWord(Pattern, word) << " ";
		}
		std::cout <<std::endl;
	}
	
}


int main ()
{
	ifstream Pairing("rules");
	ifstream Input ("text");
	TransformMessage(Pairing, Input);
	return 0;
}
