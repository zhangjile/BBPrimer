//Chapter 9.5 Additional string operations 
//Ex 47 find each numeric character and then each alphabetic character in the string "ab2c37R4E6"
#include <iostream>
#include <string>
using std::string;

void Display(const string &s);

void FindFirstOf (const string &s){
	string Numeric {}, Alphabetic {};
	size_t pos = 0;
	while((pos = s.find_first_of(("0123456789"),pos))!= string::npos){
		Numeric.push_back(s[pos]);
		++pos;
	}
	/*
	pos = 0;
	while((pos = s.find_first_not_of(("0123456789"),pos))!= string::npos){
		Alphabetic.push_back(s[pos]);
		++pos;
	}
	*/
	int j = 0;
	string temp = s;
	for(int i = 0; i < temp.size(); ++i){
		for(int j= 0; j < Numeric.size(); ++j){
			if(temp[i] == Numeric[j]){
				temp[i] = '@';
			}
		}
	}
	
	for(int i = 0; i < temp.size(); ++i){
		if(temp[i] != '@')
			Alphabetic.push_back(temp[i]);
	}
	
	Display(Numeric);
	Display(Alphabetic);
}

void Display(const string &s){
	for(char c: s){
		std::cout<< c <<"";
	}
	std::cout<<std::endl;
}

void FindFirstNotOf (const string &s);

int main() {
	string source = "ab2c3dR4E6";
	FindFirstOf(source);
	return 0;
}