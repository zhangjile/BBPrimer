//Chapter 11 Associative containers
//Ex 11.3 write your version of word-counting program
//Ex 11.4 extend your program to ignore case and punctuation.for example, "Example." "example," and "Example" should all increment the same counter.
//++ strip method using remove_if
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

// remove punctuations from a string to be a clean word, nice expression
// remove_if, returns an iterator just past the last element that was not removed, (P878)
// s.erase(pos,len); remove len characters from position len, if len is ommitted, remove to the end of s, return a reference to s (P363)
auto strip(string& str) -> string const&
{
    for (auto& ch : str) ch = tolower(ch);
    //str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
    remove_if(str.begin(), str.end(), ispunct); //it WORKS as expected!
    return str;
}


//keeps alphabets of each string and make all alphabets lower case
void FormatWords(vector<string> &v){
	for(size_t i = 0; i < v.size(); ++i){
		string word;
		strip(word);
/*		for(char c:v[i]){
			if(isalpha(c)){
				c = tolower(c);
				word += c;
			}
		}
		v[i] = word;
		
		*/
	}
}


//argument passed to the function is a formatted vector of words
void CountWords(const vector<string> &v){
	map<string, size_t> WordCount;
	set<string> Exclude = {"a","an","the"};
	
	//store each unique word in v and its occurrence count in pair in WordCount
	for(size_t i = 0; i < v.size(); ++i){
		if(Exclude.find(v[i]) == Exclude.end()){
			++WordCount[v[i]];
		}
	}
    
    //rank words by occurrences
    multimap<size_t, string> listing;
    stack<std::pair<size_t, string>> rank;
    for(const auto &e:WordCount){
        listing.insert(std::make_pair(e.second, e.first));      //subscript method is invalid here:)
    }
    /*
    auto it = listing.crbegin();
	while(it != listing.crend()){
		if(it->first >1)
			std::cout <<it->second << ", " << it->first <<std::endl;
		++it;
	}
	*/
    
    
	for(const auto &e:listing){
        if(e.first >1 )
            rank.push(std::make_pair(e.first, e.second));
    }
    
	//print the statistics
	while(!rank.empty()){
        auto e = rank.top(); 
        std::cout << e.second <<", " << e.first <<std::endl;
        rank.pop();
	}
	
}

int main()
{
	ifstream text("../Notes.md");
	istream_iterator<string> ifs(text), eof;
	vector<string> v;
	copy(ifs, eof, back_inserter(v));
	
	FormatWords(v);	//format a vector of words
	
	CountWords(v);
	
	return 0;
}
