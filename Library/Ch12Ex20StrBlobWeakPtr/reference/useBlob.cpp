﻿#include <iostream>
using std::cout; using std::endl;

#ifndef LIST_INIT
#include <iterator>
using std::begin; using std::end;

#include <string>
using std::string;
#endif

#include "StrBlob.h"

int main()
{
	StrBlob b1; 
	{

		string temp[] = { "a", "an", "the" };
		StrBlob b2(begin(temp), end(temp));

	    b1 = b2;  
	    b2.push_back("oh oh");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;

	//this line represents the spirit of mordern C++:
	// 1. using auto
	// 2. encapsulation, StrBlobPtr type is totally hidden in implementation.
	// 3. consistent user interface.
	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
		cout << it.deref() << endl;

	return 0;
}
