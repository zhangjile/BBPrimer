//Section 11.3.5 Accessing elements in map and set
//Ex11.32, P440, problem: print the authors and their works alphabetically
#include <iostream>
#include <map>
#include <set>
#include <string>
using std::map; using std::multimap; using std::string; using std::pair;
using std::set;


void PrintAlphabetically(const multimap<string, string> &m){
	map<string, set<string>> p;
	for(const auto &e:m){
		p[e.first].insert(e.second);
	}
	for(const auto &e:p){
		for(const auto &o:p[e.first]){
			std::cout <<e.first <<": " <<o << std::endl;
		}
	}
}

int main()
{
	multimap<string, string> m = {
		{"FangFang","Soft Burial"},	//方方，『軟埋』
		{"FangFang", "Diary"},	//方方，『封城日記』
		{"WuSi", "Hidden Rules"},	//吳思，『潛規則』		
		{"Clint Eastwood","Gunman"}
	};
	
	PrintAlphabetically(m);
	
	return 0;
}
