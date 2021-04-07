//Section 12 Dynamic Memory and Smart Pointers
//Ex 12.2 P458, write your version of StrBlob class including const version of front and back
#include "BlobPtrTemplate.h"
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

using std::string; using std::vector; using std::shared_ptr; using std::initializer_list; using std::make_shared; using std::out_of_range;

int main()
{
    std::ifstream ifs("MyShortCuts");
    Blob<string> blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    //this for loop is the soul and purpose of class StrBlobPtr.
    for (BlobPtr<string> pbeg(blob.begin()), pend(blob.end()); pbeg != pend; ++pbeg)
        std::cout << *pbeg << std::endl;
}
