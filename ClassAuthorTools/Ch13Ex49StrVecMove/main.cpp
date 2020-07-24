#include "StrVec.h"

int main () {
	StrVec s1;
	StrVec s2{"Gratitude", "and", "bliss"};
	std::cout << s2.size() <<std::endl;
	s1 = StrVec{"ok"};
	s1 = std::move(s2);
	return 0;
}
