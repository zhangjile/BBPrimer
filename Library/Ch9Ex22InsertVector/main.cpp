//Chapter 9, Ex 9.22 fix the error in a code block
//trace the iterator closely like a hunter
//std::vector<int>::difference_type distance (p1,p2);

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

//if we swap vi[6] and vi[7](ie, 9 and 4), in the next trip, mid will vi[10] (9), but iter will be vi[11] (5), in this case, iter will never be == to mid, ...crash! 
//18 9 1 2 18 9 3 1 4 18 9 5 6 7 8 9 9 1 1 9 9 
void double_and_insert_lambda(std::vector<int>& v, int some_val){
	auto mid = [&]{return v.begin() + v.size()/2;};
	for(auto iter = v.begin(); iter != mid(); ++iter){
		if(*iter == some_val){
			++(iter = v.insert(iter, some_val*2));
		}
	}
}
int main(){
	std::vector<int> vi = { 9,1,2,9,  3,1,9,4,  5,6,  7,8,9,9,  1,1,9,9 }; 
    double_and_insert_lambda(vi, 9);
	for(auto it = vi.begin(); it != vi.end(); ++it){
		std::cout<<*it << " ";
	}
	std::cout<<std::endl;
	return 0;
}

/*
 debugging report
  1. set up a sample iv to assist debug
  2.  if the condition test is 'while(distance(v.begin(),iter) != v.size()/2)', there are 2 possibilities: 	the first possibility is, if 'distance(v.begin(),iter) == v.size()/2)' is accidentally true while the vector grows, the code compiles and runs smoothly. 

  the second possibility is endless loop, because the distance and half of the size 
always miss each other and are never equal.
  //this is a tricky trap situation, but it's easy to spot. 
  
*/
