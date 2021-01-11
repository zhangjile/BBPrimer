// Exercise 9.38:
// Write a program to explore how vectors grow in the library you use.

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v;
//    for (std::string buffer; std::cin >> buffer; v.push_back(buffer))
        std::cout << v.capacity() << std::endl;

    v.reserve(50);
    std::cout<< v.capacity() <<std::endl;

    for(auto i = 0; i != 50; ++i){
    	v.push_back("Stop ");
    }
    std::cout<< v.capacity() <<std::endl;
    v.push_back ("the steal!");
    std::cout<< v.capacity() <<std::endl;

    for(const std::string& s:v){
    	std::cout<< s;
    }
    std::cout << std::endl;
    return 0;
}
