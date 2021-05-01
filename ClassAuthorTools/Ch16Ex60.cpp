// Exercise 16.60:
// Explain how make_shared (§ 12.1.1, p. 451) works.
//
//  make_shared shoudl be a variadic template function that forwards all arguments to
//  underlying constructors that allocate and initializes an object in dynamic memory and
//  , at last, build a shared_ptr by wrapping the raw pointer.
//
// Exercise 16.61:
// Define your own version of make_shared.

#include <iostream>
#include <memory>
#include <string>

//i figured cout the trailing return type, which is not required actually. LoL
template <typename T, typename ... Args>
auto i_make_shared(Args&&... args) -> std::shared_ptr<T>{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}


struct Foo
{
    explicit Foo(int b) : bar(b){ }
    int bar;
};

int main()
{
    auto num = i_make_shared<int>(42);
    std::cout << *num << std::endl;

    auto str = i_make_shared<std::string>(10, 'c');
    std::cout << *str << std::endl;

    auto foo = i_make_shared<Foo>(99);
    std::cout << foo->bar << std::endl;
    
    return 0;
}
