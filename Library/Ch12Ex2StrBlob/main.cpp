//Section 12 Dynamic Memory and Smart Pointers
//Ex 12.2 P458, write your version of StrBlob class including const version of front and back

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::string; using std::vector; using std::shared_ptr; using std::initializer_list; using std::make_shared; using std::out_of_range;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob (): data {make_shared<vector<string>> ()} {}
    StrBlob (initializer_list<string> il): data {make_shared<vector<string>> (il)} {}
    
    size_type size() {return data->size();}
    bool empty() {return data->empty();}
    string& front() ;
    string& back() ;
    string& front() const {return data->front();}
    string& back() const {return data-> back();}
    void push_back(const string &t) {return data->push_back(t);}
    void pop_back();
    
private:
    shared_ptr<vector<string>> data;
    void check(size_t i, const string &s  = "an empty vector") const;
};

string& StrBlob::front() {
    check(0);
    return data->front();
}

string& StrBlob::back() {
    check(0);
    return data-> back();
}
    
void StrBlob::pop_back (){
    check(0);
    return data->pop_back();
}

void StrBlob::check(size_t i, const string &msg) const {
    if(i >= data->size())
        throw out_of_range(msg);
}

int main()
{
    StrBlob sb1;  
    
    //a block of code
    {
    	StrBlob sb2 {"a","an","the"};
    	sb1 = sb2;
    	sb2.push_back("oh");
    }
    
    std::cout<<sb1.size() <<std::endl;
    return 0;
}