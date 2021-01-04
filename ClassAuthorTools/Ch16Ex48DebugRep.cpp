//Section 16.3 Overloading and Templates
//Ex16.48, p699, Write your own version of the debug_rep functions.

#include <iostream>
#include <string>
#include <sstream>

using std::string; using std::cout; using std::endl; using std::ostringstream;

template<typename T>	//1
string DebugRep(const T& t){
    ostringstream s;
    s << "const T&, " <<"\n";
    s << t;
    
    return s.str();
}

template<typename T>	//2
string DebugRep (T* t){
    ostringstream s;
    s << "T*, " << t <<"\n";
    if(t)
        s << DebugRep(*t) ;
    else
        s << "NULL";
    
    return s.str();
}

//3, if 3 is not seen when 5 is called, 1 will be called.
string DebugRep(const string& s){
    cout << "const string&, ";
    return "'" + s + "'"; 
}

string DebugRep(char* s){	//4
	cout << "char*, ";
    return DebugRep(string(s));
}

string DebugRep(const char* s){		//5
	cout << "const char*, ";
    return DebugRep(string(s));
}


int main (){
//    cout << DebugRep("Hello world!")<<endl; //5 and 3 relay
   
    string st("Hello!");
//    cout << DebugRep(st)<<endl;	//3
   
    string* stp = nullptr;
//    cout << DebugRep(stp)<<endl;		//2
    
    stp = &st;    
    cout << DebugRep(stp)<<endl;		//2 and 1 relay
    
    return 0;
}
