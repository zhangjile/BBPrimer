//Ex16.5, p 658, write a template version of Print function from $6.2.4(p217) that takes a reference to an array and can handle arrays of any size and any element type.

#include <iostream>
using std::cout; using std::endl;

template<typename T, unsigned N>
void Print (const T (&x)[N]){
    for(unsigned i = 0; i < N; ++i){
        cout << x[i] <<" ";
    }
    cout << endl;
}

//overload Print function by calling begin and end function template
template<typename T, unsigned N>
T* begin(T (&arr)[N]) {
    return arr;
}

template<typename T, unsigned N>
T* end(T (&arr)[N]) {
	return arr + N;
}

template<typename Iterator> void Print(Iterator a, Iterator b){
	for(; a !=b; ++a){
		std::cout<< *a <<" ";
	}
	cout << endl;
}

int main (){
	const char (&source)[] = {"Hi"};	//source is a ref to an array (of const char)
    Print("Hi, Mr Pompeo");
    
	//wow
    int j[] = {1,2};
    Print(j);
    
    //a new Print interface
    Print(begin(j), end(j));
    return 0;
}
