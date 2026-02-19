//#include <iostream>
//#include <string>
//using namespace std;
//
//class StringValidator {
//private:
//    string input;
//
//public:
//    StringValidator(const string& str) : input(str) {}
//
//    bool isValid() const {
//        for (int i = 0; i < input.length(); i++) {
//            if (input[i] < 'A' || input[i] > 'Z') {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    void displayResult() const {
//        if (isValid())
//            cout << "The string " << input << " is VALID (only uppercase letters)." << endl;
//        else
//            cout << "The string " << input << " is INVALID (contains non-uppercase characters)." << endl;
//    }
//};
//
//int main() {
//    StringValidator s1("QASIM");
//    StringValidator s2("World");
//    StringValidator s3("YOU");
//    StringValidator s4("123ABC");
//    StringValidator s5("ME!");
//
//    s1.displayResult();
//    s2.displayResult();
//    s3.displayResult();
//    s4.displayResult();
//    s5.displayResult();
//
//    return 0;
//}
