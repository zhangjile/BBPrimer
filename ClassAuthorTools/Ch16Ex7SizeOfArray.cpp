//Section 16.1.1 Function templates
//Ex16.7 p658, Write a constexpr template that returns the size of a given array

#include <iostream>

template<typename T, unsigned N>
T* begin(T (&arr)[N]) {
    return arr;
}

template<typename T, unsigned N>
T* end(T (&arr)[N]) {
	return arr + N;
}


template<typename T, unsigned N> constexpr	//inline/constexpr 
size_t SizeArray(T (&arr) [N]){
    return end(arr) - begin(arr);
}

//smarter
template<typename T, unsigned N> constexpr	//inline/constexpr 
size_t Size(T (&arr) [N]){
    return N;
}

int main () {
    double D[] {0.1,0.2,0.3};
    std::cout << SizeArray(D) <<std::endl;
    return 0;
    
}
