//Section 16.7 Forwarding 
//Ex16.47, p695, Write your own version of the Flip function and test it 
//by calling functions that have lvalue and rvalue reference parameters

#include <iostream>
#include <utility>

template<typename F, typename T1, typename T2>
void FlipA(F f, T1 t1, T2 t2){
    f(t2,t1);	//primitive
}

template<typename F, typename T1, typename T2>
void FlipB(F f, T1&& t1, T2&& t2){
	//water-proof forwarding that keeps all the type information
    f(std::forward<T2> (t2), std::forward<T1> (t1));	
}

//L-value/R-value nature of the argument is preserved
void f(int&& a, int& b){
    std::cout << a << ", " << ++b << std::endl;
}

int main (){
    int x = 8;
//    f(42, x);
//    std::cout << x << std::endl;

//    FlipA(f, x, 42);
//    std::cout << x << std::endl;
    
    FlipB(f, x, 42);
    std::cout << x << std::endl;
    
    return 0;
}
