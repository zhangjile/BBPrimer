//Section 15.2 Defining Base and Derived Classes
//Ex15.7 Defined a class that implements a limited discount strategy, which applies to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyong the limit.

#include <iostream>
#include <string>

using std::string; 

class Quote {
public:
    Quote () = default;
    Quote (string b, double p) :BookNo{b},Price{p} {}
    string isbn () const {return BookNo;}
    virtual double NetPrice (size_t n) const {return n*Price;}
        
private:
    string BookNo;

protected:
    double Price = 0.0;
};


class BulkQuote : public Quote
{
public:
    BulkQuote () = default;
    BulkQuote (const string& book, double p, size_t m, double d) : Quote(book, p), MinimumOrder(m), Discount(d) {}
    virtual double NetPrice (size_t n) const override {
        if(n >= MinimumOrder)
            return n * Price * (1-Discount);
        return n * Price;
    }
private:
    size_t MinimumOrder = 0;
    double Discount = 0.0;
};

class LimitedQuote : public Quote	//default private inheritance
//class LimitedQuote : Quote	//error, dynamic binding not allowed!
{
public:
	LimitedQuote () = default;
	LimitedQuote (const string& book, double p, size_t l, double d) 
		: Quote(book, p), Limit(l), Discount(d) {}
	virtual double NetPrice (size_t n) const override {
		if(n <= Limit)
			return n * Price * (1-Discount);
		return
			n*Price - Limit*Price*Discount;
	}
	
private:
	size_t Limit = 0;
	double Discount = 0.0;
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



