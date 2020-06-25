//Section 12 Dynamic Memory and Smart Pointers
//Ex 12.2 write your version of StrBlob class including const version of front and back
//Ex12.19 define your own version of StrBlobPtr class
#include "StrBlob.cpp"

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
