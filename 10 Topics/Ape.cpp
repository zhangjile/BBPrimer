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
    PrintMatches(text, r);
    
    std::string text2 = "I picked some pickle";
    std::regex r2("(pick([^ ]+)?)");
//    std::regex r2("(pick[^ ]+)?");	//blank lines    
    PrintMatches2(text2, r2);
    
    std::string text3 = "Cat, fat, mat, rat";
    std::regex r3("[cfm]at");
    PrintMatches2(text3, r3);
    
    r3 = "[C-Fc-f]at";
    PrintMatches2(text3, r3);
    
    std::string OwlFood = regex_replace(text3,r3,"owl");
    std::cout << OwlFood <<"\n";
    
    std::string text4 = "F.B.I. I.R.S CIA";
    std::regex r4("([^ ]\\..\\..)");
    PrintMatches2(text4, r4);
    
    std::string text5 = "This is\n a multiline" 
    	"\nsentence.";
    std::regex r5("\n");
    std::string s5 = std::regex_replace(text5, r5, " ");
    std::cout << s5 <<"\n";
    
    std::string text6 = "123Calculus45";
    std::regex r6("\\D");
//  std::regex r6("\\d");  
    PrintMatches2(text6, r6);
    
    std::string text7 = "123 12345 123456 1234567 12345678   ";
    std::regex r7("\\d{5,7}");
//    std::regex r7("\\d{5}");
    PrintMatches2(text7, r7);
    
    std::string text8 = "852-123-4567";
    std::regex r8("\\d{3}-\\d{3}-\\d{4}");	//w
    PrintMatches2(text8, r8);
    
    std::string text9 = "a and an are not determinantooooo";
//    std::regex r9("a[a-z].");
    std::regex r9("a[a-z]+");
    PrintMatches2(text9, r9);
    
    return 0;
}
