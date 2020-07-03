// C++ program to implement interpolation search 
// Chapter 7 Code Reuse, Ex7.3, P274

#include <iostream> 
using namespace std; 
  
// If x is present in arr, returns index of it, else returns -1. 
int interpolationSearch(int arr[], int n, int x) { 
    int lo = 0, hi = (n - 1); 	 // indexes of two corners 
  
    // check the values of 2 corner elements against the target
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) { 
        if (lo == hi) { 
            if (arr[lo] == x) return lo; 
            return -1; 
        } 
        // Probing the position 
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo])); 
  
        if (arr[pos] == x) 	return pos; // Condition of target found  
        if (arr[pos] < x) 	lo = pos + 1; // If x is larger, x is in upper part   
        else	hi = pos - 1; 	// If x is smaller, x is in the lower part 
            
    } 
    return -1; 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    int x = 18; // Element to be searched 
    int index = interpolationSearch(arr, n, x); 
  
    if (index != -1) 	// If element was found 
        cout << "Element found at index " << index; 
    else
        cout << "Element not found."; 
    return 0; 
} 
  
// This code is contributed by Mukul Singh, from geekforgeek.com
// The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed. Binary Search always goes to the middle element to check. On the other hand, interpolation search may go to different locations according to the value of the key being searched. For example, if the value of the key is closer to the last element, interpolation search is likely to start search toward the end side.
