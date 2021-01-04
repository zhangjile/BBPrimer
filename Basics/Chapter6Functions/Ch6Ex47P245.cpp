//Chapter 6.5.3 Ex47 p245
// Revise the program you wrote in the exercises in Chapter 6.3.2(p228) that used recursion to print the content of a vector to conditionally print information about its execution. For example, you might print the size of the vector on each call.
#include <iostream>
#include <vector>
using std::vector; using std::cout; using std::endl;

//original concept, dynamic spirit, the parameter are a vector and 2 integers.
void DisplayVector1(vector<int> v, int i, int j=0){
	if(j == v.size()) return;
	else{
		cout << v[j++] << endl;
		i=j;
	}
	DisplayVector1(v,i,j);
}

using iter = vector<int>::const_iterator;
void DisplayVector2(iter first, iter last){
//	#define NDEBUG	//turn off the default run-time check
	
	if(first == last) return;
	else{
		cout <<*first <<endl;
	}
	
	//this is a non-destructive implementation, displaying the interval
	#ifndef NDEBUG
	static int i = last - first;
	cout << i-- <<endl;	
	#endif
	
	DisplayVector2(++first,last);
} 

void DisplayVector3(iter first, iter last){
	if(first != last) {
		cout <<*first <<endl;
		DisplayVector3(++first,last);	//post increment is countless 10s.
	}
	
} 

//this implementation can produce the desired effect, but is destructive
void DisplayVector4(vector<int> &v){
	//switch on and off displaying v.size()
	#define NDEBUG
	//display size of the vector, before the destruction happens.
	#ifndef NDEBUG
	cout << v.size() <<endl;
	#endif
	if(v.size()==0) return;
	
	auto elem = v.back();	
	v.pop_back();
	DisplayVector4(v);
	cout << elem << endl;
	
	
}

//extra game, reverse display: 50, 40, 30, 20, 10
void DisplayVector5(vector<int> &v){
	if(v.size()==0) return;
	cout << v.back() << endl;	//better
	v.pop_back();
	DisplayVector5(v);
}


int main(){
	vector<int> v = {10,20,30,40,50};
	int i = 0;
//	DisplayVector1(v, i);
	DisplayVector4(v);
	return 0;
}
