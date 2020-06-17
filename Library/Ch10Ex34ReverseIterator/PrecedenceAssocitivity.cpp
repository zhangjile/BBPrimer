// pointer arithmetic, BB Lecture 123
// prefix increment and dereference have the same precedence, Primer,P136, 166
//postfix has higher precedence.
//observe the different caculations they perform

#include <iostream>

//make sure that pointer/iterator in use is valid, 
//basic defense, absolute certainty, mark of proficiency.

void OffEnd(){
	int arr [] = {1,2,3,4,5};
//	for(auto it = std::begin(arr); it!= std::end(arr); std::cout << *it++ << std::endl);	//1,2,3,4,5

	for(auto it = std::begin(arr); it!= std::end(arr); std::cout << *++it << std::endl)	{// if not handled, it displays 2,3,4,5 and a garbage 
		if(it == std::end(arr) - 1) break;
	}
}

int main ()
{
	OffEnd();
	return 0;
}