//Section 16.1 function templates
//Ex16.2, p658, write and test your own versions of the compare functions
 
#include <iostream>

using std::cout; using std::endl; using std::less;

template<typename T>
int Compare (const T& a, const T& b){
    if(less<T>()(a,b)) return -1;
    if(less<T>()(b,a)) return 1;
    return 0;
}

template<unsigned N, unsigned M>
int Compare(const char (&a)[N], const char (&b)[M]){
	return strcmp(a,b);
}


int main(){
    cout<< Compare (2016, 2020) << endl;
    
    //cout<< Compare (19, 20.0) << endl;	//error, 
    //candidate template ignored: deduced conflicting types for T ("int", "double")
    cout<< Compare (2024.12, 2020.12) << endl;
    
    //Compare ("Trump", "Biden"), error, call to Compare is ambiguous
    cout<< Compare ("Trump", "Biden bbbbb") << endl;	
    	
    return 0;
}
