//Revision and association, Sep,7,2020
//Section 14.8.2, library defined function objects, p574,

#include <iostream>
using namespace std; 
  
int main() 
{ 
    bool z[] = { true, false, true, false, true }; 
    bool y[] = { true, true, false, false, true }; 
//  bool y[] = { true, true, false, false };   
    int n = 5; 
    bool result[n]; 
  
    // using transform to call logical_and on two array
    // 3 ways to use predicate 
  std::function<bool(bool,bool)> predicate = std::logical_and<bool> ();	//a function object is NOT bool!
  std::logical_and<bool> b;
  transform(z,z+n, y, result, b);	//1
//  transform(z, z + n, y, result, std::logical_and<bool>()); //2    
//  transform(z,z+n, y, result, predicate);	//3
  
  //display the result of transformation
    cout << "Logical AND:\n"; 
    for (int i = 0; i < n; i++) 
        cout << z[i] << " AND " << y[i] 
             << " = " << result[i] << "\n"; 
    return 0; 
}
