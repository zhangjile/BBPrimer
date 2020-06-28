#include "str.h"
#include <fstream>
using std::ifstream; using std::getline;

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
    std::cout<<sb1.front() <<std::endl;
    
    ifstream is("ex12_20.cpp");
    StrBlob blob;
    for(string i; getline(is, i); ) {
        blob.push_back(i);
    }
    
    StrBlobPtr it (sb1.begin() );
    std::cout <<it.deref() <<std::endl;

    return 0;
}
