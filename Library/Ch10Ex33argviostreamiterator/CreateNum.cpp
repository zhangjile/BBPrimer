//a utility or an alternative implementation
//the same hidden bug appears again, and ironed again, with great confidence
//if num is created manually, OddNum and EvenNum are always blank 

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
using std::for_each;

void CreateNum(std::string num){
	std::ofstream source(num);
	std::istream_iterator<int> iter (std::cin), leo;
	std::ostream_iterator<int> out(source," ");
	for_each(iter, leo, [&](const int x){*out++ = x;});
}

int main() 
{
    CreateNum(std::string("Number_Matter"));
    /*
    //implementation using while loop
    std::ifstream number("Number_Matter");
    std::istream_iterator<int> iter (number), leo;
    std::ofstream odd("o"), even("e");
    std::ostream_iterator<int> out_odd (odd, " "), out_even(even, "\n");
   
    while(iter != leo){
    	std::cout << *iter <<std::endl;
    	if(*iter & 0x1) out_odd = *iter++;
    	else out_even = *iter++;
    } 
    */
    return 0;
}
