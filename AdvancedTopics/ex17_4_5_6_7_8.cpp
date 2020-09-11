/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       3  Mar 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 17.4:
// Write and test your own version of the findBook function.
//
// Exercise 17.5:
// Rewrite findBook to return a pair that holds an index and a pair of iterators.
//
// Exercise 17.6:
// Rewrite findBook so that it does not use tuple or pair.
//
// Exercise 17.7:
// Explain which version of findBook you prefer and why.
//
//  The version using tuple is prefered.It's more flexible, campared to other versions.
//
// Exercise 17.8:
// What would happen if we passed Sales_data() as the third parameter to accumulate
// in the last code example in this section?
//
//  If so, the output should be 0, as the Sales_data is default constructed.
//



#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using std::vector;

#include "ex17_4_5_6_7_8_SalesData.h"

// for ex17.4
// maches has 3 members:
// an index of a store and iterators into that store's vector
typedef std::tuple<std::vector<Sales_data>::size_type,
                   std::vector<Sales_data>::const_iterator,
                   std::vector<Sales_data>::const_iterator>
                                                            matches;

// for ex17.5
// return a pair that holds an index and a pair of iterators.
typedef std::pair<std::vector<Sales_data>::size_type,
                  std::pair<std::vector<Sales_data>::const_iterator,
                            std::vector<Sales_data>::const_iterator>>
                                                                      matches_pair;

// for ex17.6
// return a struct that holds an index of a store and iterators into that store's vector
struct matches_struct
{
    std::vector<Sales_data>::size_type st;
    std::vector<Sales_data>::const_iterator first;
    std::vector<Sales_data>::const_iterator last;
    matches_struct(std::vector<Sales_data>::size_type s,
                   std::vector<Sales_data>::const_iterator f,
                   std::vector<Sales_data>::const_iterator l) : st(s), first(f), last(l) { }
} ;

// for ex17.4
// return a vector with an entry for each store that sold the given book.
std::vector<matches>
findBook(const std::vector<std::vector<Sales_data>>& files,
         const std::string& book);

// print the result using the given iostream
void reportResults(
                   const std::vector<std::vector<Sales_data>>& files);

// for ex17.5
// return a vector with an entry for each store that sold the given book.
std::vector<matches_pair>
findBook_pair(const std::vector<std::vector<Sales_data> > &files,
              const std::string &book);

// for ex17.6
// return a vector with an entry for each store that sold the given book.
std::vector<matches_struct>
findBook_struct(const std::vector<std::vector<Sales_data> > &files,
                const std::string &book);

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
    
    store.push_back(Sales_data("0-201-70353-X", 4, 99.96));
	store.push_back(Sales_data("0-201-78345-X", 5, 110));
	store.push_back(Sales_data("0-201-78345-X", 5, 110));	//2 sales for the book
	store.push_back(Sales_data("0-201-82470-1", 4, 181.56));
	store.push_back(Sales_data("0-201-88954-4", 16, 198));
	store.push_back(Sales_data("0-399-82477-1", 5, 226.95));

	File.push_back(store);
	
	reportResults( File);
	
    return 0;
}

// for ex17.4
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

// for ex17.5
// return a vector with an entry for each store that sold the given book
std::vector<matches_pair>
findBook_pair(const std::vector<std::vector<Sales_data> > &files,
              const std::string &book)
{
    std::vector<matches_pair> ret;
    for(auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if(found.first != found.second)
            ret.push_back(std::make_pair(it - files.cbegin(),
                                         std::make_pair(found.first, found.second)));
    }
    return ret;
}

// for ex17.6
// return a vector with an entry for each store that sold the given book.
std::vector<matches_struct>
findBook_struct(const std::vector<std::vector<Sales_data> > &files,
                const std::string &book)
{
    std::vector<matches_struct> ret;
    for(auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if(found.first != found.second)
            ret.push_back(matches_struct(it - files.cbegin(), found.first, found.second));
    }
    return ret;
}
