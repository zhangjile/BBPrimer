//cppnuts

#include <iostream>

void func(void){}

int main (){
	int* i = new int(10);
	void* vp = i;
//	std::cout << *vp <<std::endl;	//error, void ptr cannot be dereferenced
	std::cout <<*(static_cast<int*>(vp))<<std::endl;
	int* m = static_cast<int*>(std::malloc(sizeof(int)));	//static_cast
	return 0;
}

/*
Question1: What is void and void pointer in c++?
topic: void
1) void is used to denote nothing, as in parameter list
2) if some function is not returning anything, then we use void type to denote that (declare it as void type)
3) we cannot declare/create a void type variable. 

topic:void pointer
1) void pointer is universal pointer, which means it's practically typeless.
2) we can assign a pointer of any type to a void pointer (except function pointer, const or volatile)
3) void pointer cannot be dereferenced, we can dereference a pointer of concrete type such as int, double or anything.

topic: use cases
1) malloc and calloc returns void* so that we can typecast to our desired data type
2) void* are used to create generic functions, (eg, compare function in qsort). 

*/