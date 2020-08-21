//Section 15.4, Abstract Base Class
//Ex15.15, p611, Define your own version of DiscQuote and BulkQuote
//Ex15.16, Rewrite the class representing a limited discount strategy to inherit from DiscQuote
//Ex15.17, try to define an object of type DiscQuote and see what errors you get from compiler
//++ this is probably the beginning of period that editing an existing cofe file is the major part of coding job.
//++ test the reference code by author, just make sure it clicks


#include <iostream>
#include <string>
#include "Quote.h"
//#include "Quote.cpp" //watch it on CodeLite

int main (){
    Quote q("C++ Primer, 5th", 89.5);
    print_total(std::cout, q, 1);
    
    Bulk_quote bq ("C++ Primer, 5th", 89.5, 10, 0.1);
    print_total(std::cout, bq, 100);
    
    Lim_quote lq ("C++ Primer, 5th", 89.5, 10, 0.1);
    print_total(std::cout, lq, 100);
    
    return 0;
    
}



