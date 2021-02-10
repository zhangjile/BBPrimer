//Ch12Ex26, p484, Rewrite the program on page 481 using an allocator

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using std::string;
typedef std::unique_ptr<string> ups; using std::vector; using std::allocator;

//the allocator class, p481
void new_alloc_initi (int n){
	string *p= nullptr;
	p = new string[n];
	string *q = p;
	string s;
	while(std::cin >> s && q!= p+n)
		*q++ = s;
	const size_t size = p-q;
	for(size_t i = 0; i < p-q; ++i){
		std::cout << p[i] << ", ";
	}
	std::cout << std::endl;
	delete[] p;
}

void alloc_only(int n){
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	auto q = p;
	string s;
	
//	while(std::cin >> s && s != "q" && q!= p+n) //short-circuit evaluation
	while(s != "q" && q!= p+n && std::cin >> s)
		alloc.construct(q++,s);
	const size_t size = q-p;
	for(size_t i = 0; i < q-p; ++i){
		std::cout << *(p+i) << " ";
	}
	std::cout << std::endl;
	
	while(q != p){
		alloc.destroy(--q);
	}
	
	alloc.deallocate(p, n);
	
}

void alloc_example (){
	allocator<int> alloc;
	auto const p = alloc.allocate(10);	//const specifier is significant
	auto q = p;
	alloc.construct(q++, 1);
	alloc.construct(q++, 9);
	alloc.construct(q++, 8);
	alloc.construct(q++, 9);
	std::cout << *p << std::endl;
	
	q = std::uninitialized_fill_n(q,3,6);
	std::uninitialized_fill_n(q,3,4);
	std::cout << *q << std::endl;
	while(q != p){
		alloc.destroy(--q);
	}
	alloc.deallocate(p, 10);
}

int main(){
//	experimentP470();
//	alloc_example();
	int n = 5;
	alloc_only(n);
	return 0;
}

