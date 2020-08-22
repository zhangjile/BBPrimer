//Section 12 Dynamic Memory and Smart Pointers
//Ex 12.2 P458, write your version of StrBlob class including const version of front and back

#include <iostream>
#include <vector>
#include <memory>

using std::string; using std::vector; using std::shared_ptr; using std::initializer_list; using std::make_shared; using std::out_of_range;

template<typename T>
class Blob {
public:
    Blob (): data {make_shared<vector<T>> ()} {}
    Blob (initializer_list<T> il): data {make_shared<vector<T>> (il)} {}
    
    size_t size() {return data->size();}
    bool empty() {return data->empty();}
    
    T& front() {check(0); return data->front();}
    T& back() {check(0); return data->back();}
    T& front() const {check(0); return data->front();}
    T& back() const {check(0); return data-> back();}
    
    void push_back(const T &t) {return data->push_back(t);}
    void pop_back() {check(0); return data->pop_back();}
    
private:
    shared_ptr<vector<T>> data;
    void check(size_t i, const string &s  = "an empty vector") const;
};

template<typename T>     
void Blob<T>::check(size_t i, const string &msg) const {
    if(i >= data->size())
        throw out_of_range(msg);
}

int main()
{
    Blob<double> sb1;  
    
    //a block of code
    {
    	Blob<double> sb2 {1989.64, 2020.8};
    	sb1 = sb2;
    	sb2.push_back(2020.11);
    }
/*
    Blob<string> sb1;  
    
    //a block of code
    {
    	Blob<string> sb2 {"a","an","the"};
    	sb1 = sb2;
    	sb2.push_back("oh");
    }
    */
    
    std::cout<<sb1.size() <<std::endl;
    std::cout<<sb1.front() <<std::endl;
    std::cout<<sb1.back() <<std::endl;
    
    return 0;
}
