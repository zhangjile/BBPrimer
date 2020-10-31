
#include <iostream>
#include <regex>
 
using namespace std; 

int main() 
{ 
    string sp("geeksforgeeks"); 
//    string sp("worldgeeksforgeeksforgeeks"); 
    regex re("(geeks)(.*)"); 	//what does '.' mean? 
//    regex re("(geeks)(.)"); 	//output: f
  
    smatch match; 
  
    // we can use member function on match to extract the matched pattern. 
    if (regex_search(sp, match, re) == true) { 
  
        // The size() member function indicates the 
        // number of capturing groups plus one for the overall match 
        
        cout << "Match size = " << match.size() << endl; 
  
        // pattern at index 0 is the overall match "geeksforgeeks" 
        // pattern at index 1 is the first capturing group "geeks" 
        // pattern at index 2 is the 2nd capturing group "forgeeks" 
  
        cout << "Whole match : " << match.str(0) << endl; 
        cout << "First capturing group is '" << match.str(1) 
             << "' which is captured at index " << match.position(1) 
             << endl; 
        cout << "Second capturing group is '" << match.str(2) 
             << "' which is captured at index " << match.position(2) 
             << endl; 
    } 
    else { 
        cout << "No match is found" << endl; 
    } 
    return 0; 
} 