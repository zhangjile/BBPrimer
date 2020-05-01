//cmake AddItems, 
//AddItem <infile >outfile
# include <iostream>
# include "Sales_item.h"
using std::cin; using std::cout; using std::endl;

int main() {
    Sales_item item1, item2;
    cin >> item1 >>item2;
    cout << item1 + item2 <<endl;
    return 0;
}