#include "ex13_44_47.h"
#include <algorithm>
#include <iostream>

std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return{ str, std::uninitialized_copy(b, e, str) };
}

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char *s)
{
    char *sl = const_cast<char*>(s); //remove constness of parameter passed in
    while (*sl) 	//this loop extracts the off-the-end pointer
        ++sl;
    range_initializer(s, ++sl);	//finally I understand every detail after 3 days
}

String::String(const String& rhs)
{
    range_initializer(rhs.elements, rhs.end);
    std::cout << "copy constructor" << std::endl;
}

void String::free()
{
    if (elements) {
        std::for_each(elements, end, [this](char &c){ alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String::~String()
{
    free();
}

String& String::operator = (const String &rhs)
{
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

//victory
String::String (String&& s){
	std::cout << "move constructor" << std::endl;
	elements = s.elements;
	end = s.end;
	s.elements = s.end = nullptr;
}

String& String::operator= (String&& s){
	std::cout << "move assignment" << std::endl;
	elements = s.elements;
	end = s.end;
	s.elements = s.end = nullptr;
	return *this;
}
