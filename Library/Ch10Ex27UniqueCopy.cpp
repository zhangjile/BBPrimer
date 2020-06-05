//Chapter 10.4.1 Revisiting Iterators
//Ex 27. P403, copy the element from a vecor to list using unique_copy

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

using std::vector; using std::list; using std::forward_list; using std::deque;

void Exercise27(){
	vector<int> source {1,10,3,5,3,7,7,9};
	list<int> target;
	sort(source.begin(), source.end());
	unique_copy(source.begin(), source.end(), back_inserter(target));
	//unique_copy(source.begin(), source.end(), inserter(target,target.begin()));
	for(const int &e : target){
		std::cout<< e << " ";
	}
	std::cout << std::endl;
}

void Exercise28(){
	vector<int> source {1,2,3,4,5,6,7,8,9};
	deque<int> d;
	list<int> l;
	vector<int> v;
	copy(source.begin(), source.end(), front_inserter(d));
	std::cout << "deque, front_inserter"<< std::endl;
	for(const int &e : d){
		std::cout<< e << " ";
	}
	std::cout << std::endl;
	
	copy(source.begin(), source.end(), back_inserter(l));
	std::cout << "list, back_inserter"<< std::endl;
	for(const int &e : l){
		std::cout<< e << " ";
	}
	std::cout << std::endl;
	
	copy(source.begin(), source.end(), inserter(v,v.begin()));
	std::cout << "vector, inserter"<< std::endl;
	for(const int &e : v){
		std::cout<< e << " ";
	}
	std::cout << std::endl;
	

}
int main ()
{
	std::cout << "Exercise 27" <<std::endl;
	Exercise27();	
	std::cout << "Exercise 28" <<std::endl;
	Exercise28();
	
	return 0;
}
