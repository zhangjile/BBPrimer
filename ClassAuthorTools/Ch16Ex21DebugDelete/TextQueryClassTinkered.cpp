//Section 16.1.4 Member Templates
//Ex16.22, p675, Revise your TextQuery program so that the shared_ptr members uses a DebugDelete as their deleter.
//Ex16.23, Predict when the call operator will be executed in your main query program. If your expectations and what happens differ, fix the error and be sure you understand why.
//++tinkering around, set the mapped value to be a naked set<int>

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

//Ex16.21
class DebugDelete
{
public:
    DebugDelete(std::ostream& s = std::cerr) : os(s) { }
    template<typename T>
    void operator() (T* p) const
    {
        os << "customized deleter called" << std::endl;
        delete p;
    }

private:
    std::ostream& os;
};

class QueryResult;      //forward declaration

class TextQuery{
private:
	shared_ptr<vector<string>> FileByLine;
	map<string, set<int>> Scan;	
	//set the mapped value to be a naked set container
public:
	TextQuery(istream &is);
	
	QueryResult Query(const string& key);
};

TextQuery::TextQuery(istream &is)
    : FileByLine(new vector<string> (), DebugDelete())  //standard syntax, p465!
{	
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

class QueryResult
{
    friend ostream& print (ostream& os, const QueryResult& rhs); 
public:
    QueryResult(const string& s, shared_ptr<vector<string>> f, set<int> l)
            : key{s}, File{f}, lines {l} {}
    
private:
    std::string key;
    shared_ptr<std::vector<std::string>> File;
    std::set<int> lines;
};

QueryResult TextQuery::Query(const string& key){
        
        auto loc = Scan.find(key);
        if(loc == Scan.end()){
            return QueryResult(key, FileByLine, set<int> ());
        } else {
            return QueryResult(key, FileByLine, loc ->second);
        }
        
}
        
ostream& print (ostream& os, const QueryResult& rhs){
    os << rhs.key <<" appeared "<<rhs.lines.size() << " times"<<endl;
    for(int num: rhs.lines){ 
        os <<"(line " <<num <<")\t" <<*(rhs.File->begin() + num -1) <<endl;        
    }
    return  os;
}
        
int main ()
{
	ifstream is ("100_git_commands");
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
		//splashing in water
	} 
	
	return 0;
	
}
