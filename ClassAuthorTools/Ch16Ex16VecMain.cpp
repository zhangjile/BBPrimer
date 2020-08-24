#include "Ch16Ex16Vec.h"

int main () {
	Vec<std::string> s1;
	Vec<std::string> s2{"Gratitude", "and", "bliss"};

	s1 = Vec<std::string>{"ok"};
	std::cout << s1.size() <<std::endl;
	s1 = std::move(s2);
	std::cout << s1.size() <<std::endl;
	for(const auto e : s1){
		std::cout << e << " ";
	}
	std::cout << std::endl;
	
	Vec<int> v1 = {0,2,4,6};
	std::cout << v1.size() <<std::endl;
	
	Vec<int> v2(v1.begin(), v1.end());
	std::cout << v2.size() <<std::endl;
	for(const auto e : v2){
		std::cout << e << " ";
	}
	
	return 0;
	
}
