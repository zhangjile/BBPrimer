//Section 17.3.1 Using the Regular Expression Library
//Ex17.14, p734, Write several regular expressions designed to trigger various errors. 
//Run your program to see what output your compiler generates for each error.

#include <iostream>
#include <regex>
#include <string>
#include <chrono>
using std::string; using std::regex; using std::smatch; using std::sregex_iterator;
using namespace std::chrono;

int main (){
	try{
		regex r("[[:alnum:]]+\\.(cpp|cc|cxx)$", regex::icase);
	smatch result;
	string file;
	while(std::cin >> file){
		if(regex_search(file, result, r))
			std::cout << result.str() << std::endl;
	}
	}catch(std::regex_error e) {
		std::cout << e.what() <<"\ncode: "<< e.code() << std::endl;
	}
	
	/*
	if 'cpp|cc|cxx)', the program produces bizzare results, 
	oK.CPP
	oK.CPP
	CSS.CC
	CC
	ABC.CXX
	CXX
	O9C.CXX
	CXX
	oK.CXX
	CXX
	cSS.CPP
	cSS.CPP

	analysis: filename with cc or cxx extension is ignored, only extention is kept:)
	
	*/
	
	return 0;
}
