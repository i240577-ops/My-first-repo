#include <iostream>
#include <string>
using namespace std;

struct TransactionInfo {
    double amount;
    string type;
    string date;
};
class Customer {
private:
    string name;
    int id;

public:
    Customer(string n, int i) {
        name = n;
        id = i;
        cout << "[Customer Created] " << name << endl;
    }

    ~Customer() {
        cout << "[Customer Destroyed] " << name << endl;
    }

    string getName() {
        return name;
    }
};

class Transaction {
private:
    TransactionInfo info;

public:
    Transaction(double amt, string t, string d) {
        info.amount = amt;
        info.type = t;
        info.date = d;
        cout << "[Transaction Created] " << info.type
            << " of " << info.amount << " on " << info.date << endl;
    }

    ~Transaction() {
        cout << "[Transaction Destroyed] " << info.type
            << " of " << info.amount << endl;
    }

    void showTransaction() {
        cout << "Type: " << info.type
            << ", Amount: " << info.amount
            << ", Date: " << info.date << endl;
    }
};

class Account {
private:
    int accountNumber;
    double balance;
    Customer* owner;

public:
    Account(int acc, double bal, Customer* cust) {
        accountNumber = acc;
        balance = bal;
        owner = cust;
        cout << "[Account Created] Acc# " << accountNumber
            << " | Balance: " << balance << endl;
    }

    ~Account() {
        cout << "[Account Destroyed] Acc# " << accountNumber << endl;
    }

    void deposit(double amt, string date) {
        balance += amt;
        Transaction t(amt, "Deposit", date);
    }

    void withdraw(double amt, string date) {
        if (amt <= balance) {
            balance -= amt;
            Transaction t(amt, "Withdrawal", date);
        }
        else {
            cout << "Insufficient funds!" << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    // operator > overload
    bool operator>(const Account& a) const {
        return balance > a.balance;
    }

    void showAccount() {
        cout << "Account Number: " << accountNumber
            << " | Balance: " << balance << endl;
    }
};


int main() {
    // Creating customers
    string name1;
    cout << "Enter name of customer 1: ";
    cin >> name1;
    int id1;
    cout << "Enter id of customer 1: ";
    cin >> id1;
    Customer customer1(name1, id1);
    string name2;
    cout << "Enter name of customer 2: ";
    cin >> name2;
    int id2;
    cout << "Enter id of customer 2: ";
    cin >> id2;
    Customer customer2(name2, id2);

    // Creating accounts (Composition between Customer and Account)
    int accNumber1;
    cout << "Enter account number for customer 1: ";
    cin >> accNumber1;
    int balance1;
    cout << "Enter initial balance for customer 1: ";
    cin >> balance1;
    Account acc1(accNumber1, balance1, &customer1);
    int accNumber2;
    cout << "Enter account number for customer 2: ";
    cin >> accNumber2;
    int balance2;
    cout << "Enter initial balance for customer 2: ";
    cin >> balance2;
    Account acc2(accNumber2, balance2, &customer2);

    // Transactions (Aggregation between Account and Transaction)
    int amount1;
	cout << "enter amount to deposit for account 1: ";
	cin >> amount1;
    cout << endl;
    int amount2;
	cout << "enter amount to deposit for account 2: ";
	cin >> amount2;
    cout << endl;
	int withdrawamount;
	cout << "enter amount to withdraw for account 1: ";
	cin >> withdrawamount;
    cout << endl;
    acc1.deposit(amount1, "12-11-2025");
    acc1.withdraw(withdrawamount, "13-11-2025");

    acc2.deposit(amount2, "14-11-2025");

    if (acc1 > acc2)
        cout << "Account 1 has a higher balance." << endl;
    else
        cout << "Account 2 has a higher balance." << endl;

    return 0;
}
