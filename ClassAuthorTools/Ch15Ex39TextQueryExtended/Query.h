#ifndef _QUERY_H
#define _QUERY_H

#include <iostream>
#include "TextQuery.h"

class Query;	//forward declaration
class QueryBase {
	friend class Query;
protected:	
	using line_no = TextQuery::line_no;
	virtual ~QueryBase () = default;
	
private:
	virtual QueryResult eval (const TextQuery& t) const =0;
	virtual string rep () const =0;
	
};

class Query {
	friend ostream& operator<< (ostream& os, const Query& rhs);
	friend Query operator~ (const Query& rhs);
	friend Query operator& (const Query& l, const Query& r);
	friend Query operator| (const Query& l, const Query& r);
public:
	Query(const string& s);
	QueryResult eval(const TextQuery& t) const{return q->eval(t);}	//non-virtual
	string rep () const {return q->rep();}	//non-virtual
private:
	Query(shared_ptr<QueryBase> QQ) : q(QQ){}
	shared_ptr<QueryBase> q;		
};

ostream& operator<< (ostream& os, const Query& rhs){
	os << rhs.rep() <<std::endl;
	return os;
}

class WordQuery : public QueryBase {
	friend class Query;
	WordQuery (const string& s) : QueryWord(s) {}
	//privately inherited member can be redefined!
	QueryResult eval (const TextQuery& t) const override {return t.query(QueryWord);}
	string rep () const override {return QueryWord;}
	
	//pseudo recursive call until hitting WordQuery::rep()
	//string rep () const override {return "(" + QueryWord + ")";}
	
	string QueryWord;
};

//brilliant, friendship means Query has full access to WordQuery class 
inline
Query::Query (const string& s) : q {new WordQuery(s)} {}

class NotQuery : public QueryBase {
	friend Query operator~(const Query& rhs);
	NotQuery (const Query& source) :qq(source) {}
	QueryResult eval (const TextQuery& t)const override;
	string rep ()const override  {return "~(" + qq.rep() + ")";}
	Query qq;	// this member is practically a WordQuery object
};

QueryResult NotQuery::eval (const TextQuery& t)const {
	QueryResult temp = qq.eval(t);
	auto ret_lines = std::make_shared<set<line_no>> ();
	auto beg = temp.begin(), en = temp.end();
	auto sz = t.GetFile()->size();
	for(size_t i = 0; i != sz; ++i){
		if(beg == en || *beg != i){
			ret_lines->insert(i);
		}
		else if(beg != en){
			++beg;
		}
	}
	return QueryResult(rep(), t.GetFile(), ret_lines);
}

inline
Query operator~ (const Query& rhs) {
	return shared_ptr<QueryBase> (new NotQuery(rhs));
}

class BinaryQuery : public QueryBase {
protected:
	BinaryQuery (const Query& left, const Query& right, string operand) : l(left), r(right), Op(operand) {}
	//'QueryResult eval (const TextQuery& t)const' is not overriden!
	string rep () const {return "(" + l.rep() + " " + Op + " " + r.rep() + ")";}
	Query l, r;
	string Op;
};

class AndQuery : public BinaryQuery {
	friend Query operator& (const Query& lhs, const Query& rhs);
	AndQuery (const Query& left, const Query& right) : BinaryQuery(left, right,"&") {}
	QueryResult eval (const TextQuery& t) const override;
};

QueryResult AndQuery::eval(const TextQuery& t) const {
	auto right = r.eval(t), left = l.eval(t);
	auto ret_lines = std::make_shared<set<line_no>> ();
	set_intersection(left.begin(), left.end(), right.begin(), right.end(),inserter(*ret_lines,ret_lines->begin()));
	
	return QueryResult(rep(), t.GetFile(), ret_lines);
}

inline Query operator& (const Query& lhs, const Query& rhs){
	return shared_ptr<QueryBase> (new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
	friend Query operator| (const Query& lhs, const Query& rhs);
	OrQuery (const Query& lhs, const Query& rhs) : BinaryQuery(lhs, rhs, "|") {}
	QueryResult eval (const TextQuery& t)const override;
};

QueryResult OrQuery::eval(const TextQuery& t) const {
	auto right = r.eval(t), left = l.eval(t);
	auto ret_lines = std::make_shared<set<line_no>> (left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	/*
	for(int num: *ret_lines){ 
       std::cout <<"(line " <<num <<")\t" <<*(t.GetFile()->begin() + num -1) <<endl;        
    }*/
	return QueryResult(rep(),t.GetFile(), ret_lines);
}

inline Query operator| (const Query& lhs, const Query& rhs){
	return shared_ptr<QueryBase> (new OrQuery(lhs,rhs));
}

#endif
