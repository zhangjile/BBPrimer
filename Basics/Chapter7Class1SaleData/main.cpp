//section 7.1 defining abstract data types (Ex 7.21, p 271)
//update your SalesData class to hide its implementation
//seperate .h from main
//section 7.5.1, Ex 7.38,p291, default argument of constructor
//section 7.5.3, constructors (Ex 7.41 p292),
//rewrite SalesData to use delegating constructor
// writing string isbn() function using trailing return type syntax
//testing implicit class type conversion

#include "SalesData.h"

int main(){
	std::ifstream items {"book_sales"};
	std::ofstream yeah {"book_result"};
	// trace the function calling and rewinding
	
	std::string null_isbn ("9-99-9999999-9");
	SalesData t1(null_isbn);
	SalesData t2("8-888-888888-X");
	null_isbn = "8-888-888888-X";
	t2.Combine("8-888-888888-X");
	Write(std::cout,t1) << std::endl; 
	Write(std::cout,t2) << std::endl; 
	SalesData Total(items);
	SalesData Single; 
	if(Read(items,Total)){ 
		while (Read(items,Single)){
			if(Total.isbn() == Single.isbn()){
				Total.Combine(Single);
			}
			else{
				Write(std::cout,Total) << std::endl; //wow, just wow for cout:)
				Total = Single;
			}
		}
		Save(yeah, Total);
	}
	else{
		std::cerr <<"no data" <<std::endl;
		return -1;
	}
	items.close();
	return 0;
}
