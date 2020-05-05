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
	//plain basic constructors
	SalesData() = default;
	SalesData(const std::string& s) :BookNO(s){}
	SalesData(const std::string& s, unsigned cnt, double p): BookNO(s), UnitsSold(cnt),Revenue(p*cnt) {}
	SalesData(std::ifstream &is);
	
	std::string isbn () const {return BookNO;}
	SalesData& Combine (const SalesData &item);
	
	friend std::ifstream &Read (std::ifstream &is, SalesData &item);
	friend std::ostream &Write (std::ostream &os, const SalesData &item);
	friend std::ofstream &Save (std::ofstream &os, const SalesData &item);

};

SalesData::SalesData (std::ifstream &is){
	Read(is, *this);
}

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
