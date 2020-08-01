//Chapter 15 Object-Oriented Programming
//Ex15.3, p595, define your own version of the Quote class and the PrintTotal function

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

//PrintTotal
double PrintTotal(std::ostream& os, const Quote& quote, size_t order){
    double Total = quote.NetPrice(order);
    os << "Book: " << quote.isbn() << "\ntotal: " << Total << std::endl;
    return Total;
}


int main (){
    Quote q("C++ Primer, 5th", 89.5);
    PrintTotal(std::cout, q, 2);
    return 0;
    
}

