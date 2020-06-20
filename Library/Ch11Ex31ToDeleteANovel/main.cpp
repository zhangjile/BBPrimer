//Section 11.3.5 Accessing elements in map and set
//Ex11.31, P440, problem: delete a specific piece of work by an author
#include <iostream>
#include <map>
#include <string>
using std::multimap; using std::string; using std::pair;

void DeletePiece(multimap<string, string> &m, pair<string, string> t){
	auto it = m.find(t.first);
	size_t t_count = m.count(t.first);
	while(t_count > 0){
		if(it->second == t.second){
			m.erase(it);
			break;	//ok, I see it now. 'it' is invalidated when 'it' is deleted
		}
		++it;
		--t_count;
	}
}
/*
	//to keep it alive, here is a funny way:)
		if(it->second == t.second){
			auto it_shadow = it;
			++it;
			m.erase(it_shadow);
		}
*/


int main()
{
	multimap<string, string> m = {
		{"FangFang","Soft Burial"},	//方方，『軟埋』
		{"FangFang", "Diary"},	//方方，『封城日記』
		{"WuSi", "Hidden rules"},	//吳思，『潛規則』		
		{"Clint Eastwood","Gunman"}
									};
	pair<string, string> NobelPrize ("FangFang","Dia");    // "FangFang","Diary" entry is in the multimap
	DeletePiece(m, NobelPrize);
	
	
	
	for(const auto & e: m){
		std::cout<< e.first << ", " << e.second << std::endl;
	}
	return 0;
}
