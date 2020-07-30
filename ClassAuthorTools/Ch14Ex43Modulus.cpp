//Section 14.8 Library-defined function objects
//Ex14.43, p 576, using library function objects, determine whether a given in value is divisable by any element in a container of ints.

#include <iostream>
#include <functional>
#include <algorithm>

int main () {
	auto c = {6, 12, 18};
	int n;
	std::cin >> n;
	std::modulus<int> m;
	auto predicate = [&](int x) {return m(x,n) == 0;};
	
	//test case:2,3,4,5, expected result:y,y, n,n
	auto IsDivisable = std::all_of(c.begin(), c.end(), predicate);
	std::cout << (IsDivisable ? "Yes" : "No" );
	
	return 0;
}