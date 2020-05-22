//Ex 9.27 delete the odd elements from a std::forward_list<int>
#include <iostream>
#include <forward_list>

void RemoveOdd (std::forward_list<int> & fl){
	auto prev = fl.before_begin();
	auto curr = fl.begin ();
	while (curr != fl.end()){
		if(*curr % 2 == 1){
			curr = fl.erase_after(prev);
		}
		else{
			prev = curr;
			++curr;
		}
	}
}

int main (){
	std::forward_list<int> fl {1,2,3,4,5,6,7};
	RemoveOdd(fl);
	for(const auto e: fl){
		std::cout<< e <<std::endl;
	}
	//to be tested on desktop
	//LLVM ERROR: ERROR: Constant unimplemented for type: [2 x i64]
	//exit(code = 1)
	
	return 0;
}
