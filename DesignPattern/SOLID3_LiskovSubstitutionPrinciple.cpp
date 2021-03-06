﻿// Objects in a program should be replaceable with instances of their subtypes
// w/o altering the correctness of the program

//ok, i got it, we set up the dynamic polymorhpism and the run-time binding is ready to go, but the value of some base class members are modified by accident,therefore, when some method of base class are called in which modified data members are involved, notorious chaos occur.

#include <iostream>

class Rectangle
{
protected:
  int width, height;
public:
  Rectangle(const int width, const int height)
    : width{width}, height{height} { }

  int get_width() const { return width; }
  virtual void set_width(const int width) { this->width = width; }
  int get_height() const { return height; }
  virtual void set_height(const int height) { this->height = height; }

  int area() const { return width * height; }
};

class Square : public Rectangle
{
public:
  Square(int size): Rectangle(size,size) {}
  void set_width(const int width) override {
    this->width = height = width;	//'=' has right associtivity
  }
  void set_height(const int height) override {
    this->height = width = height;
  }
};

struct RectangleFactory
{
  static Rectangle create_rectangle(int w, int h);
  static Rectangle create_square(int size);
};

void process(Rectangle& r)
{
  int w = r.get_width();
  r.set_height(10);

  std::cout << "expected area = " << (w * 10) 
    << ", got " << r.area() << std::endl;
}

int main()
{
  Rectangle r{ 5,5 };
  process(r); //process works as expected

  Square s{ 5 };	//no matter what argument to the object s is
  process(s);	//the result is permanently 100

  return 0;
}

/*
analysis:
the derived class Square is totally not necessary and totally disastrous.
replay the SOLID game on daily basis until they're absolutely easy to play.
*/
