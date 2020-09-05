#include "MySharedPTR.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
    
int main(){
        Blob<int> ib{21, 53, 84, 91, 23};
        for (const auto &elem : ib)
            std::cout << elem << ' ';
        std::cout << '\n';
    
        Blob<std::string> sb{"21", "53", "84", "91", "23"};
        for (const auto &elem : sb)
            std::cout << elem << ' ';
        std::cout << '\n';
    
        std::cout << '\n';
        Blob<std::vector<std::string>> vb{ {"21", "5"}, {"53", "23", "42", "23"},
            {"84", "59"}, {"91", "68"}, {"23", "72", "10" } };
        for (const auto &vector : vb) {
            for (const auto &elem : vector)
                std::cout << elem << ' ';
            std::cout << '\n';
        }
    
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::list<const char*> w = {"now", "is", "the", "time"};
    
        Blob<int> a1(std::begin(ia), std::end(ia));
        Blob<int> s2(vi.cbegin(), vi.cend());
        Blob<std::string> a3(w.cbegin(), w.cend());
    
        return 0;
    }
