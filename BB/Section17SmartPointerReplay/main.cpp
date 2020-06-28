//replay the smart pointer chanllenge in BB course
//Smart Pointer is among top 5 fundamentals of modern C++, it encapsulates raw pointers, which is a huge deal
#include <iostream>
#include <vector>
#include <memory>
using std::vector; using std::unique_ptr; using std::make_unique; using std::shared_ptr; using std::make_shared; using std::cout; using std::endl; using std::cin;

class Test
{
public:
	Test () :data(0) {}
	Test (int x) : data (x) {cout <<"\tconstructor called for " << data <<endl;}
	int get() {return data;}
	~Test () {cout << "\tTest destructor called for " << data << endl;}
private:
	int data;
};

typedef unique_ptr<vector<shared_ptr<Test>>> UPVS;

UPVS CreateUP (){
	return make_unique<vector<shared_ptr<Test>>> ();
}
void fill(vector<shared_ptr<Test>>& u, int items){
	int d {};
	for(int i = 1; i <= items; ++i){
		cout<< "item [" << i <<"]: "<<endl;
		cin >>d;
		//u.push_back(make_shared<Test> (Test (d)));	//compare!
		u.push_back(make_shared<Test> (d));
	}	
}

void Display(const UPVS& u){
	cout << "Displaying the vector:"<<endl;
	cout << "----------------------"<<endl;
	for(const auto &e : *u){
		cout << e->get() << endl;
	}
	cout << "----------------------"<<endl;
}

int main ()
{
	UPVS ptr = CreateUP ();
	int items {};
	cout << "How many data items? " <<endl;
	cin >>items;
	fill(*ptr, items);
	Display(ptr);
	
	return 0;
	
}
