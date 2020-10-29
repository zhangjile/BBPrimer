//regular expression, pattern of characters, example on page 729
#include <iostream>
#include <regex>
#include <string>
#include <chrono>
using std::string; using std::regex; using std::smatch; using std::sregex_iterator;
using namespace std::chrono;

int main (){
	//work on cin, cout and endl to be blazing fast
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
	auto StartTime = high_resolution_clock::now();
	string pattern ("[^c]ei");
	pattern = "([[:alpha:]]*)" + pattern + "([[:alpha:]]*)";
	string text ="receipt, freind,. theif, receive, thief";
	regex r(pattern, regex::icase);

	//capture all the qualified strings
	for(sregex_iterator it(text.begin(), text.end(), r),end_it; it != end_it; ++it){
		std::cout <<(*it)[2]<<"\n";
		std::cout << it->str() << "\n";
	}
	//using '\n' lowers the time consumption from 53 to 50.
	
	auto StopTime = high_resolution_clock::now();
    auto Duration = duration_cast<microseconds> (StopTime - StartTime);
    std::cout << Duration.count()/1000 <<"\n";
    
	return 0;
}

