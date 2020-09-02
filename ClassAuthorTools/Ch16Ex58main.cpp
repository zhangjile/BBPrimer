#include "Ch16Ex58StrVec.h"

int main()
{
	//test run operations of StrVec
	StrVec sv;
	sv.push_back("Hi");
	std::cout <<*sv.begin() <<std::endl;	//hi
	
	sv.resize(5, "oh");
	std::cout <<*(sv.end()-1) <<std::endl;	//oh
	
	StrVec sv2 ({"abc","oh"});
	std::cout << sv2.size()<<std::endl;
	
	//Ex16.58, EmplaceBack
	sv2.EmplaceBack(10, 'c');
	std::cout <<sv2.size() <<std::endl;
	
	return 0;
}
