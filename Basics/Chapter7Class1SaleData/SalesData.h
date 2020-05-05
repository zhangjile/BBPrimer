#ifndef SALESDATA_H
#define SALESDATA_H
#include <iostream>
#include <fstream>
#include <string>

class SalesData {
	private:
	std::string BookNO;
	unsigned UnitsSold = 0;
	double Revenue = 0.0;
	
	public:
	//base constructors that is called/delegated.
	SalesData(const std::string& s, unsigned cnt, double p): BookNO(s), UnitsSold(cnt),Revenue(p*cnt) {std::cout<<"base called " <<std::endl;}
	//default constructor calls/delegates to base constructor
	SalesData() : SalesData(" ", 0, 0.0){std::cout<<"default called " <<std::endl;}
	
	SalesData(const std::string& s) :BookNO(s){std::cout<<"string called " <<std::endl;}
	
	//this constructor delegates to default, which recursively delegates to base
	SalesData(std::ifstream &is):SalesData(){Read(is, *this); std::cout<<"stream called " <<std::endl;}
	
	//const std::string &isbn () const {return BookNO;}
	auto isbn() const -> std::string const & {return BookNO;} //trailing
	
	SalesData& Combine (const SalesData &item);
	
	friend std::ifstream &Read (std::ifstream &is, SalesData &item);
	friend std::ostream &Write (std::ostream &os, const SalesData &item);
	friend std::ofstream &Save (std::ofstream &os, const SalesData &item);

};


SalesData& SalesData::Combine(const SalesData &item){
	UnitsSold += item.UnitsSold;
	Revenue += item.Revenue;
	return *this;
}

std::ifstream &Read (std::ifstream &is, SalesData &item);
std::ostream &Write (std::ostream &os, const SalesData &item);
std::ofstream &Save (std::ofstream &os, const SalesData &item);

std::ifstream &Read (std::ifstream &is, SalesData &item){
	double Price {0.0};
	is >> item.BookNO >> item.UnitsSold >> Price;
	item.Revenue = item.UnitsSold * Price;
	return is;
}

std::ofstream &Save (std::ofstream &os, const SalesData &item){
	os << item.BookNO <<"\t" <<item.UnitsSold <<"\t" <<item.Revenue;
	return os;
}

std::ostream &Write (std::ostream &os, const SalesData &item){
	os << item.BookNO <<"\t" <<item.UnitsSold <<"\t" <<item.Revenue;
	return os;
}

#endif
