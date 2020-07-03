//Chapter 12 Dynamic Memory, conclusion project, P484
//shouldn't the use of dynamic memory as technique hidden?
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <map>

using std::string; using std::istream; using std::ifstream; using std::map;
using std::cout; using std::endl;

void TextQuery (istream &is, string KeyWord){
	map<int, string> Summary;
	int LineNumber {0}, Ocurrences {0};
	string Line {};
	
	while(getline(is, Line)){
		++LineNumber;
		if(Line.find(KeyWord) != std::string::npos){
			Summary[LineNumber] = Line;
			++Ocurrences;
		}
	}
	
	if(Ocurrences == 0){
		cout << KeyWord << " not found"<< endl;
	}
	else {
		cout << KeyWord << " occurs " <<Ocurrences <<" times" << endl;
		for(const auto &ele: Summary){
			cout << "\t(line " <<ele.first <<") " << ele.second <<endl;
		}
	}
}

int main ()
{
	std::ifstream is ("../Notes.md");
	std::string s = "list";
	TextQuery (is, s);
	return 0;
	
}
