//Section 17.3.3 Using Subexpressions
//Ex17.19, p741, Why is it ok to call m[4].str() without checking whether m[4] was matched?
//because there are 7 subexpressions in the pattern, the 4th subexpression is sure to be matched.
//Ex17.20, Write your own version of the program to validate phone numbers

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
using std::cout; using std::endl; using std::getline;
using std::string; using std::regex; using std::smatch; using std::sregex_iterator;

//change the name to Formatted, because the body of the function does not verify validity, but formats instead.
bool Formatted(const smatch& m){
	if(m[1].matched) 
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else return !m[3].matched && m[4].str() == m[6].str();
	//== has higher precedence over &&, !m[3].matched && (m[4].str() == m[6].str());
}

/* phones data
//add an invalid phone number 862-555-012 to morgan, it is excluded as expected!
morgan (201) 555-0168 862-555-012 862-555-0123 
drew (973)555.0130 
lee (609) 555-0132 2015550175 800.555-0110

*/

int main (){
	string phone = "(\\()?(\\d{3})(\\))?([-. ]*?)(\\d{3})([-. ]?)(\\d{4})";
//	string phone = "(\\()?(\\d{3})(\\))?([ ]*)(\\d{3})([ ]*)?(\\d{4})";
	//result: no, 132 2015550, this dangerous operation disrupted all the valid numbers.

	regex r(phone);
	smatch m;
	std::ifstream f("phones");
	string str;
	while(getline(f, str)){
		for(sregex_iterator it(str.begin(), str.end(),r), end_it; it != end_it; ++it){
			if(Formatted(*it)) {		//iterator to a smatch object
				cout <<it->length() <<endl; //it->length(6), 6th subexpression
				cout <<(*it)[7] <<endl;	//extract the content of sstr_match,yeah!
				cout <<"Formatted, " <<it->str() <<endl;
				
			}
			else cout <<"Not Formatted, " << it->str() <<endl; 
		}
	}
}


