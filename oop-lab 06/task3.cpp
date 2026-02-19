#include <iostream>
#include <string>
using namespace std;

class calendar {
private:
    string tasks[12][31];
    int currentyear;

public:
    calendar(int year) {
        currentyear = year;
    }

    void addtask(string task, int day, int month) {
        
        tasks[month - 1][day - 1] = task;
        cout << "task added on " << day << "-" << month << "-" << currentyear << endl;
    }

    void removetask(int day, int month) {
        tasks[month - 1][day - 1] = "";
        cout << "task removed from " << day << "-" << month << "-" << currentyear << endl;
    }

    void showtasks() {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 31; j++) {
                if (tasks[i][j]!= "\0") {
                    cout << "date= " << (i + 1) << "-" << (j + 1) << "-" << currentyear << " = " << tasks[i][j] << endl;
                }
            }
        }
    }
};

int main() {
    calendar calendar1(2025);
    string task;
    cout << "enter task yo have to do" << endl;
    cin >> task;
    int date;
    int month;
    cout << "enter date" << endl;
    cin >> date;
    cout << "enter month" << endl;
    cin >> month;
    calendar1.addtask(task, date, month);

    calendar1.showtasks();
    int rdate;
    int rmonth;
    cout << "enter the date from which you want to remove te task" << endl;
    cin >> rdate;
    cout << "enter the month from which you want to remove te task" << endl;
    cin >> rmonth;
    calendar1.removetask(rdate, rmonth);
    calendar1.showtasks();

    return 0;
}
