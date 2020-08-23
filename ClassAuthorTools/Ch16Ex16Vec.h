//Section 16.1.2 Class Templates
//Ex16.16, p668, Rewrite StrVec class as a template named Vec 
#ifndef _VEC_H_
#define _VEC_H_

#include <iostream>
#include <memory>

using std::allocator;

template<typename T>
class Vec {
public:
    Vec():elements{nullptr}, first_free{nullptr}, cap{nullptr} {}
    ~Vec(){Free ();}
    Vec (const Vec& source);
    Vec& operator= (const Vec& source);
    
    //top 5 methods
    void push_back(const T& source);
    
    T* begin() const {return elements;}
    T* end() const {return first_free;}
    
    size_t size () const {return first_free - elements;}
    size_t capacity() const {return cap - elements; }  //getter

    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const T& s);
    Vec (const std::initializer_list<T> &il);
    
    //move operation
    Vec (Vec&& s);
    Vec& operator= (Vec&& s);
    
private:
    static std::allocator<T> allo;     
    
    void CheckNReallocate();
    std::pair<T*, T*> AllocateNCopy(const T* b, const T* e);
    
    //move the current data to a new bigger location
    void Reallocate();
    
    //helper to destructor
    void Free();
        
    T* elements;
    T* first_free;
    T* cap;
};

//if definition statement is missing, undefined reference error
template<typename T>
allocator<T> Vec<T>::allo;

template<typename T>
void Vec<T>::CheckNReallocate (){
        if(size() == capacity ()) Reallocate ();
    }
    
template<typename T>
std::pair<T*, T*> Vec<T>::AllocateNCopy(const T* b, const T* e){
        auto data = allo.allocate(e - b);
        return {data, std::uninitialized_copy(b,e,data)};
    }

template<typename T>
void Vec<T>::Free (){
        if(elements){
            for(auto p = first_free; p != elements;)
                allo.destroy(--p);
            allo.deallocate(elements, cap-elements);
        }
    }

template<typename T>
void Vec<T>::push_back(const T& source){
        CheckNReallocate ();
        allo.construct(first_free++, source);
    }

template<typename T>    
void Vec<T>::Reallocate (){
        size_t NewCap = (size() == 0)? 1 : size()*2;
        auto p = allo.allocate(NewCap);
        auto dest = p;
        auto elem = elements;
        for(size_t i = 0; i < size(); ++i){     //sigsegv error fixed, finally!
	        allo.construct(dest++, std::move(*elem++));
        }        
        Free ();
        elements = p;
        first_free = dest;
        cap = p + NewCap;
        
    }

template<typename T>
Vec<T>::Vec (const Vec& source){
        auto data = AllocateNCopy(source.begin(), source.end());
        elements = data.first;
        first_free = cap = data.second;
    }
    
template<typename T>
Vec<T>& Vec<T>::operator= (const Vec& source){	//watch!
        Free ();
        auto data = AllocateNCopy(source.begin(), source.end());
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }
    
template<typename T>
void Vec<T>::reserve(size_t n){
    if(n<size()) return;
    auto p = allo.allocate(n);
        auto dest = p;
        auto elem = elements;
        for(size_t i = 0; i < size(); ++i){     
	        allo.construct(dest++, std::move(*elem++));
        }        
        Free ();
        elements = p;
        first_free = dest;
        cap = p + n;
}
    
template<typename T>
void Vec<T>::resize(size_t n){
    resize(n, T ());
}
/*
void Vec::resize(size_t n, const T& s){
	if(n > size()){
		if(n>capacity()) reserve (n*2);
		for(size_t i = size(); i < n; ++i){
			allo.construct(first_free++, s);
		}
	}
	else if(n < size()){
		while(first_free != elements+ n){
			allo.destroy(--first_free);
		}
	}
}
    */
    //loop using size and n

template<typename T>
void Vec<T>::resize(size_t n, const T& s){
    if( n< size()){
        while( size() - n > 0)
            allo.destroy(--first_free);
    } else if (n > size()) {
    	if(n > capacity()) reserve(n*2);
        while ( n - size() > 0)
        	allo.construct(first_free++, s);
    }
}
    
template<typename T>
Vec<T>::Vec (const std::initializer_list<T> &il){
    auto data = allo.allocate(il.size());
    elements = data;
    first_free = cap = std::uninitialized_copy(il.begin(), il.end(), data);
}

//defining move operations
template<typename T>
Vec<T>::Vec (Vec&& s) :elements{s.elements}, first_free{s.first_free}, cap{s.cap} {
	std::cout <<"Move constructor" << std::endl;
	s.elements = s.first_free = s.cap = nullptr;
}
    
template<typename T>
Vec<T>& Vec<T>::operator= (Vec&& s){
	std::cout <<"Move-assignment" << std::endl;
	elements = s.elements;
	first_free = s.first_free; 
	cap = s.cap;
	s.elements = s.first_free = s.cap = nullptr;
	return *this;
}


#endif
