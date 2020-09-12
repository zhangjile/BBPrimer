//Chapter 14 Operator Overloading
//Ex14.2, p560, write declarations for overloaded input, output, addition and compound-assignment operators for SalesData class

#ifndef SALESDATA_H
#define SALESDATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>	//tuple
#include <numeric>

using std::string; using std::fstream; using std::vector;

class SalesData {
	//replace read, print, add friend functions with overloaded operators
    friend std::istream & operator>>(std::istream &is, SalesData &item);
    friend std::ostream & operator<<(std::ostream &os, const SalesData &item);
    friend SalesData operator+(const SalesData &lhs, const SalesData &rhs);

public:
    SalesData() = default;
    SalesData(const std::string &s):BookNo(s) { }
    SalesData(const std::string &s, unsigned n, double p):BookNo(s), UnitsSold(n), Revenue(n*p){ }
    SalesData(std::istream &is) { is >> *this; }

    std::string isbn() const { return BookNo; };
    //SalesData& combine(const SalesData&);
    SalesData& operator+= (const SalesData&);

private:
    std::string BookNo;
    unsigned UnitsSold = 0;
    double Revenue = 0.0;
};

// member functions.
SalesData& SalesData::operator+=(const SalesData& rhs)
{
    UnitsSold += rhs.UnitsSold;
    Revenue += rhs.Revenue;
    return *this;
}

// friend functions
std::istream & operator>> (std::istream &is, SalesData &item)
{
    double price = 0;
    is >> item.BookNo >> item.UnitsSold >> price;
     //if there's error in istream, construction of an object won't start
    if(is) {
        item.Revenue = item.UnitsSold * price;
    } else {   
        item = SalesData ();
    }
    
    return is;
}

std::ostream & operator<< (std::ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.UnitsSold << " " << item.Revenue;
    return os;
}

//its's the plain old addition operation
SalesData operator+(const SalesData &lhs, const SalesData &rhs)
{
	SalesData sum = lhs;
    if(lhs.isbn() == rhs.isbn()){
    sum += lhs;
    }
    return sum;
	
}

//Ex17.4 FindBook

void DisplayList(const vector<SalesData> &l){
	for(const SalesData &e : l){
		std::cout << e <<std::endl;
	}
}

bool CompareISBN(const SalesData &s1,const SalesData &s2){
	return s1.isbn() < s2.isbn();	
}


typedef std::tuple<vector<SalesData>::size_type,
					vector<SalesData>::const_iterator,
					vector<SalesData>::const_iterator> matches;

vector<matches> FindBook(const vector<vector<SalesData>> &Files, const string& book){
	vector<matches> ret;
	for(auto store = Files.cbegin(); store != Files.cend(); ++store){
		auto found = equal_range(store->cbegin(), store->cend(), book, CompareISBN);
		if(found.first != found.second){
			ret.push_back(make_tuple(store - Files.cbegin(), found.first, found.second));
		}
	}
	return ret;

}


#endif
