//Section 14.6 increment and decrement operators
//14.27, p569, add increment and decrement operators to your StrBlobStr class
//14.28, define addition and substraction for StrBlobPtr so that these operators implement pointer arithmetic

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>
#include <stdexcept>
#include <initializer_list>

using std::string; using std::vector; using std::shared_ptr; 
using std::initializer_list; using std::make_shared; 
using std::runtime_error; using std::out_of_range; using std::weak_ptr;

class StrBlobPtr;

class StrBlob {
public:    
	friend class StrBlobPtr;	//grant friendship

    typedef vector<string>::size_type size_type;
    StrBlob (): data {make_shared<vector<string>> ()} {}
    StrBlob (initializer_list<string> il): data {make_shared<vector<string>> (il)} {}
    
    size_type size() {return data->size();}
    bool empty() {return data->empty();}
    string& front()  {
        check(0, "oh");
        return data->front();
    }
    string& back() {
        check(0, "oh");
        return data->back();
    }
    string& front() const {return data->front();}
    string& back() const {return data-> back();}
    void push_back(const string &t) { data->push_back(t);}
    void pop_back() {
        check(0, "oh");
        data-> pop_back();
    }
    
    //new methods
    StrBlobPtr begin();
    StrBlobPtr end();
    
private:
    shared_ptr<vector<string>> data;
    void check(size_t i, const string &msg  ) const {
        if(i >= data->size())
            throw out_of_range (msg);
    }
};

//class StrBlobPtr;
class StrBlobPtr {
public:
	StrBlobPtr () : curr(0) {}
	StrBlobPtr (StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	
	//dereference operator	
//	string& deref () {
	string& operator*(){
        auto p = Check(0, "oh");
        return (*p)[curr];
    }
	
    //increment operator
//	StrBlobPtr& incre (){
	StrBlobPtr& operator++ (){
        Check(curr, "oh");
        ++curr;
        return *this;
}

	StrBlobPtr operator++(int){
		StrBlobPtr temp = *this;
		++*this;
		return temp;
	}
	
	//pointer arithmetic
    StrBlobPtr& operator+(size_t n);
    StrBlobPtr& operator-(size_t n);
	
	//equality operator in pair
	bool operator== (const StrBlobPtr &rhs) const {return rhs.curr == curr;}
    bool operator != (const StrBlobPtr &rhs) const {return rhs.curr != curr;}
    
private:
	shared_ptr<vector<string>> Check (size_t i, const string& msg) {
        auto it = wptr.lock();
        if(!it){
            throw runtime_error("unbound");
        }
        if(i >= it->size()){
            throw out_of_range(msg);
        }
        return it;
    }

	weak_ptr<vector<string>> wptr;
	size_t curr;
};

// overloading operators is obviously easy, just consult a reference modify some lines and get things done.
//however, under the hood there's something significant and something extremely beautiful

StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {auto ret = StrBlobPtr(*this, data->size()); return ret;}

	StrBlobPtr& StrBlobPtr::operator+(size_t n){
        //so cute:)
		auto m = Check(curr + n, "oh, yeah!");
        wptr = m;
        curr += n;
        return *this;
	}

	
	StrBlobPtr& StrBlobPtr::operator-(size_t n){
        curr -= n;
        Check(curr - n, "oh, f!");
        return *this;

	}	

