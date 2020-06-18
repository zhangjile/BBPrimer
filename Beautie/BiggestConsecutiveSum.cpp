//problem: find the Max sum of consecutive elements in an array
#include <iostream>

//finally it's done, because the logic is much more straight-forward!
int CadaneV2 (int *A, size_t s){
	std::cout << "Real Cadane Algorithm" <<std::endl;
	int MaxSum = 0;
	int CurrentSum = 0;
	for(size_t i = 0; i < s; ++i){
		if(A[i] + CurrentSum > 0){
			CurrentSum += A[i];
		}
		MaxSum = CurrentSum > MaxSum ? CurrentSum : MaxSum;
		std::cout << MaxSum <<std::endl;
	}
	return MaxSum;
}

//Nick White's implementation, good
int Cadane(int *A, size_t s){
	std::cout << "Nick's Cadane" <<std::endl;
	int MaxSum = A[0];
	int CurrentSum = MaxSum;
	for(size_t i = 1; i < s; ++i){
		CurrentSum = (A[i] + CurrentSum > A[i] ? A[i] + CurrentSum : A[i]);
		MaxSum = CurrentSum > MaxSum ? CurrentSum : MaxSum;
		std::cout << MaxSum <<std::endl;
	}
	return MaxSum;
}


//this is a draft
//the concept is, recalculate running sum when a negative is spotted by resetting the CurrentSum, it's incomplete because many cases are not taken into consideration and eventually wrong.

void SplitMethod(int *A, size_t s){
	int RunningSum = 0, LargestSum = 0;
	for(int i = 0; i < s; ++i){
		if(A[i] >= 0){
			RunningSum += A[i];
		} else {			
			if(RunningSum >LargestSum){
				LargestSum = RunningSum;
			} 
			RunningSum = 0;			
		}
	}
	if(RunningSum >LargestSum)
		LargestSum = RunningSum; 
	std::cout<< LargestSum << std::endl;
	
}

int main()
{
	//	int A[size] = {1,2,3,-1,5,6,-1,8};
	// int A[] = {-2,2,5,-11,6,-1,4};
	int A[] = {6,-2,-2,3,-1,5,-1,6,-2,1};
	size_t s = sizeof(A)/sizeof(A[0]);
//	SplitMethod(A,s);
	Cadane(A,s);
//	CadaneV2(A,s);
	return 0;
}
