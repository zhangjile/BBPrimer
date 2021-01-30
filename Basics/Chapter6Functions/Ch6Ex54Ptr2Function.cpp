//Chapter 6.7 Pointers to Functions
//Exercise 6.54: Write a declaration for a function that takes two int parameters and return an int, and declare a vector whose elements have this function pointer type.
//Exercise 6.55: Write four functions that add, substract, multiply and divide tow int functions. Store pointers to these functions in your vector from the previous exercise.
//Exercise 6.56: Call each element in the vector and print the result.
 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//examples
bool LengthCompare(const string& a, const string& b){return a.size() < b.size();}
//pf is a pointer to function, a variable in essence.
bool (*pf) (const string& a, const string& b);	

void Variables(){
	pf = LengthCompare; //an object/variable,
	pf = &LengthCompare;  //equivalent
	bool result = pf("Hello","HELLO");	// a callable object
	result = (*pf)("Hello","HELLO");	//equivalent
	LengthCompare("Hello","HELLO");		//equivalent	
}
	
//FuncP and FuncP2 are pointer to function type
typedef bool (*FuncP) (const string&, const string&);
typedef decltype(LengthCompare)* FuncP2;
	
void UseBigger(const string&a, const string&b, bool pf(const string&, const string&));
void UseBigger(const string&a, const string&b, bool (*pf)(const string&, const string&));
void UseBigger(const string& a, const string& b, FuncP2);

//error, unknown type name 'LengthCompare', 
//void UseBigger(const string& a, const string& b, LengthCompare); 
//we can call UseBigger(s1,s2,LengthCompare), but we need a type name instead of a variable name in the function declaration
	
FuncP2 GetFunc();	//decltype(LengthCompare)* GetFunc();

//Exercise 54, 55, 56
int add(int a, int b){return a + b;}
int substract(int a, int b) {return a - b;}
int multiply(int a, int b) {return a * b;}
int divide(int a, int b) {return a / b;}
	
int main(){
	typedef int (*f)(int, int);	
	
	vector<f> v {add, substract, multiply, divide};
	int a = 10, b = 2;
	for(decltype(add)* e : v){cout <<e(a,b) << endl;}
	
	return 0;
}

