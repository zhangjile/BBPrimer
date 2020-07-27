//Chapter 10 Generic Algorithms 
//Ex10.42, P416,rewrite EliminateDups using list 
//Section 14.8 Function-call Operator
//Ex14.40, p 574, Rewrite the biggies function using function-object class in place of lambda


#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using std::string; using std::list; using std::stable_sort; using std::unique; 
using std::replace;

void Display (const list<string> &v){
	for(const string s : v){
		std::cout << s << " ";
	}
	std::cout << "\n";
}

bool IsShorter(const string &s1, const string &s2){
	return s1.size () < s2.size();
}

//algorithms are ballistic bombs, which hit the targets and get things done.
void EliminateDups (list<string> &v){
	v.sort();
	v.unique();	
	v.sort(IsShorter); 
}

//Ex14.40

class ShorterString {
public:
	ShorterString (size_t n) : sz {n} {}
	bool operator () (const string& a) {return a.size() < sz;}
private:
	size_t sz;
};

void Biggies(list<string> &v, size_t sz){
	EliminateDups(v);
	//v.remove_if([sz](const string &s){return s.size() < sz;});
	v.remove_if(ShorterString(sz));	// i made it
	
	size_t Count = v.size(); 
	std::cout << Count << std::endl;

	Display(v);
	std::cout << std::endl; 	
}

int main(){
	list<string> v = {"Win","Will","President","Trump","Win", "Win", "United", "States","Donald","Win"};
	//v = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	Display(v);
	
	EliminateDups(v);
	Display(v);
	
	//fill_n
	fill_n(back_inserter(v),3,"Yeah");
	Display(v);

	replace(v.begin(),v.end(), string{"Yeah"}, string {"!"}); 
	//replace(v.begin(),v.end(), +"Yeah", +"!"); 
	Display(v);
	
	Biggies(v,6);
	
	return 0;
}
