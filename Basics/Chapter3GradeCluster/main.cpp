// Chapter 3 Ex3.25 p103
// input using ifstream instead of cin, there's a bug that swallow the first score.
// Level-up: ifstream class
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int main () {
	std::ifstream is("grade_data");
	std::string s {};
	
	std::vector<int> cluster(11,0);
	int grade {0};	
	is.clear();
	while(std::getline(is, s)){		
		//std::cout << s <<std::endl;
		std::istringstream i(s);
		i>>grade;
		std::cout << grade <<std::endl;
		if(grade <= 100){
			++*(cluster.begin() + grade/10);
		}
	}
	for(int i:cluster){
		std::cout <<i <<" ";
	}
	std::cout <<std::endl;
	is.close();
	/*
	int t;
	std::cin>>t;
	while(t--)
{
     std::string arr;
     std::cin.ignore();
     getline(std::cin,arr);
     std::istringstream iss(arr);
     std::string word;
     while(iss>>word)
     {
          std::cout<<word;
      }
 }*/
	return 0;
}

