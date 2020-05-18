//Chapter 9, Ex 9.22 fix the error in a code block
#include <iostream>
#include <vector>

void double_and_insert(std::vector<int>& v, int some_val){
    auto mid = [&]{ return v.begin() +  v.size() / 2; };
    for (auto curr = v.begin(); curr != mid(); ++curr)
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val)); 
}

int main(){
	//if v.size() is odd, the code crashes on Mobile C and CodeLite
	//test it on VS code
	std::vector<int> iv = { 1, 9, 1, 9, 9, 9, 9, 1, 1, 1 }; 
	double_and_insert(iv, 9);
	for(auto it = iv.begin(); it != iv.end(); ++it){
		std::cout<<*it <<std::endl;
	}
	return 0;
}

