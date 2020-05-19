//Chapter 9, Ex 9.22 fix the error in a code block
#include <iostream>
#include <vector>

void double_and_insert(std::vector<int>& v, int some_val){
	//if v.size() is odd, the code crashes
	if(v.size()%2) v.push_back(-1);	//this line catches the bug!!!
    auto mid = [&]{ return v.begin() +  v.size() / 2; };
    for (auto curr = v.begin(); curr != mid(); ++curr)
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val)); 
    if(v.at(v.size()-1) == -1) v.pop_back(); //manually clean it up
}

int main(){
	//There's problem with the logic, this test case blow up everything
	std::vector<int> iv = { 9, 9, 9, 9, 1,1, 9, 9 }; 
	double_and_insert(iv, 9);
	for(auto it = iv.begin(); it != iv.end(); ++it){
		std::cout<<*it <<std::endl;
	}
	return 0;
}

