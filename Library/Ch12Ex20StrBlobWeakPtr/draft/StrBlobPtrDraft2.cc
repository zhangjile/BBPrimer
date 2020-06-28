#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::string; using std::vector; using std::shared_ptr; 
using std::initializer_list; using std::make_shared; 
using std::runtime_error; using std::out_of_range; using std::weak_ptr;

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
    
    //new methods
    StrBlobPtr begin();
    StrBlobPtr end();
    
private:
    shared_ptr<vector<string>> data;
    void check(size_t i, const string &msg  = "an empty vector") const;
};

string& StrBlob::front() {
    check(0);
    return data->front();
}

string& StrBlob::back() {
    check(0);
    return data-> back();
}
    
void StrBlob::pop_back (){
    check(0);
    return data->pop_back();
}

void StrBlob::check(size_t i, const string &msg) const {
    if(i >= data->size())
    	throw out_of_range (msg);
}


//class StrBlobPtr;
class StrBlobPtr {
public:
	StrBlobPtr () : curr(0) {}
	StrBlobPtr (StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	string& deref ();
	StrBlobPtr& incre ();
private:
	shared_ptr<vector<string>> Check (size_t i, const string& msg);
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

shared_ptr<vector<string>> StrBlobPtr::Check (size_t i, const string& msg){
	auto it = wptr.lock();
	if(!it){
		throw runtime_error("unbound");
	}
	if(i >= it->size()){
		throw out_of_range(msg);
	}
	return it;
}


string& StrBlobPtr::deref(){
	auto p = Check(0, "oh");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incre (){
	Check(curr, "oh");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {auto ret = StrBlobPtr(*this, data->size()); return ret;}


int main()
{
    StrBlob sb1;  
    
    //a block of code
    {
    	StrBlob sb2 {"a", "an", "the"};
    	sb1 = sb2;
    	sb2.push_back("oh");
    }
    
    std::cout<<sb1.size() <<std::endl;
    std::cout<<sb1.back() <<std::endl;
    
	StrBlobPtr sbp (sb1,3);
    sbp.deref();
    
    
    return 0;
}
