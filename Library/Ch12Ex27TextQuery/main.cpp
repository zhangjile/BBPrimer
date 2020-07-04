//Chapter 12 Dynamic Memory, conclusion project, P484
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
using std::cout; using std::endl; 
using std::vector; using std::cin; using std::set; using std::istringstream;
using std::shared_ptr;

//add class QueryResult, which is intended to be the return type of TextQuery::Query(const string& key).
//overload print operator for QueryResult and print what Query function returns

class QueryResult;      //forward declaration

class TextQuery{
private:
	shared_ptr<vector<string>> FileByLine;
	map<string, shared_ptr<set<int>>> Scan;     //make the mapped value a reference type
public:
	TextQuery(istream &is);
	
	QueryResult Query(const string& key);
};


// Scanning/parsing text is the first procedure
TextQuery::TextQuery(istream &is)
    : FileByLine(new vector<string> ())     //this line is bright!
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
            if(!loc) loc.reset(new set<int>);       //watch point, if loc is not properly initialized, core dump! LOL
			loc->insert(LineNumber);     
		}
	}
}

class QueryResult
{
    friend std::ostream& print (std::ostream& os, const QueryResult& rhs);        // final output procedure
public:
    QueryResult(const string& s, shared_ptr<std::vector<std::string>> f, shared_ptr<std::set<int>> l)
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
        
std::ostream& print (std::ostream& os, const QueryResult& rhs){
    os << rhs.key <<" appeared "<<rhs.lines->size() << " times"<<endl;
    for(int num: *rhs.lines){
        os << "( line " << num  << " ) \t" << *(rhs.File->begin() + num -1) << endl;        //walk in your own style!
    }
    return  os;
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
		print(std::cout,  tq.Query (s) )<<std::endl;    //stop copying, ie, stop walking with the walking-stick, stand steadily and walk firmly
	} 
	
	return 0;
	
}
