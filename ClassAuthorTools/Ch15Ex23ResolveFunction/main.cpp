//Section 15.6 Class Scope under Inheritance
//Ex15.23, p 621, Assuming class D1 on page 620 had intended to override its inherited fcn function, 
// how would you fix that class? Assuming you fixed the class so that fcn matched the definition
// in Base, how would the calls in that section be resolved?
// ++debugging brings me great sense of achievement recently, because it requires good 
//understanding of basics to spot where the bug exists quickly, and figuring out how to modify the code is wonderful

#include <iostream>

class Base {
public:
    virtual int fcn () { return (int) ('B');}
};

class D1 : public Base {
public:
    D1 () = default;
    //turn on and off this to see the difference
    //virtual int fcn() override { return (int) ('D');}  //override the inherited member
    
   // int fcn (int);          
    //virtual void f2 ();
};

class D2 : public D1 {
public:
    //int fcn (int);      //non virtual, D1::fcn(int) is hidden
    int fcn() { return (int) ('G');}        
    //void f2 ();         //virtual, implicitly, ready to override the version inherited from D1
};

//'error: undefined reference to vtable D1', if fcn(int) is not defined, comment it out

int main () {
    Base bobj;          D1 d1obj;        D2 d2obj;
    Base* bp1 = &bobj;
    Base* bp2 = &d1obj;
    Base* bp3 = &d2obj;
    
    std::cout << bp1->fcn () << std::endl;
    std::cout << bp2->fcn () << std::endl;
    std::cout << bp3->fcn () << std::endl;
    return 0;
}