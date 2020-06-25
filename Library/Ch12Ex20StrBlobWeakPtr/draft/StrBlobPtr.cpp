//Section 12 Dynamic Memory and Smart Pointers
//start from doing the easy part of a work, which is the biggest secret of a plan:)
//the value of a seperate header is seen recently

#include "StrBlobPtr.h"
#include "StrBlob.cpp"
using std::runtime_error;

StrBlobPtr::StrBlobPtr() : curr{0} {}

StrBlobPtr::StrBlobPtr(StrBlob &p, size_t sz = 0)
	:wpt{p.data}, curr{sz} {}

string & StrBlobPtr::deref(size_t curr){
	auto p = check(curr,"invalid");
	return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incre(){
	check(curr, "invalid");
	++curr;
	return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, string s){
	auto p = wptr.lock();
	if(!p)
		throw runtime_error("null");
	if(i > p->size()){throw std::out_of_range(s);}
	return p;
}

