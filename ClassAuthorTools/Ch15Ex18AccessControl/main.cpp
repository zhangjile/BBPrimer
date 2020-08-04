//Section 15.5 Access Control and Inheritance
//Ex15.18, p 616, Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren't allowed.
//Ex15.19, Assume that each of the classes has a member function of the form:
//void memfcn (Base& b) {b = *this;}
//for each class, determine whether this function would be legal.
//Ex15.20, write code to test your answers to the previous 2 exercises.

#include <iostream>

//the man
class Base {
public:
    void pub_mem () {std::cout <<  priv_mem << std::endl;}  //define this member, otherwise error
    //not necessary to make it virtual, just test whether the base class public member is accessible to its children and grandchildren
    void memfcn (Base& b) {b = *this;}  //Ex15.19, over-verbose, but ok
protected:
    int prot_mem;
private:
    char priv_mem;
};

//the sons
struct PubDerv : public Base {
    int f() {return prot_mem;} //ok
//    char g() {return priv_mem;} //error
    void memfcn (Base& b) {b = *this;}  //ok, member functions and friends of derived can use conversion by all means
};

struct PrivDerv : private Base {
    int f1() {return prot_mem;} //ok
    void memfcn (Base& b) {b = *this;} //ok, 
};

struct ProtDerv : protected Base {
    int f2 () {return prot_mem;} //it's absolutely natural that ProtDerv member has access to the protected members of the Base
    void memfcn (Base& b) {b = *this;}  //ok
};

//the grandsons
struct Derived_From_PubDerv : public PubDerv {
    int use_base () {return prot_mem;}  //ok
    void memfcn (Base& b) {b = *this;}  //ok
};

struct Derived_From_PrivDerv : public PrivDerv { //key point
	Derived_From_PrivDerv () = default;
//    int use_base () {return prot_mem;}  //error
//    void memfcn (Base& b) {b = *this;}  //error
};

struct Derived_From_ProtDerv : public ProtDerv {
    int use_base () {return prot_mem;}  //the protected member of Base is intended for sons and grandsons to use
    void memfcn (Base& b) {b = *this;}  //ok
};

int main (){
    PubDerv d1;
    PrivDerv d2;
    d1.pub_mem (); //ok
//    d2.pub_mem ();  //error
    
    //the object of ProtDerv cannot access the inherited public member of Base
    ProtDerv d3;
//    d3.pub_mem (); //error
    
    //Ex15.18, testing Derived_Base_Conversion
    Derived_From_PubDerv dd1;   //dd1 has type Derived_From_Public
    Derived_From_PrivDerv dd2;  //dd1 has type Derived_From_Private
    Derived_From_ProtDerv dd3;  //dd1 has type Derived_From_Protected
    
    Base* p = &d1;  //ok, user code may use the derived_to_base conversion only if inheriting publicly 
//    p = &d2;        //no
//    p = &d3;        //no
    p = &dd1;       //ok
//    p = &dd2;       //no
//    p = &dd3;       //no
    std::cout << "woo, everything is done!" << std::endl;
    return 0;
}
