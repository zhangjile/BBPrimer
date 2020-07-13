//Section 13.5 Classes that manage dynamic memory
//Ex13.39 write your own version of class StrVec, including reserve, capacity and resize methods
//construction stage of drawing: class definition, call it a day!
//++ ready to be join into TextQuery and MessageFolder modules for testing

#ifndef _STRVEC_h_
#define _STRVEC_h_

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
    
    //top 3 methods
    void push_back(const string&source);
    
    string* begin() const {return elements;}
    string* end() const {return first_free;}
    
    void reserve(size_t n);
    size_t size () const {return first_free - elements;}
    size_t capacity() const {return cap - elements; }  //getter
    void resize(size_t n);
    
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

void StrVec::CheckNReallocate (){
        if(size() == capacity ()) Reallocate ();
    }
    
std::pair<string*, string*> StrVec::AllocateNCopy(const string* b, const string* e){
        auto data = allo.allocate(e - b);
        return {data, uninitialized_copy(b,e,data)};
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
        allo.construct(first_free, source);
    }
    
void StrVec::Reallocate (){
        size_t NewCap = (size() == 0)? 1 : size()*2;
        auto p = allo.allocate(NewCap);
        auto dest = p;
        auto elem = elements;
        allo.construct(dest++, std::move(*elem++));
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
    

#endif
