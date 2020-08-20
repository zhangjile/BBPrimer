#include <iostream>
#include <vector>
#include <algorithm>

using std::for_each; using std::vector;

template<typename T, unsigned N>
T* begin(T (&arr)[N]) {
    return arr;
}

template<typename T, unsigned N>
T* end(T (&arr)[N]) {
	return arr + N;
}

int main (){
	//const size_t n = 3;
	int a[] {50,20,30};	//explicitly specifying size is optional
	
	std::cout << end(a) - begin(a) << std::endl;
	std::cout << *begin(a) << std::endl;
	std::cout << *(begin(a)+2) <<std::endl;
	
	std::sort(begin(a),end(a));
	std::cout << *begin(a) << std::endl;
	std::cout << *(begin(a)+2) <<std::endl;
	
	std::transform(begin(a), end(a), begin(a), [] (int x){ return x*2;});
	for_each(begin(a),end(a),[] (int x){ std::cout << x << " ";});	//success!
	
    return 0;
}
