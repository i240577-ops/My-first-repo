//#include<iostream>
//using namespace std;
//
//class college {
//private:
//    string company;
//    string color;
//    bool refillable;
//    bool Inkstatus;
//    int a;
//
//public:
//    void setCompany(string c) {
//        company = c;
//    }
//    void setColor(string col) {
//        color = col;
//    }
//    void setRefillable(bool r) {
//        refillable = r;
//    }
//    void setInkStatus(bool s) {
//        Inkstatus = s;
//    }
//
//    string getCompany() {
//        return company;
//    }
//    string getColor() {
//        return color;
//    }
//    bool getRefillable() {
//        return refillable;
//    }
//    bool getInkStatus() {
//        return Inkstatus;
//    }
//
//   
//    void display() {
//        cout << "Company= " << company << endl;
//        cout << "Color= " << color << endl;
//        cout << "Refillable= " << refillable << endl;
//        cout << "Ink Status= " << Inkstatus << endl;
//    }
//
//    void write() {
//        if (Inkstatus) {
//            cout << "Writing with " << color << " color" << endl;
//        }
//        else {
//            cout << "Ink empty" << endl;
//        }
//    }
//
//    void refill() {
//        if (refillable) {
//            cout << "Ink is refilled" << endl;
//        }
//        else {
//            cout << "Cannot refill" << endl;
//        }
//    }
//};
//
//int main() {
//    college C;
//
//    
//    string comp;
//    string col;
//    bool refill;
//    bool ink;
//
//    cout << "Enter company name= ";
//    cin >> comp;
//    C.setCompany(comp);
//
//    cout << "Enter color= ";
//    cin >> col;
//    C.setColor(col);
//
//    cout << "Enter refillable status (1/0)= ";
//    cin >> refill;
//    C.setRefillable(refill);
//
//    cout << "Enter ink status (1/0)= ";
//    cin >> ink;
//    C.setInkStatus(ink);
//
//    //cout << "Pen Information=" << endl;
//    C.display();
//
//    C.write();
//    C.refill();
//
//    return 0;
//}
