//Section 13.5 Classes that manage dynamic memory
//Ex13.39 write your own version of class StrVec, including reserve, capacity and resize methods
//construction stage of drawing: class definition, call it a day!
//++ ready to be join into TextQuery and MessageFolder modules for testing

#include <iostream>
#include <string>
#include <memory>

using std::string;

class StrVec {
public:
    StrVec():elements{nullptr}, first_free{nullptr}, cap{nullptr} {}
    ~StrVec(){free ();}
    StrVec (const StrVec& source){
        auto data = AllocateNCopy(source.begin(), source.end());
        elements = data.first;
        first_free = cap = data.second;
    }
    StrVec& operator= (const StrVec& source){
        free ();
        auto data = AllocateNCopy(source.begin(), source.end());
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }
    
    //top 3 methods
    void push_back(const string& source){
        CheckNReallocate ();
        allo.construct(first_free, source);
    }
    String* begin() const {return elements;}
    String* end() const {return first_free;}
    
    void reserve(size_t n);
    size_t size () const {return first_free - elements;}
    size_t capacity() const {return cap - elements; }  //getter
    void resize(size_t n);
    
private:
    static std::allocator<string> allo;
    
    void CheckNReallocate (){
        if(size() == capacity) reallocate ();
    }
    
    std::pair<string*, string*> AllocateNCopy(const string* b, const string* e){
        auto data = allo.allocate(e - b);
        return {data, uninitialized_copy(b,e,data)};
    }
    
    //move the current data to a new bigger location
    void Reallocate (){
        size_t NewCap = (size() == 0)? 1 : size()*2;
        auto p = allo.allocate(NewCap);
        auto dest = p;
        auto elem = elements;
        alloc.construct(dest++, st::move(*elem++));
        free ();
        elements = p;
        first_free = dest;
        cap = p + NewCap;
        
    }
    
    //helper to destructor
    void Free (){
        if(elements){
            for(auto p = first_free; p != elements)
                allo.destruct(--p);
            allo.deallocate(elements, cap-elements);
        }
    }
    
    string* elements;
    string* first_free;
    string* cap;
};

int main ()
{
    return 0;
}