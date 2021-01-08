//this is a utility that creates copyOut data file.
//Ch17Ex39Seekp.cpp code produces unexpected results if we create copyOut by hand.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//this function creates data file manually
void CreateBackUp(){
	ofstream ofs;
	ofs.open("Ch17Ex39Backup");
	string s{};
	for(size_t i=0; i < 4; ++i){
		cin >>s;
		ofs << s <<"\n";
	}
}

//create a copy and try out everything on the copy
void Create(){
	ofstream ofs;
	ofs.open("copyOut");
	ifstream b("Ch17Ex39Backup");
	string s{};
	for(size_t i=0; i < 4; ++i){
		getline(b,s);
		ofs << s <<"\n";
	}
}

int main(){
	//CreateBackUp();
	Create();
	return 0;
}
