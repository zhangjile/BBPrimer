//Section 16.3 Overloading and Templates
//Ex16.48, p699, Write your own version of the debug_rep functions.
//Section 16.5 Template Specializations
//Ex16.65, p712, In $16.3 we defined 2 overloading versions of DebugRep, rewrite them as specializations

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

/*
string DebugRep(char* s){
	cout << "char*, "<<endl;
    return DebugRep(string(s));
}

string DebugRep(const char* s){
	cout << "const char*, " <<endl;
    return DebugRep(string(s));
}
*/

//Ex16.65, above all, the nontemplate version has priority
template<>
string DebugRep(char* s){
	cout << "<>char*, ";
	return DebugRep(string(s));
}

template<>
string DebugRep(const char* s){
	cout << "<>const char*, ";
	return DebugRep(string(s));
}

//Ex16.66, What are the advantages and disadvantages of  overloading these DebugRep functions as compared to defining specializations? Guess: specialization code is faster
//Ex16.67, Would defining these specializations affect function matching? no. it's in the domain of the original template instantiation.

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
