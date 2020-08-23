//Section 16.1.3 Template parameters
//Ex16.19, p 672, Write a function that takes a reference to a container and prints the elements in that container.
//Use the container's size_type and size members to control the loop tht prints the elements
//Ex16.20, Rewrite the function to use iterators returned from begin and end to control the loop.
// ++ code text is wild, CS textbooks are wild, you can have tons of typo errors without being criticized by the insiders, LOL

#include <iostream>
#include <deque>
#include <string>

using std::deque; using std::string;

//Ex19
template<typename T>
void Print(const T& c){
    using STP = typename T::size_type;
    STP s = c.size();
    for(size_t i = 0; i < s; ++i){
        std::cout << c[i] << " " <<std::endl;
    }
    std::cout << std::endl;
}

//Ex20
/*
//redefinition
template<typename T>
void Print(const T& a){
    for(auto b = a.begin(), e = a.end(); b != e; ++b){
        std::cout << *b << " "<<std::endl;
    }
    std::cout << std::endl;
}

*/

template<typename T>
void Print(const T& a, std::ostream& os){
    for(auto b = a.begin(), e = a.end(); b != e; ++b){
        os << *b << " "<<std::endl;
    }
    std::cout << std::endl;
}

int main(){
    deque<string> v {"callables in C++", "functions", "pointers to functions", "lambdas","classes that overload the function-call operator" };
    Print(v);
    Print(v, std::cout);
    return 0;
}
