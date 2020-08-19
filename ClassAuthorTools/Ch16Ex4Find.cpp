//Section 16.1.1 Function Templates
//Ex16.4,p658, Write a template that acts like the library find algorithm. The function will need two template type parameters, one to represent the function's iterator parameter, and the other for the type of the value. 
//use your function to find a given value in a vector<int> and in a list<sring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>

using std::vector;

template<typename Iterator, typename T>
Iterator Find(const Iterator& b, const Iterator& e, const T& x){
    for(b != e && *b != x; ++b);
    return b;
}

int main (){
    vector<int> v = {1989, 2020, 2024};
    Find(v.begin(), v.end(), 2020);
    return 0;
}