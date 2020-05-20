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
	std::vector<int> iv = { 9,9,1,9,  9,1,9,9,  1,1,  1,1,9,9,  1,1,9,9 }; 
	double_and_insert(iv, 9);
	for(auto it = iv.begin(); it != iv.end(); ++it){
		std::cout<<*it <<std::endl;
	}
	return 0;
}

