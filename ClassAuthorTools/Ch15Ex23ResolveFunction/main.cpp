//Section 15.6 Class Scope under Inheritance
//Ex15.23, p 621, Assuming class D1 on page 620 had intended to override its 
//inherited fcn function, how would you fix that class? 
//Assuming you fixed the class so that fcn matched the definition
// in Base, how would the calls in that section be resolved?
// ++debugging brings me great sense of achievement recently, because
 //it requires pretty good understanding of basics to quickly spot where the 
 //bug exists, and the moment figuring out how to modify the code is also wonderful,
//both are signals and reflections

#include <iostream>

class Base {
public:
    virtual int fcn () { return (int) ('B');}
};

class D1 : public Base {
public:
    D1 () = default;
    //turn on and off this to see the difference
    virtual int fcn() override { return (int) ('D');}  //Ex15.23
    
    int fcn (int x) {return x*10;}          
    virtual void f2 () {std::cout << "D1::f2()" << std::endl;}
};

class D2 : public D1 {
public:
    int fcn (int);      //not virtual, D1::fcn(int) is hidden
    int fcn() { return (int) ('G');}        
    //implicitly virtual, ready to override the version inherited from D1
    void f2 () {std::cout << "D2::f2()" << std::endl;}
};

//'error: undefined reference to vtable D1', define fcn(int) , or comment it out

int main () {
    Base bobj;          
    D1 d1obj;        
    D2 d2obj;
    Base* bp1 = &bobj;
    Base* bp2 = &d1obj;
    Base* bp3 = &d2obj;
    
    std::cout << bp1->fcn () << std::endl;
    std::cout << bp2->fcn () << std::endl;
    std::cout << bp3->fcn () << std::endl;
    
    D1* d1p = &d1obj;
    D1* d2p = &d2obj;
    
    //bp2 -> f2();	//no member named 'f2' in 'Base'
    d1p->f2();
    d2p->f2();
    
    return 0;
}
