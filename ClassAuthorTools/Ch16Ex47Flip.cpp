//Section 16.7 Forwarding 
//Ex16.47, p695, Write your own version of the Flip function and test it 
//by calling functions that have lvalue and rvalue reference parameters

#include <iostream>
#include <utility>

//part 1
void fa(int a, int& b){
	std::cout << a <<":" <<++b <<std::endl;
}

template<typename F, typename T1, typename T2>
void FlipA(F f, T1 t1, T2 t2){
    f(t2,t1);	//an unexpected result pops out.
}

//part 2
void fb(int&& a, int& b){
    std::cout << a << ", " << ++b << std::endl;
}

template<typename F, typename T1, typename T2>
void FlipB(F f, T1&& t1, T2&& t2){ //half baked
	f(t2, t1);	
}

//part 3
template<typename F, typename T1, typename T2>
void Flip(F f, T1&& t1, T2&& t2){
	//done, water-proof, forwarding keeps the argument type information
    f(std::forward<T2> (t2), std::forward<T1> (t1));	
}

int main (){	
    int x = 8, y=8;
    //testing part 1
    std::cout << "testing part 1" << std::endl;
    fa(42, x);
    std::cout << x << std::endl;

    FlipA(fa, y, 42);
    std::cout << y << std::endl;
    
    //testing part 2
//    FlipB(fb, y, 42);	//error
    
   //testing part 3
   //reset 
   x =8; 
   y =8;
    
   std::cout << "testing part 3" << std::endl;    
   Flip(fb, y, 42);
   std::cout << y << std::endl;

    return 0;
}
