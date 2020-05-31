// Section 10
// Challenge - 
// Substitution Cipher


#include <iostream>
#include <string>

int main() {
    
    std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        std::string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    std::string message{};
    std::cout<<"Please enter your message: "<<std::endl;
    std::getline(std::cin,message);
    
    std::cout<<"Encrypting..." <<std::endl;
    std::string encrypt{};
    int position {};
    for(char c:message){
    	if(alphabet.find(c) != std::string::npos){
    	//if(alphabet.find(c)) 
    //the character will be trashed if not found in alphabet 
    //and else statement is rendered meaningless, a serious and tricky "leak".
    		position = alphabet.find(c);
    		encrypt += key[position];
    	}else{
    		encrypt += c; // always take "else" situations into consideration.
    	}
    }
    std::cout<<"Encrypted message: " <<encrypt<<std::endl;
    
    return 0;
}

