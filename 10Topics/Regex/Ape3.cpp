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
    
    //interpreting the expression: https? indicates 's' is optional 
    //[\\w.] means any single character, 
    //+ means one or more occurrences, space is NOT part of the expression
    std::regex r2("(https?://([\\w.]+))");
    std::string fmt = "<a href = '$1'>$2</a>\n";
    std::string output2;
    std::regex_replace(std::back_inserter(output2), text2.begin(), text2.end(), r2, fmt);
    std::cout <<output2 << "\n";
    
    
    //looking-ahead syntax, match but does not return     
    std::string text3 = " one two three four ";
    std::regex r3("(\\w+(?=\\b))");
    PrintMatches(text3, r3);
    
    
    //or
   std::string text4 = " 1. dog 2. cat 3.rabbit bunny 4. turtle fox ";
    std::regex r4("(\\d\\.\\s?(dog|rabbit))");
    PrintMatches(text4, r4);
    
    //challenge: match zip code
   std::string text5 = "12345 12345-333 12345-1234 1234";
//   std::regex r5 ("(\\d{5}(\\s|-\\d{4}))");	//yeah!
   std::regex r5 ("(\\d{5}-\\d{4}|\\d{5}\\s)");	//("(s1|s2)")
   PrintMatches(text5,r5);
   
    //challenge:recognize legetimate phone numbers
    std::string text6 = "1-412-555-1212, 14125551212, 4125551212, (412)5551212" 
   						"412 555 1212 412-555-1212";
   std::regex r6("((1?)(-?)\\d{3}[- ]?\\d{3}[- ]?\\d{4}|\\(\\d{3}\\)\\d{7}))");
//   r6 = "((1-)?\\d{3}[- ]?\\d{3}[- ]?\\d{4}|\\(\\d{3}\\)\\d{7}))";
//	r6 = "((1?)(-| ?)(\\()?(\\d{3})(\\)|-| \\))?(\\d{3})(-| )?(\\d{4}|\\d{4}))";
//	weird error, the second item is displayed 1412555121, the last digit is missing.
//	possibly it's related to how ECMAScript is executed on Mobile C 
	
	//references
//	r6 = "((1?)(-?)(\\()?(\\d{3})(\\)|-| \\))?(\\d{3})(-| )?(\\d{4}|\\d{4}))";
//  r6 = "((1?)(-?)(\\()?(\\d{3})(\\)|-| )?(\\d{3})(-| )?(\\d{4}))";
    PrintMatches2(text6,r6);
    
    return 0;
}


/*
a.b
true:acb, aab, axb
false:ab, acby, cb

a*b
true:b, ab, aab, aaab
false:a, acb, <- this is a typical false case

a*b.*y
true:by, bly, aby, ably,abliy
false:ay, ab
*/