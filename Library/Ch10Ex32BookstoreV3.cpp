//Chapter 10.4.2 iostream iterators
//Ex 10.32 P407 Rewrite the bookstore problem from chapter 1 using a vector to hold the transactions and various algorithms to do the processing. use sort with compareISBN to arrange transactions in order and then use find and accumulate to do the sum.
// find_if returns an iterator to the first element when unary predicate SUCCEEDS.
	
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include "SalesItem.h"
using namespace std;

//Bookstore Program version 1.0, P24
void BookstoreV1(){
	ifstream items {"book_sales"};
	Sales_item total;
	if(items>>total){
		Sales_item RunningSum;
		while(items>>RunningSum){
			if(total.isbn() == RunningSum.isbn()){
				total += RunningSum;
			}
			else{
				cout<< total <<endl;
				total = RunningSum;
			}		
		}
		cout<< total <<endl;
	}
	items.close();  	
}

void BookstoreV2 (){
	ifstream items {"book_sales"};
	istream_iterator<Sales_item> it (items), EOD;
	ostream_iterator<Sales_item> ot(cout, "\n");
	Sales_item sum = *it++;
	while(it != EOD){
		if(sum.isbn() == it->isbn()){
			sum += *it++;
		}else{
			*ot = sum;
			sum = *it++;
		}
	}
	*ot = sum;
	items.close();
}

void BookstoreV3 (){
	
	//copy Sales_item objects created from book_sales to v, twice
	ifstream items {"book_sales"};
	vector<Sales_item> v;
	istream_iterator<Sales_item> it(items), EOD;
	copy(it, EOD, back_inserter(v));
	list<Sales_item> l;
	l.assign(v.begin(),v.end());
	copy(l.begin(), l.end(), back_inserter(v));
	
	//sort
	stable_sort(v.begin(), v.end(), [](const Sales_item &a, const Sales_item &b){return a.isbn() < b.isbn();});
	
	//traverse and regroup using find_if, sum using accumulate
	cout<<"Bookstore V3.0"<<endl;

	//a spectacular use case of find_if, hard-core logic!
	//we want to have an iterator to the first element in array 
	//whose BookNo is different, find_if comes in play!
	for(auto front = v.cbegin(), back = front;front != v.cend();front = back){
		back = find_if(front,v.cend(), 
				[=](const Sales_item &s){return s.isbn() != front->isbn();});
		cout<< std::accumulate(front, back, Sales_item (front->isbn())) << endl;
	}

	items.close();
}

int main() 
{
//	BookstoreV1();
//	BookstoreV2();
	BookstoreV3();
	return 0;

}
