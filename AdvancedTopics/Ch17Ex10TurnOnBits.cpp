//Section 17.2 the Bitset type
//Ex17.10,p728

#include <iostream>
#include <string>
using std::string; using std::bitset;

//Ex12
void Update(bitset<12>& bit12,size_t n, char c = '0'){
	bit12[n] = c;
}

int main () {
	std::bitset<12> bvec(0xbee);
	std::cout <<bvec.to_string() <<std::endl;
	Update(bvec, 0, 1);
	std::cout <<bvec.to_string() <<std::endl;
	
	string bstr = {"010101010"};
	
	bitset<8> bvec1(bstr, 5,4);
	std::cout <<bvec1.to_string() <<std::endl;
	bitset<8> bvec2(bstr, bstr.size() -4);
	std::cout <<bvec2.to_string() <<std::endl;

	unsigned long score = 0ULL;
	score |= 1ULL<<27;
	bitset<32> s(score);	//this is brilliant:)
	std::cout <<s <<std::endl;
	score &= ~(1ULL << 27);
	std::cout <<score <<std::endl;
	bool result = score & (1ULL << 27);

	bitset<30> QuizB;
	QuizB.set(27);
//	QuizB.reset(27);
	bool status = QuizB[27];
	QuizB.to_string();

	std::cout <<QuizB.to_string('y','x') <<std::endl;
	
	return 0;
}
