//chapter 9.4 How a vector grows 
//Ex 9.38: write a program to explore how vectors grow in the library you use. P359
#include <iostream>
#include <vector>
using std::vector;

void VectorGrow();

int main (){
	vector<int> vi = {1,2,3};
	std::cout << vi.capacity() <<std::endl;	//3
	vi.resize(5);
	std::cout << vi.size() << std::endl;	//5
	std::cout << vi.capacity() <<std::endl;	//6
	for(const auto e : vi){
		std::cout<< e <<std::endl;
	}
	vi.reserve(50);
	std::cout << vi.capacity() <<std::endl;	//50
	return 0;
}