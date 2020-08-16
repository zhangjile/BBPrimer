//Chapter 12 Dynamic Memory, conclusion project, P484
// redesign the output section to be more efficienty, put all the desired info in a basket
#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_
#include <vector>
#include <iostream>
#include <string>

#include <set>
#include <sstream>
#include <fstream>
#include <memory>
#include <map>

using std::vector;
using std::string; using std::istream; using std::ifstream; using std::map;
using std::cout; using std::endl; using std::ostream;
using std::cin; using std::set; using std::istringstream; using std::shared_ptr;

//class QueryResult is designed/intended to be the return type of Query operation.
// print function (as a friend) prints a QueryResult object

class QueryResult;      //forward declaration

class TextQuery{
	friend class QueryResult;
public:
	using line_no = vector<string>::size_type;
	TextQuery(istream &is);	
	QueryResult query(const string& key) const;
	shared_ptr<vector<string>> GetFile() const {return FileByLine;}
private:
	shared_ptr<vector<string>> FileByLine;
	//make the mapped value a reference type,brilliant!
	map<string, shared_ptr<set<line_no>>> Scan; 
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
            if(!loc) loc.reset(new set<line_no>);      
			loc->insert(LineNumber);     
		}
	}
}

class QueryResult
{
    //friend ostream& print (ostream& os, const QueryResult& rhs); 
    friend ostream& operator<< (ostream& os, const QueryResult& rhs);
public:
    using line_no = vector<string>::size_type;
    QueryResult(const string& s, shared_ptr<vector<string>> f, shared_ptr<set<line_no>> l)
            : key{s}, File{f}, lines {l} {}
    auto begin() {return lines->begin();}
    auto end () {return lines->end();}
    
private:
    std::string key;
    shared_ptr<vector<string>> File;
    shared_ptr<set<line_no>> lines;
};

QueryResult TextQuery::query(const string& key) const {
        static shared_ptr<set<line_no>> NoData(new set<line_no> );
        auto loc = Scan.find(key);
        if(loc == Scan.end()){
            return QueryResult(key, FileByLine, NoData);
        } else {
            return QueryResult(key, FileByLine, loc ->second);
        }
        
}
        
ostream& operator<< (ostream& os, const QueryResult& rhs){
    os << rhs.key <<" appeared "<<rhs.lines->size() << " times"<<endl;
    for(int num: *rhs.lines){ 
        os <<"(line " <<num <<")\t" <<*(rhs.File->begin() + num -1) <<endl;        
    }
    return  os;
}
        
#endif
