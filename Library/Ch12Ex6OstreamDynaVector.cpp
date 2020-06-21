//Section 12.1.2 Managing Memory Directly 
//Ex12.6 write a function that returns a dynamically allocated vector of ints. Pass the vector to another function that reads stdin to insert elements into the vector. Pass the vector to another function to display the values that were read. 
//Remember to deallocate the heap space at appropriate time.

#include <iostream>
#include <vector>

using std::vector; using std::cout;

typedef vector<int>* piv;

piv DynamicVector (){
	return new vector<int> ();
}

piv BuildVector(piv p){
	for(int i = 0; std::cin >> i;){
		p->push_back(i);
	}
	return p;
}

//this print function is colorful.
auto Print(piv p) -> std::ostream&{	//if '&' is missing, ERROR!
	for(const auto &i : *p){
		std::cout << i << " ";
	}
	return cout;
}

int main ()
{
	piv p = DynamicVector ();
	p = BuildVector(p);
	Print(p) << std::endl;
	delete p;	//watch the dynamic memory closely!
	return 0;
}