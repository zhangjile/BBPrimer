//this is a proof of law of large number
#include <iostream>
#include <random>
#include <string>
using namespace std;

void Percentage (size_t N=1000){
    default_random_engine e;
    normal_distribution<> r(9,1);
    size_t count = 0;
    for(size_t i=0; i != N; ++i){
        double v = r(e);
//        cout << v << endl;    //uncomment this line
//if you wish to display randoms numbers(no more than 1000 please)
        if(v>8 && v<10){
            ++count;
        }        
    }
    double percent = static_cast<double>(count)/N;
    cout << percent <<endl;
}

int main()
{
    int i = 0;
    while(cin >> i && i != 'q'){    //enter 'q' to exit
            Percentage(i);
    }
    
    return 0;
}