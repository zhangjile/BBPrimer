//cppnuts
#include <iostream>

class Base{
	int x;
//	mutable int x;
public:
	void setx(int a){x = a;}
	int getx(){return x;}
//	int getx() const {x = 100; return x;}	//works as expected if x is mutable
//	int getx() const {return x;}
};

int main (){
	Base b;
	b.setx(10);
	std::cout <<b.getx() <<"\n";
	return 0;
}

/*
Question3: what is constant member function?
a const member function promises not to change the data member
a mutable data is exempted from the restriction and can be modified in a const member function
*/
