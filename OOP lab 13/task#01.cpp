#include <iostream>
using namespace std;

class Campusmember {
public:
    string name;
    int age;
    string email;

    Campusmember() {
        name = "";
        age = 0;
        email = "";
    }

    void inputbasic() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Email: ";
        cin >> email;
    }

    void showbasic() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Email: " << email << endl;
    }
};

class Student : public Campusmember {
public:
    float cgpa;
    static int totalUsers;    
    Student() {
        cgpa = 0.0;
        totalUsers++;
    }

    void inputstudent() {
        inputbasic();
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void showstudent() {
        showbasic();
        cout << "CGPA: " << cgpa << endl;
    }

    friend void comparestudents(Student s1, Student s2);

    static void showtotalusers() {
        cout << "Total Resource Users: " << totalUsers << endl;
    }
};

int Student::totalUsers = 0;


class Teacher : public Campusmember {
public:
    int experienceYears;

    Teacher() {
        experienceYears = 0;
        Student::totalUsers++;
    }

    void inputteacher() {
        inputbasic();
        cout << "Enter Years of Experience: ";
        cin >> experienceYears;
    }

    void showteacher() {
        showbasic();
        cout << "Experience: " << experienceYears << " years" << endl;
    }
};


class Staff : public Campusmember {
public:
    string department;

    Staff() {
        department = "";
        Student::totalUsers++;
    }

    void inputstaff() {
        inputbasic();
        cout << "Enter Department: ";
        cin >> department;
    }

    void showstaff() {
        showbasic();
        cout << "Department: " << department << endl;
    }
};


void comparestudents(Student s1, Student s2) {
    cout << "\nComparing Two Students Based on CGPA:\n";
    if (s1.cgpa > s2.cgpa)
        cout << s1.name << " has higher CGPA.\n";
    else if (s1.cgpa < s2.cgpa)
        cout << s2.name << " has higher CGPA.\n";
    else
        cout << "Both have equal CGPA.\n";
}


int main() {

    Student st1, st2;
    Teacher t1;
    Staff sf1;

    cout << "Student 1 = " << endl;
    st1.inputstudent();

    cout << "Student 2" << endl;
    st2.inputstudent();

    cout << "Teacher = " << endl;
    t1.inputteacher();

    cout << "Staff" << endl;
    sf1.inputstaff();

    cout << "Student 1 = " << endl;
    st1.showstudent();

    cout << "Student 22 = " << endl;
    st2.showstudent();

    cout << "Teacher = " << endl;
    t1.showteacher();

    cout << "Staff =" << endl;
    sf1.showstaff();

    comparestudents(st1, st2);

    cout << endl;
    Student::showtotalusers();

    return 0;
}
