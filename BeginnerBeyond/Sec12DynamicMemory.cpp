// Section 12
// Dynamic Memory
#include <iostream>

using namespace std;

int main() {
    
    int *int_ptr {nullptr};
    int_ptr = new int;               // allocate the int on the heap
    cout << int_ptr << endl;    // use it
    delete int_ptr;                    // release it
    
    //完完全全明白了。just assign an address on heap to int_ptr, ie, make it point somewhere on heap. now we can use the address to on the heap to store data and operate on those data.
    //就是把一個heap上的存儲地址存入到int_ptr,它就指向一個新地址了。
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

//這個示例在Mobile C上也玩不了，當初真是礙事。27/06/2019
//Now I can run it on a Desktop IDE. 15/05/2020
/*
0x281946800
How many temps? 5
LLVM ERROR: Code generator does not support intrinsic function 'llvm.umul.with.overflow.i64'!
libc++abi.dylib: terminating with uncaught exception of type std::runtime_error: exit(code = 1)
Program aborted.

*/
