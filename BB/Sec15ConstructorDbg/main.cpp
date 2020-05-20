//Section 15 Constructors and Destructors
//observe the underhood workings of inheritance in debugger finally
//in Codelite on a humble pseudo desktop with Ubuntu 18.4 os 
//on 20/05/2020
#include <iostream>

class Base 
{
private:
    int value;
public:
    Base () : value {0} {std:: cout << "Base no-arg constructor" << std::endl;}
    Base (int x) : value{x} {std:: cout << "Base (int) constructor" << std::endl;}
    ~Base () {std:: cout << "Base destructor" << std::endl;}
};

class Derived : public Base
{
private:
    int double_value;
public:
    Derived () : double_value {0} {std:: cout << "Derived no-arg constructor" << std::endl;}
//    Derived (int x) : double_value {2 * x} {std:: cout << "Derived (int) constructor" << std::endl;}
    Derived (int x) : Base(x), double_value {2 * x} {std:: cout << "Derived (int) constructor" << std::endl;}
    ~Derived () {std:: cout << "Derived destructor" << std::endl;}
};

int main() {
    //Base b {1000};
    Derived d {1000};

    return 0;
}