//Section 13.4 a copy control example
//Ex13.34, p524, Write the Message class as described in this section
//Ex13.36,Design and implement the corresponding Folder class. The class should hold a set that points to the messages in that folder
#ifndef _CH13EX31_H_
#define _CH13EX31_H_

#include <string>
#include <set>

class Folder;
class Message {
    friend class Folder;    //grant friendship/access previlage
    friend void Swap(Message& lhs, Message& rhs);
public:
    explicit Message (const std::string& str = ""): Content{str} {}
    ~Message (){RemoveFromAllFolders();}
    Message (const Message& source);
    Message& operator= (const Message& source);
    void Save(Folder& rf);
    void Delete (Folder& rf);
    size_t Occurrences () {return Folders.size();}
private:
    std::string Content;
    std::set<Folder*> Folders;
    void AddToAllFolders ();
    void RemoveFromAllFolders ();
};


class Folder {
    friend class Message;
    friend void Swap(const Folder& lhs, const Folder& rhs);
public:
    Folder () = default;
    Folder (const Folder& source);
    Folder& operator= (const Folder& source);
    ~Folder ();
    //Message* m declares an addressable variable to store the parameter, 
    //not a reference to a variable
    void AddMsg(Message* m);    //critical
    void RmMsg (Message* m);
    
    size_t Occurrences () {return AFolder.size();}
    
private:
    //Folder as an abstract data type is a set of pointers to message entries
    std::set<Message*> AFolder; 
};


#endif
