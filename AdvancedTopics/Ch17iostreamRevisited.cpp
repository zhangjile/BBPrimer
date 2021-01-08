//Chapter 17 iostream revisited
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <regex>
using namespace std;
void test1(){
    cout << cout.precision() <<endl;
    cout <<"value: "<< sqrt(2) <<endl;
    cout.precision(12);
    cout <<"value: "<< sqrt(2) <<endl;
    cout <<setprecision(2);
    cout <<"value: "<< sqrt(2) <<endl;
}

void test2(){
    char ch;
    while(cin.get(ch)){
        cout.put(ch);
    }
}

void test3(){
    string text = {"vim in on road neovim"};
    string pattern = "vim";
    regex r(pattern);
    string fmt ="VIM";
    string Rep;    
    
    regex_replace(back_inserter(Rep), text.begin(), text.end(), r, fmt);
    cout << Rep <<endl;
    
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}
