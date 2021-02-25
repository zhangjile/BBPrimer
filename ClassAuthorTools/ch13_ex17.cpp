
//  Exercise 13.17
//  Write versions of numbered and f corresponding to the previous three exercises
//  and check whether you correctly predicted the output.

#include <iostream>

class numbered {
public:
    numbered() {
        mysn = unique++;
    }
    
    //a better match, implicit conversions under the hood
    // synthesized copy ctor is still a better match than 'operator='
    numbered(const numbered& rhs){mysn = rhs.mysn +1;}
    
    //not called!
    numbered& operator=(const numbered& rhs) {
    	std::cout << "=" << std::endl;
    	mysn = rhs.mysn +1; 
    	return *this;
    }

    int mysn;
    static int unique;
};

int numbered::unique = 10;

//if 'void f( numbered s)', f(a) == 11
//because a is copied into s and mysn is incremented
void f(const numbered& s) {
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    
    f(a);   //10       
    f(b);
    f(c);
}
