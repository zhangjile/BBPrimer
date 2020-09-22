#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <fstream>

using std::vector; using std::string; using std::ifstream;
using std::cout; using std::endl;
using std::get;

#include "ex17_4_5_6_7_8_SalesData.h"
#include "ex17_4_5_6_7_8_SalesData.cpp"

vector<Sales_data> build_store(const string &s)
{
	Sales_data item;
	vector<Sales_data> ret;
	ifstream is(s);
	while (read(is, item))
		ret.push_back(item);
	sort (ret.begin(), ret.end(), compareIsbn);  // need sort for equal_range to work
	return ret;
}

// for ex17.4
// maches has 3 members:
// an index of a store and iterators into that store's vector
typedef std::tuple<std::vector<Sales_data>::size_type,
                   std::vector<Sales_data>::const_iterator,
                   std::vector<Sales_data>::const_iterator>
                                                            matches;

// return a vector with an entry for each store that sold the given book.
std::vector<matches>
findBook(const std::vector<std::vector<Sales_data>>& files,
         const std::string& book)
{
    std::vector<matches> ret;

    // for each strore find the range of matching books, if any
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        // find the range of Sales_data tat have the same ISBN
        auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if(found.first != found.second)
            ret.push_back(std::make_tuple(it - files.cbegin(),
                                          found.first, found.second));
    }
    return ret;
}

// for ex17.4
// print the result using the given iostream
void reportResults(
                   const std::vector<std::vector<Sales_data>>& files)
{
    std::string s;
    while(std::cin >> s)
    {
        auto trans = findBook(files, s);
        if(trans.empty()){
            std::cout << s << "not found in any stores" << std::endl;
            continue;
        }

        for(const auto& store :trans)
            std::cout << "store " << std::get<0>(store) << " sales: "
               << std::accumulate(std::get<1>(store), std::get<2>(store),
                                  Sales_data(s))
                  << std::endl;
    }
}

int main()
{
	vector<vector<Sales_data>> File;
	vector<Sales_data> store;
	store.push_back(Sales_data("0-201-70353-X", 4, 99.96));
	store.push_back(Sales_data("0-201-78345-X", 5, 110));	//1 sales for the book
	store.push_back(Sales_data("0-201-82470-1", 4, 181.56));
	store.push_back(Sales_data("0-201-88954-4", 16, 198));
	store.push_back(Sales_data("0-399-82477-1", 5, 226.95));

	File.push_back(store);
    store.clear();
    
    store.push_back(Sales_data("0-201-70353-X", 4, 99.96));
	store.push_back(Sales_data("0-201-78345-X", 5, 110));
	store.push_back(Sales_data("0-201-78345-X", 5, 110));	//2 sales for the book
	store.push_back(Sales_data("0-201-82470-1", 4, 181.56));
	store.push_back(Sales_data("0-201-88954-4", 16, 198));
	store.push_back(Sales_data("0-399-82477-1", 5, 226.95));

	File.push_back(store);
	
	File.push_back(build_store("store1"));
	
	reportResults( File);
	
    return 0;
}

