//Chapter 17.2 The Bitset Type, Ex17.9, p725
//Explain the bit pattern of the following bitset objects contains

#include <iostream>
#include <string>
#include <bitset>

int main(){
	std::bitset<64> bv1(32);		//32 is a  decimal number by default
	std::cout << bv1 <<std::endl;
	
	std::bitset<64> bv2(1010101);
	std::cout << bv2 <<std::endl;
	
//	std::string bstr;
//	std::cin >> bstr;	//0 1 only
//	std::bitset<8> bv(bstr);
//	std::cout << bv;
	return 0;
}