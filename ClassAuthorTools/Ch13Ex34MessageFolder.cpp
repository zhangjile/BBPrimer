#include "Ch13Ex34MessageFolder.h"
#include <iostream>

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

void Swap(Message& lhs, Message& rhs){
    using std::swap;
    for(auto f : lhs.Folders){
        f->RmMsg(&lhs);
    }
    for(auto f : rhs.Folders){
        f->RmMsg(&rhs);
    }
    swap(lhs.Content, rhs.Content);
    swap(lhs.Folders, rhs.Folders);
    
    for(auto f : lhs.Folders){
        f->AddMsg(&lhs);
    }
    for(auto f : rhs.Folders){
        f->AddMsg(&rhs);
    }
    
}


//class Folder methods

void Folder::AddMsg(Message* m){AFolder.insert(m);}
void Folder::RmMsg (Message* m){AFolder.erase(m);}

Folder::~Folder (){
//	for(Message *m : AFolder){
    for(auto m : AFolder){
		delete m;
	}
}

//test the logic
int main ()
{
    Message *m1 = new Message("Mike Pence");
    Folder f1;
    m1->Save(f1);
    //very precious picture of an iceberg under water:)
    std::cout << m1->Occurrences() <<std::endl; 
    Message *m2 = new Message ("stupid");
    f1.AddMsg(m2);
    std::cout << f1.Occurrences() <<std::endl; 
    //delete m1;
    delete m1, m2;	// the whole world is in peace now.
   
    return 0;
}
