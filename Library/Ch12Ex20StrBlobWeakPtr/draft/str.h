#ifndef STR_H_
#define STR_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::string; using std::vector; using std::shared_ptr; using std::initializer_list; using std::make_shared; using std::out_of_range; using std::runtime_error; using std::weak_ptr;

class StrBlobPtr;       //forward declaration

class StrBlob {
    friend class StrBlobPtr;        //grant friendship
public:
     StrBlobPtr begin ();
     StrBlobPtr end();
public:
    typedef vector<string>::size_type size_type;
    StrBlob (): data {make_shared<vector<string>> ()} {}
    StrBlob (initializer_list<string> il): data {make_shared<vector<string>> (il)} {}
    
    size_type size() {return data->size();}
    bool empty() {return data->empty();}
    inline string& front() ;
    inline string& back() ;
    
    void push_back(const string &t) {return data->push_back(t);}
    void pop_back();
    
private:
    shared_ptr<vector<string>> data;
    inline void check(size_t i, const string &s  = "an empty vector") const;
};

string& StrBlob::front() {
    check(0);
    return data->front();
}

string& StrBlob::back() {
    check(0);
    return data-> back();
}


void StrBlob::check(size_t i, const string &msg) const {
    if(i >= data->size())
        throw out_of_range(msg);
}

//define class StrBlobPtr;
class StrBlobPtr {
public:
    StrBlobPtr ();
    StrBlobPtr (StrBlob& a, size_t sz = 0);
   inline  string& deref ();
    inline StrBlobPtr& incre ();
private:
    shared_ptr<vector<string>> Check (size_t i, const string &msg) const{
        auto ret = wptr.lock();
        if(!ret) throw runtime_error ("unbound");
        if(i >= ret->size()) throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

string& StrBlobPtr::deref (){
    auto p = Check(0, "off the end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incre (){
    Check(curr, "beyong end");
    ++curr;
    return *this;
}



#endif