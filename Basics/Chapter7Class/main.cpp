//fstream, v2.0
#include <iostream>
#include <fstream>
#include "Sales_item.h"
using std::cin; using std::cout; using std::endl; using std::ifstream; using std::cerr;

int main() {
    Sales_item Total;
    ifstream Read ("book_sales");
    if(Read >>Total){
        Sales_item Single;
        while(Read >> Single){
            if(Total.isbn() == Single.isbn()){
                Total += Single;
            } else{
                cout << Total <<endl;
                Total = Single;
            }
            
        }
        cout << Total <<endl;
        return 0;
    } else{
        cerr <<"Error" <<endl;
        return -1;
    }
    Read.close();
    
}
