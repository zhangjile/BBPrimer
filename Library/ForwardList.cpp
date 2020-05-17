//implementating forward_list /singly-linked list
#include<iostream>

class Node 
{
public:
	int data;
	Node *next;
	Node(int x){
		data = x;
		next = nullptr;
	}
};

class LinkedList
{
private:
	Node *header;
	Node *tail;
	int size;
public:
	LinkedList(){
		header = nullptr;
		tail = nullptr;
		size = 0;
	}
	int GetSize(){return size;}
	void Append (int data);
	void Prepend (int data);
	void ToString();
	void RemoveFirst();
	void RemoveLast();
	void RemoveAt(int pos);
	void InsertAt(int data,int pos);
	
	~LinkedList();
};

void LinkedList::Append(int data){
	Node *n = new Node(data);
	if(header==nullptr){
		header = n;
		tail = n;
	}
	else {
		tail->next = n;
		tail = n;
	}
	++size;
}

void LinkedList::Prepend(int data){
	Node *n = new Node(data);
	if(header==nullptr){
		header = n;
		tail = n;
	}
	else{
		Node *temp = header;//temp is an alias of current header
		header = n; //make n header;
		// n becomes new header and point n->next to previous header
		n->next = temp; 
		
	}
		
	/*
	//more efficient
	else {
		n->next = header; //n->next is l-value,assign current header to it
		header = n; //finalize/update by making n new header
		
		//2 statements/operations are in logical order. 
	}
	*/
	++size;	
}

void LinkedList::ToString(){
	//create a temporary pointer to header
	Node *temp = header;
	
	while(temp != nullptr){
		std::cout<<temp->data<<" ";
		temp = temp->next;
	}
	std::cout<<std::endl;
}

void LinkedList::RemoveFirst(){
	if(header==nullptr) return;//define the behavior explicitly as error-catching!
	if(header != nullptr){
		Node *temp = header;
		header = header->next;
		delete temp;
		--size;
	}
}

void LinkedList::RemoveLast(){
	if(header->next == nullptr){
		RemoveFirst();
	}
	if(header != nullptr){
		Node *cur = header;
		Node *prev = nullptr;
		while(cur->next != nullptr){
			prev = cur;
			cur = cur->next;
		}
		tail = prev;
		prev->next = nullptr;//讓prev這個alias代理人來跑東跑西
		delete cur;
		--size;
	}
	/*
	if(header != nullptr){
		Node *current = header->next;
		Node *previous =header;
		while(current != nullptr){
			previous = current;
			current =current->next;
		}
		tail = previous;
		previous->next = nullptr;
		del current;
		--size;
	}
	*/
}

//通過asignment operation實現動態切換/替換，像各就各位。
void LinkedList::RemoveAt(int pos){
	if(pos>size || pos<1) return; //screen out dirt
	else if(pos==1) RemoveFirst();
	else if(pos==size) RemoveLast();
	else if(header != nullptr){
		Node *prev;
		Node *cur = header;
		for(int i=1; i<pos; ++i){
			prev = cur;//把現在的cur指定給prev
			cur = cur->next;//然後再更新cur。**正確的圍棋落子次序**
		}
		prev->next = cur->next;
		delete cur;
		--size;
	}
}


void LinkedList::InsertAt(int data, int pos){
	if(pos>size+1 || pos<1) return;
	else if(pos==1) {
		Prepend(data);
	}
	else if(pos==size+1){	
		Append(data);
	}
	//關鍵失誤：昨天發現要把size改為size+1并相應修改，但是卻沒有立即完成，更沒留下任何TODO線索./03/10/2019
	else if(header != nullptr){
		Node *prev;
		Node *cur = header;
		for(int i=1; i<pos; ++i){
			prev = cur;
			cur = cur->next;
		}
		Node *n = new Node(data);
		n->next = cur;
		prev->next = n;
		++size;
	}
}

LinkedList::~LinkedList(){
	Node *temp;
	while(header != nullptr){
		temp = header;
		header = header->next;
		delete temp; 
		//temp = nullptr; //null out temp variable and disconnect, not deallocate!
		/*
		// second approach
		temp = header->next;
		delete header;
		header = temp;
		*/		
	}
}


int main()
{
	LinkedList l;
	l.Append(1);
	l.Append(2);
	l.Append(3);
	l.Append(100);
	l.Prepend(10);//創建list
	l.ToString(); //list的外觀是一組數，但實際的內部結構是阡陌交通。
	l.RemoveFirst();
	l.ToString();
	//std::cout<<l.getSize()<<std::endl;
	l.RemoveLast();
	l.RemoveAt(2);
	l.ToString();
	l.InsertAt(200,2);
	l.ToString();
	std::cout<<l.GetSize()<<std::endl;
	
	return 0;
}
