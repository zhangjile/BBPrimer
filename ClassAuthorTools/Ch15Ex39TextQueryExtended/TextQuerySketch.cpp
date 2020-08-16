/*
I've figured out the solution plan today
set<size_t> line_numbers_All, line_numbers_A, line_numbers_B;

//calculate the following desired set<size_t> obj out of 3

!line_numbers_A = all_line_numbers - line_numbers_A;

A&B = line_numbers_A && line_numbers_B
A | B = line_numbers_A || line_numbers_B 

A & B | C
first, 'A & B' return a reference to set<size_t> obj
then, obj | C

1.make QueryResult virtual,
2.create 3 derived classes representing 4 types of calculation.
3.declare MyString as friend of QueryResult hierarchy;
4.overload 3 operators of MyString: ~, &, |, 

*/

#include <iostream>

/*
//I find the difference of modifying code and writing original code based on an original design for a problem.
//writing original code requires construction stage, in the same way as drawing that takes major parts into consideration before coding.
//Just as Anton Spraul said, take the time to draw before coding
*/

int main ()
{
    return 0;
}

//don't spend more than 30 minutes on one issue which means it's too much above you, read the clues and move on
// Errichto