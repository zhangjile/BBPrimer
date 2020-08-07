//Section 15.8 Containers and Inheritance
//Ex15.30, p634, write your own version of Basket class and use it to compute prices for the same transactions as you used in the previous exercises.

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <algorithm>

using std::string; using std::vector; using std::shared_ptr; using std::make_shared;
using std::multiset;

class Quote {
public:
    Quote () = default;
    Quote (string b, size_t o, double p) :BookNo{b},Order {o}, Price{p} {}   
    string isbn () const {return BookNo;}
    virtual double NetPrice () const {return Order*Price;}
    virtual ~Quote () = default;
    
private:
    string BookNo;     
    
protected:
    size_t Order = 0;
    double Price = 0.0;

};

class DiscQuote : public Quote{
public:
	DiscQuote () = default;
	DiscQuote (const string& book, size_t o, double p, size_t m, double d) 
		: Quote(book, o, p), Bound {m},Discount(d) {}
	virtual double NetPrice () const override = 0 ;
	
protected:		
	size_t Bound = 0;
	double Discount = 0.0;
};

class BulkQuote : public DiscQuote
{
public:
    BulkQuote () = default;
    BulkQuote (const string& book, size_t o, double p, size_t m, double d) 
    	: DiscQuote(book, o, p,m,d) {}
    virtual double NetPrice () const override {
        if(Order >= Bound)
            return Order * Price * (1-Discount);
        return Order * Price;
    }
};

class LimitedQuote : public DiscQuote
{
public:
	LimitedQuote () = default;
	LimitedQuote (const string& book, size_t o, double p, size_t m, double d) 
    	: DiscQuote(book, o,p,m,d) {}
    virtual double NetPrice () const override {
		if(Order <= Bound)
			return Order * Price * (1-Discount);
		return
			Order*Price - Bound*Price*Discount;
	}
};

//PrintTotal
double PrintTotal(std::ostream& os, const Quote& quote){
    double Total = quote.NetPrice();
    os << "Book: " << quote.isbn() << "\ntotal: " << Total << std::endl;
    return Total;
}

//Ex15.30
class Basket {
public:
	Basket () = default;
	void AddItem(const shared_ptr<Quote>& sale) {items.insert(sale);}
	double TotalReceipt (std::ostream& os) const {
		double Total = 0.0;
		for(auto it = items.cbegin(); it != items.cend(); it = items.upper_bound(*it)){
			Total += PrintTotal(std::cout, **it);
		}
		os << Total << std::endl;
		return Total;
	}
	
	void AddItem (const Basket& source){
		items = source.items;
	}
	
	//print a Basket
	void Print(){
		for(const auto &i: items){
			std::cout <<i->isbn() << std::endl;
		}
	}
	
	size_t size() {return items.size();}
private:
	static bool Comp(const shared_ptr<Quote>& a, const shared_ptr<Quote>& b){
		return a->isbn() < b->isbn();
	}
	multiset<shared_ptr<Quote>, decltype(Comp)*> items{Comp};	//() causes error
};

int main (){
	double CorrectSum = 0.0;	
	
    //test Basket
    Basket bk;
	
    Quote q("C++ Primer, 5th", 1, 89.5);
    CorrectSum += PrintTotal(std::cout, q);	
    bk.AddItem(make_shared<Quote>("C++ Primer, 5th", 1, 89.5));
    
    BulkQuote bq ("C++ Primer, 5th", 100, 89.5, 10, 0.1);
    CorrectSum += PrintTotal(std::cout, bq);
    bk.AddItem(make_shared<BulkQuote>("C++ Primer, 5th", 100, 89.5, 10, 0.1));
    
    LimitedQuote lq ("C++ Primer, 5th", 100, 89.5, 10, 0.1);
    CorrectSum += PrintTotal(std::cout, lq);
    bk.AddItem(make_shared<LimitedQuote>("C++ Primer, 5th", 100, 89.5, 10, 0.1));
    
    std::cout << CorrectSum << std::endl;

    //title: Effective C++
    CorrectSum = 0.0;
    bq = BulkQuote ("Effective C++", 10, 150.00, 10, 0.2);
    CorrectSum += PrintTotal(std::cout, bq);
    bk.AddItem(make_shared<BulkQuote>("Effective C++", 10, 150.00, 10, 0.2));
    
    lq = LimitedQuote ("Effective C++", 10, 150.00, 5, 0.1);
    CorrectSum += PrintTotal(std::cout, lq);
    bk.AddItem(make_shared<BulkQuote>("Effective C++", 10, 150.00, 5, 0.1));
    
    std::cout << CorrectSum << std::endl;
    
    
    CorrectSum = 0.0;
    bq = BulkQuote ("Bestseller, Think Like a Programmer", 10, 12.00, 5, 0.1);
    CorrectSum += PrintTotal(std::cout, bq);
    bk.AddItem(make_shared<BulkQuote>("Bestseller, Think Like a Programmer", 10, 12.00, 5, 0.1));
    
    lq = LimitedQuote ("Bestseller, Think Like a Programmer", 10, 12.00, 5, 0.1);
    CorrectSum += PrintTotal(std::cout, lq);
    bk.AddItem(make_shared<BulkQuote>("Bestseller, Think Like a Programmer", 10, 12.00, 5, 0.1));
    
    std::cout << CorrectSum << std::endl;
    std::cout <<bk.size () <<std::endl;
    
    bk.Print();
    
    return 0;
    
}



