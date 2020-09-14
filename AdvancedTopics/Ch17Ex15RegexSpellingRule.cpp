//Section 17.3 Regular Expressions
//Ex17.15, p734, write a program using the pattern that finds words that 
// violate the "i before e except after c" rule
// Have your pgrogram prompt the user to supply a word and indicate whether the word is okay or not. 
//Test your program with words that do and do not violate the rule

#include <iostream>
#include <regex>
#include <string>
#include <chrono>
using std::string; using std::regex; using std::smatch; using std::sregex_iterator;
using namespace std::chrono;

int main (){
	auto StartTime = high_resolution_clock::now();
	string pattern ("[^c]ei");
//	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	string text ="receipt freind, theif, receive, thief";
	
	regex r(pattern, regex::icase);
	smatch Result;
	while(std::cin >> text){
		if(text == "q") break;	//yeah!
		if(regex_search(text, Result, r)){
			std::cout << Result.str()<<", ok" << std::endl;
		}
		else{
			std::cout << "no" << std::endl;
		}
	}
	
	/* tests
	
	nice
	no
	receive
	no
	recieve
	no
	theif
	theif, ok
	freind
	freind, ok
	friend
	no
	
	*/
	
	
	/*
	Ex17.16, What would happen if your regex object in the previous program were initialized with "[^c]ei"? Test your program using that pattern to see whether your expectations were correct. 

	tests cases for 17.16, only 3 letters are captured
	lei
	lei, ok
	theif
	hei, ok
	thief
	no
	friend
	no
	freind
	rei, ok
	q
	*/
	return 0;
}
