//Section 16.1 function templates
//Ex16.2, p658, write and test your own versions of the compare functions
//Section 16.5 Template Specializations
//testing example Compare specialization code
 
#include <iostream>

using std::cout; using std::endl; using std::less;

template<typename T>
int Compare (const T& a, const T& b){
	std::cout << "const T&"<<std::endl;
    if(less<T>()(a,b)) return -1;   //std::less<T> () is a function object 
    if(less<T>()(b,a)) return 1;
    return 0;
}

//Section 16.5 template specialization
template <>
int Compare(const char* const &p1, const char* const &p2){
	std::cout << "const char* const &p"<<std::endl;
    if(less<decltype(p1)>()(p1,p2)) return -1;
    if(less<decltype(p1)>()(p2,p1)) return 1;
    return 0;
}

template<unsigned N, unsigned M>
int Compare(const char (&a)[N], const char (&b)[M]){
	std::cout << "const char(&)[N]" <<std::endl;
	return strcmp(a,b);
}


int main(){
//    cout<< Compare (2016, 2020) << endl;
    
    //candidate template ignored: deduced conflicting types for T ("int", "double")
    //cout<< Compare (19, 20.0) << endl;	//error, 
    
//    cout<< Compare (2024.12, 2020.12) << endl;
    
    //Ex16.37, Ex16.39, p683
    double d = 6.8;
    std::cout << std::max<double>(d,3) << std::endl; 	//6.8
    std::cout << std::max<int>(d,3) << std::endl; 	//6
    
    std::cout << Compare<std::string>("Trump", "Joe") << std::endl; 
        
    //Compare ("Trump", "Biden"), error, call to Compare is ambiguous
    cout<< Compare ("Biden bb","Trump") << endl;	//-18, strcmp does subtraction, 'T - B'
    
    //Section 16.5 test specialization of Compare template
    const char* p1 = "hi", *p2 = "hello";
    std::cout <<Compare(p1, p2) <<std::endl;	// specialization is called
    std::cout <<Compare ("hi", "hello") <<std::endl;
    	
    return 0;
}

//Artificial intelligence, machine learning, neutral network and computer vision

//Do programmers brains work something like Virtual Machines? Very likely.
//translate the code blocks into natural language, describe the functionalities and how the concepts are implemented.
//envision them as storyline. it's natural to develop the skill starting from reproducing the code from memory.

