//fstream, v2.0
#include <iostream>
#include <fstream>
#include "Sales_item.h"
using std::cin; using std::cout; using std::endl; using std::ifstream; using std::cerr;

int main() {
    Sales_item item1;
    ifstream Read ("book_sales");
    if(Read >>item1){
        Sales_item item2;
        while(Read >> item2){
            if(item1.isbn() == item2.isbn()){
                item1 += item2;
            } else{
                cout << item1 <<endl;
                item1 = item2;
            }
            
        }
        cout << item1 <<endl;
        return 0;
    } else{
        cerr <<"Error" <<endl;
        return -1;
    }
    Read.close();
    
}
