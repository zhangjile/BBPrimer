//Section 15.7.3 Derived-class Copy-Control Members
//Ex15.626, orchestrating a predicatable error in the example about copy and move constructors on this page

#include <iostream>
#include <string>

using std::string; 

class Quote {
public:
    Quote () = default;
    Quote (string b, double p) :BookNo{b},Price{p} {}   //BookNo comes before Price
    
    //set up copy and move in Base
    Quote (const Quote& source) :BookNo (source.BookNo), Price (source.Price) {}
    Quote (Quote&& source) :BookNo(std::move(source.BookNo)), Price (std::move(source.Price)) {}
    //the derived class should call corresponding copy/move operator in Base
    
    string isbn () const {return BookNo;}
    virtual double NetPrice (size_t n) const {return n*Price;}
    virtual ~Quote () = default;
    
private:
    string BookNo;   
    
protected:
    double Price = 0.0;

};


class BulkQuote : public Quote{
public:
	BulkQuote () = default;
	BulkQuote (const string& book, double p, size_t m, double d) 
		: Quote(book, p), Order(m), Discount(d) {}
	virtual double NetPrice (size_t n) const override{
		if(n >= Order)
            return n * Price * (1-Discount);
        return n * Price;
	}
		
	//set up copy and move in Derived
	BulkQuote (const BulkQuote& source) : //Quote (source), 
		Order(source.Order), Discount (source.Discount) {}
	BulkQuote (BulkQuote&& source) : Quote(std::move(source)), 
		Order(std::move(source.Order)), Discount (std::move(source.Discount)) {}
	
	//print the data members in BulkQuote objects
	void Print (){
		std::cout << isbn() <<"," <<Price <<", " <<Order <<", " <<Discount <<std::endl;
	}
protected:		
	size_t Order = 0;
	double Discount = 0.0;
};

void Print();

int main (){
    BulkQuote b1 ("C++, fifth", 89.5, 10, 0.1);
    b1.Print ();
    BulkQuote b2(b1);
    b2.Print ();		//error is reproduced, displaying 0, 10, 0.1	
    
    return 0;
    
}





