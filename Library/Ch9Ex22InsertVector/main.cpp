//Chapter 9, Ex 9.22 fix the error in a code block
//trace the iterator closely like a hunter
//std::vector<int>::difference_type distance (p1,p2);
//debug distance() != size()/2, which crashes.

#include <iostream>
#include <vector>

void double_and_insert(std::vector<int>& v, int some_val){
	auto iter = v.begin ();
	while(distance(v.begin(),iter) < v.size()/2){
		if(*iter == some_val){
			++(iter = v.insert(iter, some_val * 2));
		}
		++iter;
	}    
}

int main(){
	std::vector<int> vi = { 9,1,2,9,  3,1,4,9,  5,6,  7,8,9,9,  1,1,9,9 }; 
//	std::cout<<"There are "<< vi.size() <<" elements in vi" <<std::endl;
    double_and_insert(vi, 9);
	for(auto it = vi.begin(); it != vi.end(); ++it){
		std::cout<<*it <<std::endl;
	}
//    	std::cout<<"There are "<< vi.size() <<" elements in vi after insersion" <<std::endl;

	return 0;
}

/*
 debugging report
  * 1. set up a sample iv to assist debug
  * 2.  if the condition test in line 11 is 'while(distance(v.begin(),iter) != v.size()/2)', 
  * there are 2 possibilities: one is the code compiles and runs smoothly 
  * if accidentally 'distance(v.begin(),iter) == v.size()/2)' is true while the vector grows.
  * the second possibility is endless loop, because the distance and half of the size 
  * miss each other and are never equal.
  * this is a tricky trap situation, but it's easy to spot. 
  
*/