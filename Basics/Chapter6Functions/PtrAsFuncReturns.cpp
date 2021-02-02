//pointers returned from functions, kindness of mycodeschool.com
#include <iostream>
using namespace std;
/*
//Gameplay1
int Add(int a, int b){
	int c = a+b;
	return c;
}

int main(){
	int (*pf) (int, int);
	pf = &Add;
	int x=2, y=8;
	int z = pf(x,y);
	printf("Sum = %d\n", z);
	return 0;
}
*/
/*
//Gameplay2
int Add(int* a, int* b){
	std::cout <<"address of a in Add is " << &a <<std::endl;
	std::cout <<"value of a in Add (which is given by main) is " << a <<std::endl;
	std::cout <<"value of a in main(which is an int) is  " << *a <<std::endl;
//	printf("address of a in Add is %d\n", &a);
//	printf("value of a in Add (which is given by main) is %d\n", a);
//	printf("value of a in Add(which is originally stored in &a in main) is %d\n", *a);
	int c = (*a)+(*b);
	return c;
}	

int main(){
	int (*pf) (int*, int*);
	pf = Add;
	int a=2,b=8;
	std::cout <<"address of a in main is  " << &a <<std::endl;
//	printf("address of a in main is %d\n", &a);
	int c = pf(&a, &b);
	printf("Sum = %d\n", c);
	return 0;
}
*/


//Gameplay3
//understanding call stack push and pop behind the scene is meaningful
int* Add(int* a, int* b){
	int c = (*a)+(*b);
	//returning a the address of a local variable is error-prone and dangerous!
   //modern C++ compiler complains about this and stops the program
 return &c;

}	

int main(){
	int a=2,b=8;
	int *c = Add(&a, &b);
	cout << *c<< endl;
	return 0;
}
