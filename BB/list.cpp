// Section 20 
//cause of problem:initialization list not implemented on Mobile C
//workaround:initialize in another way
// List

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> // for std::advance

//top 3 methods: emplace, emplace_back, emplace_front, 

class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person()=default;
    //Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) 
        : name{name}, age{age}  {}
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);//critical
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}


template <typename T>
void display(const std::list<T> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\nTest1 push_back, push_front===============" << std::endl;

    std::list<int> l1;
    for(int i=1; i<=5; ++i){
    	l1.push_back(i);
    }
    display(l1);
    
    std::list<std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);
    
    std::list<int> l3;
    l3 = {1,2,3,4,5,6,7,8,9,10};
    display(l3);
    
    std::list<int> l4 (10, 100);
    display(l4);
}

void test2() {
    std::cout << "\nTest2 front, back ======================" << std::endl;

    std::list<int> l;
    for(int i=1; i<=10; ++i){
    	l.push_back(i);
    }
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
    
    std::cout << "Front : " << l.front() << std::endl;
    std::cout << "Back  : " << l.back() << std::endl;
    
    l.clear();
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
}

void test3() {
    std::cout << "\nTest3 resize======================" << std::endl;

    std::list<int> l;
    for(int i=1; i<=10; ++i){
    	l.push_back(i);
    }
    display(l);
    
    l.resize(5); //nice
    display(l);
    
    l.resize(10);
    display(l);
    
    std::list<Person> persons;
    persons.resize(5);             // uses the Person default constructor
    display(persons);
    
}
void test4() {
    std::cout << "\nTest4, insert, advance=========================" << std::endl;

    std::list<int> l = {1,2,3,4,5,6,7,8,9,10};
    //std::list<int> l;
    //for(int i=1; i<=10; ++i){
    //	l.push_back(i);
    //}
    display(l);
    auto it = std::find(l.begin(), l.end(), 5);
    if (it != l.end()) {
        l.insert(it, 100);
    }
    display(l);
    
   // std::list<int> l2 {1000,2000,3000};
    std::list<int> l2;
    for(int i=1; i<=10; ++i){
    	l2.push_back(i);
    }
    l.insert(it, l2.begin(), l2.end());
    display(l);
    
    std::advance(it, -4);       // point to the 100
    std::cout << *it << std::endl;
    
    l.erase(it);                    // remove the 100 - iterator becomes invalid
    display(l);
    
}

void test5() {
    std::cout << "\nTest5, emplace, emplace_back, emplace_front===========" << std::endl;

    std::list<Person>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };    
    display(stooges);
    /*
    std::string name;
    int age{};
    std::cout << "\nEnter the name of the next stooge: ";
    getline(std::cin, name);
    std::cout << "Enter their age: ";
    std::cin >> age;    
    //stooges.emplace_back(name, age);
    stooges.emplace_front(name, age);
    // emplace_back expects name and age as parameter, it delegates the constructor and instantiates object and finally puts the object in the back of the list.
    
    display(stooges);
    */
    
    // Insert Frank before Moe
    auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
    //Finding an object? I tried this before:)
    if (it != stooges.end())
        stooges.emplace(it, "Frank", 18); //insert at specific place(before it)!
    display(stooges);    
}

void test6() {
    std::cout << "\nTest6, sort=========================" << std::endl;
    
    std::list<Person>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    
    display(stooges);
    stooges.sort();
    display(stooges);
}


int main() {
    
  	  test1();
      test2();
      test3();
      test4();	
    test5();
    test6();
    
    std::cout << std::endl;
    return 0;
}

/*
	// No direct access to elements.
	//iterator moves bi-directional: ++it; --it;
	//std::find, std::insert/emplace ->compared to set container
	//

*/
