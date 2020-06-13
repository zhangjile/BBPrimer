//Ex 8.11 problem:create a vector of PersonInfo 
// what if PersonInfo is declared and initialized outside the outer while loop?
// reset Record.Phone to 0 before processing the next entry.
// validate the phone numbers
// detach validation module from void Process, write a function for it
// std::array and assign method
// ++ use ostringstream to manipulate output
// gcc 9 on SanDisk computer, SUCCESS!
//

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

//test file:data_source and data_err( previously they were named sstream and  sstream_err, how stupid!)
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
		//Record.Phone = {};    LOLOLOL
        Record.Phone.clear();
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
the real trouble is a data file is also named sstream by chance.
#include <sstream> 
as a result, this file is hooked and caused all the trouble!

*/
