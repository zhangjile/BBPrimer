#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main ()
{
	ifstream in_file {"responses"};
	if (!in_file){
		cerr<<"oops"<<endl;
		//Boolean expressions are effective in intercepting exceptions
		return 1;
		}
	
	string Metrics{},Name {},Answers{};
	in_file >>Metrics;
//	cout << Metrics<<endl;  //primitive debugging method
	int l = Metrics.size();	
//	cout <<l<<endl; //the value displays 8 when data file is not formatted
	
	int score {0};
	int students{0};
	int total {0};
	double average {0.0};
	cout <<setprecision(2)<<fixed;
	
	const int total_width  {30};
    const int field1_width {20};    //  name
    const int field2_width {10};    // score
    
	cout<<setw(20)<<left <<"Name" <<setw(10)<<right<< "Score"<<endl;
    
    std::cout << std::setw(total_width) 
                   << std::setfill('-') 
                   << "###" 
    			//  <<'-'
                   << std::endl;   
    std::cout << std::setfill(' '); // reset setfill to blank spaces
   
	while(in_file >>Name>>Answers){
		for(size_t i{0}; i<l; ++i){
			if(Metrics[i]==Answers[i])
				++score;
			}
			cout<<setw(20)<<left <<Name <<setw(10)<<right<< score<<endl;	
			++students;
			total += score;
			score=0;	//LOL all scores are added if this line is missing!		
		}
		std::cout << std::setw(total_width) 
                   << std::setfill('-') 
                 //  << "###" 
    			  <<'-'
                   << std::endl;
		std::cout << std::setfill(' ');
		cout<<setw(20)<<left <<"Average" <<setw(10)
			<<right<< static_cast<double>(total)/students <<endl;
				
	in_file.close();
	return 0;
	}
