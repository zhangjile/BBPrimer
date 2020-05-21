//Chapter 5 Solving Problems With Classes
//design decisions: class StudentCollection;
//架構優化/設計 
#include<iostream>
#include<string>
using std::cout; using std::string; using std::endl;

class InvalidGrade : public std::runtime_error
{
public:
    InvalidGrade() : std::runtime_error  {"Invalid grade"}
    {}
    ~InvalidGrade() = default;
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
	bool IsValidGrade(int num);
};

StudentRecord::StudentRecord(){
	StudentNum = -1;
	StudentName ="default_name";
	Grade = -1;
}

bool StudentRecord::IsValidGrade(int num){
	if(num >= 0 && num <= 100) return true;
	else return false;
}

StudentRecord::StudentRecord(int num, string name, int grade)
try:StudentNum {num}, StudentName {name}, Grade {grade} {
	if(!IsValidGrade(grade)){		
		throw InvalidGrade{}; 
	}
}catch (const InvalidGrade &ex){
	std::cerr<<ex.what();
}

void StudentRecord::SetStudentGrade(int grade){
	if(IsValidGrade(grade)){
		Grade = grade;
	}
}

string StudentRecord::LetterGrade(){
	if(!IsValidGrade(Grade)) return "ERROR"; // good defense
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
	typedef StudentNode* StudentList;
	StudentList ListHead;
	void DeleteList(StudentList sl);
	StudentList CopiedList(const StudentList &source);
};

StudentCollection::StudentCollection(){
	ListHead = nullptr;
}

StudentCollection:: ~StudentCollection(){
	DeleteList(ListHead);
	//cout <<"destructor called for THIS: "<<this<<endl;
}
/*
void StudentCollection::DeleteList(StudentList sl){
	if(sl == nullptr) return;
	StudentNode* temp = nullptr;
	while(sl != nullptr){
		temp = sl;
		sl = sl->next;
		delete temp;
	}
}

*/
//playground, just wow 24/03/2020


void StudentCollection::DeleteList(StudentList sl){
	if(sl == nullptr) return;
	constexpr int x = 2;
	StudentNode** temp = new StudentNode*[x]; //perfectly legal
	while(sl != nullptr){
		*temp = sl; //legal, but abnormal:)
		//temp[0] = sl; //ok
		sl = sl->next;
		delete temp;
		//delete temp[x]; //ok, which is safer?
	}
}


StudentCollection::StudentCollection(const StudentCollection &source){
	ListHead = CopiedList(source.ListHead);
	cout <<"deep copy constructor called"<<endl;
}

StudentCollection::StudentCollection(StudentCollection &&source){
	ListHead = source.ListHead;
	source.ListHead = nullptr;
	cout <<"move constructor called for "<<endl;
}

StudentCollection& StudentCollection::operator =(const StudentCollection &rhs){
	if(this != &rhs){ //比較兩個地址是否相同, & addressof operator
		DeleteList(ListHead);
		ListHead = CopiedList(rhs.ListHead);
	} 	
	return *this; //dereference this pointer
}

//氣定，裝配，每一行代碼的手感清晰。不是閉著眼睛亂試。
StudentCollection::StudentList StudentCollection::CopiedList(const StudentCollection::StudentList &source){
	StudentNode* NewList = new StudentNode;
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

void StudentCollection::AddRecord(const StudentRecord &NewRecord){
	StudentNode* temp = new StudentNode;
	temp->StudentData = NewRecord;
	temp->next = ListHead;
	ListHead = temp;
}

StudentRecord StudentCollection::RecordWithNum(int idNum) {
    StudentNode * loopPtr = ListHead;
    while (loopPtr != NULL && loopPtr->StudentData.GetStudentNum() != idNum) {
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL) {
      StudentRecord dummyRecord(-1, "",-1);
        return dummyRecord;
    } else {
        return loopPtr->StudentData;
    }
}

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
	delete LoopPtr; //deallocate to prevent memory leak;17/2/2020 feel at home
	Trail = nullptr; //remove double-link to be safe. 
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
	StudentCollection sc;	//sc.Print(); //display nothing:)
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

