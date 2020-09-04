//cppnuts, class template specialization 
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template<class T> T AddAll(const std::vector<T>& t){
	T Result;
	for(const auto& elem : t){
		Result += elem;
	}
	return Result;
}

template<>
std::string AddAll(const std::vector<std::string>& t){
	int sum = 0;
	for(const auto& elem : t){
		for(const auto& e: elem){
			//implicit conversion to int
			sum += e;	
		}
	}
	
	std::ostringstream Os;
	Os << sum;
	std::string SumString = Os.str();
	return SumString;
}

int main(){
	std::vector<int> vi = {1,2,3,4,5};
	std::cout << AddAll(vi) << std::endl;
	
	std::vector<std::string> sv = {"a", "b"};
	std::cout << AddAll(sv) << std::endl;
	
	return 0;
}