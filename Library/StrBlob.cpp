
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "StrBlobPtr.h"
using std::string; using std::vector; using std::shared_ptr; using std::initializer_list; using std::make_shared;

class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;	//grant friendship
public:
    typedef vector<string>::size_type size_type;
    StrBlob (): data {make_shared<vector<string>> ()} {}
    StrBlob (initializer_list<string> il): data {make_shared<vector<string>> (il)} {}
    
    size_type size() {return data->size();}
    bool empty() {return data->empty();}
    string& front() ;
    string& back() ;
    string& front() const {return data->front();}
    string& back() const {return data-> back();}
    void push_back(const string &t) {return data->push_back(t);}
    void pop_back();
    
    StrBlobPtr begin() {return StrBlobPtr(*this);}
    StrBlobPtr end() {return StrBlobPtr(*this, data->size());}
    
private:
    shared_ptr<vector<string>> data;
    void check(const string &s  = "an empty vector") const;
};

string& StrBlob::front() {
    check();
    return data->front();
}

string& StrBlob::back() {
    check();
    return data-> back();
}
    
void StrBlob::pop_back (){
    check();
    return data->pop_back();
}

void StrBlob::check(const string &s) const {
    if(data->size() == 0)
        std::cerr <<s <<std::endl;
}
