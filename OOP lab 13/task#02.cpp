//#include <iostream>
//using namespace std;
//
//class BasicVehicle {
//public:
//    string brand;
//    string model;
//    int engineCC;
//
//    void inputBasic() {
//        cout << "Enter Brand: ";
//        cin >> brand;
//        cout << "Enter Model: ";
//        cin >> model;
//        cout << "Enter Engine CC: ";
//        cin >> engineCC;
//    }
//
//    void showBasic() {
//        cout << "Brand: " << brand << endl;
//        cout << "Model: " << model << endl;
//        cout << "Engine CC: " << engineCC << endl;
//    }
//};
//
//class RegisteredVehicle : public BasicVehicle {
//public:
//    string regNumber;
//    string ownerName;
//    int regYear;
//
//    void inputReg() {
//        inputBasic();
//        cout << "Enter Registration Number: ";
//        cin >> regNumber;
//        cout << "Enter Owner Name: ";
//        cin >> ownerName;
//        cout << "Enter Registration Year: ";
//        cin >> regYear;
//    }
//
//    void showReg() {
//        showBasic();
//        cout << "Registration Number: " << regNumber << endl;
//        cout << "Owner Name: " << ownerName << endl;
//        cout << "Registration Year: " << regYear << endl;
//    }
//};
//
//class FinalVehicle : public RegisteredVehicle {
//private:
//    float yearlyTax;
//
//public:
//    static int totalApproved;
//
//    FinalVehicle() {
//        yearlyTax = 0;
//    }
//
//    void calculateTax() {
//        if (engineCC <= 1000) yearlyTax = 2000;
//        else if (engineCC <= 2000) yearlyTax = 5000;
//        else yearlyTax = 10000;
//    }
//
//    void inputFinal() {
//        inputReg();
//        calculateTax();
//        totalApproved++;
//    }
//
//    void showFinal() {
//        showReg();
//        cout << "Yearly Tax: " << yearlyTax << endl;
//    }
//
//    friend void compareVehicles(FinalVehicle v1, FinalVehicle v2);
//};
//
//int FinalVehicle::totalApproved = 0;
//
//
//void compareVehicles(FinalVehicle v1, FinalVehicle v2) {
//    cout << "Comparison Between Two Vehicles" << endl;
//
//    cout << "Comparing Engine CC:" << endl;
//    if (v1.engineCC > v2.engineCC)
//        cout << v1.brand << " " << v1.model << " has more powerful engine." << endl;
//    else if (v1.engineCC < v2.engineCC)
//        cout << v2.brand << " " << v2.model << " has more powerful engine." << endl;
//    else
//        cout << "Both engines have same capacity." << endl;
//
//    cout << "Comparing Yearly Tax:" << endl;
//    if (v1.yearlyTax > v2.yearlyTax)
//        cout << v1.brand << " " << v1.model << " pays higher tax." << endl;
//    else if (v1.yearlyTax < v2.yearlyTax)
//        cout << v2.brand << " " << v2.model << " pays higher tax." << endl;
//    else
//        cout << "Both vehicles have same tax." << endl;
//
//    cout << "Comparing Registration Year:" << endl;
//    if (v1.regYear < v2.regYear)
//        cout << v1.brand << " " << v1.model << " is older." << endl;
//    else if (v1.regYear > v2.regYear)
//        cout << v2.brand << " " << v2.model << " is older." << endl;
//    else
//        cout << "Both were registered in the same year." << endl;
//}
//
//
//int main() {
//    FinalVehicle v1, v2;
//
//    cout << "Enter Vehicle 1 Details" << endl;
//    v1.inputFinal();
//
//    cout << "Enter Vehicle 2 Details"<< endl ;
//    v2.inputFinal();
//
//    cout << "COMPLETE DETAILS OF VEHICLE 1" << endl;
//    v1.showFinal();
//
//    cout << "COMPLETE DETAILS OF VEHICLE 2" << endl;
//    v2.showFinal();
//
//    compareVehicles(v1, v2);
//
//    cout << "Total Fully Approved Vehicles: "<< FinalVehicle::totalApproved << endl;
//
//    return 0;
//}
