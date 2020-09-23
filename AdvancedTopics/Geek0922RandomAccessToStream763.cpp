//geek.com 
//Input : Welcome in GeeksforGeeks. Best way to learn things.-1
//Output : Welcome in GeeksforGeeks. Best way to learn things.

#include <iostream>
#include <fstream>
#include <string>
using std::fstream; using std::ifstream; using std::ofstream;
using std::getline; using std::string; using std::cout;

int main(){
	/*
	//ifstream and ofstream
	ifstream i("Geek0922Input");
	ofstream o("Output");
	string line;
	while(getline(i,line)){
		if(line == "-1") break;
		o << line <<"\n";		
	}
	i.close();
	o.close();	//close the file so that it can be used elsewhere, otherwise there's error
	i.open("Output");
	while(getline(i,line)){
		cout << line <<"\n";
	}
	i.close();
	*/
	
	//fstream
	string line;
	ofstream o("Output");
	fstream f("Geek0922Input");
	while(getline(f, line)){
		o << line << "\n";
	//	if(line == "-1") break;
	}
	f.seekp(fstream::beg);
	f.close();
	o.close();
	ifstream i("Output");
	while(getline(i,line)){
		cout <<line <<"\n";
	}
	i.close();
	
	return 0;

}
