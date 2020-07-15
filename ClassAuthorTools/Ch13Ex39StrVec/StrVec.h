//Section 13.5 Classes that manage dynamic memory
//Ex13.39 write your own version of class StrVec, including reserve, capacity and resize methods
//construction stage of drawing: class definition, call it a day!
//++ ready to be join into TextQuery modules for testing
//++ passed 3 the preliminary tests

#ifndef _STRVEC_H_
#define _STRVEC_H_

#include <iostream>
#include <string>
#include <memory>

using std::string;

class StrVec {
public:
    StrVec():elements{nullptr}, first_free{nullptr}, cap{nullptr} {}
    ~StrVec(){Free ();}
    StrVec (const StrVec& source);
    StrVec& operator= (const StrVec& source);
    
    //top 5 methods
    void push_back(const string& source);
    
    string* begin() const {return elements;}
    string* end() const {return first_free;}
    
    size_t size () const {return first_free - elements;}
    size_t capacity() const {return cap - elements; }  //getter

    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const string& s);
    StrVec (const std::initializer_list<string> &il);
    
private:
    static std::allocator<string> allo;     
    
    void CheckNReallocate();
    std::pair<string*, string*> AllocateNCopy(const string* b, const string* e);
    
    //move the current data to a new bigger location
    void Reallocate();
    
    //helper to destructor
    void Free();
        
    string* elements;
    string* first_free;
    string* cap;
};

//if definition statement is missing, undefined reference error
std::allocator<string> StrVec::allo;

void StrVec::CheckNReallocate (){
        if(size() == capacity ()) Reallocate ();
    }
    
std::pair<string*, string*> StrVec::AllocateNCopy(const string* b, const string* e){
        auto data = allo.allocate(e - b);
        return {data, std::uninitialized_copy(b,e,data)};
    }

void StrVec::Free (){
        if(elements){
            for(auto p = first_free; p != elements;)
                allo.destroy(--p);
            allo.deallocate(elements, cap-elements);
        }
    }


void StrVec::push_back(const string& source){
        CheckNReallocate ();
        allo.construct(first_free++, source);
    }
    
void StrVec::Reallocate (){
        size_t NewCap = (size() == 0)? 1 : size()*2;
        auto p = allo.allocate(NewCap);
        auto dest = p;
        auto elem = elements;
        for(size_t i = 0; i < size(); ++i){     //sigsegv error fixed, finally!
	        allo.construct(dest++, std::move(*elem++));
        }        
        Free ();
        elements = p;
        first_free = dest;
        cap = p + NewCap;
        
    }

StrVec::StrVec (const StrVec& source){
        auto data = AllocateNCopy(source.begin(), source.end());
        elements = data.first;
        first_free = cap = data.second;
    }
    
StrVec& StrVec::operator= (const StrVec& source){
        Free ();
        auto data = AllocateNCopy(source.begin(), source.end());
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }
    

void StrVec::reserve(size_t n){
    if(n<size()) return;
    auto p = allo.allocate(n);
        auto dest = p;
        auto elem = elements;
        for(size_t i = 0; i < size(); ++i){     
	        allo.construct(dest++, std::move(*elem++));
        }        
        Free ();
        elements = p;
        first_free = dest;
        cap = p + n;
}
    
void StrVec::resize(size_t n){
    resize(n, string ());
}
/*
void StrVec::resize(size_t n, const string& s){
	if(n > size()){
		if(n>capacity()) reserve (n*2);
		for(size_t i = size(); i < n; ++i){
			allo.construct(first_free++, s);
		}
	}
	else if(n < size()){
		while(first_free != elements+ n){
			allo.destroy(--first_free);
		}
	}
}
    */
    //loop using size and n
void StrVec::resize(size_t n, const string& s){
    if( n< size()){
        while( size() - n > 0)
            allo.destroy(--first_free);
    } else if (n > size()) {
    	if(n > capacity()) reserve(n*2);
        while ( n - size() > 0)
        	allo.construct(first_free++, s);
    }
}
    
StrVec::StrVec (const std::initializer_list<string> &il){
    auto data = allo.allocate(il.size());
    elements = data;
    first_free = cap = uninitialized_copy(il.begin(), il.end(), data);
}

#endif
