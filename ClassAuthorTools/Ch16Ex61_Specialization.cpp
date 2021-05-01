//p707
#include <iostream>
#include <string>

template <typename T> int compare(const T& a, const T& b){
	std::cout << "T" <<std::endl;
	return a < b;
}

template <unsigned M, unsigned N> 
int compare (const char (&a)[M], const char (&b)[N]){
	std::cout <<"[]"<<std::endl;
	return strcmp(a,b);
}

//specialization
template<>
int compare (const char* const &p1,const char* const &p2){
	std::cout << "<>"<<std::endl;
	return strcmp(p1, p2);
}
/*
int compare(const char* p1, const char* p2){
	std::cout << "c"<<std::endl;
	return strcmp(p1, p2);
}
*/
int main(){
	//pip is a reference to const pointer that points to const double
	double pi = 3.14159;
	const double * const &pip = &pi;
	std::cout <<pip << std::endl;
	
//	const char* p1 = "Hi", p2 = "Mom";	//error!
	const char* p1 = "Hi", *p2 = "Mom";
	compare(p1,p2);
	compare("Hi","Mom");
	return 0;
}
