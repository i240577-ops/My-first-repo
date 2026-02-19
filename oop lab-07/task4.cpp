//#include <iostream>
//#include <string>
//using namespace std;
//
//class CustomerAccount {
//private:
//    int customerID;
//    string customerName;
//    double accountBalance;
//
//public:
//    CustomerAccount(int id, const string& name, double balance)
//        : customerID(id), customerName(name), accountBalance(balance) {
//    }
//
//    void addFunds(double amount) {
//        accountBalance += amount;
//        cout << "Added " << amount << " to account of " << customerName << "." << endl;
//    }
//
//    void deductFunds(double amount) {
//        if (amount <= accountBalance) {
//            accountBalance -= amount;
//            cout << "Deducted " << amount << " from account of " << customerName << "." << endl;
//        }
//        else {
//            cout << "Insufficient balance for " << customerName << "." << endl;
//        }
//    }
//
//    void showDetails() const {
//        cout << "Customer ID: " << customerID << endl;
//        cout << "Customer Name: " << customerName << endl;
//        cout << "Account Balance: " << accountBalance << endl;
//    }
//};
//
//int main() {
//    const int SIZE = 3;
//    CustomerAccount* customers[SIZE];
//
//    for (int i = 0; i < SIZE; i++) {
//        int id;
//        string name;
//        double balance;
//
//        cout << "Enter details for Customer " << (i + 1) << ":";
//        cout << "Enter Customer ID: ";
//        cin >> id;
//        cin.ignore();
//        cout << "Enter Customer Name: ";
//        getline(cin, name);
//        cout << "Enter Initial Account Balance: ";
//        cin >> balance;
//
//        customers[i] = new CustomerAccount(id, name, balance);
//    }
//
//    for (int i = 0; i < SIZE; i++) {
//        cout << "Initial Details of Customer " << (i + 1) << endl;
//        customers[i]->showDetails();
//
//        customers[i]->addFunds(1000.0);
//
//        customers[i]->deductFunds(300.0);
//
//        cout << "Updated Details of Customer " << (i + 1) << endl;
//        customers[i]->showDetails();
//    }
//
//    for (int i = 0; i < SIZE; i++) {
//        delete customers[i];
//    }
//
//    return 0;
//}
