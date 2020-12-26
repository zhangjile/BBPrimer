
//Section 17.5.3 Random access to a stream
//Ex17.39, p 768, write your own version of seek program presented in this section
//pulled out a prick today, the code finally produces the expected result '5 9 12 14'.
#include <iostream>
#include <fstream>
#include <string>

using std::fstream; using std::string; 

int main(){
	fstream in_out("copyOut", fstream::ate | fstream::in | fstream::out);
	
	if(!in_out){
		std::cerr <<"error";
		return EXIT_FAILURE;	//good practice
	}
	
	fstream::pos_type end_mark = in_out.tellg();
	in_out.seekg(0,fstream::beg);
	
	string line;
	size_t cnt = 0;
	while(in_out && in_out.tellg() != end_mark && getline(in_out, line)){
		cnt += line.size() + 1;
		std::cout<< line.size() <<"\n";
		auto mark = in_out.tellg();
		in_out.seekp(0,fstream::end);
		in_out << cnt;
		if(mark != end_mark) in_out << " ";
		in_out.seekg(mark);
	}
	in_out.seekp(0, fstream::end);
	in_out <<'\n';

	return 0;
}



