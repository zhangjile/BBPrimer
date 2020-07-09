//Section 13.2 Copy Control and Resource Management
//Ex13.25, p 513, 
//Assume we want to define a version of StrBlob that acts like value.
//Also assume that we want to continue to use a shared_ptr so that our StrBlobPtr 
//class can still use a weak_ptr to the vector. Your revised class will need a copy 
// constructor and copy-assignment operator but will not need a destructor.
// explain what the copy constructor and copy-assignment operator must do.

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
    //Ex13.25
    StrBlob (const StrBlob& source);	
    StrBlob& operator= (const StrBlob& source);
    
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

StrBlob::StrBlob (const StrBlob& source){
	vector<string> temp;
	for(const auto &e : *source.data){
		temp.push_back(e);
	}
	data = make_shared<vector<string>> (temp);
}

StrBlob& StrBlob::operator= (const StrBlob& source){
	vector<string> temp;
	for(const auto &e : *source.data){
		temp.push_back(e);
	}
	
	/*	
	//typical mistake, temp.size is zero.
	vector<string> temp;
	size_t i = 0;
	for(const auto &e : *source.data){
		temp[i] = e;
		++i;
	}
	*/
	data = make_shared<vector<string>> (temp);
	return *this;
}

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
    	sb2.push_back("oh");	//sb1 and sb2 are irrelavant now!
    }
    StrBlob sb3( sb1);
    std::cout<<sb1.size() <<std::endl;	//3
    return 0;
}
