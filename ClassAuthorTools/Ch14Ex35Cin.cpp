//Section 14.8 function-call operator
//Ex14.35, p 572, write a class like PrintString that reads a line of input from an istream and returns a string representing what was read If the read fails, return the empty string.

#include <iostream>
#include <string>

using std::string;

class ReadLine{
public:
    string operator()(std::istream& is =std::cin) {
    if(getline(is,s)) 
        return s;
    else 
        return string ("");
    }
private:
    string s;
};

int main (){
    std::cout << ReadLine () <<std::endl;
    return 0;
}
