//Chapter 8.1 IO classes
//Ex8.1 Write a function that takes and returns an istream&. 
//The function should read the stream until it hits end-of-file. 
//The function should print what it reads to the stdout. Reset the stream 
//so that it is valid before returning the stream.
//iostream objects are much more tangible now.
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//cplusplus.com, this test code makes EOF and 'is.eof()' visible
void test(){
  std::ifstream is("OpenFile"); 
  char c;
  //loop getting single characters
  while (is.get(c))  
    std::cout << c;
  
  //confirming the stream hit EOF
  if (is.eof())    
    std::cout << "[EoF reached]\n";
  else
    std::cout << "[error reading]\n";

  is.close();           
}

// ctrl+c on windows to signal end-of-file, ctrl+d on linux
istream& hit(istream& i){
    string s;
    while(!i.eof()){
        i >> s;
        cout << s;
    }
    
    //after signaling EOF, display it
    if (i.eof())     // check for EOF
        std::cout << "[EoF reached]\n";
    else
        std::cout << "[error reading]\n";
    
    //turn of all failure bits, beautiful
    i.clear();  
    return i;
}


int main(){
	
//    hit(cin); //bare bone calling method:)
    //reference call method
    istream& is = hit(std::cin);
    //display the machine-specific integer
    std::cout<<"iostate: " << is.rdstate() << std::endl;
  
    
//    test();
    return 0;
}
