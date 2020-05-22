//9.36 Container operations may invalidate iterators, p354
#include <iostream>
#include <vector>
using std::vector;

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

template <typename T>
void Display(vector<T> vt){
	for(const auto &e : vt){
		std::cout << e << " ";
	}
	std::cout << std::endl;
}


int main (){
	vector<int> v = {1,2,3,4,5,6,7,8};
	EraseEvenAddOddDuplicate(v);
	for(const int &e : v){
		std::cout<< e << " ";
	}
	std::cout << std::endl;
	
	Insert42(v);
	Display<int>(v);
	return 0;
}