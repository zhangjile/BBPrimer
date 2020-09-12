// Chapter 10.3 customizing operations Ex 12, P387
// sort vector<SalesData> objs
// Ex 17, P392 sort it using lambda expression
// [capture list](parameter list) -> return type {function body}

//Section 17.1 the Tuple Type
//Ex17.4, p723, Write and test your own version of the FindBook function.

//prepare sales data of 3 stores, sorted

//id number of a store, first record and one past last record


//bool CompareISBN, returns true if the isbn of 2 sales is the same.


#include "SalesData.h"

void Report(std::istream& is,vector<vector<SalesData>>& Files){
	string book;
	while(is >> book){
		if(book == "q") return;
		auto m = FindBook(Files, book);
		if(m.empty()){
			std::cout << "Null" << std::endl;
			continue;
		}
		//for(auto t = m.cbegin(); t != m.cend(); ++t) {
		for(const auto& store : m){
			auto d = accumulate(std::get<1>(store), std::get<2>(store), SalesData(book));
			std::cout <<std::get<0>(store) <<" " <<d <<std::endl;
			
		}
	}
}

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


int main()
{
	vector<vector<SalesData>> File;
	vector<SalesData> store;
	store.push_back(SalesData("0-201-70353-X", 4, 99.96));
	store.push_back(SalesData("0-201-78345-X", 5, 110));	//1 sales for the book
	store.push_back(SalesData("0-201-82470-1", 4, 181.56));
	store.push_back(SalesData("0-201-88954-4", 16, 198));
	store.push_back(SalesData("0-399-82477-1", 5, 226.95));

	File.push_back(store);
    store.clear();
    
    store.push_back(SalesData("0-201-70353-X", 4, 99.96));
	store.push_back(SalesData("0-201-78345-X", 5, 110));
	store.push_back(SalesData("0-201-78345-X", 5, 110));	//2 sales for the book
	store.push_back(SalesData("0-201-82470-1", 4, 181.56));
	store.push_back(SalesData("0-201-88954-4", 16, 198));
	store.push_back(SalesData("0-399-82477-1", 5, 226.95));

	File.push_back(store);
    
    std::cout << File[1].size() << std::endl;
    Report(std::cin, File);
    
    return 0;
}
