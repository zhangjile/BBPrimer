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

using std::map; using std::set; using std::vector; using std::string; using std::ifstream; using std::istream_iterator; using std::istringstream;

//keeps alphabets of each string and make all alphabets lower case
void FormatWords(vector<string> &v){
	for(size_t i = 0; i < v.size(); ++i){
		string word;
		
		for(char c:v[i]){
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
		if(Exclude.find(v[i]) == Exclude.end()){
			++WordCount[v[i]];
		}
	}
	
	//print the statistics
	for(const auto &e:WordCount){
		if(e.second >= 2){
			std::cout << e.first <<" " << e.second <<std::endl;
		}
	}
}

int main()
{
	ifstream text("Review.md");
	istream_iterator<string> ifs(text), eof;
	vector<string> v;
	copy(ifs, eof, back_inserter(v));
	
	//format a vector of words
	FormatWords(v);
	
	CountWords(v);
	
	return 0;
}
