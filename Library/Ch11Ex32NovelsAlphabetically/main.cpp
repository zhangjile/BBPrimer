//Section 11.3.5 Accessing elements in map and set
//Ex11.32, P440, problem: print the authors and their works alphabetically
#include <iostream>
#include <map>
#include <set>
#include <string>
using std::map; using std::multimap; using std::string; using std::pair;
using std::set;

//module of utilities, seperation of concerns, avoiding duplicate code
// p[e.first] can behave unexpectedly
using mss = map<string, set<string>>;
void PrintMapOfStringSet(mss p){
	for(const auto &e:p){
	//e is a local variable and safe!
		for(const auto &o:e.second){
			std::cout <<e.first <<": " <<o << std::endl;
		}
	}
}

void PrintAlpha1(const multimap<string, string> &m){
	mss p;
	for(const auto &e:m){
		p[e.first].insert(e.second);
	}
	PrintMapOfStringSet(p);
}

void PrintAlpha2 (const multimap<string, string> & Authors){
	mss Ordering;
	for(auto beg = Authors.begin(); beg != Authors.end(); ++beg){
		Ordering[beg->first].insert(beg->second);
	}

	PrintMapOfStringSet(Ordering);
}

//hahahahahahah, laugh my butt off. What a sensational gameplay!
void PrintAlpha3 (const multimap<string, string> & Authors){
	string name = Authors.begin()->first;
	mss Ordering;
	for(auto range = Authors.equal_range(name);range.first != Authors.end();){
		set<string> works {};
		//handling exit condition in the first place
		if(range.second == Authors.end()){ // but 'range.first != Author.end()'
			while(range.first != range.second){
			works.insert(range.first->second);
			++range.first;
			}
			Ordering.insert({name, works});
			range.first = Authors.end();
		}
		else{
			while(range.first != range.second){
				works.insert(range.first->second);
				++range.first;
			}
			Ordering.insert({name, works});
			name = range.second->first;
			range = Authors.equal_range(name);
		}				
	}
	PrintMapOfStringSet(Ordering);
}

//this one is the most triumphant!
void PrintAlpha4 (const multimap<string, string> & Authors){
	mss Ordering;
	set<string> works;
	for(auto beg = Authors.begin(), Upper = beg; beg != Authors.end(); beg = Upper){
		while(beg->first == Upper->first){
			works.insert(Upper->second);
			Upper++;
		}
		Ordering.insert({beg->first, works});
		works.clear();
	}
	
	PrintMapOfStringSet(Ordering);
}

int main()
{
	multimap<string, string> authors = {
		{"FangFang","Soft Burial"},	//方方，『軟埋』
		{"FangFang", "Diary"},	//方方，『封城日記』
		{"WuSi", "Hidden Rules"},	//吳思，『潛規則』		
		{"Clint Eastwood","Gunman"}
	};
	
	PrintAlpha4(authors);
	
	return 0;
}
