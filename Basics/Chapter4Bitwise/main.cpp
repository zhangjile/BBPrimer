//Chapter 4.8 bitwise operator p 152
#include <iostream>

int MarkFifth(){
	int Quiz = 0;
	Quiz |= 1<<4;    //00001 --> 10000
	return Quiz;
}

bool IsOdd(int x) { //new math lesson
	return x & 1;
}

void Swap (int& x, int& y){ //XOR is amazing
	x = x ^ y;   // see everything on paper with an example: x=1 (01); y=3(11)
	y = x ^ y;
	x = x ^ y;
}

int main (){
	std::cout << MarkFifth() <<std::endl; // |=, bitwise compound assignment, love
	
	//shift
	int a = 5;
	a = a<<1; // a << 1 means a*2
	a <<= 1;
	std::cout << a <<std::endl;
	
	//~ tilda is NOT
	int m = 'q'; 
	std::cout << m <<std::endl;
	std::cout << int('q') <<std::endl; 
	std::cout << "Is odd: " <<IsOdd(m)<< std::endl;
	unsigned long n = ~'q' <<6; 			//18446744073709544320
	std::cout << n <<std::endl;
	std::cout << "Is odd: " <<IsOdd(n)<< std::endl;
	
	std::cout << char(0145) <<std::endl;
	std::cout << int('e') <<std::endl;   //e(char) = 101(decimal) = 145(octal)
	
	int p = int('e');
	Swap(p,m);
	std::cout << p <<std::endl;
	return 0;
}
