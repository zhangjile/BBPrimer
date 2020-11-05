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
    
    //this quoting technique is also called back reference
    std::regex_replace(std::back_inserter(output), text1.begin(), text1.end(), r1, "$1");
    std::cout <<output << "\n";
    
    //challenge insert link data into html code
    //first time to see $2 inside $1
    //using . and + the expression pattern define a link as an entity, 
    std::string text2 = "https://www.google.com http://www.youtube.com";
    std::regex r2("(https?://([\\w.]+))");
    std::string fmt = "<a href = '$1'>$2</a>\n";
    std::string output2;
    std::regex_replace(std::back_inserter(output2), text2.begin(), text2.end(), r2, fmt);
    std::cout <<output2 << "\n";
    
    return 0;
}
