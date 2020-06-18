#include <iostream>		//matrix mulplication demystified
using namespace std;
int main() {
   int product[10][10] = {0};
   /*
   int r1=3, c1=3, r2=3, c2=2, i =0, j =0, k =0;
   int a[3][3] = { {2, 4, 1} , {2, 3, 9} , {3, 1, 8} };
   int b[3][3] = { {2, 3} , {3, 6} , {4, 7} };
   */
   
   int r1=5, c1=3, r2=3, c2=2, i =0, j =0, k =0;
   int a[5][3] = { {2, 4, 1} , {2, 3, 9} , {3, 1, 8}, {100,7,5}, {200,8,9}};
   int b[3][3] = { {2, 3} , {3, 6} , {4, 7} };
   if (c1 != r2) {
   		cout <<"wrong" <<endl;
   }
   cout <<"matrix one:" <<endl;
   for(size_t i = 0; i < r1; ++i){
   		for(size_t j = 0; j < c1; ++j){
   			std::cout<<a[i][j] <<" ";
   		}
   		std::cout<< std::endl;
   }
   
   cout <<"matrix two:" <<endl;
   for(size_t i = 0; i < c1; ++i){
   	   for(size_t j = 0; j < c2; ++j){
   			std::cout<<b[i][j] <<" ";
   	   }
   	   std::cout<< std::endl;
   }
   
   for(i=0; i<r1; ++i){
        for(j=0; j<c2; ++j){
            for(k=0; k<c1; ++k) {
               product[i][j]+=a[i][k]*b[k][j];
            }
        }
    } 
    cout<<"Product of the two matrices is:"<<endl;
    for(i=0; i<r1; ++i) {   
         for(j=0; j<c2; ++j){
            cout<<product[i][j]<<" ";
         }
         cout<<endl;
    }   
   return 0;
}

