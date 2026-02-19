//#include <iostream>
//using namespace std;
//
//class Mortcalc {
//private:
//    double loanAmount;
//    int months;
//    const double interestRate;
//
//public:
//    Mortcalc(double loan, int m, double rate)
//        : loanAmount(loan), months(m), interestRate(rate) {
//        cout << "Mortgage Calculator Initialized." << endl;
//    }
//
//    double calcmonthlypay() const {
//        double monthlyPrincipal = loanAmount / months;
//        double monthlyPayment = monthlyPrincipal + (monthlyPrincipal * interestRate);
//        return monthlyPayment;
//    }
//
//    void displaypayment() const {
//        double payment = calcmonthlypay();
//        cout << "You need to pay " << payment
//            << " every month for " << months
//            << " months to repay your mortgage." << endl;
//    }
//};
//
//int main() {
//    double loan, rate;
//    int months;
//
//    cout << "Enter loan amount: ";
//    cin >> loan;
//    cout << "Enter number of months: ";
//    cin >> months;
//    cout << "Enter monthly interest rate (between 0 and 0.01): ";
//    cin >> rate;
//
//    Mortcalc m1(loan, months, rate);
//
//    m1.displaypayment();
//
//    return 0;
//}
