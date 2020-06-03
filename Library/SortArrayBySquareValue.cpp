//lambda makes its power seen

#include<iostream>

int main(){
	int size = 6;
	int A[] = {-7,-3,2,4,5,6};
	int SquareA[6] = {0};

	int i = 0, NewIndex = size - 1, EndIndex = size - 1;
	while(NewIndex >= 0){
		if(A[i]*A[i] > A[EndIndex]*A[EndIndex]){
			SquareA[NewIndex] = A[i]*A[i];
			++i;
			--NewIndex;			
		}
		else{
			SquareA[NewIndex] = A[EndIndex]*A[EndIndex];
			--NewIndex;
			--EndIndex;										
		}
	}
	
	for(int a: SquareA){
		std::cout<<a<<" ";
	}
	std::cout << std::endl;
	
	std::sort(std::begin(A),std::end(A), [](int a, int b) {return a*a < b*b;});
	std::for_each(std::begin(A), std::end(A), [] (int a) {std::cout<<a*a <<" ";});
	return 0;
}
