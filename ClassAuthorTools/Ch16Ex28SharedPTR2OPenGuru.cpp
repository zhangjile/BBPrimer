/*
 * Simple implementation of shared_ptr.
 * Below code is non thread safe.
 *
 * (c) 2015 Raghavendra Nayak, All Rights Reserved.
 * http://www.openguru.com/
 */
 
#include <iostream>
namespace my {
template <class T>
class shared_ptr {
        T* ptr;
		int* ref_count;

		void initialize_ref_count() {
			if (ref_count != nullptr)
				return;
			try {
                ref_count = new int;
                *ref_count = 1;
            }
			catch (std::bad_alloc& e) {
                std::cerr << "Memory allocation error: " << e.what();
            }
        }
        
public:
// Constructors
		shared_ptr()
            : ptr(nullptr), ref_count(nullptr) {}
		shared_ptr(nullptr_t ptr)
            : ptr(ptr), ref_count(nullptr) {
        }
		shared_ptr(T* ptr)
            : ptr(ptr), ref_count(nullptr) {
				initialize_ref_count();
        }

		~shared_ptr() {		// Destructor
            --(*ref_count);
			if (*ref_count == 0) {
				delete ref_count;
                ref_count = nullptr;
				delete ptr;
                ptr = nullptr;
            }
        }

		shared_ptr(const shared_ptr& copy) {	// Copy constructor
            ptr = copy.ptr;
            ref_count = copy.ref_count;
			if (ref_count != nullptr) {
                ++(*ref_count);
            }
        }

        shared_ptr& operator=(const shared_ptr& copy) {	// Assignment operator
            ptr = copy.ptr;
            ref_count = copy.ref_count;
			if (ref_count != nullptr) {
                ++(*ref_count);
            }
			return *this;
        }

        T& operator*() const {	// Returns stored object reference
			return *ptr;
        }

        T* operator->() const {	// Returns stored object pointer
			return ptr;
        }
    };
}


class Base
{
int data;
public:
Base() : data(0) { std::cout << "  Base::Base()\n"; }
virtual ~Base() { std::cout << "  Base::~Base()\n"; }
void set_data(int data) {
this->data = data;
    }
int get_data() const {
return this->data;
    }
};

class Derived : public Base
{
public:
Derived() { std::cout << "  Derived::Derived()\n"; }
~Derived() { std::cout << "  Derived::~Derived()\n"; }
};

my::shared_ptr<Base> func()
{
    my::shared_ptr<Base> ptr = new Derived();
return ptr;
}

int main(int argc, char **argv){
    my::shared_ptr<Base> ptr1;	// Default constructor
    {
        my::shared_ptr<Base> ptr2 = func();	// Parameterized constructor
        ptr2->set_data(100);	// operator function call
        my::shared_ptr<Base> ptr3 = ptr2;	// copy constructor call
        ptr1 = ptr3;	// assignment operator call
    }
    std::cout << "  data set to: " << (*ptr1).get_data() << std::endl;
	return 0;
}
