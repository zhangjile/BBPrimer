#ifndef _MYBLOB_H_
#define _MYBLOB_H_

#include <initializer_list>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>
#include "MySharedPTR.h"

template <typename> class BlobPtr;
template <typename> class Blob; // needed for parameters in operators below
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator!=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator<=(const Blob<T>&, const Blob<T>&);
template <typename T> bool operator>=(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator!=<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator< <T>(const Blob<T>&, const Blob<T>&);
    friend bool operator><T>(const Blob<T>&, const Blob<T>&);
    friend bool operator<=<T>(const Blob<T>&, const Blob<T>&);
    friend bool operator>=<T>(const Blob<T>&, const Blob<T>&);
    public:
        typedef T value_type;
        typedef typename std::vector<T>::size_type size_type;
        // constructors
        Blob();
        Blob(std::initializer_list<T> il);
        template <typename It> Blob(It b, It e);
        // members
        size_type size() const { return data->size(); };
        bool empty() const { return data->empty(); }
        // add and remove elements
        void push_back(const T &t) { data->push_back(t); }
        void push_back(T &&t) { data->push_back(std::move(t)); }
        void pop_back();
        // element access
        T& front();
        T& back();
        const T& front() const;
        const T& back() const;
        T& operator[](size_type);
        const T& operator[](size_type) const;
        BlobPtr<T> begin() const;   // return BlobPtr to the first element
        BlobPtr<T> end() const ;    // and one past the last element
    private:
        my_shared_ptr<std::vector<T>> data;
        void check(size_type i, const std::string &msg) const;
};

template <typename T> Blob<T>::Blob(): data(make_shared<std::vector<T>>()) { }
template <typename T> Blob<T>::Blob(std::initializer_list<T> il): data(make_shared<std::vector<T>>(il)) { }

template <typename T> 
template <typename It> Blob<T>::Blob(It b, It e): data(make_shared<std::vector<T>>(b, e)) {}

template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T> T& Blob<T>::front() {
    // if the vector is empty, check will throw
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> const T& Blob<T>::front() const {
    // if the vector is empty, check will throw
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T> T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> T& Blob<T>::operator[](size_type i) {
    return data->at(i);
}

template <typename T> const T& Blob<T>::operator[](size_type i) const {
    return data->at(i);
}

template <typename T> void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T> bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *lhs.data == *rhs.data;
}

template <typename T> bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T> bool operator<(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *lhs.data < *rhs.data;
}

template <typename T> bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {
    return rhs < lhs;
}

template <typename T> bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs > rhs);
}

template <typename T> bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs < rhs);
}

template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator<=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator>=(const BlobPtr<T>&, const BlobPtr<T>&);

// BlobPtr throws an exception on attempts to access a nonexistent element
template <typename T> class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator< <T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator><T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator<=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator>=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    public:
        BlobPtr(): curr(0) { }
        BlobPtr(const Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) { }
        T& operator*() const { 
            auto p = check(curr, "derefernce past end");
            return (*p)[curr]; // (*p) is the vector to which this object points
        }
        BlobPtr& operator++();  // prefix operators
        BlobPtr& operator--();
        T& deref() const;
        BlobPtr<T>& incr(); // prefix version
    private:
        // check returns a shared_ptr to the vector if the check succeeds
        std::shared_ptr<std::vector<T>>
            check(std::size_t, const std::string&) const;
        // store a weak_ptr, which means the underlying vector might be destroyed
        std::weak_ptr<std::vector<T>> wptr;
        std::size_t curr;   // current position within the vector
};

template <typename T> std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();     // is the vector still around?
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;         // otherwise, return a shared_ptr to the vector
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++() {
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment exceeds bounds");
    ++curr;
    return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--() {
    // if curr is zero, decrementing it will yield an invalid subscript
    --curr; // move the current state back one element
    check(curr, "decrement exceeds bounds");
    return *this;
}

template <typename T> T& BlobPtr<T>::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  // (*p) is the vector to which this object points
}

// prefix: return a reference to the incremented object
template <typename T> BlobPtr<T>& BlobPtr<T>::incr() {
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of BlobPtr");
    ++curr;     // advance the current state
    return *this;
}

template <typename T> bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.deref() == rhs.deref();
}

template <typename T> bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T> bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.deref() < rhs.deref();
}

template <typename T> bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return rhs < lhs;
}

template <typename T> bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs > rhs);
}

template <typename T> bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs < rhs);
}


template <typename T> BlobPtr<T> Blob<T>::begin() const {
    return BlobPtr<T>(*this);
}

template <typename T> BlobPtr<T> Blob<T>::end() const {
    return BlobPtr<T>(*this, data->size());
}
#endif
