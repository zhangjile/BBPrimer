#include "strblobconst.h"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("compile_flags.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incre())
        std::cout << pbeg.deref() << std::endl;
}