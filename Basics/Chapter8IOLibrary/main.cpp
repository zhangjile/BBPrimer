//Ex 8.11 problem:create a vector of PersonInfo 
// what if PersonInfo is declared and initialized outside the outer while loop?
// reset Record.Phone to 0 before processing the next entry.
// validate the phone numbers
// detach validation module from void Process, write a function for it
// std::array and assign method
// ++ use ostringstream to manipulate output
// gcc 9 on SanDisk computer, SUCCESS!
// error that came out on gcc 7.5 disappeared.

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <array>

struct PersonInfo {
	std::string Name;
	std::vector<std::string> Phone;
};

std::string Format (std::string phone);

//test file: sstream_err
void ValidateFormat(const std::vector<PersonInfo> &People){

	for(const auto &p : People){
		std::ostringstream Invalid, Formatted;  //if declared outside, big error
		for(const auto &n:p.Phone){
			if(n.size() != 10) Invalid << n << " "; 
			else {
				std::string temp = Format(n);
				Formatted << temp <<" ";
			}
		}
		if(Invalid.str().empty())
			std::cout << p.Name <<":\t"<< Formatted.str() <<std::endl;		
		else {
			std::cout << p.Name <<":\t"<< Formatted.str() <<std::endl;	
			//std::cout <<"Input Error:\t"<<p.Name <<":\t" << Invalid.str(); 		
		}
	}	
}

void Process (std::istream& is, std::vector<PersonInfo> &People){
	std::string line, PhoneNumbers;
	PersonInfo Record;
	std::istringstream iss; //iss is global in Process,
	while(getline(is,line)){
		iss.clear();		//critical
		iss.str(line);		
		iss >> Record.Name;
		while(iss >> PhoneNumbers){	
			Record.Phone.push_back(PhoneNumbers);
		}
		People.push_back(Record);
		Record.Phone = {};  
	}
}

std::string Format (std::string phone){
	std::array<char,12> temp;  
	for(int i = 0; i <4; ++i) temp[i] = phone[i];
	temp[4] = '-'; 
	for(int i = 4; i < 7; ++i) temp[i+1] = phone[i];
	temp[8] = '-';
	for(int i = 7; i<10; ++i) temp[i+2] = phone[i];
	phone.assign(temp.begin(),temp.end()); 
	return phone;
}

void DisplayPersonInfo(const PersonInfo& one){
	std::cout<< one.Name <<":\t";
	for(auto s:one.Phone){
		std::cout<<s <<", ";
	}
	std::cout<<std::endl;	
}

int main (int argc, char **argv){
	std::vector<PersonInfo> People2084;
	std::ifstream Raw (argv[1]);
	Process(Raw, People2084);
	for(PersonInfo p: People2084){
		DisplayPersonInfo(p);
	}
	ValidateFormat(People2084);
	
	return 0;
}

/*
This is what I've discovered today.

1. when I build from a command line, no surprises:)

g++ main.cpp -o PersonInfo

2. stl_uninitialized.h is a plain old header.

it is described as "raw memory manipulators" in gnu's doc, its's an internal header which should not used directly, instead, #include <memory>

I was terrified at the first sight of it and felt clueless.

it's nothing but a plain old header file, and the basic syntax in it has been covered, such as template. 

I remember that memory library is the underlying facility for smart pointers.

3. what caused the conflict?

after examining the red alert messages, which says again and again '* is not a member of std', it's high possibility that new std members are included and appeared in my code but this header has not updated for them yet, this file is outdated!

I figure the solution is upgrade gcc, it's still unimaginable to edit and save a header file to solve a build problem.

conclusion

even though it might work, I won't risk blowing up the current environment to fix this. LOL.

Thanks a lot for your time and help

Best regards,

Alvin
*/
