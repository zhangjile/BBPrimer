//section 7.1 defining abstract data types (Ex 7.21, p 271)
//update your SalesData class to hide its implementation

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SalesData {
	private:
	std::string BookNO;
	unsigned UnitsSold = 0;
	double Revenue = 0.0;
	
	public:
	std::string isbn () const {return BookNO;}
	SalesData& Combine (const SalesData &item);
	
	friend ifstream &Read (ifstream &is, SalesData &item);
	friend ostream &Write (ostream &os, const SalesData &item);
	friend ofstream &Save (ofstream &os, const SalesData &item);

};

SalesData& SalesData::Combine(const SalesData &item){
	UnitsSold += item.UnitsSold;
	Revenue += item.Revenue;
	return *this;
}

ifstream &Read (ifstream &is, SalesData &item);
ostream &Write (ostream &os, const SalesData &item);
ofstream &Save (ofstream &os, const SalesData &item);
SalesData& Add (const SalesData item1, const SalesData item2);

ifstream &Read (ifstream &is, SalesData &item){
	double Price {0.0};
	is >> item.BookNO >> item.UnitsSold >> Price;
	item.Revenue = item.UnitsSold * Price;
	return is;
}

ofstream &Save (ofstream &os, const SalesData &item){
	os << item.BookNO <<"\t" <<item.UnitsSold <<"\t" <<item.Revenue;
	return os;
}

ostream &Write (ostream &os, const SalesData &item){
	os << item.BookNO <<"\t" <<item.UnitsSold <<"\t" <<item.Revenue;
	return os;
}

SalesData& Add (const SalesData item1, const SalesData item2){
	SalesData temp = item1;
	temp.Combine(item2);
	return temp;
}



int main(){
	std::ifstream items {"book_sales"};
	ofstream yeah {"book_result"};
	SalesData Total,Single;
	if(Read(items,Total)){
		while (Read(items,Single)){
			if(Total.isbn() == Single.isbn()){
				Total.Combine(Single);
			}
			else{
				Write(cout,Total)<<endl; //wow, just wow for cout:)
				Total = Single;
			}
		}
		Save(yeah, Total);
	}
	else{
		cerr <<"no data";
		return -1;
	}
	items.close();
	return 0;
}

