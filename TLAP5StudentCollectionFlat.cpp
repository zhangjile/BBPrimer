//Chapter 5 Solving Problems With Classes
//flat design, well, no design pattern is applied actually.
#include<iostream>
#include<string>
using std::string; using std::cout; using std::endl;

class StudentRecord {
	public:
	StudentRecord();
	StudentRecord(int Num, string Na, int Gra);
	void SetStudentNum(int num){StudentNum = num;}
	int GetStudentNum(){return StudentNum;}
	void SetStudentName(string name){StudentName = name;}
	string GetStudentName(){return StudentName;}
	void SetStudentGrade(int grade);
	int GetStudentGrade()const {return Grade;} //const correctness, line 35 
	private:
	int StudentNum;
	string StudentName;
	int Grade;
};

StudentRecord::StudentRecord(){
	StudentNum = 0;
	StudentName = "";
	Grade = 0;
}

StudentRecord::StudentRecord(int Num, string Na, int Gra)
	:StudentNum {Num}, StudentName{Na}, Grade{Gra}{}
	
string LetterGrade(const StudentRecord &source){
	if(source.GetStudentGrade() < 0 || source.GetStudentGrade() > 100) {
		return "Error";
	}
	const int CATEGORIES = 11;
	const string GRADELETTERS [] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
	const int LOWERBOUNDS[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
	size_t index = 0;
	while(index < CATEGORIES && LOWERBOUNDS[index] <= source.GetStudentGrade()){
		++index;
	}
	return GRADELETTERS[index-1];
}

struct StudentNode {
	StudentRecord StudentData;
	StudentNode* next;
};

typedef StudentNode* StudentList;

//non-member function 
//What a long list of parameters:)
void AddRecord(StudentList &sl, int num, string name, int grade){
	StudentRecord NewRecord(num,name,grade); //call constructor. COMPOSITION syntax
	StudentNode *temp = new StudentNode; //line 16-20,兜個圈子就行了
	//StudentNode *temp = nullptr; //intrinsic function is not supported in Mobile C
	if(sl != nullptr){
		temp->StudentData = NewRecord;
		temp->next = sl;
	}
	else{
		temp->StudentData = NewRecord;
		temp->next = nullptr;
	}
	sl = temp;
	temp = nullptr; //caution 18/02/20
}

StudentRecord RecordWithNum(const StudentList &sl, int num){
	StudentNode* temp = sl;
	while(temp != nullptr && temp->StudentData.GetStudentNum() != num){
		temp = temp->next;
	}
	if(temp == nullptr){
		StudentRecord DummyRecord(-1, "", -1);
		return DummyRecord; //temporary error handling, trust from client code
	}
	return temp->StudentData;
}

//a brilliant and successful path/circuit
StudentRecord Retrieve(const StudentList &sl, int num){
	StudentNode* temp = sl;
	while(temp != nullptr){
		if(temp->StudentData.GetStudentNum() == num){
			return temp->StudentData;
			break;
		}
		temp = temp->next;
	}
	StudentRecord DummyRecord(-1, "", -1);	
	return DummyRecord;
}

//void RemoveRecord(StudentList &sl, int num); //喘口氣，take the time to take aim
void RemoveRecord(StudentList &sl, int num){
	StudentNode *temp = sl, *trail = nullptr;
	if(temp->StudentData.GetStudentNum() == num){
		sl = temp->next;
		delete temp;
	}
	while(temp != nullptr && temp->StudentData.GetStudentNum() != num){
		trail = temp;
		temp = temp->next;
	}
	if(temp == nullptr){
		return;
	}
	else{
		trail->next = temp->next;
	}
	delete temp; //"temp = nullptr; " is a fatal error that leaks.
	trail = nullptr;
}

//另一個RemoveRecord邏輯實現路線
void RemoveRecordShort(StudentList &sl, int num){	
	if(sl->StudentData.GetStudentNum() == num){
		sl = sl->next;
	}
	StudentNode* temp = sl, *trail = nullptr;			
	while(temp->next != nullptr){ 
		//temp != nullptr, 走到最後temp是空，於是執行line 126會出錯。COOL!
		trail = temp;
		temp = temp->next;
		if(temp->StudentData.GetStudentNum() == num){
			trail->next = temp->next;
			delete temp;
			break;	//找到之後即刻跳出，否則temp往前跑導致煮熟的鴨子還飛了！GOOD
		}
	}

}

void Print(const StudentList &sl){
	StudentNode* temp = sl;
	while(temp != nullptr){
		cout << temp->StudentData.GetStudentName() << endl;
		temp = temp->next;
	}
}

int main(){
	StudentRecord sr {8001, "Hot",88};
	cout <<LetterGrade(sr)<<endl;
	StudentList sl = nullptr;
	AddRecord(sl, 1001, "Mike", 90);
	AddRecord(sl, 2001, "Nike", 80);
	AddRecord(sl, 3001, "Quark", 70);
	AddRecord(sl, 4001, "Shark", 60);
	Print(sl);
	cout<<endl;
	StudentRecord temp = RecordWithNum(sl, 3001);
	cout<<temp.GetStudentGrade()<<endl;
	temp = Retrieve(sl, 1005);
	cout<<temp.GetStudentGrade()<<endl;
	RemoveRecordShort(sl, 2001);
	Print(sl); 
	return 0;
}

