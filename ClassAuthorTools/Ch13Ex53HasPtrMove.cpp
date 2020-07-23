//Section 13.6 Moving Objects
//Ex13.53 As a matter of low-level efficiency, the HasPtr assignment operator(implemented using std::swap) is not ideal. Explain why. 
//Implement a copy assignment and move assignment operator for HasPtr.
//Compare the operations executed in your new move assignment operator and the copy-and-swap version
//this is performance tuning, cool!

#include <iostream>
#include <string>

class HasPtr{
	friend void swap(HasPtr& lhs, HasPtr& rhs); //helper to copy-and-swap
public:
    HasPtr () = default;	//HasPtr() : ps{nullptr}, i{0} {}
    HasPtr(const std::string &s): ps{new std::string(s)}, i{0} {}
    
    //copy operations
    HasPtr (const HasPtr& source): ps{new std::string(*source.ps)}, i{source.i} {
            std::cout << "copy constructor" <<std::endl;
        }
    /*
    HasPtr& operator= (const HasPtr& source){
        std::cout << "copy assignment" <<std::endl;
        if(this != &source){
            delete ps;
            *ps = *source.ps;
            i = source.i;            
        }
        return *this;
    }
    */
    
    //move operations
    HasPtr (HasPtr&& source) noexcept : ps {source.ps}, i{source.i} {
        std::cout << "move constructor" <<std::endl;
        source.ps = nullptr;
        source.i = 0;
    }    
    /*
    HasPtr& operator= (HasPtr&& source) noexcept {
        std::cout << "move assignment" <<std::endl;
        if(this != &source){    //check against self assignment
            delete ps;
            ps = source.ps;
            i = std::move(source.i);
            source.ps = nullptr;
        }
        return *this;
    }        
 */   
    
    //copy-and-move implementation
    HasPtr& operator= (HasPtr v){
        std::cout << "copy-and-move" <<std::endl;
        swap(*this, v);
        return *this;
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

inline void swap(HasPtr& lhs, HasPtr& rhs){
	using std::swap;
	std::swap(lhs.ps, rhs.ps);
	std::swap(lhs.i, rhs.i);
	std::cout << "swap called"<< std::endl;
}

int main()
{
	HasPtr c;
    HasPtr c1("Charlie Kirk");
    HasPtr c2 = c1;   
    c1 = HasPtr("a vessel of idiots");
    c2.Print();
    
    HasPtr hp1("hello"), hp2("World");
    HasPtr *pH = new HasPtr("World");
    hp1 = hp2;
    hp1 = std::move(*pH);
    
    return 0;
}
