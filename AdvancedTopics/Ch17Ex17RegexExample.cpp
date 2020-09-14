//regular expression, pattern of characters, example on page 729
#include <iostream>
#include <regex>
#include <string>
#include <chrono>
using std::string; using std::regex; using std::smatch; using std::sregex_iterator;
using namespace std::chrono;

int main (){
	auto StartTime = high_resolution_clock::now();
	string pattern ("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	string text ="receipt freind, theif, receive, thief";
	regex r(pattern, regex::icase);
	
	//capture the first qualified string
	smatch Result;
	if(regex_search(text, Result, r))
		std::cout << Result.str() << std::endl;

	//capture all the qualified strings
	for(sregex_iterator it(text.begin(), text.end(), r),end_it; it != end_it; ++it){
		std::cout << it->str() << std::endl;
	}

	auto StopTime = high_resolution_clock::now();
    auto Duration = duration_cast<microseconds> (StopTime - StartTime);
    std::cout << Duration.count()/1000 <<std::endl;
    
	return 0;
}

