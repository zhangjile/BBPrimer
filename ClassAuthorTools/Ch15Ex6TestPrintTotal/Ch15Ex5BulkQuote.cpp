//Section 15.2 Defining Base and Derived Classes
//Ex15.5 Define your own version of BulkQuote class
//Ex15.6 Test your PrintTotal function by passing both Quote and BulkQuote objects to that function

#include <iostream>
#include <string>

class BulkQuote : public Quote
{
public:
    BulkQuote () = default;
    BulkQuote (const string& book, double p, size_t m, double d) : Quote(book, p), MinimumOrder(m), Discount(d) {}
    virtual double NetPrice (size_t n) const override {
        if(n >= MinimumOrder)
            return n * Price * (1-Discount);
        //explicit, good taste and good practice by instinct
        else 
            return n * Price;
    }
private:
    size_t MinimumOrder = 0;
    double Discount = 0.0;
};