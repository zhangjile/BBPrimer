//Section 17.4, professional random numbers, 17/09/2020
//Ex.17.30, p749, Revise your function again this time to take a minimum and maximum value for the numbers that the function should return.Random In Range

#include <iostream>
#include <vector>
#include <string>
#include <random>

using std::cout; using std::endl; using std::vector; using std::string;
using std::default_random_engine; 
using std::uniform_int_distribution; using std::normal_distribution;

//normal distribution, is this mathematics course?
void NormalDistribution(){
	default_random_engine e;
	normal_distribution<double> n(4, 1.5);
	vector<unsigned> vec(9);
	for(size_t i = 0; i < 200; ++i){
		auto v = lround(n(e));
		if(v < vec.size())	++vec[v];
	}
	
	for(size_t i = 0; i < vec.size(); ++i){
		cout << string(vec[i], '*')<<endl;
	}
}

int main(){
	//Ex17.30 RandomInRange
	default_random_engine e;
	uniform_int_distribution<int> u(1,2);
	
	for(size_t i = 0; i < 10; ++i){
		cout << u(e) << " ";
	}
	cout << endl;
	
	//normal distribution in action
	NormalDistribution();
	
	return 0;
}
