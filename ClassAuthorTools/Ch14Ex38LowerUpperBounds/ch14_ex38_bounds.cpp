//Chapter14.8 function-call operator
//Ex14.38, p574, Write a class that tests whether the length of a given string matches a given bound. Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.

#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;

struct Bound{
public:
	Bound(size_t n): bound{n}{}
	bool operator()(const string& s){return s.size() <= bound;}
private:
	size_t bound = 1;
};
int main(){
	ifstream in("main.cpp");
	std::istream_iterator<string> iis(in),eof;
	size_t n = count_if(iis,eof,Bound(3));
	std::cout << n <<std::endl;
	in.close();	
	
	//close and open to reset the in object and the consequent iis!
	in.open("main.cpp");
	vector<string> v;
//	copy_if(iis, eof,back_inserter(v),Bound(3));
	
	int index = 0;
	assert(v.size() > 0);	//assert in service for the first time, haha
	for_each(v.begin(), v.end(), [&index](const string& s){std::cout <<++index << ": "<< s << std::endl;});
	in.close();
	
	return 0;
}
