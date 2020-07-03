//Chapter 12 Dynamic Memory, conclusion project, P484
//reduce the workload of TextQuerry function because it will be used frequently!
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <map>

using std::string; using std::istream; using std::ifstream; using std::map;
using std::cout; using std::endl; 
using std::vector; using std::cin;

void TextQuery (const vector<string> &file, string KeyWord){
	map<int, string> Summary;
	int LineNumber {0}, Ocurrences {0};
	string Line {};
	
	for(size_t i = 0; i < file.size(); ++i){
		if(file[i].find(KeyWord) != std::string::npos){
			++Ocurrences;
			LineNumber = i+1;
			Summary[LineNumber] = file[i];
		}
	}
	
	if(Ocurrences == 0){
		cout << KeyWord << " not found"<< endl;
	}
	else {
		cout << KeyWord << " occurs " <<Ocurrences <<" times" << endl;
		for(const auto &ele: Summary){
			cout << "\t(line " <<ele.first <<") " << ele.second <<endl;
		}
	}
}

int main ()
{
	//create vector of lines for a file
	std::ifstream is ("../Notes.md");
	vector<string> FileByLine;
	string Line {};
	while(getline(is, Line)){
		FileByLine.push_back(Line);
	}
	
	// accept query from stdin impromptu
    while(true){
        std::string s {};
        cout<<"Enter your query: "<<endl;
        cin >> s;
        if(s == "q") {
            cout<< "bye!" << endl;
            break;
        }
        TextQuery (FileByLine, s);
	}
	
	return 0;
    
}
