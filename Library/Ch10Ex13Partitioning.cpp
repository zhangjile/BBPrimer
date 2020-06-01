//Section 10.3 Customizing operations
//Ex. 13 P387
//The libray defines an algorithm named partition that takes a predicate and partitions the container so that the values for which the predicate is true appear in the first part and those for which the predicate is false appear in the second part. The algorith returns an iterator just past the last element for which the predicate returned true. 
//write a function that takes a string and returns a bool indicating whether the string has five characters or more. 
//use that function to partition words. print the elements that have five or more characters.

#include <iostream>
#include <vector>
#include <string>
using std::vector; using std::string; using std::sort;

bool MoreThan5(const string &s){
	return s.size() >= 5;	
}

//so happy that the code just flows out of fingers, and setup is done with speed
int main ()
{
	vector<string> v = {"Win","Will","Trump","of", "the", "United", "States","Donald","Win"};
	auto partitioned = partition(v.begin(), v.end(), MoreThan5);
	for(auto it = v.begin(); it != partitioned; ++it){
		std::cout<< *it <<" ";	//partitioned and sorted in alphabetical order.
	}
	std::cout << std::endl;
	return 0;
}