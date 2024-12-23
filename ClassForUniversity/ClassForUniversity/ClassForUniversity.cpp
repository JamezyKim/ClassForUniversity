# include <iostream>
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
public:
	Student() {}

	Student(string name, int studentNumber, string studentMail, int age) {
		this->name = name;
		this->studentNumber = studentNumber;
		this->studentMail = studentMail;
		this->age = age;
		this->sex = "";
	}

	Student(string name, int studentNumber, string studentMail, int age, string sex) {
		this->name = name;
		this->studentNumber = studentNumber;
		this->studentMail = studentMail;
		this->age = age;
		this->sex = sex;
	}

	void printStudent() {
		cout << "Name: " << this->name << endl;
		cout << "Student number: " << this->studentNumber << endl;
		cout << "Student mail: " << this->studentMail << endl;
		cout << "Age: " << this->age << endl;
		if (this->sex != "") {
			cout << "Sex: " << this->sex << endl;
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

class UnderGraduate :Student {
private:
	string major;
public:
	UnderGraduate(string major) {
		this->major = major;

	}
};

int main() {
	Student s1("James", 123, "yka138@sfu.ca", 20);
	Student s2("Aiden", 456, "ad345@sfu.ca", 23, "Male");
	UnderGraduate g1("math");

	s1.printStudent();
	s1.setStudentMail("jam123@sfu.ca");
	cout << "After set" << endl;
	s1.printStudent();

	cout << s1.getStudentMail() << endl;
}