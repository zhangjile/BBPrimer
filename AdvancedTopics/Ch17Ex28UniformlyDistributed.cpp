//Section 17.4, professional random numbers, 17/09/2020
//Ex.17.28, p749, Write a function that generates and returns a uniformly distributed int each time it is called.
//Ex17.29, Allow the user to supply a seed as an optional argument to the function you wrote in the previous exercise.

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using std::cout; using std::endl; using std::vector;
using std::default_random_engine; using std::uniform_int_distribution;

void test1(){
	default_random_engine e;
	for(size_t i = 0; i < 10; ++i){
		cout << e() <<", ";
	}
	cout << endl;
}

//random number generator = distribution + engine
void test2(){
	uniform_int_distribution u(0,9);
	default_random_engine e;
	for(size_t i = 0; i < 10; ++i){
		cout << u(e) <<", ";
	}
	cout << endl;
}

//generate real random numbers between 0 and 1
void test3(){
	std::uniform_real_distribution<double> u(0,1);
	default_random_engine e;
	for(size_t i = 0; i < 10; ++i){
		cout << u(e) <<", ";
	}
	cout << endl;
}

vector<unsigned> bad_rand_vec(){
	vector<unsigned> v;
	uniform_int_distribution<unsigned> u(0,9);
	default_random_engine e;
	for(size_t i = 0; i < 10; ++i){
		v.push_back(u(e));
	}
	for(size_t i = 0; i < 10; ++i){
		cout << v[i] << ", ";
	}
	cout << endl;
	return v;
}

vector<unsigned> good_rand_vec(){
	vector<unsigned> v;
	static uniform_int_distribution<unsigned> u(0,9);
//	static default_random_engine e;
	static default_random_engine e(time(0));	//truly random numbers
	for(size_t i = 0; i < 10; ++i){
		v.push_back(u(e));
	}
	for(size_t i = 0; i < 10; ++i){
		cout << v[i] << ", ";
	}
	cout << endl;
	
	return v;
}

int main(){
	test1();
	test1();	//using the same default seed 
	test2();
	test2();	//and produced the same sequence of integers
	test3();
	test3();
	vector<unsigned> v1 = bad_rand_vec();
	vector<unsigned> v2 = bad_rand_vec();
	cout <<((v1 == v2)? "same": "different") <<endl<< endl;
	v1 = good_rand_vec();
	v2 = good_rand_vec();
	cout <<((v1 == v2)? "same": "different") << endl;
	
	return 0;
}
