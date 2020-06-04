//lambda makes its power seen
//this is an amazon interview problem: sort an array of integers according to the square value of elements and display the array
#include<iostream>
#include <algorithm>

int main(){

	/*
	int size = 6;
	int A[] = {-7,-3,2,4,5,6}; //sort by face value of elements 
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
*/
	int B[] = {7,3,-5,4,2,6};
	std::sort(std::begin(B),std::end(B), [](int a, int b) {return a*a < b*b;});
	std::for_each(std::begin(B), std::end(B), [] (int a) {std::cout<<a*a <<" ";});
	return 0;
}
