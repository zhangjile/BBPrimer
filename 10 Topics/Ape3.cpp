//humor and generosity of Derek Banas 
#include <iostream>
#include <string>
#include <regex>
using namespace std::regex_constants;

void PrintMatches(std::string s, std::regex reg){
    std::smatch results;
    while(std::regex_search(s, results, reg)){
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
    std::string text1 = "<a href='#'> <b> this is a link </b></a>";
    std::regex r1 ("<b>(.*)</b>");
    std::string output;
    std::regex_replace(std::back_inserter(output), text1.begin(), text1.end(), r1, "$1");
    std::cout <<output << "\n";
    
    
    
    return 0;
}
