//Section 16.3 Overloading and Templates
//Ex16.48, p699, Write your own version of the debug_rep functions.

#include <iostream>
#include <string>
#include <sstream>

using std::string; using std::cout; using std::endl; using std::ostringstream;

template<typename T>
string DebugRep(const T& t){
    ostringstream s;
    s << "const T&, ";
    s << t;
    
    return s.str();
}

template<typename T>
string DebugRep (T* t){
//    string s;
//    s = "T* " + *t;
    ostringstream s;
    s << "T*, " << t;
    if(t)
        s << ", "<< *t;
    else
        s << "NULL";
    
    return s.str();
}

string DebugRep(const string& s){
    cout << "const string&, ";
    return "'" + s + "'"; 
}

string DebugRep(char* s){
    return DebugRep(string(s));
}

string DebugRep(const char* s){
    return DebugRep(string(s));
}


int main (){
    cout << DebugRep("Hello world!")<<endl;
    
    string st("Hello!");
    cout << DebugRep(st)<<endl;
    
    string* stp = nullptr;
    cout << DebugRep(stp)<<endl;
    
    stp = &st;    
    cout << DebugRep(stp)<<endl;
    
    return 0;
}
