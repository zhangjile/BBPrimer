//Section 15.7.3 Derived-Class Copy-Control members
//Ex15.27, p 629, redefine your BulkQuote with using expression

#include <iostream>
#include <string>

using std::string; 

class Quote {
public:
    Quote () = default;
    Quote (string b, double p) :BookNo{b},Price{p} {}  
    string isbn () const {return BookNo;}
    virtual double NetPrice (size_t n) const {return n*Price;}
    virtual ~Quote () = default;
    
private:
    string BookNo;      
    
protected:
    double Price = 0.0;

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
//    BulkQuote () = default;
//    BulkQuote (const string& book, double p, size_t m, double d) 
//    	: DiscQuote(book, p,m,d) {}
	using DiscQuote::DiscQuote;
	//An 'inherited' constructor is not treated as a user-defined constructor, 
	//therefore, a class that contains only inherited constructors will have a 
	//synthesized default constructor.
	
	
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



