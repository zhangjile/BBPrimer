//Section 16.1.5 controlling initiation, efficiency and flexibility
//Ex16.28, p678, write your own shared_ptr and unique_ptr
//Frankly, I've never imagined that implementing smart pointers comes so sooon.
//it's the core of modern C++, give it 5 days to build them!

#include <iostream>

template<typename T>
class Delete{
public:
    Delete(std::ostream& s) : os(s) {}
    void operator ()(T* p) {
        os << "custom deleter";
        delete p;
    }
private:
    std::ostream& os;
};

template<typename T>
class Shared_PTR {
public:
    Shared_PTR (const T& arg) :t(arg){}
private:
    T t;
    Delete<T> d (T* p){  d ? d(p) : delete p;}
};

template<typename T, typename Del>
class Unique_PTR {
public:
    Unique_PTR(const T& arg, Del cust) : t(arg), d(cust) {}
private:
    T t;
    Del d;
};

int main () {

    return 0;
}
