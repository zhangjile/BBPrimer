//Chapter 10.4.2 iostream iterators 
//Ex10.33 write a program that takes the names of an input file and two output files.
// the input file should hold integers. using istream_iterator read the input file
// using ostream_iterator write the odd numbers into the first output file, each value should be followed by a space
// write the even numbers into the second file, each of these values should be placed on a seperate line.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
using std::for_each;

int main(int argc, char **argv) 
{
   // if(argc != 4) return -1;
    
    std::ifstream ifs(argv[1]);
    std::istream_iterator<int> is_iter (ifs), leo;
    std::ofstream os_odd(argv[2]), os_even(argv[3]);
    std::ostream_iterator<int> osi_odd (os_odd, " "), osi_even(os_even, "\n");
    
    for_each(is_iter, leo, [&osi_odd, &osi_even](const int x){
        *((x % 2 == 0) ? osi_even : osi_odd)++ = x;
    });
    
    return 0;
}