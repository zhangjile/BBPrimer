//This is naive implementation, upon which builders are crafted.
#include <iostream>
#include <string>
#include <sstream>
using std::string; using std::cout; using std::endl; 
using std::ostringstream;

int main()
{
  // <p>hallo</p>
  auto text = "hallo";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  cout << output << endl;
  cout << endl;

  // <ul><li>hiya</li><li>world</li></ul>
  string words[] = { "hiya", "world" };
  ostringstream oss;
  oss << "<ul>";
  for (auto w : words)
    oss << "  <li>" << w << "</li>";
  oss << "</ul>";
  cout << oss.str() <<endl;
  cout << endl;
  
  return 0;
}