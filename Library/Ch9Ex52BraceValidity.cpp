// Chapter 9.6 Container adaptors Ex52, P371
// CheckBraceValidity method checks whether a block of code is correct in using braces
// the description of this problem appear to be rather complicated, well, it is not complicated at all when I sit down and translate everything calmly, pretty easy.
// The previous 'class Date' appeared to be complicated too, it's surprising that I figured out everything, without difficulty. 
// the real difficulty and danger is, I'm in a hurry to move on fast. no, don't do that the real progress is precisely I solve one problem after another in leisure. 

#include <iostream>
#include <string>
#include <stack>

using std::string; using std::stack;

bool CheckBraceValidity(const string &s) {
	int OpenBraceCount = 0;
	stack<char> Adaptor;
	for(int i = 0; i < s.size(); ++i){
		Adaptor.push(s[i]);
		if(s[i] == '('){
			++OpenBraceCount;
		}
		if(OpenBraceCount > 0 && s[i] == ')')  {
			while(!Adaptor.empty() && Adaptor.top() != '(' ){
				Adaptor.pop();
			}		
			if(Adaptor.top() == '(') {
				Adaptor.pop();
				--OpenBraceCount;
			}
		}
		//std::cout<<OpenBrace <<std::endl; //check the count of open brace 
	}
	while(!Adaptor.empty()){
		if(Adaptor.top() == '(' || Adaptor.top() == ')') {
			return false;
		}
		Adaptor.pop();
	}
	return true;
}

int main(){
	string Braced = {"while(pos = find_first_of(numbers, pos)) != npos"};
	bool Result = CheckBraceValidity(Braced);
	std::cout << Result << std::endl;
	return 0;
}
