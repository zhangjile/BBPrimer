//Section 11.3.5 Accessing elements in map and set
//Ex11.31, P440, problem: delete a specific piece of work by an author
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iterator>
using std::multimap; using std::string; using std::pair; using std::equal_range;
using std::set; using std::iterator;

void DeletePiece(multimap<string, string> &m, pair<string, string> t){
	auto it = m.find(t.first);
	size_t t_count = m.count(t.first);
	while(t_count > 0){
		if(it->second == t.second){
			m.erase(it);
			break;	//ok, I see it now. it is invalidated when it is deleted
		}
		++it;
		--t_count;
	}
}
/*
multimap<string, string> ReorderMap (multimap<string, string> authors){
	multimap<string, string> ReorderedMap;
	for(auto it = authors.begin(); it != authors.end();){		
		if(authors.count(it->first) >1){
			multimap<string, string> RearrangeMap;
			for(auto i = authors.count(it->first); i >0; --i){
				RearrangeMap.insert(it->second, it->first);
			}
			for(auto e:RearrangeMap){
				ReorderedMap.insert(e.second, e.first);
				++it;
			}
		} else {
			ReorderedMap.insert(*it);	//insert(it), haha
			++it;
		}
	}
	return ReorderedMap;
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
	pair<string, string> NobelPrize ("FangFang","Diay");
	DeletePiece(m, NobelPrize);
	
	
	
	for(auto it = m.begin(); it != m.end();){
		auto range = m.equal_range(it->first);
		if(m.count(it->first) > 1){
			sort(range.first, range.second, [](pair<string, string> a, pair<string,string> b){return a.second < b.second;});
			std::cout<< (++range.first)->first << ", " << (++range.first)->second << std::endl;
		}else {
			std::cout << it->first << it->second <<std::endl;
			++it;
		}
	}
	
	
	//for_each
	
	for(auto it = m.begin(); it != m.end();){
		auto Range = m.equal_range(it->first);
		set<string> s;
		for_each(Range.first, Range.second, [=](std::pair<string, string>::iterator a){s.insert(a->second);});
	}
	
	
	return 0;
}
