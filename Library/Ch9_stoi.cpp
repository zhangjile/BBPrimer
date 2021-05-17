#include <iostream>
#include <string>

int main(){
  std::string str_dec = "2001, A Space Odyssey";
  std::string str_hex = "40c3";
  std::string str_bin = "-10010110001";
  std::string str_auto = "0x7f";

  std::string::size_type sz  {0}; // alias of size_t

  int i_dec = std::stoi (str_dec,&sz); //pass by reference, sz is 4
  int i_hex = std::stoi (str_hex,nullptr,16); //in order to specify 16, nullptr is required
  int i_bin = std::stoi (str_bin,nullptr,2);
  int i_auto = std::stoi (str_auto,nullptr,0); //binary

  std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  std::cout << str_hex << ": " << i_hex << '\n';
  std::cout << str_bin << ": " << i_bin << '\n';
  std::cout << str_auto << ": " << i_auto << '\n';
}