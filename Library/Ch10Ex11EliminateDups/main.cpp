//Chapter 10 Generic Algorithms 
//Ex10.9, P385 mission: implement your own version of ElimDups
//Ex10.11, P387 
//reorder the words according length AND 
	//keep the alphabetical order among elements of the same length words
//Ex10.16, write your own version of void Biggies,

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::string; using std::vector; using std::stable_sort; using std::unique; 
using std::replace;

void Display (const vector<string> &v){
	for(const string s : v){
		std::cout << s << " ";
	}
	std::cout << "\n";
}

bool IsShorter(const string &s1, const string &s2){
	return s1.size () < s2.size();
}

void EliminateDups (vector<string> &v){
	sort(v.begin(), v.end());
	auto pos = unique(v.begin(), v.end()); //unique works on a sorted sequence	
	v.erase(pos, v.end());
	
	//Ex10.11
	stable_sort(v.begin(),v.end(),IsShorter);
}

void Biggies(vector<string> &v, size_t sz){
	EliminateDups(v);
	auto it = find_if(v.begin(),v.end(),[sz](const string &s){return s.size() > sz;});
	size_t Count = v.end() - it;
	std::cout << Count << std::endl;
	for_each(it, v.end(), [](const string &s){std::cout<< s << " ";});
	std::cout << std::endl;
}

int main(){
	vector<string> v = {"Win","Will","Trump","Win", "Win", "United", "States","Donald","Win"};
	//v = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	Display(v);
	
	EliminateDups(v);
	Display(v);
	
	//fill_n
	fill_n(back_inserter(v),3," yeah");
	Display(v);
	
	//doesn't work on Mobile C, no function to call for replace!
	//cf BB/Section20/Algorithms
	replace(v.begin(),v.end(), " yeah", "!"); 
	
	Biggies(v,5);
	
	return 0;
}
