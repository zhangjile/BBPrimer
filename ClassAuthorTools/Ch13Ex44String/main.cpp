#include "Ch13Ex44String.h"
#include "Ch13Ex44String.cpp"

int main (){
	char m[] = "Books";
    String s(m);
    String s1(s);
    std::cout << s1.size() << std::endl;
    
    String s3("abc");
    std::cout << *(s3.begin()+1) << std::endl;
    
    return 0;
}
