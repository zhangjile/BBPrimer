//Chapter 16.2.3 Trailing return types and type transformation
//Ex16.40,p686, Is the function legal, what are restrictions on the argument types that can be passed, what is the return type?
//answer:legal, the arguments must be a pointer or iterator type and the underlying type must be integral, the return type is integral type.
#include <iostream>
#include <vector>
#include <string>

template<typename T> auto fcn(const T& a, const T& b)->decltype(*a+0){
	return *a;
}

//Ex16.41
template<typename T> auto sum(const T& lhs, const T& rhs)->decltype(lhs + rhs){return lhs + rhs;}

int main(){
	std::vector<int> vi {1,2, 2,3};
	std::vector<std::string> vs {"oh", "what"};
	std::vector<char> vc {"o", "w"};
	auto result_1 = fcn(vi.begin(), vi.end());
//	auto result_2 = fcn(vs.begin(), vs.end());	//error, because string obj is not ingegral type.
	auto result_3 = fcn(vc.begin(), vc.end());
	std::cout<< result_1 <<std::endl;
	std::cout <<(char)(result_3) <<std::endl;
	std::cout <<(int)('o') <<std::endl;
}
