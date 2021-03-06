// Section 12
// Dynamic Memory
#include <iostream>

using namespace std;

int main() {
    
    int *int_ptr {nullptr};
    int_ptr = new int;               // allocate the int on the heap
    cout << int_ptr << endl;    // use it
    delete int_ptr;                    // release it
    
    //just assign an address on heap to int_ptr, ie, make it point somewhere on heap. now we can use the address on the heap to store data and operate on those data.
    //21:08 27/06/2019
    
    
    size_t size{0};
    double *temp_ptr {nullptr};
    
    cout << "How many temps? ";
    cin >> size;
    
    temp_ptr = new double[size];    // allocate the storage on the heap
    cout << temp_ptr << endl;       // use it
    delete [] temp_ptr;                     // release it
    
    cout << endl;
    return 0;
}

//the code could not run normally on Mobile C. 27/06/2019
//Now I can run it on a Desktop IDE. 15/05/2020
/*
 on Mobile C
 
0x281946800
How many temps? 5
LLVM ERROR: Code generator does not support intrinsic function 'llvm.umul.with.overflow.i64'!
libc++abi.dylib: terminating with uncaught exception of type std::runtime_error: exit(code = 1)
Program aborted.

 on CodeLite on desktop running Ubuntu     //SUCCESS!
 0x16de7a0
How many temps? 10
0x16defe0

Hit any key to continue...

 on VS Code  //SUCCESS!
neutron@neutron-us:~/VS/BBChapter12DynamicMemory$ ls
DynamicMemory  DynamicMemory.cpp
neutron@neutron-us:~/VS/BBChapter12DynamicMemory$ ./DynamicMemory
0x55ca0bc8ae70
How many temps? 10
0x55ca0bc8b6b0

neutron@neutron-us:~/VS/BBChapter12DynamicMemory$ 

*/
