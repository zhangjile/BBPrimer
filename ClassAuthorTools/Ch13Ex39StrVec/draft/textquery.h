#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_
#include "strvec.h"
#include <iostream>
#include <set>
#include <sstream>
#include <fstream>
#include <memory>
#include <map>

using std::string; using std::istream; using std::ifstream; using std::map;
using std::cout; using std::endl; 
using std::cin; using std::set; using std::istringstream; using std::shared_ptr;

class QueryResult;  

class TextQuery{
private:
	shared_ptr<StrVec> FileByLine;
	map<string, shared_ptr<set<int>>> Scan; // the mapped value a reference type
public:
	TextQuery(istream &is);	
	QueryResult Query(const string& key);
};


// Scanning/parsing text is the first procedure
TextQuery::TextQuery(istream &is)
    : FileByLine(new StrVec)   
{	
	string Line {};
	int LineNumber {0};
	while(getline(is, Line)){
		++LineNumber;
		FileByLine->push_back(Line);
		string word {};
		istringstream iss(Line);
		while(iss >>word){
            auto &loc = Scan[word];
            if(!loc) loc.reset(new set<int>);      
			loc->insert(LineNumber);     
		}
	}
}

class QueryResult
{
    friend std::ostream& print (std::ostream& os, const QueryResult& rhs);   
public:
    QueryResult(const string& s, shared_ptr<StrVec> f, shared_ptr<std::set<int>> l)
            : key{s}, File{f}, lines {l} {}
    
private:
    std::string key;
    shared_ptr<StrVec> File;
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
        
std::ostream& print (std::ostream& os, const QueryResult& rhs){
    os << rhs.key <<" appeared "<<rhs.lines->size() << " times"<<endl;
    for(int num: *rhs.lines){ 
        os <<"(line " <<num <<")\t" <<*(rhs.File->begin() + num -1) <<endl;        
    }
    return  os;
}

#endif