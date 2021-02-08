// Chapter 12.1.5, Exercise 12.17:
// Which of the following unique_ptr declarations are illegal or likely to
// result in subsequent program error? Explain what the problem is with each
// one.

#include <iostream>
#include <vector>
#include <memory>

int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;

    //error: invalid conversion from 'int' to 'std::unique_ptr<int>::pointer'
    IntP p0(ix);

    /*
     The code can compile, but will cause error at run time.
     * The reason is that when the unique_ptr p1 is out of scope, delete will be called to free an object on STACK, the object is not allocate on heap using new.
     *  @badcode
     */
    IntP p1(pi);

    /**
     * The code can compile, but causes a dangling pointer at run time.
     * The reason is that the unique_ptr will free the object the raw pointer p2 is pointing to, which is a mature named addressable variable
     * @badcode
     */
    IntP p2(pi2); 

    /**
     * When the unique_ptr goes out of scope, it will call delete to free an obeject on STACK
     * @badcode
     */
    IntP p3(&ix);

    //legal 
    IntP p4(new int(2048));

    /**
     * error: double free or corruption at run time
     * two unique_ptr are pointing to the same object. Thus when they both are out of scope, os will throw double free or corruption.
     * @badcode
     */
    IntP p2(new int(555));
    IntP p5(p2.get());

    return 0;
}
