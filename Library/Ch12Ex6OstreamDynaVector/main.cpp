//Section 12.1.2 Managing Memory Directly 
//Ex12.6 write a function that returns a dynamically allocated vector of ints. Pass the vector to another function that reads stdin to insert elements into the vector. Pass the vector to another function to display the values that were read. 
//Remember to deallocate the heap space at appropriate time.
//Ex12.7 rewrite the previous exercise using shared_ptr and watch the magic

#include <iostream>
#include <vector>
#include <string>
#include <memory> 

using std::vector; using std::cout; using std::shared_ptr; using std::make_shared;
using std::string; using std::endl;
typedef shared_ptr<vector<int>> piv;

piv DynamicVector (){
	return make_shared<vector<int>> ();
}

piv BuildVector(piv p){
	for(int i = 0; cout <<"Enter here: ", std::cin >> i, i != 1989;){
		p->push_back(i);
	}
	return p;
}

//this print function is colorful.
//auto Print(piv p) -> std::ostream&{	//if '&' is missing, ERROR!
 std::ostream& Print(piv p){	
	for(const auto &i : *p){
		cout << i << " ";
	}
	return cout;
}

void TestReset466(){
	shared_ptr<int> p(new int(42));
	shared_ptr<int> p1(p);
	cout <<"\nUse count of p: " <<p.use_count() << endl;
	if(!p.unique()){
		p.reset(new int(*p));
		cout <<"executed" <<endl;	//confirming 'p.use_count() == 2'
	}
	cout << p.use_count() << endl;
}


//Ch12Ex6, this is pure gameplay, use smart pointers exclusively!
using std::istream; using std::cin;
using vip = vector<int>*;

vip pv(){
	auto ptr(new vector<int>());
	return ptr;
}

vip Initialize(vip p, istream& is = cin){
	int i = 0;
	while(is >> i){
		p->push_back(i);
	}
	return p;
}

void Print(vip p){
	for(const int& i : *p){
		cout << i << " ";
	}
	cout << endl;
	
	//the caller is responsible for deallocating the heap memory and cleaning up.
	//this is the key, destroy the link, free the memory and 
	//it is destroyed after the block is executed
	delete p;	
}

int main ()
{
	piv p = BuildVector(DynamicVector ());
	//shared_ptr handles the dynamic memory properly!
	Print(p) << std::endl;	
	TestReset466();
	
	//Ex6
	vip p_raw = pv();
	vip p_data = Initialize(p_raw);
	Print(p_data);
	return 0;
}
