// Chapter11, Ex11.11 P426 redefine multiset Bookstore without using decltype
// ++ Ex11.19, P431, write the type signature of bookstore.begin()
	
#include "SalesData.h"
using ISBN = bool (*) (const SalesData &a, const SalesData &b);

void SalesReport(vector<SalesData> &l){
	std::ifstream book ("book_sales");
	SalesData Total;
	std::cout << "raw data:" << std::endl;
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

// Chapter11, Ex11.11
//sort the individual sales record according to BookNo.
void IndividualRecordsSorted (){
	std::cout << "get individual records sorted by BookNo: " << std::endl;
	std::multiset <SalesData, ISBN> Bookstore(CompareISBN);	
	std::ifstream book ("book_sales");
	
	//Ex11.19 P431, explicit signature
	std::multiset<SalesData, ISBN> ::iterator it = Bookstore.begin();
	SalesData item;
	
	while(read(book,item)){
		Bookstore.insert(item);
	}

	for(const SalesData &e:Bookstore){	//
		print(std::cout,e) <<std::endl;
	}
}

int main()
{
	vector<SalesData> l;
	SalesReport(l);
	
    //trivial and significant
    std::cout << "sorted by BookNo:" << std::endl;
	sort(l.begin(), l.end(), [](const SalesData &s1,const SalesData &s2){return s1.isbn() <s2.isbn();});	
	
	//sort(l.begin(), l.end(), CompareISBN);	

	DisplayList(l);
	
	IndividualRecordsSorted();
    
    return 0;
}
