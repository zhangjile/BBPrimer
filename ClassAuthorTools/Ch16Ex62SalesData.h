//Chapter 14 Operator Overloading
//Ex14.2, p560, write declarations for overloaded input, output, addition and compound-assignment operators for SalesData class
//Section 16.5 Template Specializations
//Ex16.62, p712, Define your own versions of hash<SalesData> and define an unordered_multiset of SalesData objects. Put several transactions into the container and print its contents.

#ifndef SALESDATA_H
#define SALESDATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using std::string; using std::fstream; using std::vector; 

//this forward declaration recommended in the book causes error! 
//template<typename T> std::class hash; 
//take away 'std::' before hash
//otherwise, it's an error:forward declaration of class cannot have a nested name specifier

class SalesData {
	//forward declaration for a std::hash is not needed
	friend class std::hash<SalesData>;
	
	//replace read, print, add friend functions with overloaded operators
    friend std::istream & operator>>(std::istream &is, SalesData &item);
    friend std::ostream & operator<<(std::ostream &os, const SalesData &item);
    friend SalesData operator+(const SalesData &lhs, const SalesData &rhs);
    friend bool operator ==(const SalesData& lhs, const SalesData& rhs);

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
    sum += lhs;
    return sum;
}

bool operator ==(const SalesData& lhs, const SalesData& rhs){
	return lhs.BookNo == rhs.BookNo && lhs.UnitsSold == rhs.UnitsSold;
}
	
//it's better for SalesData class to grant friendship to class std::hash<SalesData>;
namespace std {
	template<>
	class hash<SalesData> {
	public:
		typedef size_t return_type;
		typedef SalesData argument_type;
		size_t operator()(const SalesData& a) const{
			return std::hash<std::string> () (a.BookNo) ^
				std::hash<unsigned>() (a.UnitsSold) ^
				std::hash<double> () (a.Revenue);

		}
	};	
}
	
#endif
