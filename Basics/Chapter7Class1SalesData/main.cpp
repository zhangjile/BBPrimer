//section 7.1 defining abstract data types (Ex 7.3, p 260)
//add Combine and isbn members to the SalesData class and revise transaction processing program
// the 3rd item in book_sales file is taken as Revenue
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct SalesData {
	std::string BookNO;
	unsigned UnitsSold = 0;
	double Revenue = 0.0;
	std::string isbn () const {return BookNO;}
	SalesData& Combine (const SalesData &item);
};

SalesData& SalesData::Combine(const SalesData &item){
	UnitsSold += item.UnitsSold;
	Revenue += item.Revenue;
	return *this;
}

int main(){
	std::ifstream items {"book_sales"};
	SalesData total,Single;
	if(items>>total.BookNO >>total.UnitsSold >>total.Revenue){
		while (items>>Single.BookNO >>Single.UnitsSold >>Single.Revenue){
			if(total.BookNO == Single.BookNO){
				total.Combine(Single);
			}
			else{
				cout<< total.BookNO <<"\t"<<total.UnitsSold <<"\t"<<total.Revenue <<endl;
				total = Single;
			}
		}
		cout<< total.BookNO <<"\t"<<total.UnitsSold <<"\t"<<total.Revenue <<endl;
	}
	else{
		cerr <<"no data";
		return -1;
	}
	items.close();
	return 0;
}

