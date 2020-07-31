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
    ReadLine (std::istream& i = std::cin) : is {i} {}
    string operator()() const {
        string s;
        std::getline(is,s);
        return is ? s : string ("");
    }
    
private:
    std::istream& is;
};

int main (){
    ReadLine rd;
    vector<string> v;
    
    //Ex14.36
    v.push_back(rd());
    std::cout<< v[0].size() <<std::endl;
    
    return 0;
}
