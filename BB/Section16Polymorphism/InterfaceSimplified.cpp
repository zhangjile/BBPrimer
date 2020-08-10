// Section 16 Interfaces - complete,simplified
// rule of name lookup, Derived is nested in Base scope, Primer, p617

#include <iostream>

class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable (){};
};

std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    std::cout<<"\npure_vitrtual";
    return os;
}

class Dog : public I_Printable {
public:
  virtual void print(std::ostream &os) const override {
        os << "Woof woof";
    } 
};

void StandAlonePrint (const I_Printable& obj){
	std::cout << obj<< std::endl;
	std::cout << "StandAlonePrint" << std::endl;
}

int main() {
    Dog *dog = new Dog();
    
    //look up 'operator <<' outward in Base scope 
    std::cout << *dog<< std::endl;  
    std::cout << std::endl;  
    
    StandAlonePrint(*dog);
    
    delete dog;
    return 0;
}
