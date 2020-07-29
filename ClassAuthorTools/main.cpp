#include "strblobweak.h"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("README.md");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
  
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; ++pbeg)
        std::cout << *pbeg << std::endl;
}

  // client code, scenario of application
    //this for loop is the purpose of class StrBlobPtr.
    //when 3 methods are joined together to make a statement, everything makes sense
    //!= operator, increment method and dereference method
