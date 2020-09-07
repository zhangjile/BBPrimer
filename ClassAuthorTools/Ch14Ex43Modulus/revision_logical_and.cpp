//Revision and association, Sep,7,2020
//Section 14.8.2, library defined function objects, p574,

#include <iostream>
using namespace std; 
  
int main() 
{ 
    bool z[] = { true, false, true, false, true }; 
    bool y[] = { true, true, false, false, true }; 
    int n = 5; 
    bool result[n]; 
  
    // using transform to 
    // call logical_AND on two array 
    transform(z, z + n, y, result, 
              logical_and<bool>()); 
  
    cout << "Logical AND:\n"; 
    for (int i = 0; i < n; i++) 
        cout << z[i] << " AND " << y[i] 
             << " = " << result[i] << "\n"; 
    return 0; 
}