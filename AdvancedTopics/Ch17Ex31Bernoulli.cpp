
//Ex17.31, p753, What would happen if we defined b and e inside the 
//do loop of the game-playing program from this section?
//the engine and the distribution device don't generate random numbers properly
//Ex17.32,What would happen if we defined resp inside the loop? failure.

#include <iostream>
#include <random>
#include <string>

using std::cout; using std::endl; using std::string;
using std::cin;
using std::bernoulli_distribution;
using std::default_random_engine;

int main(){
	string resp;
	default_random_engine e;
//	bernoulli_distribution b;	//50/50 odds by default;
	bernoulli_distribution b(.8);	//80/20 odds
	do{
		bool who_first = b(e);
		cout << (who_first ? "Let's start!" : "You go first!") <<endl;
		//cout << ((play(who_first)) ? "You lost!" : "Congrats, you won!") <<endl;	//end a gameplay
	}while(cin >>resp && resp[0] == 'y');

	return 0;
}