// Section 20
// Challenge 3 - Solution 
// Maps and Sets

#include <iostream>
#include <fstream>
#include <sstream>  //line 167, 驗證 25/10/2019
#include<queue>
#include <map>
#include<unordered_map>
#include <set>
#include <string>
#include <iomanip>


// This displays the priority queue by
// repeatedly topping and popping the priority queue
// It is being passed by value so we don't modify the 
// priority queue being passed in

template <typename T>
void display(std::priority_queue<T> pq)  {
	int i = 10;
	std::cout<<"\nTop 10 list\n";
	std::cout << std::setw(12) << std::left << "\nWord"
                << std::setw(8) << std::right << "Count"<< std::endl;
    std::cout << "===================" << std::endl;
    
    while (i>0) {
        T elem = pq.top();
        pq.pop();
        std::cout << elem ;
        --i;
    }
}


// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>

void display_words(const std::multimap<int, std::string> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
                << std::setw(7) << std::right << "Count"<< std::endl;
    std::cout << "===================" << std::endl;
    for (auto pair: words)
        std::cout << std::setw(12) << std::left << pair.second 
                       << std::setw(7) << std::right << pair.first << std::endl;
}


// Used for Part2
// Display the word and occurences from the 
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words)
{
     std::cout << std::setw(12) << std::left << "\nWord"
                << "Occurrences"<< std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair: words) {
        std::cout << std::setw(12) << std::left << pair.first 
    	           << std::left << "[ ";
       	for (auto i: pair.second) {
           	std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue; //very nice
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1() {
    std::map<std::string, int> words;
    std::string line;       
    std::string word;   
    std::ifstream in_file {"words"};
    
    std::set<std::string> exclude {"a","an","the","and","to","of"};
    
    if (in_file) {
        while (std::getline(in_file, line)) {
            //std::cout << line;
            std::stringstream ss(line);
            while (ss >> word) {
                word = clean_string(word);
                if(exclude.find(word)==exclude.end()){
               		 words[word]++;  // increment the count for the word in the map
               	}
            }
        }
        
        in_file.close();
                    	
        //display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }

    /*
    std::multimap<int,std::string> m;
    for (const auto &ele:words){
        if (ele.second>5)
        m.insert(std::make_pair(ele.second,ele.first));
        }
    display_words(m); //good practice:single responsibility pattern
        */
   
}
    
// Part1 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file {"words"};
    if (in_file) {
        int line_number = 0;
        while (std::getline(in_file, line)) {
            //std::cout << line;
            line_number++;
            std::stringstream ss(line);
            while (ss >> word) {
               word = clean_string(word);
               words[word].insert(line_number);
            }  
        }
        in_file.close();
        
        std::map<std::string, std::set<int>> m;
    	for (const auto &ele:words){
        	if (ele.second.size()>5)
        	m.insert(std::make_pair(ele.first, ele.second));
        }
	    display_words(m); //good practice:single responsibility pattern

        //display_words(words);
        
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}


int main() {
    part1();
    part2();
    return 0;
}
