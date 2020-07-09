//Section 13.3 Swap
//Ex13.30 write and test a swap function for your value-like version HasPtr, give your swap a print statement that signals when it is executed.
//Ex13.31, p519, Give your class a < operator and define a vector of HasPtrs, sort it.


#include <iostream>
#include <string>
#include <vector>

class HasPtr{
public:
    HasPtr(const std::string &s):
        ps{new std::string(s)}, i{0} {}
    
    HasPtr (const HasPtr& source):
        ps{new std::string(*source.ps)}, i{source.i} {}
        
    HasPtr& operator= (const HasPtr& source){
        std::string* Newp = new std::string(*source.ps);
        delete ps;  //deallocate ps, not destroying ps
        ps = Newp;
        i = source.i;

        return *this;
    }
    
    //Ex13.30, swap method
    void swap(HasPtr& lhs, HasPtr& rhs){
        std::cout << "swapping" <<std::endl;
        using std::swap;    //good taste
        swap(lhs.ps, rhs.ps);
        swap(lhs.i, rhs.i);
    }
    
    //Ex13.30 operator<
    bool operator< (const HasPtr& rhs){
        return ps->size() < rhs.ps->size();
    }
    
    
    ~HasPtr(){
        delete ps;
    }
    void Print() const {
        std::cout << *ps <<", " << ps->size() <<std::endl;
    }
private:
    std::string* ps;
    int i;
};

int main()
{
    std::vector<HasPtr> vhp;
    HasPtr c1("Charlie Kirk");
    vhp.push_back(c1);
    HasPtr c2 = c1;   
    vhp.push_back(c2);
    HasPtr c3("Donald Trump Jr");
    vhp.push_back(c3);
    HasPtr c4("Britanica");
    HasPtr c ("BNO");
    swap(c,c4);
    vhp.push_back(c4);
    HasPtr c5("Al Pacino");
    vhp.push_back(c5);
    
   // sort(vhp.begin(), vhp.end());
    for(const auto& ele : vhp){
        ele.Print();
    }
    
    return 0;
}
