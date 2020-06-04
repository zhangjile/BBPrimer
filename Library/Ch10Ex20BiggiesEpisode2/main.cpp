//Chapter 10 Generic Algorithms 
//10.3.2 Lambda Expressions
//Ex10.19, P392, use stable_partition
//10.3.3 Lambda captures and returns
//Ex10.20 P397, count_if comes in play

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
	auto pos = unique(v.begin(), v.end()); 	
	v.erase(pos, v.end());
	
	//Ex10.11
	stable_sort(v.begin(),v.end(),IsShorter);
}

void Biggies(vector<string> &v, size_t sz){
	EliminateDups(v);
	
	//Ex10.19
	auto it = stable_partition(v.begin(),v.end(),[sz](const string &s){return s.size() >= sz;});
	size_t Count = it - v.begin();
	std::cout << Count << std::endl;

	//Ex 10.20
	size_t ByCountIf = count_if(v.begin(),v.end (), [=](const string &s) {return s.size() >= sz;});
	std::cout << "By count-if: " << ByCountIf << std::endl;
	
	reverse(v.begin(), it);	
	for_each(v.begin(), it, [](const string &s){std::cout<< s << " ";});
	std::cout << std::endl; 	
}

int main(){
	vector<string> v = {"Win","Will","President","Trump","Win", "Win", "United", "States","Donald","Win"};
	//v = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	Display(v);
	
	EliminateDups(v);
	Display(v);
	
	//fill_n
	fill_n(back_inserter(v),3,"Yeah");
	Display(v);
	
	Biggies(v,5);
	
	return 0;
}
