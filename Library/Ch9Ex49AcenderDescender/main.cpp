//  Chaper 9 Ex 9.49
//  description
//	A letter has an ascender if, as with d or f, part of the letter extends
//          above the middle of the line.
//          A letter has a descender if, as with p or g, part of the letter extends below the line.
//          Write a program that reads a file containing words and reports the longest word
//          that contains neither ascenders nor descenders.

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
    
    string run {};
    string longest {};
    if(ifs >> run){
    	string longest = run;
    }
    while(ifs >> run){
    	
    	//LOL
    	if(run.find_first_of ("bdfghjklpqty/,()+-;:0123456789") != string::npos ) continue;
    	
    	else {
    		if (run.size() > longest.size())
    			longest = run;
    	}
    }   
    ifs.close();
    cout << longest << endl;
    return 0;
}
