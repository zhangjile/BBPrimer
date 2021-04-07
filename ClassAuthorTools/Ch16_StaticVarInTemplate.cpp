//CppNuts, count me in
//How static variables behave in template class and template function?
#include <iostream>
using std::cout; using std::endl;

template<typename T>
class Print{
private:
    int x;
public:
    static T val;
    void spin() {cout << ++val <<endl;}
};

template<typename T>
T Print<T>::val = 0;

// 2 initiations, not one
int main(){
    Print<int> i;
    i.spin();  //1
    
    Print<int> i2;
    i2.spin();
    
    Print<double> d;
    d.spin(); //1
    
    return 0;
}