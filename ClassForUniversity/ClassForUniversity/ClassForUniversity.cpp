# include <iostream>
# include <vector>
# include <string>
#include <algorithm>


using namespace std;

class Professor {
private:
	string name;
	string courseName;
	int age;
	string sex;
	int payment;

public:
	Professor(){}

	Professor(string name, string courseName, int age, string sex, int payment) {
		this->name = name;
		this->courseName = courseName;
		this->age = age;
		this->sex;
		this->payment = payment;
	}


};

class Student {
private:
	string name;
	int studentNumber;
	string studentMail;
	int age;
	string sex;
	int numberOfCourses;
	vector<string> courses;

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
		courses.push_back(course);
	}

	void swap(string originalCourse, string courseToSwitch, int numberOfCourses) {
		if (find(courses.begin(), courses.end(), originalCourse) == courses.end()) {
			cout << "The course you want to switch is not in your course cart. " << endl;
		}

		for (int i = 0; i < numberOfCourses; i++) {
			if (courses[i] == originalCourse) {
				courses[i] = courseToSwitch;
				cout << "The course has successfully swapped. Now your courses are ";

			}
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
		cout << "Please tell me the course you want to replace ";
		getline(cin >> ws, courseToSwitch);
		s1.swap(originalCourse, courseToSwitch, numberOfCourses);
		s1.printStudent();
	}
	else if (userChoice == 2) {
		string originalCourse;
		cout << "Thank you to choose the DROP service. " << endl;
		cout << "Please tell me the course you want to drop: ";
		getline(cin >> ws, originalCourse);
	}
	else if (userChoice == 3) {
		return 0;
	}

	//s1.setStudentMail("jam123@sfu.ca");
	//cout << "After set" << endl;
	//s1.printStudent();

	//cout << s1.getStudentMail() << endl;
}