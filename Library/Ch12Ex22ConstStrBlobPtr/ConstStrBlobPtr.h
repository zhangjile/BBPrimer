#include <iostream>
#include <string>
#include <vector>
#include <memory>
//#include <stdexcept>
//#include <initializer_list>

using std::string; using std::vector; using std::shared_ptr; 
using std::initializer_list; using std::make_shared; 
using std::runtime_error; using std::out_of_range; using std::weak_ptr;

class ConstStrBlobPtr;

class StrBlob {
public:    
	friend class ConstStrBlobPtr;	//grant friendship

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
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;
    
private:
    shared_ptr<vector<string>> data;
    void check(size_t i, const string &msg  ) const {
        if(i >= data->size())
            throw out_of_range (msg);
    }
};

//class ConstStrBlobPtr;
//StrBlobPtr type becomes useless. 
class ConstStrBlobPtr {
public:
	ConstStrBlobPtr () : curr(0) {}
	//critical consistency in constructor layer
	ConstStrBlobPtr (const StrBlob &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	string& deref () const {
        auto p = Check(0, "oh");
        return (*p)[curr];
    }

	ConstStrBlobPtr& incre (){
        Check(curr, "oh");
        ++curr;
        return *this;
}
    bool operator != (const ConstStrBlobPtr &rhs) const {return rhs.curr != curr; };
private:
	shared_ptr<vector<string>> Check (size_t i, const string& msg) const {
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


ConstStrBlobPtr StrBlob::begin() const {return ConstStrBlobPtr(*this);}
ConstStrBlobPtr StrBlob::end() const {auto ret = ConstStrBlobPtr(*this, data->size()); return ret;}


