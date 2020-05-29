//Chapter 5.6 Try block and exception handling
//Ex. 5.23 write a program that reads 2 integers from the stdin and prints the result of dividing the first by the second
//Ex 5.24 throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don't catch it.
//Ex 5.25 Revise your program from the previous exercise to use a try block to catch exception. The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.
//this piece is written in vim:)
#include <iostream>

class DivideByZero : public std::runtime_error{
public:
	DivideByZero ():runtime_error("Can't divide by zero"){}
};

int main(){
	double a{0},b{0};
	try{
		std::cin >> a >> b;
		if(b==0) throw DivideByZero ();
	}catch(const DivideByZero &ex){
		std::cerr << ex.what() <<std::endl;
	}
	std::cout << a/b << std::endl; //10/0 inf NaN
	
	return 0;
}

