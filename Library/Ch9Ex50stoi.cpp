//Chapter 9.5 string operations Ex9.50
#include <iostream>
#include <string>
#include <vector>

using std::vector; using std::string;

//Ex 9.50, add up a vector of strings that represent integral value
int AddUp(vector<string> vs){
	int s {0};
	for(const auto &e:vs){
		s += stoi(e);
	}
	return s;
}


//Ex 51, constructor a date object from a string
class Date {
private:
	unsigned year;
	unsigned month;
	unsigned day;
public:
	Date ():year{1900},month{1},day{1} {}
	Date (const string &s);
	void DisplayDate();
};

Date::Date(const string &str){
	//wash the potato before peeling
	string numbers = "0123456789";
	string alpha {};
	for(char c:str){	//exlucde symbols and spaces such as , / .
		if(isalnum(c)){
			alpha.push_back(c);
		}
	}
	for(char &c:alpha){	//tolower for precise comparison
		c = tolower(c);
		//std::cout << c <<"";
	}
	std::cout << std::endl;
	
	year = stoi(alpha.substr(alpha.size()-4,4)); //the last 4 digits represent year
	alpha.resize(alpha.size()-4);
	
	day = stoi(alpha.substr(alpha.find_first_of(numbers)));
	
	vector<string> m = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
	
	for(int i = 0; i < m.size(); ++i){
		if(alpha.find(m[i])!= string::npos){ //if(alpha.find(m[i])), wrong!
			month = i + 1;
			break;
		}		
	}
}

void Date::DisplayDate(){
	std::cout<<"The date: " <<month <<"/" <<day <<"/"<<year<<"\n"<<std::endl;
}

int main ()
{
	//Add
	vector<string> vs {"12","34","50"};
	std::cout <<AddUp(vs)<<std::endl;
	
	//Date
	Date today("June the. /04, 1989");
	today.DisplayDate();
	
	//verifying the example code
	string name = "HongKong2020Freedom";
	string numbers = "0123456789";
	auto s = name.find_first_of(numbers); //a size_t value for index
	std::cout << "The index for the first digit is: " << s << std::endl;
	
	auto str = name.substr(name.find_first_not_of(numbers),8);
	std::cout << str << std::endl;
	str = name.substr(name.find_first_of(numbers));	//2020Freedom
	std::cout << str << std::endl;
	
	auto i = stoi(name.substr(name.find_first_of(numbers),2)); //2020, numbers only
	std::cout << i << std::endl;
	
	return 0;
}
