//Chapter 12 Dynamic Memory, conclusion project, P484
//interior decoration, redesign the major componets
#include "strvec.h"
#include "textquery.h"
#include <iostream>

std::allocator<string> StrVec:: allo;
        
int main ()
{
	std::ifstream is ("README.md");
	TextQuery tq(is);
	
	while(true){
		std::string s {};
		cout<<"Enter your query: "<<endl;
		cin >> s;
		if(s == "q") {
			cout <<"bye"<<endl;
			break;
		}
		print(std::cout,  tq.Query (s) )<<std::endl;    
		
	} 
	
	return 0;
	
}
