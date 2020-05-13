//Ex 8.11 problem:create a vector of PersonInfo 
// what if PersonInfo is declared and initialized outside the outer while loop?
// reset Record.Phone to 0 before processing the next entry.
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
		iss.clear();	//only the first entry is processed if this line is missing
		iss.str(line);		
		iss >> Record.Name;
		while(iss >> PhoneNumbers){
			Record.Phone.push_back(PhoneNumbers);
		}
		People.push_back(Record);
		Record.Phone = {};  //empty the PhoneNumbers of previous record manually
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
	//Process(std::cin, People2084);
	for(PersonInfo p: People2084){
		DisplayPersonInfo(p);
	}
	return 0;
}
