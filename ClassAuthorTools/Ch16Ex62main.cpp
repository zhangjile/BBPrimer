#include "Ch16Ex62SalesData.h"

int main()
{
    std::unordered_multiset<SalesData> mset;
	
	SalesData sd("6 Chapters of the 2019 by Xu Zhang Run", 10, 0.98);
	mset.emplace(sd);
	mset.emplace("C++ Primer", 5, 9.99);

    for(const auto &item : mset)
        std::cout << "the hash code of " << item.isbn()
                  <<":\n0x" << std::hex << std::hash<SalesData>()(item)
                  << "\n"
    				<<std::endl;

	return 0;
}
