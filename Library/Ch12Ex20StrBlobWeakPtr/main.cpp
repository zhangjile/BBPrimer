#include "strblobweak.h"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("Ch12Ex20StrBlobWeakPtr.project");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    //begin and end in client code, scenario of application
    //this for loop is the soul and purpose of class StrBlobPtr.
    //when 3 methods are joined together to make a statement, everything makes sense
    //!= operator, increment method and dereference method
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incre())
        std::cout << pbeg.deref() << std::endl;
}