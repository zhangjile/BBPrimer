//Chapter 10 Generic Algorithms 
//10.3.4 Binding arguments
//Ex10.22 rewrite the program to count words of size 6 or less using function in place of lambda
//Ex10.25 rewrite Biggies using CheckSize and bind method

#include <iostream>
#include <vector>
#include <functional>
#include <string>

using std::string; using std::vector; using std::stable_sort; using std::unique; 
using std::replace;
using namespace std::placeholders;

bool IsShorter(const string &s1, const string &s2){
	return s1.size () < s2.size();
}

void EliminateDups (vector<string> &v){
	sort(v.begin(), v.end());
	auto pos = unique(v.begin(), v.end()); 	
	v.erase(pos, v.end());
	stable_sort(v.begin(),v.end(),IsShorter);
}

	// Ex10.22
bool NoMoreThan(const string &s, size_t sz){
	return s.size() <= sz;
}

//revision and association
auto Bind6 = bind(NoMoreThan, _1, 6);	//create a new callable taking 1 argument

void ShortWords(const vector<string> &v){
//	size_t Count6 = count_if(v.begin(), v.end(), bind(NoMoreThan, _1, 6));
	size_t Count6 = count_if(v.begin(), v.end(), Bind6);	//use the callable
	std::cout<< Count6 << " words are as long as or shorter than 6" <<std::endl; 
	
}

	//Ex10.25
bool CheckSize(const string &s, size_t sz){
	return s.size() >= sz;
}

void Biggies(vector<string> &v, size_t sz){
	EliminateDups(v);
	
	auto it = stable_partition(v.begin(),v.end(), bind(CheckSize, _1, sz)); //done!
	size_t Count = it - v.begin();
	std::cout << Count << std::endl;

	reverse(v.begin(), it);	//change the range to be in descending order
	for_each(v.begin(), it, [](const string &s){std::cout<< s << " ";});
	std::cout << std::endl; 	
}

// Ex10.25, second implementation
void BIGGES(vector<string> &v, size_t sz){
	EliminateDups(v);
	
	//this one liner extracts the count
	size_t Count = count_if(v.begin(),v.end(),bind(CheckSize, _1, sz));
	
	std::cout << Count << std::endl;

	reverse(v.begin(), v.end());	//in descending order	
	for_each(v.begin(), v.begin()+Count, [](const string &s){std::cout<< s << " ";});
	std::cout << std::endl; 
}

int main(){
	vector<string> v = {"Win","Will","President","Trump","Win", "Win", "United", "States","Donald","Win"};
	//v = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	
//	ShortWords(v);
		
	BIGGES(v,5);
	
	return 0;
}
