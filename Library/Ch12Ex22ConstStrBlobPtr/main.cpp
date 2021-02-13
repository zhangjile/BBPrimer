//Chapter 12.1.6 weak_ptr, Exercise 12.22, p476
//What changes would need to be made to StrBlobPtr to create a class that can be used with a 'const StrBlob'? Define a class named ConstStrBlobPtr to accomodate this requirement.

#include "ConstStrBlobPtr.h"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("Notes.md");
    StrBlob b;
    for (std::string str; std::getline(ifs, str); )
        b.push_back(str);
    const StrBlob blob(b);
    for (ConstStrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incre())
        std::cout << pbeg.deref() << std::endl;
    return 0;
}
