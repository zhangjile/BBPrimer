//Chapter 10.3.3 Lambda captures and returns
//Ex10.21 decrement a number using lambda
#include <iostream>

//Ex10.21
void LargerThanZero(int UpperBound){
	if(UpperBound < 0) {
		LargerThanZero(-UpperBound);
	}
	if(UpperBound == 0) return;
	while(UpperBound > 0) {
		//good chance to see how prefix and postfix decrement work.
		auto f1 = [&UpperBound] {std::cout << --UpperBound << std::endl;};
		//auto f2 = [&UpperBound] {std::cout << UpperBound-- << std::endl;};
		f1();
		//f2();
	}
}

//parameter list cannot be ommitted with mutable
int Mutable (int Local){
	auto f = [Local]() mutable {return ++Local;};
	Local = 100;
	return f();
}

//capture by reference
int CaptureByReference(int Local){
	auto f = [&Local]() mutable {return ++Local;};
	Local = 100;
	return f();
}


int main(){
	int p = 3.14;
	LargerThanZero(p);
	std::cout << Mutable(p) << std::endl;
	std::cout << CaptureByReference(p) << std::endl;	//101, not surprising:)
	return 0;
}
