﻿// Chapter 10.3 customizing operations Ex 12, P387
// sort vector<SalesData> objs
// Ex 17, P392 sort it using lambda expression
// [capture list](parameter list) -> return type {function body}

#include "SalesData.h"

void SalesReport(vector<SalesData> &l){
	std::ifstream book ("book_sales");
	SalesData Total;
	if(book >> Total){
		SalesData Trans;
		while(book >> Trans){
			if(Total.isbn() == Trans.isbn()){
				Total += Trans;
				
			}else {
				l.push_back(Total);
				std::cout << Total << std::endl;
				Total = Trans;
			}
		}
		l.push_back(Total);
		std::cout << Total << std::endl;
	}
	book.close();
}

void DisplayList(const vector<SalesData> &l){
	for(const SalesData &e : l){
		std::cout << e <<std::endl;
	}
}

bool CompareISBN(const SalesData &s1,const SalesData &s2){
	return s1.isbn() < s2.isbn();
}


int main()
{
	vector<SalesData> l;
	std::cout << "Aggreagted" << std::endl;
	SalesReport(l);
	//sort algorithm requires random access, that's why list container didn't work
	//trivial and significant
	std::sort(l.begin(), l.end(), [](const SalesData &s1,const SalesData &s2){return s1.isbn() <s2.isbn();});	
	std::cout << "\nSorted" << std::endl;
	DisplayList(l);
    
    return 0;
}
