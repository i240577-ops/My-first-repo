#include <iostream>
using namespace std;


class Person {
public:
    string name;
    int age;

    Person(string n = "", int a = 0) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};


class Student : public Person {
public:
    int studentID;
    int gradeLevel;

    Student(string n = "", int a = 0, int id = 0, int grade = 0): Person(n, a)
    {
        studentID = id;
        gradeLevel = grade;
    }

    void displayStudent() {
        cout << "Student ID: " << studentID << endl;
        cout << "Grade Level: " << gradeLevel << endl;
    }
};


class Teacher : public Person {
public:
    string subject;
    int roomNumber;

    Teacher(string n = "", int a = 0, string sub = "", int room = 0)
        : Person(n, a)
    {
        subject = sub;
        roomNumber = room;
    }

    void displayTeacher() {
        cout << "Subject: " << subject << endl;
        cout << "Room Number: " << roomNumber << endl;
    }
};

class GraduateStudent : public Student, public Teacher {
public:
    string researchTopic;

    GraduateStudent(string n, int a, int id, int grade, string sub, int room, string topic): Student(n, a, id, grade),
        Teacher(n, a, sub, room)
    {
        researchTopic = topic;
    }

    void display() {
        cout << "Graduate Student Details" << endl;;

        cout << "Person part from Student" << endl;;
        Student::displayPerson();

        cout << "Person part from Teacher" << endl;;
        Teacher::displayPerson();

        cout << "Student Details" << endl;;
        displayStudent();

        cout << "Teacher Details" << endl;;
        displayTeacher();

        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main() {
    GraduateStudent gs("Ahmed Ali", 24, 1234, 16, "Mathematics", 205, "Machine Learning"
    );

    gs.display();

    return 0;
}
