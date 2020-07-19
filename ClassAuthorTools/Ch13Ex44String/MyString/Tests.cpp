#include "MyString.h"

#include <iostream>
#include <vector>

int main (){
	MyString a;
	MyString b("Yan Li Meng");	// 閆麗夢
	a = b;
	MyString c(b);
	std::cout <<b.back() <<std::endl;
	std::cout <<b.size() <<std::endl;
	std::vector<MyString> vms;
	vms.reserve(10);
	vms.push_back(a);
	vms.push_back(b);
	vms.push_back(c);	
	vms.push_back(MyString("Hero"));
	std::cout <<vms.size() <<std::endl;
	
	return 0;
	
}
