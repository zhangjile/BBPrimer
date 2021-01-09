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
			++prev; //optional, wow, in-depth skilled tracking:)
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

/*
This is an even more engaging story, choose a robust implementation.
everything is fine if the user calls the function normally, but what if the user accidentally calls 'InsertAfter(fl, a,a)', well, there will be an endless loop, the program crashes!
another route is, take away else operator and the curly brackets, which means the code after if block will be executed in every run, and it's a great idea that can prevent the crash from happening when a user makes a mistake.

and this code block clarifies one piece of truth, if statement and else statement are exclusive and non-compatible, just like elements in a sample space. ie, if else operator is not taken away, the else block will not be executed if if condition is true, which is quite obvious and now 1000% certain.

*/
