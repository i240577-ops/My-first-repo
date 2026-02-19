#include<iostream>
using namespace std;

class dairyfarm {
private:
    string company;
    string color;
    double capacityLiters;
    int capacityMilliliters;

public:
    void setCompany(string c) {
        company = c;
    }

    void setColor(string col) {
        color = col;
    }

    void setCapacityLiters(double cl) {
        capacityLiters = cl;
    }

    void setCapacityMilliliters(int cm) {
        capacityMilliliters = cm;
    }


    string getCompany() {
        return company;
    }

    string getColor() {
        return color;
    }

    double getCapacityLiters() {
        return capacityLiters;
    }

    int getCapacityMilliliters() {
        return capacityMilliliters;
    }

    void drinkWater(int ml) {
        if (capacityMilliliters >= ml) {
            capacityMilliliters -= ml;
            cout << "Drank " << ml << " ml of water that is remaining= " << capacityMilliliters << " ml" << endl;
        }
        else {
            cout << "Not enough water!!!! Only " << capacityMilliliters << " ml left." << endl;
            capacityMilliliters = 0;
        }
    }
};

int main() {
    dairyfarm D;
    string comp, col;
    double liters;
    int milliliters, water;

   
    cout << "Enter company name: ";
    cin >> comp;
    D.setCompany(comp);

    cout << "Enter color: ";
    cin >> col;
    D.setColor(col);

    cout << "Enter capacity in liters: ";
    cin >> liters;
    D.setCapacityLiters(liters);

    cout << "Enter capacity in milliliters: ";
    cin >> milliliters;
    D.setCapacityMilliliters(milliliters);

    cout << "Enter quantity of water to drink inn milliliters: ";
    cin >> water;
    D.drinkWater(water);

    return 0;
}
