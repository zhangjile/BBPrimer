//
//  ex7_27.h
//  Exercise 7.27
//
//  Created by pezy on 11/14/14.
//

#ifndef CP5_ex7_27_h
#define CP5_ex7_27_h

#include <string>
#include <iostream>

template<unsigned Height, unsigned Width>
class Screen {
	friend std::ostream& operator<<(std::ostream& os,const Screen<Height,Width>& source){
		size_t size = Height*Width;
    	for(size_t i = 0; i < size; ++i){
    		os << source.contents[i];
    		if((i+1) % Width == 0)
    			os << "\n";
    	}
    	return os;
	}
	friend std::istream& operator>>(std::istream& is, Screen& source){
		std::cout << "type a character: " << std::endl;
    	char c;
    	is >>c;
    	source.contents = std::string(Height * Width, c);
		return is;
	}
public:
    using pos = std::string::size_type;

    Screen() = default; 
    Screen(char c):contents(Height*Width, c){ } 
	
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*Width+c]; }
    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(std::ostream &os) const { do_display(os); return *this; }
    Screen& display(std::ostream &os) { do_display(os); return *this; }

private:
    void do_display(std::ostream &os) const { 
    	size_t size = height*width;
    	for(size_t i = 0; i < size; ++i){
    		os << contents[i];
    		if((i+1) % Width == 0)
    			os << "\n";
    	}
    }

private:
    pos cursor = 0;
    pos height = Height, width = Width;
    std::string contents;
};

template<unsigned Height, unsigned Width>
inline Screen<Height, Width>& Screen<Height, Width>::move(pos r, pos c)
{
    cursor = r*Width + c;
    return *this;
}

template<unsigned Height, unsigned Width>
inline Screen<Height, Width>& Screen<Height, Width>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template<unsigned Height, unsigned Width>
inline Screen<Height, Width>& Screen<Height, Width>::set(pos r, pos c, char ch)
{
    contents[r*Width+c] = ch;
    return *this;
}
/*
template<unsigned Height, unsigned Width>
std::ostream& operator<<(std::ostream& os,const Screen<Height,Width>& source){
		size_t size = Height*Width;
    	for(size_t i = 0; i < size; ++i){
    		os << Screen<Height,Width>::contents[i];
    		if((i+1) % Width == 0)
    			os << "\n";
    	}
    	return os;
}*/

#endif
