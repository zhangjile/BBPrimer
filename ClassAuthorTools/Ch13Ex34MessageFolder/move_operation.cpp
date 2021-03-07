//solution 1
//
void Message::move_folders(Message *m){
	Folders = std::move(m->Folders);
	for(auto f : m->Folders){
		f->RmMsg(m);
		f->AddMsg(this);
	}
	m->Folders.clear();
}

Message::Message(Message&& m) noexcept: Content{std::move(m.Content)}{
	std::cout<< "Move ctor, Message" << std::endl;
	move_folders(&m);
}

Message& Message::operator= (Message&& m) noexcept {
	std::cout<< "Move =, Message" << std::endl;
	if(this != &m){
		RemoveFromAllFolders();
		Content = std::move(m.Content);
		move_folders(&m);
	}
	return *this;
}

//solution 2
//it works to specify 'Message &' as parameter, but not as reliable as solution 1
void Message::move_folders(Message &m){
	Folders = std::move(m.Folders);
	for(auto f : m.Folders){
		f->RmMsg(&m);
		f->AddMsg(this);
	}
	m.Folders.clear();
}

Message::Message(Message&& m): Content{std::move(m.Content)}{
	std::cout<< "Move ctor, Message" << std::endl;
	move_folders(m);
}

Message& Message::operator= (Message&& m){
	std::cout<< "Move =, Message" << std::endl;
	if(this != &m){
		RemoveFromAllFolders();
		Content = std::move(m.Content);
		move_folders(m);
	}
	return *this;
}
