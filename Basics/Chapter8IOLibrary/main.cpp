//Ex 8.11 problem:create a vector of PersonInfo 
// what if PersonInfo is declared and initialized outside the outer while loop?
// reset Record.Phone to 0 before processing the next entry.
//++validate the phone numbers

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

struct PersonInfo {
	std::string Name;
	std::vector<std::string> Phone;
};

void Process (std::istream& is, std::vector<PersonInfo> &People){
	std::string line, PhoneNumbers;
	PersonInfo Record;
	std::istringstream iss; //global in the function, calling clear() is critical
	while(getline(is,line)){
		iss.clear();	//ok, i feel the urgent need for vim now! 13/05/2020
		iss.str(line);		
		iss >> Record.Name;
		while(iss >> PhoneNumbers){	
			//validate and format, 
			//sstream_err is the test input file
			//Lee's second number is invalid and excluded
			if(PhoneNumbers.length() != 10) continue;
			else{
				std::string temp(12,'0');
				for(int i = 0; i <4; ++i) temp[i] = PhoneNumbers[i];
				temp[4] = '-'; 
				for(int i = 4; i < 7; ++i) temp[i+1] = PhoneNumbers[i];
				temp[8] = '-';
				for(int i = 7; i<10; ++i) temp[i+2] = PhoneNumbers[i];
				PhoneNumbers = temp;
			}
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
	return 0;
}
