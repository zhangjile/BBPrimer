#include <iostream>
#include "employee.h"

int main()
{
    Employee One("Xu Zhang Run");
    std::cout<<One.GetName() <<", " <<One.GetID() <<std::endl;
    return 0;
}
