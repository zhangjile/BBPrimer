//Chapter 13 Copy Control
//Ex13.5, p499, Given the following sketch of a class, wrte a copy constructor that copies all the members. Your constructor should dynamically allocate a new string and copy the object to which ps points rather than copying ps itself
//Ex13.22, p 511, Assume that we want HasPtr to behave like a value. That is, each object should have its own copy of the string to which the object points. Write the copy constructor and copy assignment operator for class HasPtr.

#include <iostream>
#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s):
        ps{new std::string(s)}, i{0} {}
    //Ex 13.5
    HasPtr (const HasPtr& source):
        ps{new std::string(*source.ps)}, i{source.i} {}
    //Ex13.22
    HasPtr& operator= (const HasPtr& source){
        //route 0
        if(this != &source){
            delete ps;
            *ps = *source.ps;
            i = source.i;            
        }
        return *this;
    /*
        //route 1
        std::string* Newp = new std::string(*source.ps);
        delete ps;  //deallocate ps, not destroying ps
        ps = Newp;
        i = source.i;

        return *this;
    */
    }
    
    //pointer data member must be freed manually
    ~HasPtr(){
        delete ps;
    }
    void Print(){
        std::cout << *ps <<", " << i <<std::endl;
    }
private:
    std::string* ps;
    int i;
};

int main()
{
    HasPtr c1("Charlie Kirk");
    HasPtr c2 = c1;    //this is the meaning of value-like behavior, like 'x = 5'.
    c2.Print();
    return 0;
}