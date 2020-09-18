//	Section 8.1.3 Managing the output buffer

#include <iostream>
#include <chrono>
using namespace std::chrono;
#include <fstream>
using std::cin; using std::cout; using std::istream; using std::ofstream;

int main()
{
	std::ofstream ofs ("buffer.txt", ofstream::app);  
	std::cout << "tie example:\n";   
	
	// 空参数调用返回一個指向默认的ostream object(cout)的指針  
	*cin.tie() << "This is inserted into cout\n";  
	*cin.tie() << "the magic of tying\n";  
	
	// tie cin to ofs
	cin.tie(&ofs);
	//std::ostream* prevstr = std::cin.tie(&ofs);  
	
	//returns a pointer to ofs, the ostream object tied currently  
	*cin.tie() << "This is inserted into the file\n";  
	
//  cin is tied to cout again, back to default status, optional  
//	std::cin.tie(prevstr);  
	
	ofs.close();  //close the file linked to ofs object.
	
	//test the performance of new setting
	std::ios_base::sync_with_stdio(false);  
	cin.tie(0);  
	auto StartTime = high_resolution_clock::now();
	for(int i = 0; i < (int)1e5; i++){  
		cout<<rand()<<"\n";  
	}  
	auto StopTime = high_resolution_clock::now();
	auto Duration = duration_cast<microseconds> (StopTime - StartTime);
    std::cout << Duration.count()/1000 <<"\n";
    
    return 0;
}
