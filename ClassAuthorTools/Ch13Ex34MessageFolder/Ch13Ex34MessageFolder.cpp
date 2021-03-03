#include "Ch13Ex34MessageFolder.h"
#include <iostream>

void swap(Message& lhs, Message& rhs){
    using std::swap;
    lhs.RemoveFromAllFolders ();
    rhs.RemoveFromAllFolders ();
    swap(lhs.Content, rhs.Content);
    swap(lhs.Folders, rhs.Folders);
    lhs.AddToAllFolders ();
    rhs.AddToAllFolders ();
}

void Message::Save (Folder& rf){
    Folders.insert(&rf);    //insert address of a folder
    rf.AddMsg(this);    //add pointer to this message into a Folder object
}

void Message::Delete(Folder& rf){
    Folders.erase(&rf);
    rf.RmMsg(this);
}

void Message::AddToAllFolders (){
    for(auto f: Folders){
        f->AddMsg(this);
    }
}

void Message::RemoveFromAllFolders(){
    for(auto f: Folders){
        f->RmMsg(this);
    }
}

Message::Message(const Message& source){
    Content = source.Content;
    Folders = source.Folders;
    AddToAllFolders();
}

Message& Message::operator= (const Message& source){
    RemoveFromAllFolders();
    Content = source.Content;
    Folders = source.Folders;
    AddToAllFolders ();
    return *this;
}

//Ex13.49 add move operations to Message class
Message::Message (Message&& m) {
	std::cout<< "move constructor, Message" << std::endl;
	Content = std::move(m.Content);
	Folders = std::move(m.Folders);
}

Message& Message::operator= (Message&& m){
	std::cout<< "Move Assignment, Message" << std::endl;
	Content = std::move(m.Content);
	Folders = std::move(m.Folders);
	return *this;
}


//class Folder methods

void swap(Folder& lhs, Folder& rhs){
    using std::swap;
    lhs.RemoveThisFolderFromMessages ();
    rhs.RemoveThisFolderFromMessages ();
    swap(lhs.AFolder, rhs.AFolder);
    lhs.AddThisFolderToMessages ();
    rhs.AddThisFolderToMessages ();    
}

Folder::Folder(const Folder& source)
    :AFolder{source.AFolder}
{
    AddThisFolderToMessages ();
    
}

Folder& Folder:: operator= (const Folder& s){
    RemoveThisFolderFromMessages ();
    AFolder = s.AFolder;
    AddThisFolderToMessages ();
    return *this;
}

void Folder::AddMsg(Message* m){AFolder.insert(m);}
void Folder::RmMsg (Message* m){AFolder.erase(m);}

//engage the target, take aim and shoot, 
//say good-bye to taking random shots 
void Folder::AddThisFolderToMessages(){
    for(auto m: AFolder){
        m-> AddAFolder (this);
    }
}
void Folder::RemoveThisFolderFromMessages(){
    for(auto m: AFolder){
        m->Folders.erase(this); 
    }
}

