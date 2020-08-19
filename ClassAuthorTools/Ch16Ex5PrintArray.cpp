//Ex16.5, p 658, write a template version of Print function from $6.2.4(p217) that takes a reference to an array and can handle arrays of any size and any element type.

#include <iostream>
using std::cout; using std::endl;

template<typename T, unsigned N>
void Print (const T (&x)[N]){
    for(unsigned i = 0; i < N; ++i){
        cout << x[i] <<" ";
    }
    cout << endl;
}

int main (){
    Print("Hi, Mr Pompeo");
    //wow
    int j[] = {1,2};
    Print(j);
    return 0;
}
