//Section 16.4.1 Writing a Variadic Function Template
//Ex16.53, p 702, Write your own version of the Print functions and test them by printing one, two and five arguments, each of which should have different types.
//Ex16.54, What if we call print on a type that doesn't have an << operator defined?
//compile error
//Ex16.55, Explain how the variadic version of print would execute if we define the nonvariadic version of print after the definition of the variadic version.
// out of scope and invisible, terminator is missing, endless loop will occur.

#include <iostream>

template<typename T>
std::ostream& Print(std::ostream& os, const T& t){
    os << t;
    return os;
}

template<typename T, typename ... Args>
std::ostream& Print(std::ostream& os, const T& t, const Args& ... Rest){
    os << t << ", ";
    return Print(os, Rest...);	//Recursion is revisited
}

int main (){
    Print(std::cout, "Chez", 2020.83);
    return 0;
}
