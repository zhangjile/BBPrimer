#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//一桿子到底，哈哈大笑
//和Frank的解決方案對比，Frank是習慣性地使用functions，模塊化并簡化代碼
int main ()
{
	ifstream in_file {"responses.txt"};
	if (!in_file){
		cerr<<"oops"<<endl;
		//Boolean expression is totally effective in screening out so-called exceptions
		return 1;
		}
	//cout <<"good" <<endl;
		
	//char answers[] {};
	//如果聲明answers是char，那麼 in_file >>answers 陣述的執行結果就是讀入一個字母
	string answers{},name {},response{};
	in_file >>answers;
	//cout << answers<<endl;
	//int length = strlen(answers);
	int length = answers.length();	
	//cout <<length<<endl;
	
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
                 //  << "###" 
    			  <<'-'
                   << std::endl;   // display total_width dashes
    std::cout << std::setfill(' '); // reset setfill to blank spaces
    /*
    in_file >>name>>response;
    
    cout<<setw(20)<<left <<name <<setw(10)<<right<< response<<endl;		
    cout << response[2]<<endl;
    
    
	in_file >>name>>response;
		for(size_t i{0}; i<length; ++i){
			cout<< answers[i]<<response[i]<<endl;
		
			}
			cout<<setw(20)<<left <<name <<setw(10)<<right<< response<<endl;		
			cout<<setw(20)<<left <<name <<setw(10)<<right<< score<<endl;			
		*/
	
	
	while(in_file >>name>>response){
		for(size_t i{0}; i<length; ++i){
			if(answers[i]==response[i])
				++score;
			}
			//cout<<setw(20)<<left <<name <<setw(10)<<right<< response<<endl;		
			cout<<setw(20)<<left <<name <<setw(10)<<right<< score<<endl;	
			++students;
			//cout <<students<<endl;
			total += score;
			//cout <<total<<endl;
			score=0;
/********************************************************************************
			//LOL all scores are added if this line is missing!		
			//連滾帶爬的感覺，因為沒有使用函數來處理，前後數據粘在一起了，竟然要手動歸零。26/06/2019
**********************************************************************************/
		}
		std::cout << std::setw(total_width) 
                   << std::setfill('-') 
                 //  << "###" 
    			  <<'-'
                   << std::endl;
		std::cout << std::setfill(' ');
cout<<setw(20)<<left <<"Average" <<setw(10)<<right<< static_cast<double>(total)/students <<endl;
		
		
		/*
	while(!in_file.eof()){
		getline(in_file, name);
		getline (in_file,response);
		
		for(size_t i {1};i<=length; ++i){
			 if (response[i]== answers[i])
			 	++score;			 			 		
			 }
			 
		cout<<name <<response<<endl;
		}
		
		*/
	in_file.close();
	return 0;
	}
