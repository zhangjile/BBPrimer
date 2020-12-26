//signature of cin.ignore():
//istream& ignore (streamsize n = 1, int delim = EOF);
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

void TestIgnore1(){
	char name[30];
//	cin.ignore();
	cin.getline(name, 30);
	cout<<"NAME:"<<name; // THIS PRINTS 'im' for 'Kim'
}

//This fuction creates copyOut in 'pure' machine file format, assign 4 to T and type abcd efg hi j in 4 lines
void TestIgnore2(){
	int T, i = 1;
    string line;
	ofstream OpenF("copyOut");
    cin >> T;
	std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n' );
    while (i <= T) {
        getline(cin,line);
        OpenF << line << endl;
        i++;
    }
}

int main () {
    
	TestIgnore2();
    return 0;
}
