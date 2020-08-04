//Section 14.18.1 Lambdas are function objects
//Ex14.38, p574, Write a class that tests whether the length of a given string matches a given bound. 
//Use that object to write a program to report how many words 
//in an input file are of sizes 1 through 10 inclusive

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <map>
#include <fstream>

using std::string; using std::vector; using std::map; using std::ifstream;

class Bound {
public:
    Bound(size_t l, size_t u) : LowerBound{l}, UpperBound{u} {}
    bool operator() (const string& s){
        return s.size() >= LowerBound && s.size() <= UpperBound;
    }
    size_t Upper() const {return UpperBound;}
private:
    size_t LowerBound;
    size_t UpperBound;
};

int main (){
    vector<Bound> bd;
    size_t Lower = 1;
    
    //14u (unsigned) helps to detect the longest word in source manually.
    vector<size_t> Uppers = {1u,2u,3u,4u,5u,6u,7u,8u,9u,10u,11u,12u, 13u, 14u};
    for(auto u:Uppers){
        bd.emplace_back(Bound(Lower,u));
    }
    /*
    //Bound object cannot be used as index before defining operator<
    map<Bound, size_t> Results;
    for(auto i: bd){
        Results[i] = 0; 
    }
    
    */
    
    map<size_t, size_t> Results; //soul of the piece
    for(auto i: Uppers){
        Results[i] = 0; 
    }
    
    //abstract the raw data and put it in the map Results
    ifstream input ("README.md");
    string word;
    
    while(input >> word){
        for(auto f: bd){
            if(f(word))
                ++Results[f.Upper()];
        }
    }
    
    std::cout << "In README.md, "<< std::endl;
    for(auto i : Results){
        std::cout  <<i.second <<" words have "<< i.first <<" letters or less "<< std::endl;
    }
    
    //calculate the number of words that have n characters from raw data 
    size_t prev = 0, temp = 0;
    for(auto &current : Results){
    	temp = current.second; //store the current.second in a temp variable
    	current.second -= prev;
    	prev = temp;	//load temp for the next.second	
    	//putting a thread through the tiny needle hole
    	
    }
    std::cout << "\nIn README.md, "<< std::endl;    
    for(auto i : Results){
        std::cout <<i.second <<"words have "<< i.first <<((i.first > 1)?"characters":"character" )<< std::endl;
    }
    
    return 0;
}

