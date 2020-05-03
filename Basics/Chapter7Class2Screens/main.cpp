//Class features Ex 7.27 p 278
//Graphical interface, symbols expand the width of the device
#include <iostream>
#include <vector>

class Screen {
public:
	typedef std::string::size_type pos;
	Screen () = default;
	Screen (pos ht, pos wd, char c):
	Height (ht), Width (wd), Contents (ht * wd, c){}
	char Get() const {return Contents[Cursor];}
	inline char Get(pos ht, pos wd) const;
	Screen &Move (pos r, pos c);
	Screen &Set(char c);
	Screen &Set(pos r, pos c, char ch);
	Screen &Display(std::ostream &os) {DoDisplay (os); return *this;}
	const Screen &Display (std::ostream &os) const {DoDisplay (os); return *this;}
private:
	pos Cursor = 0;
	pos Height = 0, Width = 0;
	std::string Contents;
	void DoDisplay(std::ostream &os) const {os << Contents;}
	
};

char Screen::Get(pos r, pos c) const {
	pos Row = r * Width;
	return Contents[Row + c];
}

inline Screen& Screen::Move(pos r, pos c){
	pos Row = r * Width;
	Cursor = Row + c;
	return *this;
}

inline Screen& Screen::Set(char c){
	Contents[Cursor] = c;
	return *this;
}

inline Screen& Screen::Set(pos r, pos c, char ch){
	Contents[r*Width +c] = ch;
	return *this;
}

class Screen_mgr {
	private:
	std::vector<Screen> Screens {Screen(24,80, ' ')};
};

int main () {
	Screen MyScreen(5,5,'#');
	MyScreen.Move(1,0).Set('\'').Display(std::cout);
	std::cout<<"\n";
	MyScreen.Set('?').Display(std::cout);
	std::cout<<"\n";
	const Screen Black {5,2,'@'};
	Black.Display(std::cout);
	return 0;
}