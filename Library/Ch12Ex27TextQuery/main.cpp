﻿//Chapter 12 Dynamic Memory, conclusion project, P484
//shouldn't the use of dynamic memory as technique hidden?
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include <memory>
#include <map>

using std::string; using std::istream; using std::ifstream; using std::map;
using std::cout; using std::endl; 
using std::vector; using std::cin; using std::set; using std::istringstream;
using std::shared_ptr;

class TextQuery{
private:
	shared_ptr<vector<string>> FileByLine;
	map<string, set<int>> Scan;
public:
	TextQuery(istream &is);
	
	void Query(const string& key){
		if(Scan.find(key) == Scan.end()){cout << key << " not found"<< endl;}
		
		size_t Occurences = Scan[key].size();
		cout << key << " occurs " <<Occurences <<" times" << endl;
		for(const auto &ele : Scan[key]){
			cout <<"\t(line "<<ele << ")" <<"\t" <<(*FileByLine)[ele-1]<<endl;
		}
	}
};

TextQuery::TextQuery(istream &is)
    : FileByLine(new vector<string> ())     //this line is bright!
{	// Parsing text
	string Line {};
	int LineNumber {0};
	while(getline(is, Line)){
		++LineNumber;
		FileByLine->push_back(Line);
		string word {};
		istringstream iss(Line);
		while(iss >>word){
			Scan[word].insert(LineNumber);
		}
	}
}


int main ()
{
	std::ifstream is ("../Notes.md");
	TextQuery tq(is);
	
	while(true){
		std::string s {};
		cout<<"Enter your query: "<<endl;
		cin >> s;
		if(s == "q") {
			cout <<"bye"<<endl;
			break;
		}
		tq.Query (s);
	} 
	
	return 0;
	
}
