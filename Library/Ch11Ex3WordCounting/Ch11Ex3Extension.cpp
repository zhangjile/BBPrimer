//Chapter 11 Associative containers
//Ex 11.3 write your version of word-counting program
//Ex 11.4 extend your program to ignore case and punctuation.for example, "Example." "example," and "Example" should all increment the same counter.

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <stack>

using std::map; using std::multimap; using std::set; using std::vector; using std::string; using std::ifstream; using std::istream_iterator; using std::istringstream; 
using std::stack;

//Solution 3, 
//using erase method
auto strip(string& str) -> string const&
{
	for (auto& ch : str) ch = tolower(ch);
    for(size_t i=0; i < str.size(); ++i){
    	if(ispunct(str[i])){
    		str.erase(i--, 1);
    	}
    }
    return str;
}


void Format(vector<string> &v){
	for(size_t i = 0; i < v.size(); ++i){		
		string word;
		word = strip(v[i]);
		v[i] = word;
		//Supposing the function body is only RemoveCopyIf(v[i])', v will not be modified
		//RemoveCopyIf function implicitly invalidated the argument passed by reference!!! wow!!!		
	}
}


//Solution 4, the champion, strip is a one liner in function that transforms the vector
void Format4(vector<string> &v){
	for(size_t i = 0; i < v.size(); ++i){		
		string word;
		remove_copy_if(v[i].begin(),v[i].end(),back_inserter(word),ispunct);
		v[i] = word;
	}
}


//Solution 5
// remove punctuations by excluding punctuation
//keeps alphabets of each string and make all alphabets lower case
void FormatWords(vector<string> &v){
	for(size_t i = 0; i < v.size(); ++i){
		string word;		
		for(char& c:v[i]){
			if(!ispunct(c)){	//don't remove char from string using range for 
				word += tolower(c);
			}
		}
		v[i] = word;		
	}
}

//argument passed to the function is a formatted vector of words
void CountWords(const vector<string> &v){
	map<string, size_t> WordCount;
	set<string> Exclude = {"a","an","the"};
	
	//store each unique word in v and its occurrence count in pair in WordCount
	for(size_t i = 0; i < v.size(); ++i){
		//2'##' and (); in Note.md are reduced to empty string, 
		//therefore we'll have 3 empty strings if not excluded
		if(Exclude.find(v[i]) == Exclude.end() && v[i].size() >0){
			++WordCount[v[i]];
		}
	}
    
    //rank words by occurrences
    multimap<size_t, string> listing;
	for(const auto &e:WordCount){
        listing.insert(std::make_pair(e.second, e.first));      
    }
    //preparing for desired display
    stack<std::pair<size_t, string>> rank;
	for(const auto &e:listing){
        if(e.first >1 )
            rank.push(std::make_pair(e.first, e.second));
    }
    
	//display 
	while(!rank.empty()){
        auto e = rank.top(); 
        std::cout << e.second <<", " << e.first <<std::endl;
        rank.pop();
	}	
}

int main()
{
	ifstream text("Notes.md");
	istream_iterator<string> ifs(text), eof;
	vector<string> v;
	copy(ifs, eof, back_inserter(v));

	//any of the 3 is good enough to format a vector of words	
//	Format(v);	
	Format4(v);
//	FormatWords(v);	
	
	CountWords(v);
	
	return 0;
}
