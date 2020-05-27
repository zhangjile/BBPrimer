// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(25) << std::left << s.name
       << std::setw(33) << std::left << s.artist
       << std::setw(20) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "D - Deleting the song playing" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
	std::cout <<"\nPlaying: " << song.get_name() <<std::endl<<std::endl;
    
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
	std::cout << std::setw(25) << std::left << "Song"
       << std::setw(30) << std::left << "Artist"
       << std::setw(20) << std::left << "Rating" <<std::endl;
	std::cout <<"-------------------------------------------------------------"<<std::endl; 
	for (const auto &song:playlist)
		std::cout << song << std::endl;
	play_current_song(current_song);
    
}

// Frank helped out with 2 lines of critical code for this function
std::list<Song> create_playlist () 
{
	std::string name {}, artist {};
    int rating {};
    std::string temp{};
    std::list<Song> playlist;
	std::list<Song> playlist_backup{
            {"Sing a song",       "Carpenters",                5},
            {"San Francisco",  	  "Meckenzie",                 5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    std::ifstream in_file {"Playlist.txt"};
    
    if (!in_file) {
        std::cerr << "Problem opening latest playlist file" << std::endl;
        std::cerr << "Loading backup playlist..." << std::endl;
        playlist = playlist_backup;
        // what to do if this fails??
        	
    }        
        
    while (getline (in_file, name)){
    	getline (in_file, artist);
        
    	getline(in_file, temp);   // read rating using getline
        rating = std::stoi(temp); // convert the temp string to an int
        
    	playlist.emplace_back(name, artist, rating);
    }
        
    return playlist;
}
	
void write_playlist (std::list<Song> playlist)
{
	std::ofstream out_file {"Playlist.txt"};
	if (!out_file){
		std::cerr <<"Saving the new entry failed" <<std::endl;
	}
	else {
    	for (const auto &song : playlist){
    	out_file <<song.get_name() << std::endl;
    	out_file <<song.get_artist() << std::endl;
    	out_file << song.get_rating() <<std::endl;
    	}
    }
}

int main() {	
	std::list<Song> playlist = create_playlist();        
    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    
    char select {};    
    do
    {
    	
    	display_menu();   
   		std::cin >> select;
   		select = static_cast<char>(std::toupper(select));
    	if (select == 'F'){
    		current_song = playlist.begin();
    		play_current_song(*current_song);
    	}
    		
    	else if (select == 'N'){
    		++current_song;
    		if(current_song == playlist.end()){
    			current_song = playlist.begin();    			
    		}
    		play_current_song(*current_song);
    	}
    		   	
    	else if (select == 'P'){        			
    		--current_song; 
    		if(current_song == playlist.end()){
    			--current_song;
    		}
    		play_current_song(*current_song);    			
    	 }
    		    		
    	else if (select == 'A'){
    		std::cin.clear();
    		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    		std::cout << "What's the name of the song? " <<std::endl;
    		std::string name;
    		std::getline(std::cin, name);
    		std::cout << "Who is the artist? " <<std::endl;
    		std::string artist;
    		std::getline(std::cin, artist);
    		std::cout << "What's your rating? " <<std::endl;
    		int rating;
    		std::cin >>rating;
    		
    		//validate adding new song to prevent invalid entry from being saved
    		if (name.size()==0 || artist.size() == 0 ){
    			std::cout <<"sorry, looks like an invalid entry, please try again" <<std::endl;  	    		
    		}
    		else{
    			playlist.emplace(current_song, name, artist, rating);    
    			--current_song;
    			display_playlist(playlist, *current_song);    		
    			write_playlist(playlist);
    		}    		
    		std::cin.clear();
    		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');		
    	}
    		
       else if (select == 'D'){        			
    		auto it = current_song; 
    		++current_song;
    		playlist.erase(it);    		
    		if(current_song == playlist.end()){
    			current_song = playlist.begin();    			
    		}
    		play_current_song(*current_song);
    		write_playlist(playlist);
    	}
    		
    	else if (select == 'L'){
    		display_playlist(playlist, *current_song);
    	}
    
    	else if (select == 'Q'){
    		std::cout <<"Exit music player" << std::endl;
    	}
    		
    	else {
    		std::cout << "Invalid selection, try again please" <<std::endl;
    	}
    		
    } while (select != 'Q');    

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
    
}

/*
Graduation presentation
1. catch error: playlist = playlist_backup  	//line 95
2. catch error: validate new song entry before saving to file  // line 173
3. catch error: dump invalid entry,	go right back to menu    //line 182, Finale
4. extend functionality: delete current song 	// line 185
5. professionalism: indentation
6. professionalism: commenting
7. professionalism: polishing
*/
