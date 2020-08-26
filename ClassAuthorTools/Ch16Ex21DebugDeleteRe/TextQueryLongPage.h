/***************************************************************************
 *  @file       TextQuery.h
 *  @author     Alan.W
 *  @date       27  DEC 2013
 *  @remark
 ***************************************************************************/

//
// Exercise 12.27:
// The TextQuery and QueryResult classes use only capabilities that we have
// already covered. Without looking ahead, write your own versions of these
// classes.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

class DebugDelete
{
public:
    DebugDelete(std::ostream& s = std::cerr) : os(s) { }
    template<typename T>
    void operator() (T* p) const
    {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }

private:
    std::ostream& os;
};


class QueryResult;

class TextQuery
{
public:
    typedef std::shared_ptr<std::vector<std::string>> sp_file_Tp;
    typedef std::shared_ptr<std::map<std::string, std::set<int>>> sp_Qmap_Tp;

    // constructors
    TextQuery() = default;
    TextQuery(std::ifstream &fin);

    // query operation
    QueryResult
    query(const std::string &qWord) const;

private:
    // smart pointer to a vector to be storing a file.
    sp_file_Tp sp_fileData = nullptr;

    // smart pointer to a map to be storing results of querries.
    sp_Qmap_Tp sp_queryMap = nullptr;
};


/**
 *  Constructor
 *  read each line into the dynamicly allocated vector.
 */
TextQuery::TextQuery(std::ifstream &fin) :
    // @oldcode
    // custom deleter may not use with std::make_shared, as it has an internal
    // deleter which may not be replaced. As a result, keyword new is the only
    // option to use with DebugDelete.
    /*
    sp_fileData(std::make_shared<std::vector<std::string>>() ),
    sp_queryMap(std::make_shared<std::map<std::string, std::set<int>>>() )
    */
    sp_fileData(new std::vector<std::string>(), DebugDelete() ),
    sp_queryMap(new std::map<std::string, std::set<int>>(), DebugDelete())
{
    std::string line;
    while(std::getline(fin, line))
        sp_fileData->push_back(line);

}

class QueryResult
{
public:    
    QueryResult() = default;	// default constructor

    QueryResult(const QueryResult &qr);

    QueryResult(std::size_t c, const std::string &str,
                   const TextQuery::sp_file_Tp &sp_f,
                   const TextQuery::sp_Qmap_Tp &sp_m);

    std::size_t
    getCounter() const { return counter; }

    std::string
    getQueryWord() const { return queryWord; }

    TextQuery::sp_file_Tp
    getSp_file() const { return sp_file; }

    TextQuery::sp_Qmap_Tp
    getSp_Qmap() const { return sp_Qmap; }

private:    
    std::size_t counter = 0;	// number of occurrence
    std::string queryWord = "";		// the word being searched

    // smart pointer to a vector to be storing a file.
    TextQuery::sp_file_Tp sp_file = nullptr;

    // smart pointer to a map to be storing results of querries.
    TextQuery::sp_Qmap_Tp sp_Qmap = nullptr;
};

// print the result of searching
void print(std::ostream &os, const QueryResult &qr);

// copy constructor
inline QueryResult::QueryResult(const QueryResult &qr):
    counter(qr.getCounter()), queryWord(qr.getQueryWord()),
    sp_file(qr.getSp_file()), sp_Qmap(qr.getSp_Qmap())
{
}

// constructor
QueryResult::QueryResult(std::size_t c, const std::string &str,
                               const TextQuery::sp_file_Tp &sp_f,
                               const TextQuery::sp_Qmap_Tp &sp_m) :
    counter(c), queryWord(str), sp_file(sp_f), sp_Qmap(sp_m)
{
}

// a non-member function printing the result of a query.
void print(std::ostream &os, const QueryResult &qr)
{
    // fetch the word being queried.
    const std::string queryWord = qr.getQueryWord();

    // print the word and occurrence times
    os << "The word ["
         <<queryWord
           <<"] occurs "
             <<qr.getCounter()
               <<" times :\n";

    // fetch smart pointers to the map and the file
    auto sp_m = qr.getSp_Qmap();
    auto sp_f = qr.getSp_file();

    // print each line in which it appears and the corresponding index.
    for(const auto &index : (*sp_m)[queryWord])
        std::cout << "\n(Line "
                    <<index
                       <<") "
                          << (*sp_f)[index]
                             << "\n\n";
}


QueryResult
TextQuery::query(const std::string &qWord) const
{
    // storing the amount of occurrence
    std::size_t counter = 0;

    // loop through each line
    for(std::size_t i=0; i != sp_fileData->size(); ++i)
    {
        // break into each word
        std::stringstream lineS((*sp_fileData)[i]);	//watch, lineS is red
        std::string word;
        while(lineS >> word)
        {
            if(!word.compare(qWord))
            {
                ++counter;

                // add the index of the line into the result map
                (*sp_queryMap)[qWord].insert(i);
            }
        }
    }

    // creare a object holding the result .
    QueryResult qResult(counter, qWord, sp_fileData, sp_queryMap);

    return qResult;
}


