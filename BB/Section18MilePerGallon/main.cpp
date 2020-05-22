// Section 18
// Miles per Gallon - Function - Exception Classes - Inheritance
// exceptions cannot be handled on Mobile C
// I see exception handling finally 22/05/2020

#include <iostream>

class DivideByZeroException : public std::runtime_error  {
public:
    DivideByZeroException() : std::runtime_error {"Cannot divide by zero"}
    {}//this constructor is cool
};
class NegativeValueException : public std::runtime_error {
public:
    NegativeValueException() : std::runtime_error {"one of your parameters is negative"}
    {}
};

double calculate_mpg(int miles, int gallons) {
    if (gallons == 0)
        throw DivideByZeroException();
    else if (miles < 0 || gallons < 0)
        throw NegativeValueException();
    return static_cast<double>(miles) / gallons;
}

int main() {    
    int miles {};
    int gallons {};
    double miles_per_gallon {};   
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;

    } catch (const DivideByZeroException &ex) {
        std::cerr << ex.what() << std::endl;
    } catch (const NegativeValueException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;
}

