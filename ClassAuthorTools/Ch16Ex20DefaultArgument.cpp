//This is test code for the example in p671

#include <iostream>

template<typename T = int> class Number{
public:
	Number (T v = 0) : val(v) {}
	//T Get() const {return val;}
	T Get() const;
private:
	T val;
};

template<typename T>	//wow!
T Number<T>::Get() const {
	return val;
	}

int main () {	
	Number<long double> high(2020.88);
	std::cout << high.Get() <<std::endl;
	Number <> aver(2020);	//2020.88, warning, implicit conversion, haha
	std::cout << aver.Get() <<std::endl;
	
	return 0;
}
