//to create a long complicated string, which is Html code. 
//in this case, C_string concatenation or string constructors doesn't suffice.
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

struct HtmlBuilder;

struct HtmlElement
{
  string name;
  string text;
  vector<HtmlElement> elements;
  const size_t indent_size = 2;

  HtmlElement() {}
  HtmlElement(const string& name, const string& text)
    : name(name),text(text){}

  string str(int indent = 0) const
  {
    ostringstream oss;
    string i(indent_size*indent, ' '); //a string of this number of whitespaces
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0)
      oss << string(indent_size*(indent + 1), ' ') << text << endl;

    for (const auto& e : elements)
      oss << e.str(indent + 1);

    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

  static unique_ptr<HtmlBuilder> build(string root_name)
  {
    return make_unique<HtmlBuilder>(root_name);
  }
};

struct HtmlBuilder
{
  HtmlBuilder(string root_name)
  {
    root.name = root_name;
  }

  // void to start with
  HtmlBuilder& add_child(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return *this;
  }

  // pointer based
  HtmlBuilder* add_child_2(string child_name, string child_text)
  {
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return this;
  }

  string str() { return root.str(); }

  operator HtmlElement() const { return root; }
  HtmlElement root;
};

int main()
{
  // easier
  HtmlBuilder builder{ "ul" };
  builder.add_child("li", "hello").add_child("li", "Assembly");
  cout << builder.str() << endl;
  cout << endl;

  auto builder2 = HtmlElement::build("ul");	//done, fixed, wahoo!
    builder2->add_child_2("li", "hello")->add_child_2("li", "C++ world");
  cout << builder2->str() << endl;

  return 0;
}