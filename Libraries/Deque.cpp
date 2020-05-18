//client code
#include "Deque.h"


int main()
{
	//create a sample list
	Deque l;
	l.Append(1);
	l.Append(2);
	l.Append(3);
	l.Append(100);
	l.Prepend(10);
	
	//display the list, it's a string of ints, but it's organized under the hood 
	l.ToString(); 
	l.RemoveFirst();
	l.ToString();
	std::cout<<l.GetSize()<<std::endl;
	
	//a short video showing how the machine works.
	l.RemoveLast();
	l.RemoveAt(2);
	l.ToString();
	l.InsertAt(200,2);
	l.ToString();
	std::cout<<l.GetSize()<<std::endl;
	
	return 0;
}
