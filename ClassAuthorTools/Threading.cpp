//first taste of thread, courtesy of CPPNUTS
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std; using namespace std::chrono;
typedef unsigned long long  ull;

ull OddSum = 0;
ull EvenSum = 0;


void GetOddSum(ull start, ull Num){
    for(ull i = start; i < Num; ++i){
        if((i&1) == 1)
            OddSum += i;
    }
}

void GetEvenSum(ull start, ull Num){
    for(ull i = start; i < Num; ++i){
        if((i&1) == 0)
            EvenSum += i;
    }
}

int main (){
    ull start = 0;
    ull Num = 1000000;
    auto StartTime = high_resolution_clock::now();
    
    //creating 2 threads
    std::thread t1 (GetOddSum, start, Num);
    std::thread t2 (GetEvenSum, start, Num);
    t1.join();
    t2.join();
    /*
    //LOL
    SIGBUS on thread : 6162280448
    SIGBUS on thread : 6170537984
    libc++abi.dylib: terminating with uncaught exception of type 
    std::runtime_error: exit(code = 0)
    Program aborted.
    */
    
    //default main() thread/process
    //GetOddSum(start, Num);
    //GetEvenSum(start, Num);
    auto StopTime = high_resolution_clock::now();
    auto Duration = duration_cast<microseconds> (StopTime - StartTime);
    std::cout << OddSum <<std::endl;
    std::cout << EvenSum <<std::endl;
    std::cout << Duration.count()/10000 <<std::endl;

    return 0;
}
