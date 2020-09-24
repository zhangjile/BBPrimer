//CppNuts, class design::function hiding
/*
Question: what is data hiding?
1) If a function inherited from the Base has the same name as one in Derived, then the inherited function is hidden by the one in the Derived, it's hidden and invisible, it's unreachable by Derived objects, and is practically invisible to Derived class.
2) a helper function usually should be detached from interface, keep it hidden and free from casual mistakes, ie, designate it as private.
keyword: name lookup, overloading, using expression, function matching, scope resolution operator ::, sniper's techniques:)

cf Section 7.4 class scope, p282


*/

/*
//test 1
#include <iostream>

class Base{
public:
	void fun(int i){
		std::cout << "Base\n";
	}
};

class Derived : public Base {
public:
	void fun(char c){
		std::cout <<"Derived\n";
	}
};

int main (){
	Derived d;
	d.fun(1);	//"Derived", name lookup rule, Base::fun is hidden.
	d.fun('a');	//"Derived"
	return 0;
}

*/

/*
//test 2
#include <iostream>

class Base{
public:
	void fun() {std::cout << "Base::void\n";}
	void fun(int i){
		std::cout << "Base\n";
	}
};

class Derived : public Base {
public:
	using Base::fun;	//bring Base::fun in the scope of the derived class
	void fun(char c){
		std::cout <<"Derived\n";
	}
};

int main (){
	Derived d;
	d.fun(1);	//"Base"
	d.fun('a');	//"Derived"
	d.fun();	//"Base::void"
	return 0;
}

*/


//test 3
#include <iostream>

class Base{
public:
	void fun(int i, int j){std::cout << "Base:int, int\n";}
	void fun(int i){
		std::cout << "Base\n";
	}
};

class Derived : public Base {
public:
	void fun(char c){
		std::cout <<"Derived\n";
	}
};

int main (){
	Derived d;
	d.Base::fun(1);	//"Base", specifying fun in Base scope to be used here
	d.fun('a');	//"Derived"
//	d.fun(1,2);	//error, the matching Base::fun(int,int) is hidden by Derived::fun
	return 0;
}
