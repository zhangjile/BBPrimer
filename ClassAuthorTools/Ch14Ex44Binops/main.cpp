//Section 14.8.3 callable objects and function template
//Ex14.44, p 579, write your own version of a simple desk calculator that can handle binary operations 
#include <iostream>
#include <functional>
#include <string>
#include <map>

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

map<string, function<int(int, int)>> binops = {
    {"+", Add},
    {"-", std::minus<int> ()},
    {"*", [](int a, int b){return a*b;}},
    {"/", Divide ()},
    {"%", mod}
};

int main () {
    int a = binops["+"](2020, 730);
    std::cout << a << std::endl;
    a = binops["-"](2020, 730);
    std::cout << a << std::endl;
    a = binops["*"](2020, 730);
    std::cout << a << std::endl;
    a = binops["/"](2020, 730);
    std::cout << a << std::endl;
    a = binops["%"](2020, 730);
    std::cout << a << std::endl;
    return 0;
}
