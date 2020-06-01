// Use the function you wrote for the first exercise in § 8.1.2 (p.314) to print the contents of an istringstream object.

#include <iostream>
#include <sstream>
using std::istream;

istream& func(istream &is)
{
    std::string buf;
    // char buf; //one character a line:)
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear(); //good defense
    return is;
}

int main()
{
    std::istringstream iss("C++ is a great programming language");
    func(iss);
    return 0;
}
