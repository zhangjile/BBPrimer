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
Iterator Find(Iterator b, Iterator e, const T& x){
    for(; b != e && *b != x; ++b);	//the formal ; expression is required
    return b;	//if not found, b == e and then quit the loop!    
}


int main (){
    vector<int> v = {1989, 2000, 2020, 2024};
    auto it = Find(v.cbegin(), v.cend(), 2028);    
    std::cout <<"Index: "<< it - v.cbegin() << std::endl;	//index or off the end
    
    std::list<std::string> l = { "aa", "bb", "cc", "dd", "ee", "ff", "gg" };
    
    // '=' is right-associative of very low precedence 
    bool is_in_list = l.cend() != Find(l.cbegin(), l.cend(), "zz");
    std::cout << (is_in_list ? "found\n" : "not found\n");

    return 0;
}
