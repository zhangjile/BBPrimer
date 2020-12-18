#include <iostream>
#include <string>
#include <vector>
#include <random>

int main (){
    static std::default_random_engine e;
    static std::normal_distribution<> n(4,1.5);
    std::vector<unsigned> ind (9);
    for(size_t i=0; i<100; ++i){
        unsigned v = lround(n(e));
        if(v < ind.size()){
            ++ind[v];
        }
    }
    for(size_t i=0; i<9; ++i){
        std::cout <<i <<": "<< std::string (ind[i],'*') << std::endl;
    }
}