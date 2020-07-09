//Chapter 13 Copy Control
//Ex13.18, p510 Define an Employee class that contains an employee name and 
// a unique employee identifier. Give the class a default constructor 
// and a constructor that takes a string representing the employee's name. 
// Each constructor should generate a unique ID by 
// incrementing a static data member
// first time that i write code in a text editor instead of an IDE:)

#include <iostream>
#include <string>

using std::string;

class Employee
{
static int IDGenerator;
public:
    //disable default synthesized constructor, 
    //disable copy constructor and 
    //disable copy assignment operator
    Employee () = delete;   //disabled
    Employee (string name) : EmployeeName {name}, EmployeeID(++IDGenerator) {}
    Employee (const Employee& ob) = delete;     //disabled
    Employee& operator= (const Employee& ob) = delete;  //disabled
    
    string GetName() {return EmployeeName;}
    int GetID() {return EmployeeID;}
private:
    string EmployeeName;
    int EmployeeID;
};

int Employee::IDGenerator = 0;

int main()
{
    Employee One("Xu Zhang Run");
    std::cout<<One.GetName() <<", 00" <<One.GetID() <<std::endl;
    return 0;
}
