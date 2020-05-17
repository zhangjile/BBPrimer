//Ex 8.11 problem:create a vector of PersonInfo 
// what if PersonInfo is declared and initialized outside the outer while loop?
// reset Record.Phone to 0 before processing the next entry.
// validate the phone numbers
// detach validation module from void Process, write a function for it
// ++std::array and assign method

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <array>

struct PersonInfo {
	std::string Name;
	std::vector<std::string> Phone;
};

//test file: sstream_err
void ValidateFormat(std::vector<PersonInfo> &People){
	std::vector<PersonInfo> Formatted;
	for(auto &p : People){
		for(auto &n:p.Phone){
			if(n.size() != 10) n = "-1"; // "-1" represent an invalid phone number
			else {
				std::array<char,12> temp;  //faster than std::string temp(12,'0');
				for(int i = 0; i <4; ++i) temp[i] = n[i];
				temp[4] = '-'; 
				for(int i = 4; i < 7; ++i) temp[i+1] = n[i];
				temp[8] = '-';
				for(int i = 7; i<10; ++i) temp[i+2] = n[i];
				n.assign(temp.begin(),temp.end()); 
			}
		}
	
	Formatted.push_back(p); //finish touch, first time work in vim 15/05/2020
	}	
}

void Process (std::istream& is, std::vector<PersonInfo> &People){
	std::string line, PhoneNumbers;
	PersonInfo Record;
	std::istringstream iss; //global in Process, calling clear() on it is critical
	while(getline(is,line)){
		iss.clear();	
		iss.str(line);		
		iss >> Record.Name;
		while(iss >> PhoneNumbers){	
			Record.Phone.push_back(PhoneNumbers);
		}
		People.push_back(Record);
		Record.Phone = {};  
	}
}

void DisplayPersonInfo(const PersonInfo& one){
	std::cout<< one.Name <<":\t ";
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
	for(PersonInfo p: People2084){
		DisplayPersonInfo(p);
	}
	return 0;
}

