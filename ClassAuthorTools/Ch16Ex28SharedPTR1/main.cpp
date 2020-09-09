/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       04  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.29:
// Revise your Blob class to use your version of shared_ptr rather than the
// library version.
//


#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include "DebugDelete.h"
#include "shared_pointer.h"
#include "unique_pointer.h"
#include "Blob.h"

int main()
{
    Blob<std::string> b;
    b.push_back("sss");


    b[0] = "zzzz";
    std::cout << b[0] << "\n";
    
    auto pi = new std::vector<int> ();
    pi->push_back(100);
    
    shared_pointer<std::vector<int>> vi(pi);
    shared_pointer<std::vector<int>> ci(pi);
    std::cout << vi.use_count() << "\n";
     
    std::cout << (*vi)[0] << "\n";
    delete pi;
    
}
