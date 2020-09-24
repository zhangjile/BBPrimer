//CppNuts, class design::data hiding
/*
Question: what is data hiding?
data hiding is specifying the access level as private or protected to a specific data member.
data hiding is not about hacking or something, it's about correctness of expression and preventing a data member from being changed accidentally.
*/
//play with 100+ classes, something like getting the storyline of 100 movies

#include <iostream>

class ABCPlayer{
private:
	int volume;
public:
	ABCPlayer () :volume(0){}
	void set_volume(int a){
		if(a >= 0 && a < 100){
			volume = a;
			std::cout << "set" <<"\n";
		}
		else {
			std::cout << "not set" <<"\n";
		}
	}
	int getv(){return volume;}
};

int main (){
	ABCPlayer ob1;
	ob1.set_volume(200);
	std::cout << ob1.getv() << std::endl;
	ob1.set_volume(20);
	std::cout << ob1.getv() << std::endl;
	return 0;
}

// test and see what happens if default constructor is not provided
// the program displays 20 twice, the output speaks out everything