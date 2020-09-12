//good reference, nice code, fixed a bug

/*
 * Simple implementation of shared_ptr.
 * Below code is non thread safe.
 *
 * (c) 2015 Raghavendra Nayak, All Rights Reserved.
 * http://www.openguru.com/
 */
 
#include <iostream>
#include <cstddef>
using std::cout; using std::endl;

namespace my {
template <class T>
class shared_ptr {
		friend std::ostream& operator<<(std::ostream& os, shared_ptr<T>& sp) 
		{ 
			os << "Address pointed : "
			<< sp.ptr << "; " << *(sp.ref_count) << endl; 
			return os;
		}
		 
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

		//SMELLS VERY BAD! decrement use_count of *this seems to be missing! Primer, p453,465
        //I was right!
        shared_ptr& operator=(const shared_ptr& copy) {	// Assignment operator
        	
        	--(*ref_count);
			if (*ref_count == 0) {
				delete ref_count;
                ref_count = nullptr;
				delete ptr;
                ptr = nullptr;
            }
        	//decrementing ref_count properly
            
            ptr = copy.ptr;
            ref_count = copy.ref_count;
			if (ref_count != nullptr) {
                ++(*ref_count);
            }
			return *this;
        }

        T operator*() const {return *ptr;}	//dereferencing
        T* operator->() const {return ptr;}	//arrow
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
	/*
    my::shared_ptr<Base> ptr1;	// Default constructor
    {
        my::shared_ptr<Base> ptr2 = func();	// Parameterized constructor
        ptr2->set_data(100);	// operator function call
        my::shared_ptr<Base> ptr3 = ptr2;	// copy constructor call
        ptr1 = ptr3;	// assignment operator call
    }
    std::cout << "  data set to: " << (*ptr1).get_data() << std::endl;
    */
    // ptr1 pointing to an integer. 
	my::shared_ptr<int> ptr1(new int(151)); 
	cout << "--- Shared pointers ptr1 ---\n"; 
	*ptr1 = 100; 
	cout << " ptr1's value now: " << *ptr1 << endl; 
	cout << ptr1; 

	{ 
		my::shared_ptr<int> ptr2 = ptr1; 
		cout << "--- Shared pointers ptr1, ptr2 ---\n"; 
		cout << ptr1; 
		cout << ptr2; 

		{ //innermost scope
			my::shared_ptr<int> ptr3(new int(200));
			ptr2 = ptr3;
			cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n"; 
			cout << ptr1; 
			cout << ptr2; 
			cout << ptr3; 
		} 

		// ptr3 is out of scope,destructed. 
		cout << "--- Shared pointers ptr1, ptr2 ---\n"; 
		cout << ptr1; 
		cout << ptr2; 
	} 

	// ptr2 is out of scope. 
	cout << "--- Shared pointers ptr1 ---\n"; 
	cout << ptr1; 
	
	return 0;
}
