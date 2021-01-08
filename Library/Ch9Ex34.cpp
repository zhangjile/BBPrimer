//  Chapter 9, Ex32,  Assuming vi is a container of ints that includes even and odd values, predict the behavior of the following loop. 
//  After you've analyzed this loop, write a program to test whether your expectations were correct.
//			
//	  iter = vi.begin(); 
//	  while (iter != vi.end())    
//		if (*iter % 2)        
//			iter = vi.insert(iter, *iter);    
//		++iter; 
//
//  @Answer "infinite loop". Becasue the `++iter` is outside of the scope of the `while` loop.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for(auto cur = data.begin(); cur != data.end();){
        if(*cur & 0x1){
//          cur = data.insert(cur, *cur), ++cur;	//pezy, nice line
    		cur = data.insert(cur, *cur);	//my pitch
    		++cur;
    	}
    	++cur;
 	}
    for (auto i : data)
        cout << i << " ";

    return 0;
}
