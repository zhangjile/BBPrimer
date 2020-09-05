//Section 16.5 Template Specializations
//Ex16.63 p712, Define a function template to count the number  of occurrences of a given value in a vector. Test your program by passing it a vector of ints, a vector of doubles and a vector of strings.

#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::string; using std::cout; 
using std::endl;

template <typename T>
size_t Occurrences(vector<T> t, T v){
	size_t count = 0;
	for(const auto& elem : t){
		if(elem == v)
			++count;
	}
	return count;
}

template <>
size_t Occurrences(vector<const char*> t, const char* v){
	cout <<"<>"<<endl;
	size_t count = 0;
	for(const auto& elem : t){
		if(elem == v)
			++count;
	}
	return count;
}

//extension,handle Occurences(vector<string> const char*)
template<unsigned N>
size_t Occurrences(vector<string> t, const char (&v)[N]){	//wow const!
	cout <<"const char (&v)[N]"<<endl;
	size_t count = 0;
	for(const auto& elem : t){
		if(elem == v)
			++count;
	}
	return count;

}

int main() {
	vector<double> d = {3.1, 3.14, 3.2,3.14};
	size_t c = Occurrences(d, 3.14);
	cout << c << endl;
	
	vector<string> s = {"Xu","Zhang","Run","Run"};	//章潤檄文傳天下
	string str = "Run";
	c = Occurrences(s, str);	//Occurences(s, "Run"), error!
	cout<< c << endl;
	
	vector<int> i = {1,2,3,4,3};
	cout << Occurrences(i, 3) <<endl;
	
	vector<const char*> cc = {"Xu","Zhang","Run","Run"};
	cout << Occurrences(cc, "Run") << endl;
	cout << Occurrences(s, "Run") << endl;
	return 0;
}