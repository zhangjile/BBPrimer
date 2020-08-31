//Section 16.4 Variadic Templates
//Ex16.51 p701, Determine what 'sizeof ...(Args)' and 'sizeof ... (Rest)' return for each call to Foon, and 
//Ex16.52, write a program to check your answers against your predictions.

#include <iostream>
#include <string>

using std::string; using std::cout; using std::endl;

template<typename T, typename ... Args>
void Foon(const T&, const Args ... Rest){
    cout << sizeof ... (Args) << endl;
    cout << sizeof ... (Rest) << endl;
}

int main (){
    string s("As Easy As a Cake!");
    Foon(5);
    Foon(5, 'C');
    Foon(5, 'C', s);
    
    return 0;
}