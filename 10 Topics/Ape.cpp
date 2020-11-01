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

void PrintMatches2(std::string str, std::regex reg){
	std::sregex_iterator CurrentMatch(str.begin(), str.end(),reg), End;
	while(CurrentMatch != End){
		std::cout <<CurrentMatch->str() <<"\n";
		++CurrentMatch;
	}
	std::cout << std::endl;
}

int main(){
    std::string text = "ape at apex";
    std::regex r ("(ape[^ ]?)");
//    PrintMatches(text, r);
    
    std::string text2 = "I picked some pickle";
    std::regex r2("(pick([^ ]+)?)");
//    std::regex r2("(pick[^ ]+)?");	//blank lines    
    PrintMatches2(text2, r2);
    
    std::string text3 = "Cat, fat, mat, rat";
    std::regex r3("[cfm]at");
    PrintMatches2(text3, r3);
    
    r3 = "[C-Fc-f]at";
    PrintMatches2(text3, r3);
    
    return 0;
}
