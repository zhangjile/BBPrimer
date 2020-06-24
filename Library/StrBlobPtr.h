//Section 12 Dynamic Memory and Smart Pointers
//start from doing the easy part of a work, which is the biggest secret of a plan:)
//Ex12.19 P476
//the value of a seperate header is seen recently

#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using std::vector; using std::string; using std::shared_ptr; using std::weak_ptr;

class StrBlobPtr
{
public:
	StrBlobPtr();
	StrBlobPtr(weak_ptr<vector<string>> &p, size_t sz);
	string &deref(size_t curr);
	StrBlobPtr& incre();
private:
	shared_ptr<vector<string>> check(size_t i, string s);
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

#endif
