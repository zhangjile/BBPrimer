//Section 14.8 Library-defined function objects
//Ex14.43, p 576, using library function objects, determine whether a given in value is 
//divisable by any element in a container of ints.
//++ check if the given value is divisable by all the elements in a container
//++ Correction: the previous code works in the opposite direction.
#include <iostream>
#include <functional>
#include <algorithm>

int main () {
	auto c = {6, 12, 18};
	int n;
	std::cin >> n;
	std::modulus<int> m;
	//lambda object is an unnamed unique type, auto keyword is the only option.
	auto predicate = [=](int x) {return m(n, x) == 0;};	
	
    //test case: 180, 120, 100
    //expected result:yy, yn, nn
    bool IsDivisableByAny = std::any_of(c.begin(), c.end(), predicate);
	std::cout <<"IsDivisableByAny: "<< (IsDivisableByAny ? "Yes" : "No" ) <<std::endl;
    
    //raw lambda with modulus object
	
	auto IsDivisableByAll = std::all_of(c.begin(), c.end(), [&](int x) {return std::modulus<int>()(n, x) == 0;});
	std::cout << "IsDivisableByAll: "<<(IsDivisableByAll ? "Yes" : "No" ) <<std::endl;
    	
	return 0;
}
