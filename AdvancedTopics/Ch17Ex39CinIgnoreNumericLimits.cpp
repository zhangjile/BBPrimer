
//Chapter 17.5.2, unformatted IO operations, p763,
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

//https://stackoverflow.com/questions/5918451/why-getline-skips-first-line?noredirect=1&lq=1
void TestIgnore2(){
	int T, i = 1;
    string line;
	ofstream OpenF("copyOut");
    cin >> T;
	std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n' );
    while (i <= T) {
        getline(cin,line);
        OpenF << line <<std::endl;
        i++;
    }
}
int main () {
//    TestIgnore1();
	TestIgnore2();
    return 0;
}
