# include <iostream>
# include <vector>
# include <string>
#include <algorithm>
using namespace std;

class Node {
public:
	string value;
	Node* next;
	Node() {
		value = ' ';
		next = NULL;
	}
	Node(string value, Node* next) {
		this->value = value;
		this->next = next;
	}
	~Node() {};
};

class Stack {
private:
	Node* top = NULL;
	int stackSize = 0;

public:
	Stack() {}

	void push(string value) {
		Node* newNode = new Node(value, top);
		top = newNode;
		stackSize++;
	}

	string pop() {
		if (top == NULL) {
			return ""; 
		}

		Node* tempNode = top;
		top = top->next;
		string result = tempNode->value;
		delete tempNode;
		stackSize--;
		return result;
	}

	void printStack() {
		Node* tempNode = top;
		while (tempNode != NULL) {
			cout << tempNode->value;
			if (tempNode->next != NULL) {
				cout << "->";
			}
			tempNode = tempNode->next;
		}
		cout << endl;
	}

	bool isEmpty() {
		return top == NULL;
	}

	int returnSize() {
		return stackSize;
	}

	string returnTop() {
		if (top != NULL) {
			return top->value;
		}
		else {
			return "";
		}
	}

	string getFirstElement() {
		if (top != NULL) {
			Node* tempNode = top;
			top = tempNode->next;
			string result = tempNode->value;
			delete tempNode;
			return result;
		}
	}

	void removeFirst() {
		if (top != NULL) {
			Node* tempNode = top;
			top = tempNode->next;
			delete tempNode;
			stackSize--;
		}
	}

	int getIth(string value) {
		int i = 0;
		if (top != NULL) {
			Node* tempNode = top;
			while (tempNode->next != NULL) {
				if (tempNode->value == value) {
					return i;
				}
				tempNode = tempNode->next;
				i++;
			}
		}
		else {
			return -1;
		}
	}

	string getNextElement(string value) {
		if (top != NULL) {
			Node* tempNode = top->next;
			string result = tempNode->value;
			top->next = tempNode->next;
			return result;
		}
	}

	void insertAtLocationI(int i, string value) {
		Node* newNode = new Node(value, top);
		int index = 0;
		if (top == NULL) {
			top = newNode;
			stackSize++;
		}
		else {
			Node* tempNode = top;

			if (i == 0) {
				top = newNode;
				stackSize++;
				return;
			}

			while (index != i - 1) {

				tempNode = tempNode->next;
				index++;
			}
			newNode->next = tempNode->next;
			tempNode->next = newNode;
		}
		stackSize++;
	}

	void deleteAtLocationI(int i) {
		int index = 0;
		if (top != NULL) {
			Node* tempNode = top;
			Node* prevNode = top;

			if (i == 0) {
				top = tempNode->next;
				delete tempNode;
				stackSize--;
				return;
			}

			while (index != i) {
				prevNode = tempNode;
				tempNode = tempNode->next;
				index++;
			}
			prevNode->next = tempNode->next;
			tempNode->next = NULL;
			delete tempNode;
			stackSize--;
		}
	}

	string findX(string value) {
		if (top != NULL) {
			Node* tempNode = top;
			while (tempNode->next != NULL) {
				if (tempNode->value == value) {
					return value;
				}
			}
		}
		else {
			cout << "The value does not exist in the list" << endl;
		}
	}

	void storeElements(string input) {
		int length = 0;
		while (input[length] != '\0') {
			length++;
		}
		for (int i = 0; i < length; i++) {
			string value(1, input[i]);
			Node* newNode = new Node(value, top);
			top = newNode;
			stackSize++;
		}
	}

	~Stack() {
		if (stackSize > 0) {
			for (int i = 0; i < stackSize; i++) {
				pop();
			}
		}
	};
};

class Building {
private:
	string name;
	int capacity;
	int numberOfFloors;
	Stack courses;
public:
	Building() {}

	Building(string name, int capacity, int numberOfFloors){
		this->name = name;
		this->capacity = capacity;
		this->numberOfFloors = numberOfFloors;
	}

	void printBuilding() {
		cout << "Name: " << this->name << endl;
		cout << "Capacity: " << this->capacity << endl;
		cout << "Number of floors: " << this->numberOfFloors << endl;
	}

	void addCourse(string course) {
		courses.push(course);
	}

	~Building() {};
};

class Courses {
private:
	string name;
	int courseNumber;
	int courseUnit;
	string professorName;

public:
	Courses() {}

	Courses(string name, int courseNumber, int courseUnit, string professorName) {
		this->name = name;
		this->courseNumber = courseNumber;
		this->courseUnit = courseUnit;
		this->professorName = professorName;
	}

	void printCourse() {
		cout << "Name: " << this->name << endl;
		cout << "course number: " << this->courseNumber << endl;
		cout << "course unit: " << this->courseUnit << endl;
		cout << "Professor name: " << this->professorName << endl;
	}
	~Courses() {};
};

class Professor {
private:
	string name;
	string courseName;
	int age;
	string sex;
	int payment;
	int numberOfCourses;
	int professorID;
	string mail;
	string major;
	Stack courses;

public:
	Professor(){}

	Professor(string name, string courseName, int age, string sex, int payment, int numberOfCourses,
		int professorID, string mail, string major) {

		this->name = name;
		this->courseName = courseName;
		this->age = age;
		this->sex = sex;
		this->payment = payment;
		this->numberOfCourses = numberOfCourses;
		this->professorID = professorID;
		this->mail = mail;
		this->major = major;
	}
	void printProfessor() {
		cout << "Name: " << this->name << endl;
		cout << "Course name: " << this->courseName << endl;
		cout << "Age: " << this->age << endl;
		cout << "Sex: " << this->sex << endl;
		cout << "Payment: " << this->payment << endl;
		cout << "Professor ID: " << this->professorID << endl;
		cout << "Courses: " << endl;
		for (int i = 0; i < this->numberOfCourses; i++) {
			cout << " - " << courses.pop() << endl;
		}
	}

	void addCourse(string course) {
		courses.push(course);
	}

	string getProfessorMail() {
		return this->mail;
	}

	void setProfessorMail(string mail) {
		this->mail = mail;
	}

	void setProfessorMajor(string major) {
		this->major = major;
	}

	~Professor() {};
};

class Student {
private:
	string name;
	int studentNumber;
	string studentMail;
	int age;
	string sex;
	int numberOfCourses;
	Stack courses;

public:
	Student() {}

	Student(string name, int studentNumber, string studentMail, int age) {
		this->name = name;
		this->studentNumber = studentNumber;
		this->studentMail = studentMail;
		this->age = age;
		this->sex = "";
	}

	Student(string name, int studentNumber, string studentMail, int age, string sex, int numberOfCourses) {
		this->name = name;
		this->studentNumber = studentNumber;
		this->studentMail = studentMail;
		this->age = age;
		this->sex = sex;
		this->numberOfCourses = numberOfCourses;
	}

	void enroll(string course) {
		courses.push(course);
	}

	void swap(string originalCourse, string courseToSwitch, int numberOfCourses) {
		if (find(courses.begin(), courses.end(), originalCourse) == courses.end()) {
			cout << "The course you want to switch is not in your course cart. " << endl << endl;
		}

		for (int i = 0; i < numberOfCourses; i++) {
			if (courses[i] == originalCourse) {
				courses[i] = courseToSwitch;
				cout << "The course has successfully swapped. Now your courses are " << endl;
				printStudent();
			}
		}
	}

	void drop(string originalCourse, int numberOfCourses) {
		auto it = find(courses.begin(), courses.end(), originalCourse);
		if (it == courses.end()) {
			cout << "The course you want to switch is not in your course cart. " << endl;
		}
		else {
			courses.erase(it);
			cout << originalCourse << "has successfully removed from courses cart" << endl;
			printStudent();
		}
	}

	void printStudent() {
		cout << "Name: " << this->name << endl;
		cout << "Student number: " << this->studentNumber << endl;
		cout << "Student mail: " << this->studentMail << endl;
		cout << "Age: " << this->age << endl;
		if (this->sex != "") {
			cout << "Sex: " << this->sex << endl;
		}
		cout << "Courses: " << endl;
		for (int i = 0; i < this->numberOfCourses; i++) {
			cout << " - " << courses[i] << endl;
		}
	}

	string getStudentMail() {
		return this->studentMail;
	}

	void setStudentMail(string studentMail) {
		this->studentMail = studentMail;
	}


	~Student() {}
};

//class UnderGraduate :Student {
//private:
//	string major;
//public:
//	UnderGraduate(string major) {
//		this->major = major;
//	}
//};

int main() {
	int userChoice = 0;

	do {
		cout << "Welcome to Univerisity system." << endl << "We offer you several options " <<
			endl << "Option 1: Student" << endl << "Option 2: Professor" << endl << "Option 3: Course"
			<< endl << "Option 4: Building" << endl << "Option 5: Ends the system" << endl << "User choice: ";
		cin >> userChoice;
		if (userChoice == 1) {
			int numberOfCourses = 0;
			cout << "How many courses are you taking this semester? ";
			cin >> numberOfCourses;
			cout << endl;
			Student s1("James", 123, "yka138@sfu.ca", 20, "Male", numberOfCourses);
			string courseName;
			for (int i = 0; i < numberOfCourses; i++) {
				cout << "Type the name of a course: ";
				getline(cin >> ws, courseName);
				s1.enroll(courseName);
			}
			cout << endl;
			//UnderGraduate g1("math");

			s1.printStudent();
			int userChoice = 0;
			cout << endl << "Which service do you want to take? " << endl;
			cout << "Option 1: Swap" << endl << "Option 2: Drop" << endl << "Option 3: End the system" << endl
				<< "Please choose a number between 1-3: ";
			cin >> userChoice;
			if (userChoice == 1) {
				string originalCourse;
				string courseToSwitch;
				cout << "Thank you to choose the SWAP service. " << endl;
				cout << "Please tell me the course you want to switch from your course cart: ";
				getline(cin >> ws, originalCourse);
				cout << "Please tell me the course you want to replace: ";
				getline(cin >> ws, courseToSwitch);
				s1.swap(originalCourse, courseToSwitch, numberOfCourses);
			}
			else if (userChoice == 2) {
				string originalCourse;
				cout << "Thank you to choose the DROP service. " << endl;
				cout << "Please tell me the course you want to drop: ";
				getline(cin >> ws, originalCourse);
				s1.drop(originalCourse, numberOfCourses);
			}
			else if (userChoice == 3) {
				cout << "Thank you for using the university system.";
				return 0;
			}
		}
		else if (userChoice == 2) {
			int numberOfCourses = 0;
			cout << "Hello Professor." << endl << "How many courses are you teaching this semester? ";
			cin >> numberOfCourses;
			cout << endl;
			Professor p1("Pro1", "Computing Scinece", 45, "Male", 6000, numberOfCourses, 540349534, "abs@sfu.ca", "Computer Scince");

			string courseName;
			for (int i = 0; i < numberOfCourses; i++) {
				cout << "Type the name of a course: ";
				getline(cin >> ws, courseName);
				p1.addCourse(courseName);
			}
			cout << endl;

			p1.printProfessor();
		}
		else if (userChoice == 3) {

			Courses c1("CMPT125", 543798, 3, "David");
			c1.printCourse();
		}
		else if (userChoice == 4) {
			int numberOfCourses = 0;
			cout << "This service is for setting a building."
				<< endl << "Please tell me the number of courses for the building: ";
			cin >> numberOfCourses;
			cout << endl;
			Building b1("SUB", 4000, 4);
			string courseName;
			for (int i = 0; i < numberOfCourses; i++) {
				cout << "Type the name of a course: ";
				getline(cin >> ws, courseName);
				b1.addCourse(courseName);
			}
			cout << endl;
			b1.printBuilding();
		}
	} while (userChoice != 5);
	


	

	//s1.setStudentMail("jam123@sfu.ca");
	//cout << "After set" << endl;
	//s1.printStudent();

	//cout << s1.getStudentMail() << endl;
}