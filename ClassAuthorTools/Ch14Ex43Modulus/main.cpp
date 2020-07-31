//Section 14.8 Library-defined function objects
//Ex14.43, p 576, using library function objects, determine whether a given in value is 
//divisable by any element in a container of ints.
//++ check if the given value is divisable by all the elements in a container
#include <iostream>
#include <functional>
#include <algorithm>

int main () {
	auto c = {6, 12, 18};
	int n;
	std::cin >> n;
	std::modulus<int> m;
	auto predicate = [&](int x) {return m(x,n) == 0;};
	
    //3,6, 9
    auto IsDivisable = std::any_of(c.begin(), c.end(), predicate);
	std::cout <<"IsDivisableByAny"<< (IsDivisable ? "Yes" : "No" ) <<std::endl;
    
	//test case:2,3,4,5, expected result:y,y, n,n
	auto IsDivisableByAll = std::all_of(c.begin(), c.end(), predicate);
	std::cout << "IsDivisableByAll:"<<(IsDivisableByAll ? "Yes" : "No" ) <<std::endl;
    
    
	
	return 0;
}