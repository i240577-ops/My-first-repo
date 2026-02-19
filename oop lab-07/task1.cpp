//#include <iostream>
//using namespace std;
//
//class Rectangle {
//private:
//    double width;
//    double height;
//    static double totalArea;
//
//public:
//    Rectangle() : width(0), height(0) {}
//
//    Rectangle(double w, double h) : width(w), height(h) {}
//
//    void setWidth(double w) {
//        width = w;
//    }
//
//    void setHeight(double h) {
//        height = h;
//    }
//
//    double getWidth() const {
//        return width;
//    }
//
//    double getHeight() const {
//        return height;
//    }
//
//    double calcArea() {
//        double area = width * height;
//        totalArea += area;
//        return area;
//    }
//
//    static double getTotalArea() {
//        return totalArea;
//    }
//
//    ~Rectangle() {}
//};
//
//double Rectangle::totalArea = 0;
//
//int main() {
//    int n;
//    cout << "Enter number of rectangles: ";
//    cin >> n;
//
//    double w, h;
//
//    for (int i = 1; i <= n; i++) {
//        cout << "Enter width of rectangle " << i << ": ";
//        cin >> w;
//        cout << "Enter height of rectangle " << i << ": ";
//        cin >> h;
//
//        Rectangle rect(w, h);
//        double area = rect.calcArea();
//        cout << "Area of rectangle " << i << " = " << area << endl;
//    }
//
//    cout << "Total area of all rectangles = " << Rectangle::getTotalArea() << endl;
//
//    return 0;
//}
