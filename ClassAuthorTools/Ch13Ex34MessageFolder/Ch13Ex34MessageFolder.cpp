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

void Message::Save (Folder& f){
    Folders.insert(&f);    //insert address of a folder
    f.AddMsg(this);    //add pointer to this message to a Folder 
}

void Message::Delete(Folder& f){
    Folders.erase(&f);
    f.RmMsg(this);
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

//Ex13.49 add move operations to Message class, 
//move Folders is done and code is correct now
Message::Message(Message&& m) noexcept : Content{std::move(m.Content)}{
	std::cout<< "Move ctor, Message" << std::endl;
	Folders =std::move(m.Folders);
	for(auto f:m.Folders){
		f->RmMsg(&m);
		f->AddMsg(this);
	}
	m.Folders.clear();
}

Message& Message::operator= (Message&& m) noexcept {
	std::cout<< "Move =, Message" << std::endl;
	if(this != &m){
		RemoveFromAllFolders();
		Content = std::move(m.Content);
		Folders = std::move(m.Folders);
		for(auto f:m.Folders){
			f->RmMsg(&m);
			f->AddMsg(this);
		}
		m.Folders.clear();
	}
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

