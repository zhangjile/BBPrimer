//since this is a game, why don't I play it absolutely pressure-free?
//++ read the QueryWord and OpSymbol from stdin
#include "Query.h"

void RunQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        std::cout << tq.query(s) << std::endl;
        
    }
}

int main()
{
	std::ifstream is ("README.md");
	TextQuery t(is);
	
	Query bug("bug"), word("word"), code ("code");
	
	QueryResult result = bug.eval(t);
	//std::cout << result <<std::endl;
	
	Query AQ = word & bug | code;
	result = AQ.eval(t);
	std::cout << result <<std::endl;
	
	bug.eval(t);
}
