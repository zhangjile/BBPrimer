//Section 16.1.2 Class Templates
//Ex16.12, p668, Write your own version of the Blob and BlobPtr templates. 
//Section 16.1.4 Member Template
//Ex16.24, p675, Add a new constructor that takes two iterators
//implementing methods outside of the class declaration unexpectedly caused all the redefinition problems, Heck!


#include <iostream>
#include <string>
#include <vector>
#include <memory>
//#include <stdexcept>
//#include <initializer_list>

using std::string; using std::vector; using std::shared_ptr; 
using std::initializer_list; using std::make_shared; 
using std::runtime_error; using std::out_of_range; using std::weak_ptr;

template <typename> class BlobPtr;

template<typename T> class Blob {
public:    
	friend  class BlobPtr<T>;	//grant friendship

    typedef typename vector<T>::size_type size_type;
    Blob (): data {make_shared<vector<T>> ()} {}
    Blob (initializer_list<T> il): data {make_shared<vector<T>> (il)} {}
    
    //Ex16.24, 
    template<typename Iterator>
    Blob(Iterator b, Iterator e) : data(make_shared<vector<T>> (b,e)) {}

    
    size_type size() {return data->size();}
    bool empty() {return data->empty();}
    T& front()  {
        check(0, "oh");
        return data->front();
    }
    T& back() {
        check(0, "oh");
        return data->back();
    }
    T& front() const {return data->front();}
    T& back() const {return data-> back();}
    void push_back(const T &t) { data->push_back(t);}
    void pop_back() {
        check(0, "oh");
        data-> pop_back();
    }
    
    //new methods
    BlobPtr<T> begin();
    BlobPtr<T> end();
    
private:
    shared_ptr<vector<T>> data;
    void check(size_t i, const string &msg  ) const {
        if(i >= data->size())
            throw out_of_range (msg);
    }
};

//class BlobPtr;
template<typename T> class BlobPtr {
public:
	BlobPtr () : curr(0) {}
	BlobPtr (Blob<T> &a, size_t sz = 0)
		: wptr(a.data), curr(sz) {}
	T& deref () {
        auto p = Check(0, "oh");
        return (*p)[curr];
    }

	BlobPtr& incre (){
        Check(curr, "oh");
        ++curr;
        return *this;
}
    bool operator != (const BlobPtr &rhs) const {return rhs.curr != curr; };
private:
	shared_ptr<vector<T>> Check (size_t i, const string& msg) {
        auto it = wptr.lock();
        if(!it){
            throw runtime_error("unbound");
        }
        if(i >= it->size()){
            throw out_of_range(msg);
        }
        return it;
    }

	weak_ptr<vector<T>> wptr;
	size_t curr;
};

//the right place for begin and end methods
//the whole point of creating class StrBlobPtr is to create begin and end methods for a StrBlob object. 

template<typename T>
BlobPtr<T> Blob<T>::begin() {return BlobPtr<T> (*this);}

template<typename T>
BlobPtr<T> Blob<T>::end() {auto ret = BlobPtr<T> (*this, data->size()); return ret;}


