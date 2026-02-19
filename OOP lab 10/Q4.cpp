#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
        cout << "Time Created: " << hours << "h " << minutes << "m " << seconds << "s\n";
    }

    ~Time() {
        cout << "Time Destroyed: " << hours << "h " << minutes << "m " << seconds << "s\n";
    }

    int getTotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    void show() const {
        cout << hours << "h " << minutes << "m " << seconds << "s";
    }
};

class User;

class Device {
private:
    string deviceName;
    string brand;

public:
    Device(string n, string b) {
        deviceName = n;
        brand = b;
        cout << "Device Created " << deviceName << " " << brand << endl;
    }

    ~Device() {
        cout << "Device Destroyed " << deviceName << endl;
    }

    void show() {
        cout << "Device: " << deviceName << " ,  Brand: " << brand << endl;
    }
};

// ------------------ WorkoutSession Class ---------------------
class WorkoutSession {
private:
    string type;
	Time duration;           // Composition between WorkoutSession and Time
    Device* deviceUsed;      // Association

public:
    WorkoutSession(string t, Time d, Device* dev)
        : type(t), duration(d)   
    {
        deviceUsed = dev;
        cout << "WorkoutSession Created: Type: " << type << endl;
    }

    ~WorkoutSession() {
        cout << "WorkoutSession Destroyed: " << type << endl;
    }

    bool operator==(const WorkoutSession& other) const {
        return duration.getTotalSeconds() == other.duration.getTotalSeconds();
    }

    void show() {
        cout << "Workout Type: " << type << " , Duration: ";
        duration.show();
        cout << endl;

        if (deviceUsed) {
            cout << "Device used: ";
            deviceUsed->show();
        }
    }
};

class User {
private:
    string name;
    int id;

public:
    User(string n, int i) {
        name = n;
        id = i;
        cout << "User Created " << name << endl;
    }

    ~User() {
        cout << "User Destroyed " << name << endl;
    }

    void show() {
        cout << "User: " << name << " , ID: " << id << endl;
    }
};

int main() {

    User u1("qasim", 101);
	//associating Device with User
    Device d1("Smartwatch", "FitPro");

    Time t1(1, 20, 30);     
    Time t2(1, 20, 30);   

    // Creating WorkoutSessions (Aggregation + Composition)
    WorkoutSession s1("Running", t1, &d1);
    WorkoutSession s2("Cycling", t2, &d1);

    s1.show();
    s2.show();

    if (s1 == s2)
        cout << "Both sessions have equal duration.\n";
    else
        cout << "Sessions differ in duration.\n";

    return 0;
}
