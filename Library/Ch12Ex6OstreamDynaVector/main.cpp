//Section 12.1.2 Managing Memory Directly 
//Ex12.6 write a function that returns a dynamically allocated vector of ints. Pass the vector to another function that reads stdin to insert elements into the vector. Pass the vector to another function to display the values that were read. 
//Remember to deallocate the heap space at appropriate time.
//Ex12.7 rewrite the previous exercise using shared_ptr and watch the magic

#include <iostream>
#include <vector>
#include <memory> 

using std::vector; using std::cout; using std::shared_ptr; using std::make_shared;

typedef shared_ptr<vector<int>> piv;

piv DynamicVector (){
	return make_shared<vector<int>> ();
}

piv BuildVector(piv p){
	for(int i = 0; cout <<"Enter here: ", std::cin >> i;){
		p->push_back(i);
	}
	return p;
}

//this print function is colorful.
auto Print(piv p) -> std::ostream&{	//if '&' is missing, ERROR!
	for(const auto &i : *p){
		cout << i << " ";
	}
	return cout;
}

int main ()
{
	piv p = BuildVector(DynamicVector ());
	Print(p) << std::endl;
	//shared_ptr handles the dynamic memory properly!
	return 0;
}
