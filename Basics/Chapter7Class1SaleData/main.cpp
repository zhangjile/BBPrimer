//section 7.1 defining abstract data types (Ex 7.21, p 271)
//update your SalesData class to hide its implementation
//seperate .h from main
#include "SalesData.h"

int main(){
	std::ifstream items {"book_sales"};
	std::ofstream yeah {"book_result"};
	SalesData Total,Single;
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
