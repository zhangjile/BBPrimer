//Section 15.7.3 Derived-class Copy-Control Members
//Ex15.26, p628, Define the Quote and BulkQuote copy-control members to do the same job as the synthesized versions. Give them and the other constructors print statements that identif which function is running. Write programs using these classes and predict wat objects will be created and destroyed. Compare your predictions with the output and continue experimenting until your predictions are reliably correct.
//this is a wonderful exercise, it's game-like.

#include <iostream>
#include <string>

using std::string; 

class Quote {
public:
	
    Quote () {std::cout << "Quote::default constructor" << std::endl;}
    Quote (string b, double p) :BookNo{b},Price{p} {
    	std::cout << "Quote (string b, double p)" << std::endl;
    }   
    Quote (const Quote& rhs) : BookNo{rhs.BookNo}, Price{rhs.Price} {
    	std::cout << "Quote::copy constructor" << std::endl;
    }
    Quote (Quote&& m) :BookNo{std::move(m.BookNo)}, Price{std::move(m.Price)} {
    	std::cout << "Quote::move constructor" << std::endl;
    }
    
    string isbn () const {return BookNo;}
    virtual double NetPrice (size_t n) const {return n*Price;}
    virtual ~Quote () {
    	std::cout << "Quote::destructor" << std::endl;
    }
    
private:
    string BookNo;      
    
protected:
    double Price = 0.0;

};

//DiscQuote as an interface
class DiscQuote : public Quote{
public:
	DiscQuote () {std::cout << "DiscQuote::default" << std::endl;}
	DiscQuote (const string& book, double p, size_t m, double d) 
		: Quote(book, p), Order(m), Discount(d) {
			std::cout << "DiscQuote (b, p, m, d)" << std::endl;
		}
	virtual double NetPrice (size_t n) const override = 0 ;
	
	virtual ~DiscQuote () {std::cout << "DiscQuote::destructor" << std::endl;}
protected:		
	size_t Order = 0;
	double Discount = 0.0;
};


class LimitedQuote : public DiscQuote
{
public:
	//default, copy and move members cannot be inherited
	LimitedQuote () {std::cout << "LimitedQuote::default" << std::endl;}
	LimitedQuote (const string& book, double p, size_t m, double d) 
    	: DiscQuote(book, p,m,d) {
    		std::cout << "LimitedQuote (b, p, m, d)" << std::endl;
    	}
    virtual double NetPrice (size_t n) const override {
		if(n <= Order)
			return n * Price * (1-Discount);
		return
			n*Price - Order*Price*Discount;
	}
	
	//Base::~Base invoked automatically
	virtual ~LimitedQuote (){
		std::cout << "LimitedQuote::destructor" << std::endl;
	/*
		LimitedQuote::destructor
		DiscQuote::destructor
		Quote::destructor
	*/
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
    
    LimitedQuote lq ("C++ Primer, 5th", 89.5, 10, 0.1);
    PrintTotal(std::cout, lq, 100);
    
    return 0;
    
}



