//Section 13.6 Moving Objects
//Ex13.47, p534, Give the copy constructor and copy assignment operator 
// in clss MyString a statement that prints a message each time
// the function is executed. (raise flag or something)
//Ex13.48, Define a vector<MyString> and call push_back on it several times. Run it to see how often MyString objects are copied.
//Ex13.49, p 544, Add a move constructor and move-assignment operator to your StrVec, MyString and Message class
//Ex13.50, put print statements in the move operations in class MyString, rerun the program in Ex13.48 that used a vector<MyString> to see when copies are avoided.

#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <memory>

class MyString {
public:
    MyString() : cp{}, v{0} {}
    MyString(const char* c);
    MyString (const MyString& source);
    MyString& operator= (const MyString& source);
    ~MyString ();
    
    //Ex13.49
    MyString (MyString&& s) noexcept;
    MyString& operator=(MyString&& s) noexcept;
    
    char front() {return *cp;}
    char back() {return *(cp + v -1);}
    size_t size () {return v;}
    
private:
    char* cp;
    size_t v =0;
//    void Free (); //unnecessary to destroy 'char'
    static std::allocator<char> alloc;
};

std::allocator<char> MyString::alloc;

MyString::MyString(const char* c){
	v = std::strlen(c);
	cp = alloc.allocate(v);
	std::uninitialized_copy(c,c+v, cp);	//conversion under hood
}
/*
MyString::MyString(const char* c){
    size_t Size = strlen(c);
    cp = alloc.allocate(Size);
    for(size_t i = 0; i < Size; ++i){
        alloc.construct(cp++,*c++); //error,initialize non-const with const
    }
    v = Size;
}
*/

//copy operations
MyString::MyString (const MyString& source){
	std::cout <<"Copy constructor" << std::endl;
    v = strlen(source.cp);
    cp = alloc.allocate(v);
    std::uninitialized_copy(source.cp, source.cp+v, cp);
    
}

MyString& MyString::operator= (const MyString& source){
	std::cout <<"Copy_Assignment" << std::endl;
    Free();
    v = strlen(source.cp);
    cp = alloc.allocate(v);
    std::uninitialized_copy(source.cp, source.cp+v, cp);	
    return *this;
}

//destructor
MyString::~MyString(){
    alloc.deallocate(cp, cp+v); //good enough
}

//move operations
MyString::MyString (MyString&& s) noexcept: cp{s.cp},v{s.v} {
	std::cout << "Move constructor" << std::endl;
	s.cp = nullptr;
	s.v = 0;
}
MyString& MyString::operator=(MyString&& s) noexcept {
	std::cout << "Move assignment" << std::endl;
	if(cp != &s){
	    if(cp)
            alloc.deallocate(cp,v);
        	cp = s.cp;
	    v = s.v;
        	s.cp = nullptr;
        	s.v = 0;
    }
	return *this;
}

#endif
