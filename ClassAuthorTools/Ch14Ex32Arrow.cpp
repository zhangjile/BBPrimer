#include <iostream>

struct A { void foo(){std::cout <<"yes!"<<std::endl;} };
struct B { A* operator->(){A* a; return a;} };
struct C { B operator->(){B b; return b;} };
struct D { C operator->(){C c; return c;} };
int main() {
   D d;
   d->foo();
}
