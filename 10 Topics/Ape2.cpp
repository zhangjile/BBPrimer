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
    std::string text = "an ape was at apex cat, cats";
    std::regex r ("([cat]+s?)");
//    std::regex r ("([cat]+?)");
    PrintMatches2(text, r);
    
    std::string text2 = "doctor, doctors, doctor's";
    std::regex r2 ("([doctor]+['s]{0,2})");
//    std::regex r2 ("([doctor]+['s]*)");
    PrintMatches2(text2, r2);
    
    std::string text3 = "some lines\n\r and some more\r";
    std::regex r3("[\\n]?\\r");
//    std::regex r3("[\\n\\r]");
    std::string line = std::regex_replace(text3, r3, " ");
    std::cout << line << "\n";
    
    //greedy and lazy, this is a beautiful instance
    std::string text4 = "<name> Life on Mars </name>"
    					"<name> Freaks and Geeks </name>";
    std::regex r4("<name>(.*?)</name>");
//    std::regex r4("<name>(.*)</name>");

    PrintMatches(text4, r4);

    //word boundary
    std::regex r5("(\\bape\\b)");
//    std::regex r5("(ape)");
//    std::regex r5("ape");
    PrintMatches(text, r5);
    
    //^ outside [] indicates beginning of string, $
    std::string text6 = "Match everything up to @";
    std::regex r6("(^.*[^@])");
    PrintMatches(text6, r6);
    
    std::string text7 = "@ Get this string";
    std::regex r7("([^@\\s].*$)");
    PrintMatches(text7, r7);
	
    //. represent some single character    
    std::string text8 = "123-456-7890, 234-567-8901";
    std::regex r8(".{3}-(.{8})");	//- becomes the anchor point of the pattern
//	std::regex r8(".{4}(.{8})");	//weird but interesting

    PrintMatches(text8, r8);
    
    std::string text9 = "My number is 123-456-7890";
    std::regex r9("(.{3})-(.{3})-(.{4})");
    std::smatch result;
    std::regex_search(text9,result,r9);
    std::cout << result.str(3);
    
    return 0;
}
