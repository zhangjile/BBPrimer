//9.36 Container operations may invalidate iterators, p355
//Example code, insert 42 AFTER each element of a vector<int> 
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using std::vector; using std::list; using std::forward_list;

//insert 42 after each element of a vector<int>

void Insert42(vector<int> &vi){
	auto Begin = vi.begin();
	while (Begin != vi.end()){
		++Begin;
		Begin = vi.insert(Begin, 42);
		++Begin;
	}
}

//extend the game, using a forward_list<int> container
void Insert42(forward_list<int> &flst){
	auto Begin = flst.begin();
	while (Begin != flst.end()){
		Begin = flst.insert_after(Begin, 42);
		++Begin;
	}
}


template<typename T>
void Display(const T& t){
	for(const auto& e:t){
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main (){
	vector<int> v = {1,2,3,4,5,6,7,8};
	forward_list<int> fli;
	fli.assign(v.begin(), v.end()); //play with assign
	forward_list<int> fi(v.begin(), v.end()); //initialization
	
//	Insert42(v);
//	Display(v);
	
	Insert42(fli);
	Display(fli);
	
	return 0;
}
