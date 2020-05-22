//p243 Chapter 6.5.3 Aids for debugging, Ex 6.47
//assert is a preprocessor macro. A precprocessor macro is a preprecessor variable that acts somewhat like an inline function.
#include <iostream>
#include <string>
#include <vector>
//#define NDEBUG

using std::string; using std::vector; using std::cout; using std::endl;
using iter = vector<string>::const_iterator;

void DisplayVector(iter first, iter last){
	//assert(word.size() > threshold);
	if(first != last){
		cout<< *first <<endl;
		
		#ifndef NDEBUG
		cout <<"The size of the vector int the function " << __func__ <<" is: " <<last - first <<endl;
		#endif
		
		DisplayVector(++first, last);
	}
}

int main(){
	vector<string> v(10, "ok");
	DisplayVector(v.begin(), v.end());
	return 0;
}