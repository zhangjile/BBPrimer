//Section 13.6 moving objects
//Ex13.58, p 548, write versions of class Foo with print statements in sorted functions to test your answers to the previous two exercises.

#include <iostream>
#include <vector>
#include <algorithm>

class Foo {
public:
    Foo () = default;
    Foo (std::vector<int> v) : data{v} {}
    Foo sorted () const &;  //'&' is required and should be placed at the back
    Foo sorted () &&;   //in the same "signature group" as the method above
    Foo& Sorted (); //intend to modify the data member
    void Display ();

private:
    std::vector<int> data;
};

Foo Foo::sorted () && {
    std::cout<< "&&" <<std::endl;
    std::sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted () const & {
	return Foo(*this).sorted();	//move semantics works as expected
	
	/*
	//normal good implementation
    std::cout<< "&" <<std::endl;
    Foo ret(*this);
    std::sort(ret.data.begin(), ret.data.end());
    return ret;
    */
}

Foo& Foo::Sorted(){
	std::sort(data.begin(), data.end());
	return *this;
}

void Foo::Display(){
    for(const int& i:data){
        std::cout << i << " ";
        
    }
    std::cout<< std::endl;
}

int main (){
    //std::vector<int> v {20,7,21};
    Foo f({20,7,21});
    
    f.Sorted(); //data has been re-ordered
    f.Display();	//works as expected

//    f.sorted().Display();
    
    Foo({19,89,64}).sorted ().Display();
    
    return 0;
}
