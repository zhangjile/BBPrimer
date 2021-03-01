//Chapter 13 Copy Control
//Ex13.18, p510 Define an Employee class that contains an employee name and 
// a unique employee identifier. Give the class a default constructor 
// and a constructor that takes a string representing the employee's name. 
// Each constructor should generate a unique ID by 
// incrementing a static data member
// first time that i write code in a text editor instead of an IDE:)
// refactor: define a class in a .h instead

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
    static int IDGenerator;
public:
    Employee (): EmployeeID{++IDGenerator}{}  
    Employee (std::string name) : EmployeeName {name}, EmployeeID(++IDGenerator) {}
    
    //disable copy constructor and copy assignment operator
    Employee (const Employee& ob) = delete;     
    Employee& operator= (const Employee& ob) = delete;  
    
    std::string GetName() {return EmployeeName;}
    int GetID() {return EmployeeID;}
private:
    std::string EmployeeName;
    int EmployeeID;
};

int Employee::IDGenerator = 0;

#endif //EMPLOYEE_H