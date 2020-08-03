//Section 15.4, Abstract Base Class
//Ex15.15, p611, Define your own version of DiscQuote and BulkQuote
//Ex15.16, Rewrite the class representing a limited discount strategy to inherit from DiscQuote
//Ex15.17, try to define an object of type DiscQuote and see what errors you get from compiler
//++ this is probably the beginning of period that editing an existing cofe file is the major part of coding job.


#include <iostream>
#include <string>

using std::string; 

class Quote {
public:
    Quote () = default;
    Quote (string b, double p) :BookNo{b},Price{p} {}
    string isbn () const {return BookNo;}
    virtual double NetPrice (size_t n) const {return n*Price;}

protected:
    double Price = 0.0;
            
private:
    string BookNo;

};

//DiscQuote as an interface
class DiscQuote : public Quote{
public:
	DiscQuote () = default;
	DiscQuote (const string& book, double p, size_t m, double d) 
		: Quote(book, p), Order(m), Discount(d) {}
	virtual double NetPrice (size_t n) const override = 0 ;
protected:		
	size_t Order = 0;
	double Discount = 0.0;
};

class BulkQuote : public DiscQuote
{
public:
    BulkQuote () = default;
    BulkQuote (const string& book, double p, size_t m, double d) 
    	: DiscQuote(book, p,m,d) {}
    virtual double NetPrice (size_t n) const override {
        if(n >= Order)
            return n * Price * (1-Discount);
        return n * Price;
    }
};

class LimitedQuote : public DiscQuote
{
public:
	LimitedQuote () = default;
	LimitedQuote (const string& book, double p, size_t m, double d) 
    	: DiscQuote(book, p,m,d) {}
    virtual double NetPrice (size_t n) const override {
		if(n <= Order)
			return n * Price * (1-Discount);
		return
			n*Price - Order*Price*Discount;
	}
};

//PrintTotal
double PrintTotal(std::ostream& os, const Quote& quote, size_t order){
    double Total = quote.NetPrice(order);
    os << "Book: " << quote.isbn() << "\ntotal: " << Total << std::endl;
    return Total;
}


int main (){
    Quote q("C++ Primer, 5th", 89.5);
    PrintTotal(std::cout, q, 1);
    
    BulkQuote bq ("C++ Primer, 5th", 89.5, 10, 0.1);
    PrintTotal(std::cout, bq, 100);
    
    LimitedQuote lq ("C++ Primer, 5th", 89.5, 10, 0.1);
    PrintTotal(std::cout, lq, 100);
    
    return 0;
    
}



