//CppNuts
//static_cast, performs implicit conversion between types

#include <iostream>
#include <string>
using std::string;

//static means it happens at compile time and the static_cast can be searched
void test1() {
	float f = 3.14;
	int a {};
	a = f;
	std::cout << a << "\n";
	a = static_cast<int>(f);	//prefered.
	std::cout << a << "\n";
	//Q: why use static_cast?
	//A: C_styple implicit cast is hard to find, but se can search 'static_cast' keyword to spot a use case
}

//use static_cast between types if conversion is provide 
//through conversion operator/conversion constructor
void test2 (){
	class Int {
	private:
		int x;
	public:
		explicit Int(int a = 0) : x{a} {std::cout << "conversion constructor\n";}
		operator string (){
			std::cout << "conversion operator\n";
			return std::to_string(x);
		}
		int getx() {return x;}
	};
	
	Int obj1(10);
	string s1 = obj1;
	std::cout << s1 << "\n";
	s1 = 1;	//assignment, conversion operator
//	s1(1);	//error, re-initializing 
	
	string s2 = static_cast<string>(obj1);
	std::cout << s2 << "\n";
	obj1 = static_cast<Int> (100);
	std::cout << obj1.getx() << "\n";

}

//static_cast is more restrictive and intercepts
// a good amount of errors at compile time
void test3(){
	char c; 	//1 byte in memory
	int* i = (int*)&c;	//4 bytes, sometimes pass at compile time but fail at runtime 
	
	//this is so dangerous that it's the No. 1 death zone of C.
	*i = 100;	
	//the worst hidden problem is corrupting data in ajacent memory.
	
//	int* is = static_cast<int*> (&c);	//future failure detected at compile time	
	
	int p = 100;
	char* cp = (char*)&p;	//ok, outpud: d, 101 -> e
//	char*cp = static_cast<char*>(&p);	//won't compile
	std::cout << cp << "\n";
	
}

//Nuts0923VoidPtr.cpp
void test4 (){
	int i = 100;
//	void* v = &i;
	void* v = static_cast<void*>(&i);
	int* ip = static_cast<int*>(v);	//restore the type of pointer stored in v;
}

int main(){
//	test1();
//	test2();
	test3();
	
	return 0;
}
