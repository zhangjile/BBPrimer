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
	auto predicate = [&](int x) {return m(x,n) == 0;};	//lambda object is an unnamed unique type, auto keyword is the only option.
	
    //test case: 3,4,5, 
    //expected result:y, y,n
    bool IsDivisable = std::any_of(c.begin(), c.end(), predicate);
	std::cout <<"IsDivisableByAny"<< (IsDivisable ? "Yes" : "No" ) <<std::endl;
    
    //raw lambda with modulus object
	//expected result:y, n,n
	auto IsDivisableByAll = std::all_of(c.begin(), c.end(), [&](int x) {return std::modulus<int>()(x,n) == 0;});
	std::cout << "IsDivisableByAll:"<<(IsDivisableByAll ? "Yes" : "No" ) <<std::endl;
    
    
	
	return 0;
}