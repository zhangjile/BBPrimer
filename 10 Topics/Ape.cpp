//humor and generosity of Derek Banas 
#include <iostream>
#include <string>
#include <regex>
using namespace std::regex_constants;

void PrintMatches(std::string s, std::regex reg){
    std::smatch results;
    while(std::regex_search(s, results, reg)){
        std::cout <<std::boolalpha;
        std::cout <<results.ready() <<"\n";
        std::cout <<results.size() <<"\n";
        std::cout <<results.str(1) <<"\n";
        s = results.suffix().str();
        std::cout << "\n";
    }
}

int main(){
    std::string text = "ape at apex";
    std::regex r ("(ape[^ ]?)");
    PrintMatches(text, r);
    return 0;
}
