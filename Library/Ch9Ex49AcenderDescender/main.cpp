//  Chaper 9 Ex 9.49
//  description
//	A letter has an ascender if, as with d or f, part of the letter extends
//          above the middle of the line.
//          A letter has a descender if, as with p or g, part of the letter extends below the line.
//          Write a program that reads a file containing words and reports the longest word
//          that contains neither ascenders nor descenders.

//++ put lambda in action

#include <string>
#include <fstream>
#include <iostream>

using std::string; using std::cout; using std::endl; using std::ifstream;

int main()
{
    ifstream ifs("Ch49Ex49Description.md");
    if (!ifs) {
        std::cerr << "oops" << std::endl;
        return -1;
    }

    string AscenderAndDescender = "bdfghjklpqty";
    string NoneDescenderNorAscender = "aceimnorsuvwxz";
    string b = NoneDescenderNorAscender;
    
    string run {};
    string longest {};
    
    //lucid lambda in play
    //if any letter not from "aceimnorsuvwxz" is not found in string a == every letter in string a is found in "aceimnorsuvwxz", no exception.
    //for example, "iostream", 't' is not from "aceimnorsuvwxz"
    //but is found in string a indexed 3, so the condition is false
    //essentially the if expression checks if a is a subset of b.
    auto update = [&longest] (const string &a){
    	if(a.find_first_not_of("aceimnorsuvwxz") == string::npos){
    		longest = longest.size() < a.size() ? a : longest;
    	}
    };
    
    for(string curr; ifs >> curr; update(curr));
    
    /*
    if(ifs >> run){
    	string longest = run;
    }
    while(ifs >> run){
    	
    	//LOL
    	if(run.find_first_of ("bdfghjklpqtyBDFGHJKLPQTY/,()+-;:0123456789") != string::npos ) continue;
    	
    	else {
    		if (run.size() > longest.size())
    			longest = run;
    	}
    }   
    */
    ifs.close();
    cout << longest << endl;
    return 0;
}
