//Section 15.2 Defining Base and Derived Classes
//Ex15.6 Test your PrintTotal function by passing both Quote and BulkQuote objects to that function

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


//PrintTotal
double PrintTotal(std::ostream& os, const Quote& quote, size_t order){
    double Total = quote.NetPrice(order);
    os << "Book: " << quote.isbn() << "\ntotal: " << Total << std::endl;
    return Total;
}


int main (){
    Quote q("C++ Primer, 5th", 89.5);
    PrintTotal(std::cout, q, 2);
    
    BulkQuote bq ("C++ Primer, 5th", 89.5, 10, 0.1);
    PrintTotal(std::cout, bq, 100);
    return 0;
    
}



