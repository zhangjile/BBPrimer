//Section 17.5.2 Unformatted Input/Output Operations
//Ex17.37, p 764, Use the unformatted version of getline to read a file a line at a time. Test your program by giving it a file that contain empty lines as well as lines that are longer than the characters that you pass to getline

#include <iostream>
#include <cmath>
#include <fstream>

using std::cin; using std::cout; 
using std::ifstream; 

int main(){
	//returns nothing on Mobile C, test it on desktop
	ifstream ifs("README.md");
	char ch[100];
	while(ifs.getline(ch, 100, '.')){
		cout << ch[3] <<"\n";
		cout.write(ch,100);
	}
	
	/*
	int ch;
	while((ch = cin.get()) != EOF){
		cout.put(ch);
	}
	*/
	
	/*
	char ch;
	while(cin.get(ch)){
		cout.put(ch);
	}
	*/
	return 0;
}

