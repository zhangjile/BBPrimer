//Section 16.2.6 Understanding std::move
//Ex16.46 p692, Explain this loop from StrVect::reallocate in $13.5
//for(size_t i = 0; i<size(); ++i){
//  alloc.construct(desti++, std::move(*elem++));
//the content in *elem is taken away}

#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
typename std::remove_reference<T>::type&& Move(T&& source){
    return static_cast<typename std::remove_reference<T>::type&&>(source);
}

int main(){
    std::string s1 ("Hi"), s2;
    s2 = std::move(std::string("Hello"));
    std::cout << s2 << std::endl;
    s2 = std::move(s1);
    std::cout << s2 << std::endl;
    s2 = std::move("WTF!");
    std::cout << s2 << std::endl;

    return 0;
}
