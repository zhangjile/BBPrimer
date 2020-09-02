
//Section 16.4.2 Variadic template pack expansion
//Ex16.56, p704, Write and test a variadic version of errormsg.

#include <iostream>
#include <sstream>

template<typename T>
std::ostream& Print(std::ostream& os, const T& t){
    os << t;
    return os;
}

template<typename T, typename ... Args>
std::ostream& Print(std::ostream& os, const T& t, const Args& ... Rest){
    os << t << ”, “;
    return Print(os, Rest...);	//Recursion is revisited
}

template<typename T>
std::string DebugRep(const T& t){
	std::ostringstream temp;
	temp << t;
	return temp.str();
}

template<typename... Args>
std::ostream& ErrorMSG (std::ostream& os, const Args&... Rest){
	return Print(os, DebugRep(Rest)...);
}


int main () {
	std::string item(”howdy“);
	ErrorMSG(std::cerr, item, ”Faith“);
	return 0;
} 

//The call to print uses the patttern DebugRep(rest). That pattern says that we want to call debugRep on each element in the function parameter pack rest. 
//The resulting expanded pack will be a comma-seperated list of calls to DebugRep.
