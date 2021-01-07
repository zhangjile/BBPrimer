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
void TestEOF(){
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

//testflight for tie()

void TestTie(){
	std::ostream *prevstr;  //nice pointer
    std::ofstream ofs;
    ofs.open ("test.txt");

    std::cout << "tie example:\n";

    *std::cin.tie() << "This is inserted into cout";
    prevstr = std::cin.tie (&ofs);//store
    *std::cin.tie() << "This is inserted into the file";
    std::cin.tie (prevstr); //restore

    ofs.close();
}

int main(){	
    istream& is = hit(std::cin);
    //display the machine-specific integer
    std::cout<<"iostate: " << is.rdstate() << std::endl;
  
    
//    TestEOF();
//    TestTie();
    return 0;
}
