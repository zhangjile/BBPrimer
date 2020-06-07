//Chapter 10.4.2 iostream iterators 
//Ex10.33 write a program that takes the names of an input file and two output files.
// the input file should hold integers. using istream_iterator read the input file
// using ostream_iterator write the odd numbers into the first output file, each value should be followed by a space
// write the even numbers into the second file, each of these values should be placed on a seperate line.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

int main(int argc, char **argv) {
    if(argc != 4) return -1;
    std::ifstream ifs(argv[1]);
    std::istream_iterator<int> is_iter (ifs), eo;
    std::ofstream os_odd(argv[2]), os_even(argv[3]);
    std::ostream_iterator<int> osi1 (os_odd, " "), osi2(os_even, "\n");
    for_each(is_iter, eo, [&osi1, &osi2](const int x){*((x % 2 == 0) ? osi1 : osi2)++ = x;} );
    
    return 0;
}