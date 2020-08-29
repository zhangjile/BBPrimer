//Section 16.2.3 Trailing return type and type transformation, type transformation library template classes
//textbook reference
//to be tested on codelite

#include <iostream>
using std::cout; using std::endl;

#include <type_traits>
using std::remove_reference;

#include <vector>
using std::vector;

#include <string>
using std::string;

#ifndef INITIALIZER_LIST
#include <iterator>
using std::begin; using std::end;
#endif

#include "Blob.h"

// auto as function return type indicates we're using a trailing return type
// function that returns a reference to an element in the range
template <typename It>
auto reffcn(It beg, It end) -> decltype(*beg)
{
    // process the range
    return *beg;  
}

// function that returns an element in the range by value
// must use typename to use a type member of a template parameter
template <typename It>
auto valfcn(It beg, It end) -> 
	typename remove_reference<decltype(*beg)>::type
{	
   	// process the range
    return *beg;  // return a copy of an element from the range
}

int main()
{
#if defined(LIST_INIT) && defined(INITIALIZER_LIST)
	vector<int> vi = {1,2,3,4,5};
	Blob<string> ca = { "hi", "bye" };
#else
	int temp[] = {1,2,3,4,5};
	string temp2[] = { "hi", "bye" };
	vector<int> vi(begin(temp), end(temp));
	Blob<string> ca(begin(temp2), end(temp2));
#endif

	auto &i = reffcn(vi.begin(), vi.end()); // reffcn should return int&
	auto &s = reffcn(ca.begin(), ca.end()); // reffcn should return string&

#ifdef LIST_INIT
	vi = {1,2,3,4};
#else
	int temp3[] = {1,2,3,4};
	vector<int> vtemp(begin(temp3), end(temp3));
	vi = vtemp;
#endif

	for (auto i : vi) cout << i << " "; cout << endl;
	auto &ref = reffcn(vi.begin(), vi.end());  // ref is int&
	ref = 5; // changes the value of *beg to which ref refers
	for (auto i : vi) cout << i << " "; cout << endl;

	auto val = valfcn(vi.begin(), vi.end()); // val is int
	cout << val << endl;  // will print 5
	
	return 0;
}

