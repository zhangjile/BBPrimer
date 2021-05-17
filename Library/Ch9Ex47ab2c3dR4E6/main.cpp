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
	
	pos = 0;
	while((pos = s.find_first_not_of(("0123456789"),pos))!= string::npos){
		Alphabetic.push_back(s[pos]);
		++pos;
	}
	
	/*
	// o(n squared) implementation, clumsy, silly, abandoned!
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
	*/
	
	Display(Numeric);
	Display(Alphabetic);
}

void Display(const string &s){
	for(char c: s){
		std::cout<< c <<"";
	}
	std::cout<<std::endl;
}

//s.find_first_of(s2,pos,n)
void FindFirstOf_n(const string& s, size_t n){
	string::size_type pos = 0;
	if(s.find_first_of(("0123456789"),2,n) != std::string::npos)
		std::cout << s.find_first_of(("0123456789"),2,n) << std::endl;
	else
		std::cout << "not found" <<std::endl;
}


//gratitude to the author
void cplusplus_example (){
  std::string str ("Please, replace the vowels in this sentence by asterisks.");
  std::size_t found = str.find_first_of("aeiou");
  while (found!=std::string::npos)
  {
    str[found]='*';
    found=str.find_first_of("aeiou",found+1);
  }

  std::cout << str << '\n';

}

int main() {
	string s = "ab8c7dR6E4";
	FindFirstOf(s);
	FindFirstOf_n(s, 7);	//9, if n=4 -> not found
	//終於搞明白了，find_first_of返回的值是一個index
	//"ab8c7dR6E4" 字符串中6出現在第7的位置上，第9的位置是4。
	
	cplusplus_example();
	return 0;
}
