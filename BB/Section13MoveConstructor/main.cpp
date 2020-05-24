// Section 13
// Move Constructor 
#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    
    Move(int d);   // Constructor
    Move(const Move &source); 	// Copy constructor
    Move(Move &&source) noexcept;    //move constructor
    ~Move();
};
	
Move::Move(int d)  {
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

Move::Move(const Move &source)
   // : Move {*source.data} {
   	{
   		data = new int;
   		*data = *source.data;
        cout << "Copy constructor  - deep copy for: " << *data << endl;
}


	// SPEECHLESS with the move constructor! Supramacy.
Move::Move(Move &&source) noexcept 
    //: data {source.data} {
    	{data = source.data;
        source.data = nullptr;	//!!!null out data member of source object, remove cross-linking !!!
        cout << "Move constructor - moving resource: " << *data << endl;
}

	// Destructor
Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

int main() {
	
	cout << "R-value reference" <<endl;
	
	int num {100};
	int &n_ref = num;
	n_ref = 8;
	
    cout << num <<endl;
	cout << &n_ref <<endl;
	
	int &&r_ref = 800;
	r_ref =8000;
	cout <<&r_ref <<endl;
	cout << r_ref <<endl;
	
	cout << "testing R-value reference completed" <<endl;	
	cout <<endl;
	
    vector<Move> vec;

    vec.push_back(Move{10});
   // vec.push_back(Move{20});
    //vec.push_back(Move{30});
    //vec.push_back(Move{40});
    //vec.push_back(Move{50});
  //  vec.push_back(Move{60});
   // vec.push_back(Move{70});
    //vec.push_back(Move{80});


    return 0;
}

