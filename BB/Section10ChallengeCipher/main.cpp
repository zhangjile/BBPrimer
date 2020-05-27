// Section 10
// Challenge - 
// Substitution Cipher

/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet 
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

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
         //the character will be trashed if not found in alphabet and else statement is rendered meaningless, which is a serious and tricky "leak".
    		position = alphabet.find(c);
    		encrypt += key[position];
    	}else{
    		encrypt += c; // always take "else" situations into consideration.
    	}
    }
    std::cout<<"Encrypted message: " <<encrypt<<std::endl;
    
    return 0;
}

