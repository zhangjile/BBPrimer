//Chapter 10.4.3 reverse iterators
//Ex10.34 P410, use reverse iterators to print a vector in reverse order.

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <functional>
using std::vector; using std::list; using std::string;

void Display(const string &s,const vector<int> &v){
	std::cout << s << std::endl;
	for(const int &e : v){
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main()
{
	vector<int> v {1,2,3,4,5,6,7,8,9,10};
	Display("original sequence: ", v);	//this client code is cool.
	
	//Ex10.34
	std::cout << "crbegin method" << std::endl;
	auto it = v.crbegin();
	while(it != v.crend()){
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
//	for_each(v.crbegin(), v.crend(), [](int x){std::cout << x << " ";});
	
	//Ex10.35 Now print the elements in reverse order using ordinary iterator
	std::cout << "prev algorithm" << std::endl;
	for(auto it = prev(v.end()); true; --it){
		std::cout << *it << " ";
		if (it == v.begin()) break;
	}
	std::cout << std::endl;
	/*
	//Ex10.36 find the last element in a list of ints with the value 0;
	list<int> li = {1,2,3,4,5,0,6,0,7,8,9,10};
	//find algorithm is perfectly legal, and the problem is on Mobile C side.
	auto it_0 = find(li.crbegin(), li.crend(), 0); //constant unimplemented
	size_t ind = distance(it_0, li.crbegin());
	std::cout << ind << std::endl;
	*/
	
	list <int> nl;
	//v.begin()+3 is 4, inclusive, and v.begin()+7 points to 8, exclusive.
	copy(v.begin() +3, v.begin() + 7, front_inserter(nl));
	
	for(const int & i : nl){
		std::cout << i << " ";	//7 6 5 4
	}
	
	
	return 0;
}
