//GeekforGeek.com
//this is a successful implementation because the use_count works as expected.
//well, make HasPTR pointerlike a template class, it is shared pointer.

#include <iostream> 
using namespace std; 

template <typename T> 
class Shared_PTR { 
public: 
	// Constructor 
	explicit Shared_PTR(T* ptr = nullptr) { 
		m_ptr = ptr; 
		m_counter = new size_t(); 
		if (ptr) { 
			(*m_counter)++; 
		} 
	} 

	// Copy constructor 
	Shared_PTR(Shared_PTR<T>& sp) { 
		m_ptr = sp.m_ptr; 
		m_counter = sp.m_counter; 
		(*m_counter)++; 
	} 

	//assignment operator missing, problem is sure to come out if '=' is used.	
	
	size_t use_count() {return *m_counter; } 
	T* get() {return m_ptr;} 
	T& operator*() {return *m_ptr; } 
	T* operator->() {return m_ptr; } 
	
	// Destructor 
	~Shared_PTR() { 
		(*m_counter)--; 
		if (*m_counter == 0) { 
			delete m_counter; 
			delete m_ptr; 
		} 
	} 

	friend ostream& operator<<(ostream& os, Shared_PTR<T>& sp) 
	{ 
		os << "Address pointed : "
		<< sp.get() << "; " << *(sp.m_counter) << endl; 
		return os;
	} 

private: 
	size_t* m_counter; 
	T* m_ptr; 
}; 

int main() 
{ 
	// ptr1 pointing to an integer. 
	Shared_PTR<int> ptr1(new int(151)); 
	cout << "--- Shared pointers ptr1 ---\n"; 
	*ptr1 = 100; 
	cout << " ptr1's value now: " << *ptr1 << endl; 
	cout << ptr1; 

	{ 
		Shared_PTR<int> ptr2 = ptr1; 
		cout << "--- Shared pointers ptr1, ptr2 ---\n"; 
		cout << ptr1; 
		cout << ptr2; 

		{ //innermost scope
			Shared_PTR<int> ptr3(ptr2);
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
