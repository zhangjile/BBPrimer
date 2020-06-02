//Chapter 2 Variables and Basic Types
//Ex 2.42 P77, read data from book_sales, sum up sales for each book.
//the main function is too fat to be healthy!
// Chapter 10.3 customizing operations Ex 12, P387
// sort vector<SalesData> objs

#include "SalesData.h"

//vector<SalesData> MakeList (std::istream& is); //alternative modularization concept

void SalesReport(vector<SalesData> &l){
	std::ifstream book ("book_sales");
	SalesData Total;
	if(read(book,Total)){
		SalesData Trans;
		while(read(book,Trans)){
			if(Total.isbn() == Trans.isbn()){
				Total.combine(Trans);
				
			}else {
				l.push_back(Total);
				print(std::cout,Total) << std::endl;
				Total = Trans;
			}
		}
		l.push_back(Total);
		print(std::cout,Total) << std::endl;
	}
	book.close();
}

void DisplayList(const vector<SalesData> &l){
	for(const SalesData &e : l){
		print(std::cout, e) <<std::endl;
	}
}

bool CompareISBN(const SalesData &s1,const SalesData &s2){
	return s1.isbn() < s2.isbn();
}


int main()
{
	vector<SalesData> l;
	SalesReport(l);
	sort(l.begin(), l.end(), CompareISBN);
	DisplayList(l);
    
    return 0;
}
