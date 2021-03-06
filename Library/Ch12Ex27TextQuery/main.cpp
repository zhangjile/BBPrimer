﻿//Chapter 12 Dynamic Memory, conclusion project, P484
//interior decoration, redesign the major componets
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include <memory>
#include <map>

using std::string; using std::istream; using std::ifstream; using std::map;
using std::cout; using std::endl; using std::ostream;
using std::vector; using std::cin; using std::set; using std::istringstream;
using std::shared_ptr;

//add class QueryResult, which is intended to be the return type of TextQuery::Query(const string& key).
// print function (as a friend) prints a QueryResult object

class QueryResult;      //forward declaration

class TextQuery{
private:
	shared_ptr<vector<string>> FileByLine;
	//make the mapped value a reference type,brilliant!
	map<string, shared_ptr<set<int>>> Scan; 
public:
	TextQuery(istream &is);
	
	QueryResult Query(const string& key);
};


// Scanning/parsing text is the first procedure
TextQuery::TextQuery(istream &is)
    : FileByLine(new vector<string> ())     //brilliant!
{	
	string Line {};
	int LineNumber {0};
	while(getline(is, Line)){
		++LineNumber;
		FileByLine->push_back(Line);
		string word {};
		istringstream iss(Line);
		while(iss >>word){
			 //watchpoint, if loc is not initialized, core dump! LOL
            auto &loc = Scan[word];
            if(!loc) loc.reset(new set<int>);      
			loc->insert(LineNumber);     
		}
	}
}

class QueryResult
{
    friend ostream& print (ostream& os, const QueryResult& rhs); 
public:
    QueryResult(const string& s, shared_ptr<vector<string>> f, shared_ptr<set<int>> l)
            : key{s}, File{f}, lines {l} {}
    
private:
    std::string key;
    shared_ptr<std::vector<std::string>> File;
    shared_ptr<std::set<int>> lines;
};

QueryResult TextQuery::Query(const string& key){
        static shared_ptr<set<int>> NoData(new set<int> );
        auto loc = Scan.find(key);
        if(loc == Scan.end()){
            return QueryResult(key, FileByLine, NoData);
        } else {
            return QueryResult(key, FileByLine, loc ->second);
        }
        
}
        
ostream& print (ostream& os, const QueryResult& rhs){
    os << rhs.key <<" appeared "<<rhs.lines->size() << " times"<<endl;
    //' *rhs.lines == *(rhs.line)', precedence, cf P110, Primer
    //walk by your own!
    for(int num: *rhs.lines){ 
        os <<"(line " <<num <<")\t" <<*(rhs.File->begin() + num -1) <<endl;        
    }
    return  os;
}
        
int main ()
{
	ifstream is ("../Notes.md");
	TextQuery tq(is);
	
	while(true){
		std::string s {};
		cout<<"Enter your query: "<<endl;
		cin >> s;
		if(s == "q") {
			cout <<"bye"<<endl;
			break;
		}
		print(cout,  tq.Query (s) )<<endl;    
		//stop holding a walking-stick, stand steadily and walk firmly
	} 
	
	return 0;
	
}
