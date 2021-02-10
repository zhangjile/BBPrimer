//Ch12.1.5 unique_ptr, p472, Ex16 
//orchestrate an error for copying or assigning a unique pointer.
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using std::string;
typedef std::unique_ptr<string> ups; 

void experimentP470 () {
	//put it on heap
	std::unique_ptr<string> ps1 (new string("Jose Mourinho")); 	
	
	/*
	//orchestrate an error
	auto err = ps1;
	//call to implicitly-deleted copy constructor of
      'unique_ptr<basic_string<char>,
      default_delete<basic_string<char> > >'
	*/
	
	auto p1 = ps1.get();	//inspect the raw ptr managed by ps1
	std::cout <<"p1: "<< p1 << std::endl;
	ups ps2(ps1.release());	//p1 is tranfered to ps2
	auto p2 = ps2.get();	//inspect the raw ptr managed by ps2
	std::cout <<"p2: "<< p2 << std::endl;
	
	ups ps3 (new string("Tottenham"));
	auto p3 = ps3.get();	
	ps2.reset(ps3.release());	//p3 is transfered to ps2
	p2 = ps2.get();
	std::cout <<"p2: "<< p2 << std::endl;	//p2 has been changed
	// good practice to reset it to nullptr
	// 'u.reset()' deletes the object u points but doesn't RESET
	ps2.reset(nullptr);	
	
}


int main(){
	experimentP470();
	return 0;
}

