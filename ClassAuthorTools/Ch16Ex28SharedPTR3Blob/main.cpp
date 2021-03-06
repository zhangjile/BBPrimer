﻿//Section 16.1.4 Member Templates
//Ex16.22, p675, Revise your TextQuery program so that the SharedPTR members uses a DebugDelete as their deleter.
//Ex16.23, Predict when the call operator will be executed in your main query program. If your expectations and what happens differ, fix the error and be sure you understand why.
//Ex16.28, write your version shared pointer
//the working of use_count in reset is verified. 

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

template <typename T> 
class SharedPTR { 
public: 
	// Constructor 
	explicit SharedPTR(T* ptr = nullptr) { 
		m_ptr = ptr; 
		m_counter = new size_t(); 
		if (ptr) { 
			(*m_counter)++; 
		} 
	} 

	// Copy constructor 
	SharedPTR(const SharedPTR<T>& sp) { //watch the effect of const!
		m_ptr = sp.m_ptr; 
		m_counter = sp.m_counter; 
		(*m_counter)++; 
	} 

	// Reference count 
	size_t use_count() {return *m_counter; } 

	// Get the pointer
	T* get() {return m_ptr; } 
 
	// Overload * operator, dereferencing
	T& operator*() {return *m_ptr; } 

	// Overload -> operator, watch out the const correctness!
	T* operator->() const {return m_ptr; } 
	
	//Primer, p465,
	//if p is the only shared_ptr pointing at its object, reset frees p's existing object. If the optional built-in pointer q is passed, makes p point to q, otherwise mkaes p nullptr.
	SharedPTR reset(T* ptr = new T()){
		m_ptr = ptr;
		m_counter = new size_t();
		if(ptr) ++*m_counter;
		return *this;	//final touch, wow!
	}
	
	// Destructor 
	~SharedPTR() { 
		(*m_counter)--; 
		if (*m_counter == 0) { 
			delete m_counter; 
			delete m_ptr; 
		} 
	} 

	friend ostream& operator<<(ostream& os, SharedPTR<T>& sp) 
	{ 
		os << "Address pointed : "
		<< sp.get() << "; " << *(sp.m_counter) << endl; 
		return os;
	} 

private: 
	size_t* m_counter; 
	T* m_ptr; 
}; 

class QueryResult;      //forward declaration

class TextQuery{
private:
	SharedPTR<vector<string>> FileByLine;
	map<string, SharedPTR<set<int>>> Scan;	
	//set the mapped value reference type to be modifiable
public:
	TextQuery(istream &is);
	
	QueryResult Query(const string& key);
};

TextQuery::TextQuery(istream &is)
    : FileByLine(new vector<string> ())  
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
            if(!loc.get()) loc.reset(new set<int> ());      
			loc->insert(LineNumber);     
		}
	}
}

class QueryResult
{
    friend ostream& print (ostream& os, const QueryResult& rhs); 
public:
    QueryResult(const string& s, SharedPTR<vector<string>> f, SharedPTR<set<int>> l)
            : key{s}, File{f}, lines {l} {}
    
private:
    std::string key;
    SharedPTR<std::vector<std::string>> File;
    SharedPTR<std::set<int>> lines;
};

QueryResult TextQuery::Query(const string& key){
        static SharedPTR<set<int>> NoData(new set<int> );
        auto loc = Scan.find(key);
        if(loc == Scan.end()){
            return QueryResult(key, FileByLine, NoData);
        } else {
            return QueryResult(key, FileByLine, loc ->second);
        }
        
}
        
ostream& print (ostream& os, const QueryResult& rhs){
	SharedPTR<std::set<int>> c = rhs.lines;
    os << rhs.key <<" appeared "<<rhs.lines->size() << " times"<<endl;
    for(int num: *c){ 
        os <<"(line " <<num <<")\t" <<*(rhs.File->begin() + num -1) <<endl;        
    }
    return  os;
}
        
int main ()
{
	ifstream is ("README.md");
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
	} 
	
	return 0;
	
}
