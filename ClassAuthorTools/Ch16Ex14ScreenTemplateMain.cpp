//
//  ex7_27_TEST.cpp
//  Test of Exercise 7.27
//
//  Created by pezy on 11/14/14.
//

#include "Ch16Ex14ScreenTemplate.h"

int main()
{
    Screen<5,20> myScreen('X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    
	std::cin>>myScreen;
    std::cout << myScreen;
	
	return 0;
}
