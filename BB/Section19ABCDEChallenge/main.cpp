//modularization is done!

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void DisplayRuler (){
	const int total_width  {30};
    const int field1_width {20};    //  name
    const int field2_width {10};    // score
    
    std::cout << std::setw(total_width) 
                   << std::setfill('-') 
                //   << "###" 
    			  <<'-'
                   << std::endl;   
    std::cout << std::setfill(' '); // reset setfill to blank spaces    
}

int Score (string M, string A){
	int s {0};
	for(size_t i{0}; i<M.size(); ++i){
		if(M[i] == A[i])
			++s;
	}
	return s;
}

void DisplayStudent(string s, double d){
	cout<<setw(20)<<left << s <<setw(10)<<right<< d <<endl;		
}

int main ()
{
	cout<<setw(20)<<left <<"Name" <<setw(10)<<right<< "Score"<<endl;
	DisplayRuler ();
	
	ifstream in_file {"responses.txt"};
	if (!in_file){
		cerr<<"oops"<<endl;
		return 1;
		}
	
	string Metrics{},Name {},Answers{};
	in_file >>Metrics;
	size_t l = Metrics.size();	 //l is undefined if data file is not formatted
    
	int students{0};
	int total {0};
	
	while(in_file >>Name>>Answers){
		++students;
		int result = Score(Metrics, Answers);
		DisplayStudent(Name, result);		
		total += result;
	}
		
	DisplayRuler();
	
	//idiomatic expression for intercepting divide-by-zero exception
	cout <<setprecision(2)<<fixed;
	double average = (students == 0)?0:static_cast<double>(total)/students;
	DisplayStudent(string("Average"), average);
	
	in_file.close();
	return 0;
	}
