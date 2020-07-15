#include "StrVec.h"
#include "TextQuery.h"

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.Query(s)) << std::endl;
    }
}

int main()
{
	//test run operations of StrVec
	StrVec sv;
	sv.push_back("Hi");
	std::cout <<*sv.begin() <<std::endl;
	sv.resize(5, "oh");
	StrVec sv2 ({"abc","oh"});
	std::cout << sv.size()<<std::endl;
	
	//StrVec.h works as vector 
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
    //std::ifstream file("README.md");
    //runQueries(file);
}
