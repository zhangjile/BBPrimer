//first step exploring C compilation
// precompile $gcc -E main.cpp >main.p //I see redirection operator here
#include <iostream>

#define PI 3.14159

int main() 
{
    std::cout << "Value of PI: " << PI <<std::endl;
    return 0;
}