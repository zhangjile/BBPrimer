//Chapter 5 Solving Problems With Classes
//design decisions: class StudentCollection;
//work towards a better structure 
#include<iostream>
#include<string>

using std::cout; using std::string; using std::endl;

//exception handling is controvertial, 
//if taken away, the user will have to take up the responsibility of ensuring the client code won't crash, and it's justifiable.
class IsValidGrade : public std::runtime_error
{
public:
    IsValidGrade() : std::runtime_error  {"Invalid grade"}
    {}
    ~IsValidGrade() = default;
};

class StudentRecord{
public:
	void SetStudentNum(int num){StudentNum = num;}
	int GetStudentNum(){return StudentNum;}
	void SetStudentName(string name){StudentName = name;}
	string GetStudentName(){return StudentName;}
	void SetStudentGrade(int grade);
	int GetStudentGrade(){return Grade;}
	StudentRecord();
	StudentRecord(int num, string name, int grade);
	string LetterGrade();
private:
	int StudentNum;
	string StudentName;
	int Grade;
	bool IsValid(int num);
};

StudentRecord::StudentRecord(){ //default constructor, good practice
	StudentNum = -1;
	StudentName ="default_name";
	Grade = -1;
}

bool StudentRecord::IsValid(int num){
	if(num >= 0 && num <= 100) return true;
	else return false;
}

StudentRecord::StudentRecord(int num, string name, int grade)
try:StudentNum {num}, StudentName {name}, Grade {grade} {
	if(!IsValid(grade)){		
		throw IsValidGrade{}; 
	}
}catch (const IsValidGrade &ex){
	std::cerr<<ex.what();
}

void StudentRecord::SetStudentGrade(int grade){
	if(IsValid(grade)){
		Grade = grade;
	}
}

//convert a StudentGrade into a letter representation
//a big piece of pearl
string StudentRecord::LetterGrade(){
	if(!IsValid(Grade)) return "ERROR"; // good defense
	const int CATEGORIES = 11;
	const string GRADELETTERS [] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
	const int LOWERBOUNDS[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
	size_t index = 0;
	while(index < CATEGORIES && LOWERBOUNDS[index] <= Grade){ //this->Grade
		++index;
	}
	return GRADELETTERS[index-1];
}

class StudentCollection{
private:
	struct StudentNode{
		StudentRecord StudentData;
		StudentNode* next;
	};
public:
	StudentCollection();
	~StudentCollection();
	StudentCollection(const StudentCollection &original); //deep copy constructor
	StudentCollection(StudentCollection &&original); //move constructor
	StudentCollection& operator =(const StudentCollection &rhs);
	void AddRecord(const StudentRecord &NewRecord);
	StudentRecord RecordWithNum(int num);
	void RemoveRecord(int num);
	void Print();
private:
	typedef StudentNode* StudentList; //StudentList is a StudentNode*
	StudentList ListHead;  //the data member of a StudentCollection

	//private helper, detach interface and implementation
	void DeleteList(StudentList sl);  
	StudentList CopiedList(const StudentList &source);
};

StudentCollection::StudentCollection(){
	ListHead = nullptr;
}

StudentCollection:: ~StudentCollection(){
	DeleteList(ListHead);
}

//sharp blade
void StudentCollection::DeleteList(StudentList sl){
	if(sl == nullptr) return;
	StudentNode* temp = nullptr;
	while(sl != nullptr){
		temp = sl;
		sl = sl->next;
		delete temp;
	}
}

StudentCollection::StudentCollection(const StudentCollection &source){
	ListHead = CopiedList(source.ListHead);
	cout <<"deep copy constructor called"<<endl;
}

StudentCollection::StudentCollection(StudentCollection &&source){
	ListHead = source.ListHead;
	source.ListHead = nullptr;
	cout <<"move constructor called "<<endl;
}

StudentCollection& StudentCollection::operator =(const StudentCollection &rhs){
	if(this != &rhs){ //compare 2 addresses
		DeleteList(ListHead);
		ListHead = CopiedList(rhs.ListHead);
	} 	
	return *this; 
}

//copy one StudentList variable to another, 2 distinct addresses, no more double link
StudentCollection::StudentList StudentCollection::CopiedList(const StudentCollection::StudentList &source){
	StudentNode* NewList = new StudentNode;	//create a new node, a new empty box
	NewList-> StudentData = source-> StudentData;
	StudentNode* NewLoopPtr = NewList; 
	StudentNode* OldLoopPtr = source->next;
	while(OldLoopPtr != nullptr){
		NewLoopPtr->next = new StudentNode;
		NewLoopPtr = NewLoopPtr->next;
		NewLoopPtr->StudentData = OldLoopPtr-> StudentData;
		OldLoopPtr = OldLoopPtr->next;
	}
	NewLoopPtr->next = nullptr;
	return NewList;
}

//add record in the head position
void StudentCollection::AddRecord(const StudentRecord &NewRecord){
	StudentNode* temp = new StudentNode;
	temp->StudentData = NewRecord;
	temp->next = ListHead;
	ListHead = temp;
}

//search for a specific StudentRecord for a StudentID in a StudentCollection object
StudentRecord StudentCollection::RecordWithNum(int idNum){
    StudentNode* LoopPtr = ListHead;
    while(LoopPtr != nullptr && LoopPtr ->StudentData.GetStudentNum() != idNum){
        LoopPtr = LoopPtr ->next;
    }
    if(LoopPtr == nullptr){
        StudentRecord DummyRecord(-1, "", -1);
        return DummyRecord;
        }else {
            return LoopPtr -> StudentData;
        }
}

//remove a StudentRecord from a StudentCollection object
//organizing the program flow with class is much more efficient, operation on this 
void StudentCollection::RemoveRecord(int IDNum){
	StudentNode* LoopPtr = ListHead;
	StudentNode* Trail = nullptr;
	while(LoopPtr != nullptr && LoopPtr->StudentData.GetStudentNum() != IDNum){
		Trail = LoopPtr;
		LoopPtr = LoopPtr->next;
	}
	if(LoopPtr == nullptr){
		return;
	}
	if(Trail == nullptr){
		ListHead = ListHead->next;
	}
	else{
		Trail->next = LoopPtr->next;	
	}
	delete LoopPtr; 
	Trail = nullptr; 
}
	

void StudentCollection::Print(){
	StudentNode* temp = ListHead;
	while(temp != nullptr){
		cout<<temp->StudentData.GetStudentNum()<<", "<<temp->StudentData.GetStudentName()<<", "<<temp->StudentData.GetStudentGrade()<<endl;
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	StudentRecord sr(2001, "Lam", 80);
	sr.SetStudentGrade(30);
	cout<<sr.LetterGrade()<<endl;

	StudentCollection sc;	
	sc.AddRecord(sr);
	sc.AddRecord(StudentRecord(3001,"Liu", 90)); 
	sc.AddRecord(StudentRecord(4001,"Gao", 60));
	sc.RemoveRecord(4001);
	StudentCollection scDeepCopy = sc;
	scDeepCopy.Print();
	sr = sc.RecordWithNum(3001);
	cout<<sr.GetStudentName()<<endl;
	return 0;
}
