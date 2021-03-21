//https://www.geeksforgeeks.org/calling-virtual-methods-in-constructordestructor-in-cpp/

#include<iostream> 
using namespace std; 
  
class dog { 
public: 
    dog()  
    { 
        cout<< "Constructor called" <<endl; 
        bark() ; 
    } 
  
    ~dog() 
    {  
        bark();  
    } 
  
    virtual void bark() 
    {  
        cout<< "Virtual method called" <<endl;  
    } 
  
    void seeCat()  
    {  
        bark();  
    } 
}; 
  
class Yellowdog : public dog { 
public: 
        Yellowdog()  
        { 
            cout<< "Derived class Constructor called" <<endl;  
        } 
        void bark()  
        { 
            cout<< "Derived class Virtual method called" <<endl;  
        } 
}; 
  
int main() { 
    Yellowdog d; 
    //Although, bark method is virtual method,
    //when it is called inside constructor it will behave as non-virtual method 
    //because by the time constructor of dog(base) class is called as in above code,
    //Yellowdog(derived) class is not constructed by that time.
    d.seeCat(); 
    //Dog::seeCat(const Dog& b)   //implicit parameter
    //b.seeCat()   // const Dog& b = d, 
    //which in turn calls bark().
    /*
    Output:
        Constructor called
        Virtual method called
        Derived class Constructor called
        Derived class Virtual method called  //seeCat()
        Virtual method called //destructor
    */
} 
