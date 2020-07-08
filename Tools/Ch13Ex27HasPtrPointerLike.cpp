//Chapter 13 Copy Control
//Ex13.27 p516, Define your own reference-counted version of class HasPtr.
//there's no dangling pointer or memory leak, of course.

#include <iostream>
#include <string>

class HasPtr{
public:
    HasPtr(const std::string &s):
        ps{new std::string(s)}, i{0}, use {new size_t(1)} {}
        
    HasPtr (const HasPtr& source):
        ps{source.ps}, i{source.i}, use{source.use} {++*use;}
        
    HasPtr& operator= (const HasPtr& source){
        ++*source.use; //size_t incremented = ++*source.use;
        if(--*use == 0){
        	delete ps;
        	delete use;
        }
        ps = source.ps; //*ps = *source.ps;
        i = source.i;
        use = source.use; //*use = incremented;
        return *this;
    }
    
    //test the logic
    HasPtr& Modify(string NewString){
        *ps = NewString;
        return *this;
    }
    
    ~HasPtr (){
    	if(--*use == 0){
    		delete ps;
    		delete use;
    	}
    }
    
    void Print(){
        std::cout << *ps <<", " << *use<<std::endl;
    }
    
private:
    std::string* ps;
    int i;
    size_t* use;
};

int main()
{
    HasPtr c1("Charlie Kirk");
    
    //memberwise copying with correct copy control using reference count
    HasPtr c2 = c1;    // c2 is an identical copy of c1
    
    c2.Print();// Charilie Kirk, 2 
    
    c2.Modify("Charles Kirk");  //we intend the change to be effective elsewhere
    
    c1.Print(); //Charles Kirk, 2, success!
    return 0;
}
