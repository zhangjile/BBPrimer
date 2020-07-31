//Section 14.8 Function-call operator
//Ex14.37, p572, Write a class that tests whether two values are equal. Use that object and the library algorithms to write a program to replace all instances of a given value in a sequence.
//++ it's a simplified user-defined equal_to<sring> operator. 

#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using std::deque; using std::string; 

class EqualTo {
public:
	EqualTo(string s) : b{s} {}	//oh yeah!
    bool operator () (const string& a) const {return a == b;}
private:
    string b;
};

int main (){
    deque<string> ss = {"C++","the", "most", "accurate", "language", "C++"};
    replace_if(ss.begin(), ss.end(), EqualTo("C++"), "Sanskrit");
    for(const string& e : ss){
        std::cout << e << std::endl;
    }
    return 0;
}

//this problem appears to be extremely  abstract and therefore difficult:), 
//it actually takes very little effort to draw out the solution. just replace two values with 2 ins or 2 strings, everything becomes clear instantly