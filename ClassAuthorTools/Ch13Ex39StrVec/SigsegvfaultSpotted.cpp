//wildly powerful. IDEs can do nothing with sigsegv error
//to find the line that causes a segmentation fault, using gdb 
#include <iostream>

int main (){
    int x = 7;
    int *p = 0;
    *p = 10;
    //p = &x;
    std::cout << x << std::endl;
    std::cout <<"The pointer points to value: "<< *p << std::endl;

    return 0;
}
/*
j@j-desktop:~/badCode$ g++ -g 227.cpp 
j@j-desktop:~/badCode$ gdb ./a.out 

(gdb) run 
Starting program: /home/j/badCode/a.out 

Program received signal SIGSEGV, Segmentation fault.
0x0000000000400824 in main () at 227.cpp:13
13 cout << "The pointer points to the value " << *p; 

Thoughts: Well, the segFault happens on this line. I'm using a pointer here, p. I'd better check the value of that pointer.

(gdb) print p 
$1 = (int *) 0x0 
Thoughts:Aha! The pointer has a value of zero - it's a null pointer. Trying to dereference it is causing a segFault. Let's see the nearby code.

(gdb) list 
int x = 7;
int *p = 0;

Thoughts: Ah, I never set the pointer to point at anything. That's easily fixed.

(gdb) quit A debugging session is active.
*/