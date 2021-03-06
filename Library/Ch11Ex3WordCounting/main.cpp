﻿//Chapter 11 Associative containers
//Ex 11.3 write your version of word-counting program
//Ex 11.4 extend your program to ignore case and punctuation.for example, "Example." "example," and "Example" should all increment the same counter.
//++ list words by occurrence using multimap and crbegin(), cool 

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

//Solution 1, 
//remove_if algorithm is tricky
auto strip(string& str) -> string const&
{
    for (auto& ch : str) ch = tolower(ch);
    str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
     //it pretends to works, LOL!
//    remove_if(str.begin(), str.end(), ispunct);
    return str;
}

void Format(vector<string> &v){
	for(size_t i = 0; i < v.size(); ++i){		
		string word;
		word = strip(v[i]);
		v[i] = word;
	}
}

/*remove_if(b,e,unaryPred)
"Removes" elements from the sequence by overwriting them with elements that are to be kept. The removed elements are those that are == val or for which unaryPred succeeds. 

!Returns an iterator just past the last element that was not removed.

if we trace the process of the following lines, the first character erased is the period in the end of the string s.
	string s = " ?*-this.";	
	s.erase (std::remove_if (s.begin (), s.end (), ispunct),s.end());
	std::cout << s<< std::endl;
	//	remove_if(s.begin(), s.end(), ispunct); //thishis. LOL

*/

//Solution 2
// remove punctuations from a string by identifying alphabets
//keeps alphabets of each string and make all alphabets lower case
void FormatWords(vector<string> &v){
	for(size_t i = 0; i < v.size(); ++i){
		string word;		
		for(char& c:v[i]){
			if(isalpha(c)){
				c = tolower(c);
				word += c;
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
    		//multimap doesn't have subscript method
        listing.insert(std::make_pair(e.second, e.first));      
    }
    
    auto it = listing.crbegin();
	while(it != listing.crend()){
		if(it->first >1)
			std::cout <<it->second << ", " << it->first <<std::endl;
		++it;
	}
//	for_each(listing.crbegin(), listing.crend(), [](std::pair<size_t, string> e){if(e.first > 1) std::cout <<e.second << ", " << e.first <<std::endl;});
}

int main()
{
	ifstream text("../Notes.md");
	istream_iterator<string> ifs(text), eof;
	vector<string> v;
	copy(ifs, eof, back_inserter(v));
	
	Format(v);	
//	FormatWords(v);	//format a vector of words
	
	CountWords(v);
	
	return 0;
}
