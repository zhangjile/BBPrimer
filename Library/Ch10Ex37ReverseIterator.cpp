//Ch10Ex36, Use find to find the last element in a list of ints with value 0
//Ch10Ex37, p410, Given a vector that has 10 elements, copy the elements from position 3 through 7 in reverse order to a list.
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

void Display(std::list<int> v){
	auto iter = v.cbegin();
	while(iter != v.cend()){
		std::cout << *iter << " ";
		++iter;
	}
}
int main(){
	//Ex36
	std::list<int>l;
	l = {1,2,0, 3,8,0,4};
	//big error,arithmetic operation not supported, 
	//iterator in list is forward list, not random access
	//l.insert(l.begin()+3, 0);	
	l.insert(prev(l.begin(),-3), 5);	
	auto iter = find(l.rbegin(), l.rend(),0);
//	std::cout << *++iter << std::endl;	//confirmed!
	std::cout <<std::distance(l.rbegin(), ++iter)<<std::endl;
	std::cout <<std::distance(l.rbegin(), l.rend())<<std::endl;
	
	
	std::vector<int> v {1,2,3,4,5,6,7,8,9,10};
//	sort(v.rbegin(),v.rend());
	std::list<int> lst;
	std::copy(v.rbegin() + 2, v.rend()-3, back_inserter(lst));
	Display(lst);
	
	return 0;
}
