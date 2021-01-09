//Chapter 9.3.6 Container operations may invalidate iterators,
//Ex 9.31, p356, the program on p354 to remove even-valued elements and duplicate odd ones will not work on a list or forward_list. Why?
//implement same operations using list and forward_list
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using std::vector; using std::list; using std::forward_list;

//traverse a vector<int>, erase the even elements and add duplicate of each odd after itself
void EraseEvenAddOdd (vector<int> &vi){
	vector<int>::iterator iter = vi.begin();
	while(iter != vi.end()){
		if(*iter % 2){
			iter = vi.insert(iter,*iter);
			iter += 2;
		}
		else {
			iter = vi.erase(iter);
		}
	}
}

void EraseEvenAddOdd (list<int> &li){
	list<int>::iterator it = li.begin();
	while(it != li.end()){
		if(*it % 2) {
			//it = li.insert(it, *it)' modifies node li points to!
			li.insert(it, *it); 
			++it;
		}
		//a node object in a list has two pointer members: left, right
		else it = li.erase(it); 
	}
}

void EraseEvenAddOdd (forward_list<int> &fi){
	forward_list<int>::iterator prev = fi.before_begin();
	auto curr = fi.begin();
	while(curr != fi.end()){
		if(*curr % 2) {
			curr = fi.insert_after(curr, *curr);
			prev = curr;
			++curr;
		}
		else{
			curr = fi.erase_after(prev);
		}
	}
}

template<typename T>
void Display(const T& t){
	for(const auto& e:t){
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

int main (){
	vector<int> v = {1,2,3,4,5,6,7,8};
	list<int> li;
	li.assign(v.begin(), v.end()); //play with assign
	forward_list<int> fi(v.begin(), v.end()); //initialization
	
	EraseEvenAddOdd(v);
	Display(v);
	
	EraseEvenAddOdd(li);
	Display(li);
	
	EraseEvenAddOdd(fi);
	Display(fi);
	
	return 0;
}
