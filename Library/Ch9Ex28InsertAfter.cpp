//Chapter 9, Ex 9.28 Success in one run:)
//insert b after a if a is found in a forward_list<string>, if not found, append it in the end of list.
#include <iostream>
#include <forward_list>
using std::forward_list; using std::string;

void InsertAfter (forward_list<string> & fl, string a, string b){
	auto prev = fl.before_begin();
	auto curr = fl.begin ();
	unsigned cnt {0};
	while (curr != fl.end()){
		if(*curr == a){
			curr = fl.insert_after(curr,b);
			++cnt;
		}
		else{
			prev = curr;
			++curr;
		}
	}
	if(cnt == 0){
		fl.insert_after(prev,b);
	}
}

int main (){
	forward_list<string> fl {"Donald", "J", "Trump", "Pence"};
	string a = "Mike";
	string b {"Great"};
	InsertAfter(fl, a, b);
	for(const auto e: fl){
		std::cout<< e <<" ";
	}
	std::cout<<std::endl;
	return 0;
}
