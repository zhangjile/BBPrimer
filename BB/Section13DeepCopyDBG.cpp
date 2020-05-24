// Section 13
// Copy Constructor - Deep Copy
#include <iostream>
using namespace std;

class Deep {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value()const { return *data; }
    Deep(int d);	// Constructor
    Deep(const Deep &source);	// Copy Constructor
    ~Deep();	// Destructor
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
    cout <<"constructor called" <<endl;
}

Deep::Deep(const Deep &source)
  //  : Deep {*source.data} {  	//delegating, more concise
    {
    data = new int;
    *data = *source.data; // *(source.data), actual order of evaluation.    
    cout << "Copy constructor  - deep copy" << endl;
}

Deep::~Deep() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_deep(const Deep &s) {
    cout << s.get_data_value() << endl;
}

int main() {
    
    Deep obj1 {100};
    //if deep copy not implemented, crash is cerrtainty! 
    //display_deep on obj1 creates a copy, when this operation is completed, 
    //this unnamed copy is out of scope and DESTROYED, and memory is released
    //data member of obj1 is invalidated and becomes a dangling pointer
    display_deep(obj1);
    
    cout <<"======obj2======"<<endl;     
    Deep obj2 {obj1}; 
    obj2.set_data_value(1000);
    display_deep(obj2);
    
    return 0;
}

