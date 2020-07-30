//Section 14.8 function-call operator
//Ex14.35, p 572, write a class like PrintString that reads a line of input from an istream and 
//returns a string representing what was read If the read fails, return the empty string.

#include <iostream>
#include <string>

using std::string;

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
    std::cout << rd () <<std::endl ;
    
    return 0;
}
