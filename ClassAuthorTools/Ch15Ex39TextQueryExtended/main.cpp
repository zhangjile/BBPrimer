//since this is a game, why don't I play it absolutely pressure-free?
//++ read the QueryWord and OpSymbol from stdin
#include "Query.h"

int main()
{
	std::ifstream is ("README.md");
	TextQuery t(is);
	
	Query bug("bug"), word("word"), code ("code");
	
	Query AQ = word & bug | code;
	QueryResult result = AQ.eval(t);
	std::cout << result <<std::endl;
	
	AQ = ~code;
	result = AQ.eval(t);
	std::cout << result <<std::endl;
	
	bug.eval(t);
}
