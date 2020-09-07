//Section 14.8.3 callable objects and function template
//Ex14.44, p 579, write your own version of a simple desk calculator that can handle binary operations 
#include <iostream>
#include <functional>
#include <string>
#include <map>

#include <chrono>	//calculate the time of execution
using namespace std::chrono;
typedef unsigned long long ull;

using std::string; using std::map; using std::function;

int Add (const int& a, const int& b){
    return a + b;
}

class Divide {
public:     //wahoo, it's this access specifier missing that caused all the failure!
    int operator()(const int& a, const int& b){
        return a/b;
    }
};

auto mod = [](const int& a, const int& b){
    return a % b;
};

//test this map declaration on CodeLite
//map<string, int(*)(int, int)> binops = 
map<string, function<int(int, int)>> binops = {
    {"+", Add},
    {"-", std::minus<int> ()},
    {"*", [](int a, int b){return a*b;}},
    {"/", Divide ()},
    {"%", mod}
};

//review the library defined function objects
map<string, function<int(int,int)>> FunctionOBJ = {
	{"+", std::plus<int>()},
	{"-", std::minus<int>()},
	{"*", std::multiplies<int> ()},
	{"/", std::divides<int>()},
	{"%", std::modulus<int>()}
};

int main () {
	ull start = 0;
    auto StartTime = high_resolution_clock::now();
	
    int a = binops["+"](2020, 730);
    std::cout << a << std::endl;
    a = binops["-"](2020, 730);
    std::cout << a << std::endl;
    a = binops["*"](2020, 730);
    std::cout << a << std::endl;
    a = FunctionOBJ["/"](2020, 730);
    std::cout << a << std::endl;
    a = FunctionOBJ["%"](2020, 730);
    std::cout << a << std::endl;
    
    //examples on p575
    std::plus<int> IntAdd;	//creating a function object that can add 2 ints
    std::negate<int> IntNeg;
    int sum = IntAdd(100,200);
    std::cout<< sum << std::endl;
    std::cout<< IntAdd(100, IntNeg(100)) << std::endl;
    std::cout<< IntNeg(IntAdd(100,200)) << std::endl;
    
    auto StopTime = high_resolution_clock::now();
    auto Duration = duration_cast<microseconds> (StopTime - StartTime);
    std::cout << Duration.count()/1000 <<std::endl;	//5 seconds

    return 0;
}

