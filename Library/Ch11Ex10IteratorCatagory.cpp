// Exercise 11.10:
// Could we define a map from vector<int>::iterator to int? What about from list<int>::iterator to int? In each case, if not, why not?

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

int main()
{
    std::map<std::vector<int>::iterator, int> mv;
    std::map<std::list<int>::iterator, int> ml;

    //  vector<int>::iterator to int is ok , because < is defined, vector<T>::iterator is random access iterator or lower (p412)
    std::vector<int> vi;
    mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));

    //  list<int>::iterator to int is not ok, as list<T>::iterator is forward iterator, < operation is not available.
//    error: invalid operands for 'operator<' in '__x < __y'
//    std::list<int> li;
//    ml.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));

    return 0;
}
