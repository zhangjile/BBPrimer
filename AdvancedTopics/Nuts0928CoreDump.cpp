//orchestrate a core dump resulted from sigseg fault, debug it using commands
//generosity of Selik Samai

#include <iostream>

void PointerSeg (){
    int value = 10;
    int *p = 0;
    std::cout << "The value of p is " <<*p <<"\n";
    
}

void ArraySeg(){
    int arr[10];
    int count = 20;
    for(int i = 0; i<count; ++i){
    	arr[i] = i*10;
        std::cout << arr[i] << "\n";
        //there's no crash on Mobile C, LOL	
    }
}

int main (){
    PointerSeg();
    ArraySeg();
    return 0;
}

//g++ -g nut.cpp
//set var p = &value
