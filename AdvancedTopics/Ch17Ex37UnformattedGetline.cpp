//Section 17.5.2 Unformatted Input/Output Operations
//Ex17.37, p 764, Use the unformatted version of getline to read a file a line at a time. Test your program by giving it a file that contain empty lines as well as lines that are longer than the characters that you pass to getline
//Ex17.38, extend your program from the previous exercise to print each word you read onto its own line

#include <iostream>
#include <cmath>
#include <fstream>

using std::cin; using std::cout; 
using std::ifstream; 

int main(){
	//take out the delim and it works!
	ifstream ifs("README_clean.md");
	char ch[200];
	while(ifs.getline(ch, 200, '\n')){
//	while(ifs.getline(ch, 200, ' ')){//Ex17.38
		cout <<"\n";
		cout.write(ch,200);
	}
	//try out gcount and bit type check
	std::cout << ifs.gcount() << std::endl;
	std::cout << std::boolalpha << (ifs.rdstate() == std::ios_base::failbit) << std::endl;
	//if there's a block of more than 200 bits, failbit happens!
	
	/*
	//example in textbook
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

