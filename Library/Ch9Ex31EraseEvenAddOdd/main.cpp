//9.36 Container operations may invalidate iterators, p354
//Ex 9.31 implement same operations using list and forward_list
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
using std::vector; using std::list; using std::forward_list;

//traverse a vector<int>, erase the even elements and add duplicate of each odd after itself
void EraseEvenAddOddDuplicate (vector<int> &vi){
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

//insert an int 0 after each element of a vector<int>

void Insert42(vector<int> &vi){
	auto Begin = vi.begin();
	while (Begin != vi.end()){
		++Begin;
		Begin = vi.insert(Begin, 0);
		++Begin;
	}
}

void ListEraseEvenAddOdd (list<int> &li){
	list<int>::iterator it = li.begin();
	while(it != li.end()){
		if(*it % 2) {
			li.insert(it, *it); //it is fresh and valid
			++it;
		}
		else it = li.erase(it); //refresh it is a must
	}
}

void ForwardListEraseEvenAddOdd (forward_list<int> &fi){
	forward_list<int>::iterator prev = fi.before_begin();
	auto curr = fi.begin();
	while(curr != fi.end()){
		if(*curr % 2) {
			curr = insert_after(curr, *curr);
			prev = curr;
			++curr;
		}
		else{
			curr = fi.erase_after(prev);
		}
	}
}


int main (){
	vector<int> v = {1,2,3,4,5,6,7,8};
	list<int> li;
	li.assign(v.begin(), v.end()); //play with assign
	forward_list<int> fi;
	fi.assign(v.begin(), v.end());
	
	EraseEvenAddOddDuplicate(v);
	for(const int &e : v){
		std::cout<< e << " ";
	}
	std::cout << std::endl;
	
	Insert42(v);
	for(const int &e : v){
		std::cout<< e << " ";
	}
	std::cout << std::endl;
	
	ListEraseEvenAddOdd(li);
	for(const int &e : li){
		std::cout<< e << " ";
	}
	std::cout << std::endl;
	
	ForwardListEraseEvenAddOdd(fi);
	std::cout << std::endl;
	
	return 0;
}