//  Chapter 7 
//  Ex 7.21

#ifndef SALESDATA_H
#define SALESDATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm> //sort was not declared in this scope, if missing

using std::string; using std::fstream; using std::vector;

class SalesData {
    friend std::istream &read(std::istream &is, SalesData &item);
    friend std::ostream &print(std::ostream &os, const SalesData &item);
    friend SalesData add(const SalesData &lhs, const SalesData &rhs);

public:
    SalesData() = default;
    SalesData(const std::string &s):BookNo(s) { }
    SalesData(const std::string &s, unsigned n, double p):BookNo(s), UnitsSold(n), Revenue(n*p){ }
    SalesData(std::istream &is) { read(is, *this); }

    std::string isbn() const { return BookNo; };
    SalesData& combine(const SalesData&);

private:
    std::string BookNo;
    unsigned UnitsSold = 0;
    double Revenue = 0.0;
};

// member functions.
SalesData& SalesData::combine(const SalesData& rhs)
{
    UnitsSold += rhs.UnitsSold;
    Revenue += rhs.Revenue;
    return *this;
}

// friend functions
std::istream &read(std::istream &is, SalesData &item)
{
    double price = 0;
    is >> item.BookNo >> item.UnitsSold >> price;
    item.Revenue = price * item.UnitsSold;
    return is;
}

std::ostream &print(std::ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.UnitsSold << " " << item.Revenue;
    return os;
}

//this function is not useful yet, but looks pretty.
SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;
}


#endif
