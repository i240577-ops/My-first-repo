#include <iostream>
#include <string>
using namespace std;


//Task 1
//class Vector2D {
//private:
//    double x, y;
//
//public:
//
//    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}
//
//
//    Vector2D operator+(const Vector2D& other) const {
//        return Vector2D(x + other.x, y + other.y);
//    }
//
//    Vector2D operator-(const Vector2D& other) const {
//        return Vector2D(x - other.x, y - other.y);
//    }
//
//    double operator*(const Vector2D& other) const {
//        return x * other.x + y * other.y; // Dot product
//    }
//
//
//    string toString() const {
//        return "(" + to_string(x) + ", " + to_string(y) + ")";
//    }
//
//};
//
//int main() {
//    Vector2D v1(3, 4);
//    Vector2D v2(1, 2);
//
//    Vector2D sum = v1 + v2;
//    Vector2D diff = v1 - v2;
//    double dot = v1 * v2;
//
//    cout << "v1 + v2 = " << sum.toString() << std::endl;
//    cout << "v1 - v2 = " << diff.toString() << std::endl;
//    cout << "v1 * v2 = " << dot << std::endl;
//
//    return 0;
//}






//Task 2


//class Time {
//private:
//    int hours;
//    int minutes;
//
//    // Helper to normalize minutes into hours
//    void normalize() {
//        if (minutes >= 60) {
//            hours += minutes / 60;
//            minutes = minutes % 60;
//        }
//    }
//
//public:
//
//    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
//        normalize();
//    }
//
//
//    Time operator+(const Time& other) const {
//        Time result;
//        result.hours = hours + other.hours;
//        result.minutes = minutes + other.minutes;
//        result.normalize();
//        return result;
//    }
//
//
//    bool operator>(const Time& other) const {
//        if (hours > other.hours) return true;
//        if (hours == other.hours && minutes > other.minutes) return true;
//        return false;
//    }
//
//    bool operator<(const Time& other) const {
//        if (hours < other.hours) return true;
//        if (hours == other.hours && minutes < other.minutes) return true;
//        return false;
//    }
//
//
//    int getHours() const { return hours; }
//    int getMinutes() const { return minutes; }
//
//    // Display function
//    void display() const {
//        cout << hours << " hr " << minutes << " min";
//    }
//};
//
//int main() {
//    Time t1(2, 45);
//    Time t2(1, 30);
//
//    Time total = t1 + t2;
//    bool check = (t1 > t2);
//
//    cout << "t1 + t2 = ";
//    total.display();
//   cout << endl;
//
//   cout << "Is t1 > t2? " << (check ? "Yes" : "No") << endl;
//
//    return 0;
//}





//task 3


class Inventory {
private:
    int quantity;

public:
    // Constructor
    Inventory(int q = 0) : quantity(q) {
        if (quantity < 0) quantity = 0;
    }


    Inventory operator+(int addQty) const {
        return Inventory(quantity + addQty);
    }


    Inventory operator-(int removeQty) const {
        if (removeQty >= quantity) {
            cout << "Not enough stock! Operation ignored.\n";
            return Inventory(quantity); // Keep same quantity
        }
        return Inventory(quantity - removeQty);
    }

    // Getter for current quantity
    int getQuantity() const {
        return quantity;
    }
};

int main() {
    Inventory item1(50);

    item1 = item1 + 25;
   cout << "After adding: " << item1.getQuantity() << std::endl;

    item1 = item1 - 40;
  cout << "After selling: " << item1.getQuantity() << std::endl;

    item1 = item1 - 50;
    cout << "After invalid removal: " << item1.getQuantity() << std::endl;

    return 0;
}
