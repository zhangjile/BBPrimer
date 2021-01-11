//more methods to manipulate strings
#include <iostream>
#include <string>
#include <vector>
using std::string;

void ExampleP360(){	//Primer, 
	const char* cp = "Hello, Mr. Donald Trump!!!";
	char Danger[] = {'H', 'i'};	//not a NULL terminated C string
	string s1(cp);
	string s2(Danger, 2);
	std::cout << s2 <<std::endl;
//	string s3(Danger);		//danger becomes disaster
	string s4(cp+11, 6);	//Donald
	string s5(s1, 11, 6);	//Donald
	string s6(s1, 11);	//Donald Trump!!!
	string s7(s1, 11, 60);	//result is 'Donald Trump!!!', typo dosn't cause problem
	std::cout << s7 <<std::endl;
//	string s8(s1,110); //typo, crash, out_of_range exception
	
	//s.substr(pos, n);
	s7 = s1.substr(0,5);	//range is s1[0] + 5
	std::cout << s7 <<std::endl;
	s7 = s1.substr(7);	//s[7] to the end of s1
	std::cout << s7 <<std::endl;
	s7 = s1.substr(11,60);	//robust implementation, typo error can be tolerated.
	std::cout << s7 <<std::endl;
}

//calling some functions on a string object:insert, erase, assign, append, replace
void ExamplesP362(){
	string s(5,'F');
	s.insert(s.size(), 5,'!');	//add 5 '!' before s.end(), s.size() is index in s
	std::cout << s << std::endl;
//	s.erase();	//same effect as s.clear(); Surprise! hahaha
//	std::cout << s << std::endl;
	s.erase(s.size()-5, 5);		//erase 5 elements inclusive from the index 's.size()-5'
	std::cout << s << std::endl;
	const char* Shout = "Stop the steal!!!";
	s.assign(Shout,4);	//subset 4 characters starting from the pointer in Shout
//	s.assign(Shout,40); //it's ok, tolerate the typo error
	std::cout << s << std::endl;

	//take out characters from Shout[8] inclusive to the end, insert before s.end()
	s.insert(s.size(), Shout+8);	 
	std::cout << s << std::endl;	//Stop steal, s[5] points to the space before 'steal'
	
	string str(Shout);
	s.insert(5,str,5,4);	//the insertion point is before the space in front of 'steal', star of the day!
	std::cout <<"line of the day: "<< s << std::endl;	//something like lego blocks
	
	//testflight append
	string st("C++ Primer"), st2 = st;
	st.insert(st.size(), " 4th Ed.");
	st2.append(" 4th Ed.");		//st == st2
	
	//testflight replace
	st.erase(11, 3);
	st.insert(11,"5th");
	std::cout << st << std::endl;
	
	st2.replace(11, 3, "Fifth");	//replace 3 characters with n characters.
//	st2.replace(11, 3, "5th");	//replace 3 characters with 3 characters identically.
	std::cout << st2 << std::endl;
	
}

//Ch9Ex41, this exercise is a great step forward. 
//It's a proof of the technique/methology of simplifying problems.
string ExpectedS1(string s, string OldVal, string NewVal){
	s.erase(3, 4);
	std::cout << s <<std::endl;		//calculate the index manually to understand
	s.insert(4, NewVal);
	return s;
}

string ExpectedS2(string s, string OldVal, string NewVal){
	s.replace(3,4,NewVal);
	return s;
}

string ExpectedS3(string s, string OldVal, string NewVal){
	while(s.find(OldVal) != string::npos){
		s.replace(s.find(OldVal),OldVal.size(),NewVal);
	}
	return s;
}


int main (){
	string s = "go thru the tunnel", OldVal ="thru", NewVal = "through";
	std::cout << ExpectedS3(s, OldVal, NewVal) <<std::endl;
	
//	ExampleP360();
//	ExamplesP362();

	return 0;
}

