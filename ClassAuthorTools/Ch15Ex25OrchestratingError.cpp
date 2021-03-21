//Section 15.7 Constructors and Copy Control
//Ex 15.25, p 625, why did we define a default constructor for DiscQuote? What effect would removing that constructor have on the behavior of BulkQuote?
//
/*
the compiler complains that:
> 'Bulk_quote::Bulk_quote()' is implicitly deleted because the default definition would be ill-formed.

 A constructor taking 4 parameters has been defined, which prevents compiler generating synthesized version default constructor.

As a result, the default constructor of any class derived from it has been defined as deleted. 

rule of thumb is, the default constructor be defined explicitly so that the derived classes can call it when executing its default constructor.
*/

#include <iostream>
#include <string>

using std::string; 

class Quote {
public:
    Quote () = default;
    Quote (string b, double p) :BookNo{b},Price{p} {}   //BookNo comes before Price
    string isbn () const {return BookNo;}
    virtual double NetPrice (size_t n) const {return n*Price;}
    virtual ~Quote () = default;
    
private:
    string BookNo;      //therefore BookNo should be placed before Price 
    
protected:
    double Price = 0.0;

};

//DiscQuote as an interface
class DiscQuote : public Quote{
public:
	DiscQuote () = delete;	//explicit
	//DiscQuote ();  //implicit 
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
    
    	//successfully orchestrated an error, overwhelming happiness:)
    BulkQuote f;
    //error, call to implicitly-deleted default constructor of 'BulkQuote'
    
    BulkQuote bq ("C++ Primer, 5th", 89.5, 10, 0.1);
    PrintTotal(std::cout, bq, 100);
    
    LimitedQuote lq ("C++ Primer, 5th", 89.5, 10, 0.1);
    PrintTotal(std::cout, lq, 100);
    
    return 0;
    
}



