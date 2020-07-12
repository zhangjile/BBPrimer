//Section 13.5 Classes that manage dynamic memory
//Ex13.39 write your own version of class StrVec, including reserve, capacity and resize methods
//construction stage of drawing: class definition, call it a day!

#include <iostream>
#include <string>
#include <memory>

using std::string;

class StrVec {
public:
    StrVec();
    ~StrVec();
    StrVec (const StrVec& source);
    StrVec& operator= (const StrVec& source);
    String* begin() const;
    String* end() const;
    
    void reserve();
    size_t size () const;
    size_t capacity() const;  //getter
    void resize();
    
private:
    static std::allocator<string> allo;
    
    void CheckNReallocate ();
    std::pair<string*, string*> AllocateNCopy(const string* b, const string* e);
    void Reallocate ();
    void Free ();
    
    string* elements;
    string* first_free;
    string* cap;
};

int main ()
{
    return 0;
}