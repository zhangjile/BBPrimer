//Chapter 10.4.2 iostream iterators 
//Ex 10.29 P407, read a file into a vector of strings using istream_iterator
//Ex 10.30 read a sequence of integers from stdin, sort them and then write back to stdout
//Ex10.33 write a program that takes the names of an input file and two output files. the input file should hold integers. using istream_iterator read the input file. using ostream_iterator write the odd numbers into the first output file, each value should be followed by a space. write the even numbers into the second file, each of these values should be placed on a seperate line.


#include <iostream>
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
	copy(v.begin(), v.end(), ot);
	cout << endl;
}

//Ex333
void Selection(){
	ifstream is ("NumbersMatter");
	ofstream os1 ("os1", std::ios::app), os2 ("os2");
	std::istream_iterator<int> iit (is), eof;
	std::ostream_iterator<int> osi1 (os1, " "), osi2(os2, "\n");
	if(*iit++ % 2 == 0){
		*osi1 = *iit++;
	}else{
		*osi2 = *iit++;
	}
	cout << endl;
}

int main(){
	//Ex 29 structure: user input(an istream object), call a method, get the result
	ifstream is ("Ch10Ex27UniqueCopy.cpp");
	VectorFromFile(is);
	
	//Ex 30
	Module30 ();
	
	//Ex33
	Selection();
	return 0;
}
