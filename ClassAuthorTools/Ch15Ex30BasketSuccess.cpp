//Section 15.8 Containers and Inheritance
//Ex15.30, p634, write your own version of Basket class and use it to compute prices for the same transactions as you used in the previous exercises.
//++ AddItem(const Quote&), done, improving readability

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
    
    //clone operation, VIRTUAL
    virtual Quote* clone() const & {
    	Quote* temp = new Quote(*this);
    	return temp;
    }
    virtual Quote* clone() && {
    	Quote* temp = new Quote(std::move(*this));
    	return temp;
    	
    }
    
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
    
    //clone operation, VIRTUAL
    virtual BulkQuote* clone() const & override{
    	BulkQuote* temp = new BulkQuote(*this);
    	return temp;
    }
    virtual BulkQuote* clone() && override{
    	BulkQuote* temp = new BulkQuote(std::move(*this));
    	return temp;
    	
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
	
	//clone operation, VIRTUAL
    virtual LimitedQuote* clone() const & override{
    	LimitedQuote* temp = new LimitedQuote(*this);
    	return temp;
    }
    virtual LimitedQuote* clone() && override{
    	LimitedQuote* temp = new LimitedQuote(std::move(*this));
    	return temp;
    	
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
	
	//overloading AddItem providing copy and move operations, ++readability
	void AddItem(const Quote& sale) {
		items.insert(shared_ptr<Quote> (sale.clone())); //click click
		//'new Quote(sale)' works literaly, therefore it produces error here
		//items.insert(shared_ptr<Quote> (new Quote(sale)));

	}
	void AddItem(Quote&& sale){
		items.insert(shared_ptr<Quote> (std::move(sale).clone()));
	// new operator works literally, creating error here
	//	shared_ptr<Quote> temp (new Quote(std::move(sale)));
	//	items.insert(temp);
	}
	
	double TotalReceipt (std::ostream& os) const {
		double Total = 0.0;
		//jump to the next BookNo entry
		for(auto it = items.cbegin(); it != items.cend(); it = items.upper_bound(*it)){
			Total += PrintTotal(std::cout, **it);
		}
		os << Total << std::endl;
		return Total;
	}	
	
	// verify that multiset object is working properly
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
	//'items(Comp)' causes error
	multiset<shared_ptr<Quote>, decltype(Comp)*> items{Comp};	
};

int main (){
	Basket bk;
	
    BulkQuote bq ("C++ Primer, 5th", 100, 89.5, 10, 0.1);
    //bk.AddItem(make_shared<BulkQuote>(bq)); //8055 
    bk.AddItem(bq);	//8055, error fixed
    
    LimitedQuote lq ("C++ Primer, 5th", 100, 89.5, 10, 0.1);
    bk.AddItem(lq);
    
    bq = BulkQuote ("Beginning and Beyond", 3, 10.00, 3, 0.2);
    bk.AddItem(bq);
    
    lq = LimitedQuote ("Beginning and Beyond", 1, 10.00,3, 0.1);    
    bk.AddItem(lq);
    
    bq = BulkQuote ("Think Like a Programmer", 10, 28.00, 5, 0.1);
    bk.AddItem(bq);
    
    lq = LimitedQuote ("Think Like a Programmer", 10, 28.00, 5, 0.1);
    bk.AddItem(lq);
    
    std::cout <<"There are "<<bk.size ()<<" elements in bk" <<std::endl;
    
    bk.TotalReceipt (std::cout);
    
    return 0;
    
}



