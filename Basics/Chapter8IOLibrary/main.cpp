//Ex 8.11 problem:create a vector of PersonInfo 
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

struct PersonInfo {
	std::string name;
	std::vector<std::string> phone;
};

void Process (std::istream& is, std::vector<PersonInfo> &People){
	std::string line, Phone_num;
	while(getline(is,line)){
		PersonInfo One;
		std::istringstream iss(line);
		iss >> One.name;
		while(iss >> Phone_num){
			One.phone.push_back(Phone_num);
		}
		People.push_back(One);
	}
}

void DisplayPersonInfo(const PersonInfo& one){
	std::cout<< one.name <<":\t ";
	for(auto s:one.phone){
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
