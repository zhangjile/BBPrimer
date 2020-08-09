/*～～～～
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

～～～～*/
