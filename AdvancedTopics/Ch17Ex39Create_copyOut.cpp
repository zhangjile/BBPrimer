//this is a utility that creates copyOut data file.
//Ch17Ex39Seekp.cpp code produces unexpected results if we create copyOut by hand.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Create(){
	ofstream ofs;
	ofs.open("copyOut");
	string s{};
	for(size_t i=0; i < 4; ++i){
		cin >>s;
		ofs << s <<"\n";
	}
}

int main(){
	Create();
	return 0;
}
