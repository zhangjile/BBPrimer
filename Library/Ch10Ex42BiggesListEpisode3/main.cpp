//Chapter 10 Generic Algorithms 
//Ex10.42, P416 
//rewrite EliminateDups using list

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using std::string; using std::list; using std::stable_sort; using std::unique; 
using std::replace;

void Display (const list<string> &Words){
	for(const string s : Words){
		std::cout << s << " ";
	}
	std::cout << "\n";
}

bool IsShorter(const string &s1, const string &s2){
	return s1.size () < s2.size();
}

//I'm in love with algorithms.
//algorithms are ballistic bombs, which hit the targets and get things done.
void EliminateDups (list<string> &Words){
	Words.sort();
	Words.unique();	
	Words.sort(IsShorter); 
}

void Biggies(list<string> &Words, size_t sz){
	EliminateDups(Words);
	Words.remove_if([sz](const string &s){return s.size() < sz;});
	size_t Count = Words.size(); 
	std::cout << Count << std::endl;

	Display(Words);
	std::cout << std::endl; 	
}

int main(){
	list<string> Words = {"Win","Will","President","Trump","Win", "Win", "United", "States","Donald","Win"};
	//Words = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	Display(Words);
	
	EliminateDups(Words);
	Display(Words);
	
	//fill_n
	fill_n(back_inserter(Words),3,"Yeah");
	Display(Words);

	replace(Words.begin(),Words.end(), string{"Yeah"}, string {"!"}); 
	//replace(Words.begin(),Words.end(), +"Yeah", +"!"); 
	Display(Words);
	
	Biggies(Words,6);
	
	return 0;
}
