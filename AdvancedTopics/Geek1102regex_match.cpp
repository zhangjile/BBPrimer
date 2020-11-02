#include <iostream> 
#include <regex> 
  
using namespace std; 

// C++ program to demonstrate working of regex_match() 
void Match(){
	string a = "GeeksForGeeks"; 
  
    // Here b is an object of regex (regular expression) 
    regex b("(Geek)(.*)"); // Geeks followed by any character 
  
    // regex_match function matches string a against regex b 
    if ( regex_match(a, b) ) 
        cout << "String 'a' matches regular expression 'b' \n"; 
  
    // regex_match function for matching a range in string  
    // against regex b 
    if ( regex_match(a.begin(), a.end(), b) ) 
        cout << "String 'a' matches with regular expression "
                "'b' in the range from 0 to string end\n"; 
  	else
  		cout << "String 'a' doesn't match regular expression 'b' \n"; 
  
}

void Replace(){
	string s = "I am looking for GeeksForGeek \n"; 
      
    // matches words beginning by "Geek" 
    regex r("Geek[a-zA-z]+"); 
      
    // regex_replace() for replacing the match with 'geek'  
    cout << std::regex_replace(s, r, "geek"); 
      
    string result; 
      
    // regex_replace( ) for replacing the match with 'geek' 
    regex_replace(back_inserter(result), s.begin(), s.end(), 
                  r,  "geek"); 
  
    cout << result; 
}

int main() 
{ 
    Match();
    Replace();
    return 0; 
} 
