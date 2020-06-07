//Chapter 10.4.2 iostream iterators 
//Ex 10.29 P407, read a file into a vector of strings using istream_iterator
//Ex 10.30 read a sequence of integers from stdin, sort them and then write back to stdout

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using std::string; using std::vector; using std::cout; using std::endl; using std::ifstream; using std::ofstream;

//Ex 29 
void VectorFromFile(std::istream &is){
	std::istream_iterator<string> iit(is), eov;
	vector<string> vs (iit, eov);
	for(const string &s : vs){cout << s <<"";}
	cout << endl;
}

void Module30 (){
	std::istream_iterator<int> iit (std::cin), eos;
	vector<int> v (iit,eos);	//error on Mobile C, constant unimplemented 
	sort(v.begin(), v.end());
	std::ostream_iterator <int> ot(std::cout, " ");
	for(const auto &e : v){
		*ot++ = e;
	}
	//copy(v.begin(), v.end(), ot);   //display for a second time.

}

int main(){
	//Ex 29 structure: user input(an istream object), call a method, get the result
	ifstream is ("compile_flags.txt");
	VectorFromFile(is);
	
	//Ex 30
	Module30 ();
	
	return 0;
}
