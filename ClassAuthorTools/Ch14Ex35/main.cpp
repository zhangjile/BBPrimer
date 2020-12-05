//Section 14.8 function-call operator
//Ex14.35, p 572, write a class like PrintString that reads a line of input from an istream and 
//returns a string representing what was read If the read fails, return the empty string.
//Ex14.36, use the class to read the standard input, storing 
//each line as an element in a vector

#include <iostream>
#include <string>
#include <vector>
using std::string; using std::vector;

class ReadLine{
public:
    ReadLine (std::istream& i = std::cin, std::string st = "") : is {i}, s{st}{}
    // constructor for 'ReadLine' must explicitly initialize the reference member 's'
    string operator()() const {
        std::getline(is,s);
        return s;
    }
    
private:
    std::istream& is;
    std::string& s;	// make it a reference for getline method, otherwise error
};

//overloading call operator
class AbInt{
public:
	int operator()(int val){
		return (val>0) ? val:-val;
	}
};

int main (){
    ReadLine rd;
    vector<string> v;
    
    //Ex14.36
    v.push_back(rd());
    std::cout<< v[0].size() <<std::endl;
//    int arg = -8;
    AbInt a;
    std::cout << a(-8);
    
    return 0;
}
