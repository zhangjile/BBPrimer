// carefully arrange the program flow to accommodate interdependencies
// much better to restrict unfettered access to the private members of class Screen
// ++ defense and pruning
#include <iostream>
#include <vector>

class Screen;

class Screen_mgr {
	public:
	using ScreenIndex = std::vector<Screen>::size_type;
	Screen_mgr ();
	void Clear(ScreenIndex i);
	const Screen& Get(ScreenIndex i = 0) const {return Screens[i];}
	private:
	std::vector<Screen> Screens;
	// Screen is an incomplete class by now, 
	//in-class initializing not viable!
//	std::vector<Screen> Screens{Screen(10,20,' ')};
};

class Screen {
	friend void Screen_mgr::Clear(ScreenIndex);
public:
	typedef std::string::size_type pos;
	Screen () = default;
	Screen (pos ht, pos wd): Height(ht),Width(wd), Contents(ht*wd, ' ') {}
	Screen (pos ht, pos wd, char c):Height (ht), Width (wd), Contents (ht*wd, c){}
	char Get() const {return Contents[Cursor];}
	inline char Get(pos ht, pos wd) const; //inline specifier
	Screen &Move (pos r, pos c);
	Screen &Set(char c);
	Screen &Set(pos r, pos c, char ch);
	Screen &Display(std::ostream &os) {DoDisplay (os); return *this;}
	const Screen &Display (std::ostream &os) const {DoDisplay (os); return *this;}
	
private:
	pos Cursor = 0;
	pos Height = 0, Width = 0;
	std::string Contents;
	
	//simulating a full-screen display, a persisting puzzle is solved, finally
	//display contents of "cccc cccc cccc" by Height=3 and Width=4, Period.
	void DoDisplay(std::ostream &os) const {
		size_t s = Contents.size();
		for(size_t i = 0; i < s; ++i){
			os << Contents[i];
			if((i+1)% Width == 0)
				os <<"\n";
		}		
	}	
};

char Screen::Get(pos r, pos c) const {
	pos Row = r * Width;
	return Contents[Row + c];
}

inline 
Screen& Screen::Move(pos r, pos c){ 
	pos Row = r * Width;
	Cursor = Row + c;
	return *this;
}

inline 
Screen& Screen::Set(char c){
	Contents[Cursor] = c;
	return *this;
}

inline 
Screen& Screen::Set(pos r, pos c, char ch){
	Contents[r*Width +c] = ch;
	return *this;
}

Screen_mgr::Screen_mgr (){
	Screens.push_back(Screen(5,20,'a')); //last stroke to secure a success
}

void Screen_mgr::Clear(ScreenIndex i){
	if(i >= Screens.size()) return; //Great defense
	Screen &temp = Screens[i];
	temp.Contents = std::string (temp.Height * temp.Width, 'X');
}

int main () {
	Screen MyScreen(5,5,'#');
	MyScreen.Move(1,0).Set('\\').Display(std::cout);
	std::cout<<"\n";
	MyScreen.Set('?').Display(std::cout);
	std::cout<<"\n";
	const Screen Black {5,2,'@'};
	Black.Display(std::cout);
	std::cout<<"\ndefault:\n";
	Screen_mgr m ;
	Screen n = m.Get(0);
	n.Display(std::cout);
	std::cout<<"\nclear:\n";
	m.Clear(0);
	n = m.Get(0);
	n.Display(std::cout);
	return 0;
}
