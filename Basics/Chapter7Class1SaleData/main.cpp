//section 7.1 defining abstract data types (Ex 7.21, p 271)
//update your SalesData class to hide its implementation
//seperate .h from main
//section 7.5 Constructor revisited ( Ex 7.38,p291 )
//++ std::cin as a default parameter
#include "SalesData.h"

int main(){
	SalesData Total, Single;
	if(Read(std::cin,Total)){ 
		while (Read(std::cin,Single)){
			if(Total.isbn() == Single.isbn()){
				Total.Combine(Single);
			}
			else{
				Write(std::cout,Total) << std::endl; //wow, just wow for cout:)
				Total = Single;
			}
		}
		Write(std::cout,Total) << std::endl; 
	}
	else{
		std::cerr <<"no data" <<std::endl;
		return -1;
	}
	return 0;
}
