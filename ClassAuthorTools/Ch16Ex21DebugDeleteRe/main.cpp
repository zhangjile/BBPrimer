/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       03  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//
// Exercise 16.21:
// Write your own version of DebugDelete.
//
// Exercise 16.22:
// Revise your TextQuery programs from § 12.3 (p. 484) so that the shared_ptr
// members use a DebugDelete as their deleter (§ 12.1.4, p. 468).
//

#include <iostream>
#include <vector>
#include <list>

#include "DebugDelete.h"
#include <memory>

#include "wy_queryresult.h"
#include "wy_queryresult.cpp"
#include "wy_textquery.h"
#include "wy_textquery.cpp"

int main()
{
    std::ifstream is("100_git_commands");
    wy_textQuery re (is);
    print(std::cout, re.query("add"));
    
    return 0;
}
/*
summary
QueryResult Query(const string& s) can be defined either:
1) in wy_textquery.cpp
2) or in a long file after class QueryResult{};

*/