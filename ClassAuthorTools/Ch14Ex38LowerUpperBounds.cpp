//Section 14.18.1 Lambdas are function objects
//Ex14.38, p574, Write a class that tests whether the length of a given string matches a given bound. 
//Use that object to write a program to report how many words 
//in an input file are of sizes 1 through 10 inclusive

#include <iostream>
#include <set>
#include <functional>
#include <string>
#include <fstream>

using std::string; using std::set; using std::ifstream;

class Bound {
public:
    Bound(size_t x) : LowerBound{x} {}
    bool operator() (const string& s){
        return s.size() >= LowerBound;
    }
private:
    size_t LowerBound;
};

int main (){
    ifstream input ("Notes.md");
    string word;
    Bound bd(5);
    size_t cnt = 0;
    while(input >> word){
        if(bd(word))
            ++cnt;
    }
    std::cout << cnt << std::endl;
    return 0;
}

//this is a prototype, yeah!