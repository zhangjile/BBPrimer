#ifndef _MYSHAREDPTR_H_ 
#define _MYSHAREDPTR_H_

#include <cstddef>
#include <algorithm>

template <typename> class my_shared_ptr;

template <typename T> void swap(my_shared_ptr<T>&, my_shared_ptr<T>&);
template <typename T> my_shared_ptr<T> make_shared(T);

template <typename T> class my_shared_ptr {
    friend void swap<T>(my_shared_ptr<T>&, my_shared_ptr<T>&);
    friend my_shared_ptr make_shared<T>(T);
    public:
        my_shared_ptr(): p(nullptr), del(nullptr), count(nullptr) { }
        //my_shared_ptr(T *pt): p(pt), count(new std::size_t(1)), del(nullptr) { }
        //my_shared_ptr(T *pt, void (*d)(T*)): p(pt), count(new std::size_t(1)), del(d) { }
        explicit my_shared_ptr(T *pt): p(pt), count(new std::size_t(1)), del(nullptr) { } // shared_ptr<T> p(q)
        explicit my_shared_ptr(T *pt, void (*d)(T*)): p(pt), count(new std::size_t(1)), del(d) { } //shared_ptr<T> p(q, d)
        my_shared_ptr(const my_shared_ptr&);        // copy constructor
        my_shared_ptr(const my_shared_ptr&, void (*d)(T*)); // copy constructor with deleter
        my_shared_ptr& operator=(my_shared_ptr&);   // copy assignment operator
        ~my_shared_ptr();               // destructor

        T& operator*() const;
        T* operator->() const;

        T* get();
        my_shared_ptr& swap(my_shared_ptr&); 
        bool unique() const;
        std::size_t use_count() const;
        my_shared_ptr& reset();
        my_shared_ptr& reset(T*);
        my_shared_ptr& reset(T*, void (*d)(T*));
    private:
        T* p;
        void (*del)(T*);
        std::size_t *count;
};

// copy constructor
template <typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr &rhs): p(rhs.p), del(nullptr), count(rhs.count) { 
    ++*count;
}

// copy constructor with deleter
template <typename T>
my_shared_ptr<T>::my_shared_ptr(const my_shared_ptr &rhs, void (*d)(T*)): p(rhs.p), del(d), count(rhs.count) {
    ++*count;
}

// copy assignment operator
template <typename T>
my_shared_ptr<T>& my_shared_ptr<T>::operator=(my_shared_ptr &rhs) {
    ++*rhs.count;
    --*count;   
    if(--*count == 0) {
        del ? del(p) : delete p;
        del ? del(count) : delete count;
    }
    p = rhs.p;
    del = rhs.del;
    return *this;
}

// destructor
template <typename T>
my_shared_ptr<T>::~my_shared_ptr() {
    if(--*count == 0) {
        del ? del(p) : delete p;
        del ? del(count) : delete count;
    }
    del = nullptr;
}

// dereference operator
template <typename T>
T& my_shared_ptr<T>::operator*() const {
    return *p;
}

// member access operator
template <typename T>
T* my_shared_ptr<T>::operator->() const {
    return & this->operator*();
}

// get
template <typename T>
T* my_shared_ptr<T>::get() {
    return p;
}

// member swap
template <typename T>
my_shared_ptr<T>& my_shared_ptr<T>::swap(my_shared_ptr &rhs) {
    using std::swap;
    swap(p, rhs.p);
    swap(del, rhs.del);
    return *this;
}

// unique
template <typename T>
bool my_shared_ptr<T>::unique() const {
    if (*count == 1)
        return true;
    else
        return false;
}

// use_count
template <typename T>
std::size_t my_shared_ptr<T>::use_count() const {
    return count;
}

template <typename T> my_shared_ptr<T>& my_shared_ptr<T>::reset() {
    if (--*count == 0) {
        delete p;
        delete count;
    }
    del = nullptr;
    return *this;
}

template <typename T> my_shared_ptr<T>& my_shared_ptr<T>::reset(T *t) {
    if (--*count == 0) {
        delete p;
        delete count;
    }
    p = t.p;
    del = nullptr;
    return *this;
}

template <typename T> my_shared_ptr<T>& my_shared_ptr<T>::reset(T *t, void (*d)(T*)) {
    if (--*count == 0) {
        delete p;
        delete count;
    }
    p = t.p;
    del = d;
    return *this;
}

// make_shared
template <typename T>
my_shared_ptr<T> make_shared(T t) {
    return my_shared_ptr<T>(new T(t));
}

// non-member swap
template <typename T> inline void swap(my_shared_ptr<T> &lhs, my_shared_ptr<T> &rhs) {
    using std::swap;
    swap(lhs.p, rhs.p);
    swap(lhs.del, rhs.del);
}

#endif
