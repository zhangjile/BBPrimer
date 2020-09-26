//CppNuts
//don't use a cast until we really have to
//const_cast, flip the constness of a variable

#include <iostream>
#include <string>
using std::string;

//typical mistake: remove constness of a varaible, dereference it and assign new value
void test1(){
	const int a1 = 10;
	const int *b1 = &a1;
	int *d1 = const_cast<int*>(b1);

	//	hideous, undefined error, pass in compile time but it is destructive
//	*d1 = 200;	
//	std::cout <<*d1 <<"\n";
}

void test2(){
	int a2 = 20;
	const int *b2 = &a2;
	int * d2 = const_cast<int*>(b2);
	*d2 = 30;
	std::cout <<*d2 <<"\n";
}

//check out whether the function change the parameter manually!
void ThirdPartyLibrary(int* x) {
	int k = 10;
	std::cout << k + *(x) <<"\n";
}

int main(){
//	test1();	//it is explicitly stated that this operation is undefined.
	test2();
	
	const int i = 100;
	const int *pi = &i;
	//pass it as parameter by explicitly removing constness of pi
	//the ThirdPartyLibrary does not change parameter, 
	//otherwise it's test1 danger case 
	ThirdPartyLibrary(const_cast<int*>(pi));
	
//	test3();
	
	return 0;
}
