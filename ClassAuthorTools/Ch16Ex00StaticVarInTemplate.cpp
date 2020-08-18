#include <iostream>
using std::cout; using std::endl;

template<typename T>
void spin(T x){
    static int var = 10;
    cout<< ++var <<endl;
}

// 3 initiations, not one
int main(){
    //instantiating spin(int x)
    spin(720);  //11
    //spin(709);    //12
    
    //instantiating spin(float x)    
    spin(7.20); //11
    
    //instantiating spin(char x)
    spin('L');  //11
    return 0;
}