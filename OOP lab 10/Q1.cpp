#include <iostream>
using namespace std;

class Item {
private:
    string itemName;
    double price;

public:
	//parameterd constructor
    Item(string name = "", double p = 0) {
        itemName = name;
        price = p;
    }

    // Getters and setters
    string getItemName() { return itemName; }
    double getPrice() { return price; }

    void setItemName(string name) { itemName = name; }
    void setPrice(double p) { price = p; }

    ~Item() {
        cout << "Item destroyed: " << itemName << endl;
    }
};

///////////////////////////////////////////////////
 
class CustomerServiceAgent {
private:
    string agentName;

public:
    CustomerServiceAgent(string name = "") {
        agentName = name;
    }

    string getAgentName() { return agentName; }
    void setAgentName(string name) { agentName = name; }

    ~CustomerServiceAgent() {
        cout << "Agent destroyed: " << agentName << endl;
    }
};

////////////////////////////////////////////////////

class Order {
private:
    Item* items[10];      //compose
    int itemCount;
	CustomerServiceAgent* agent; //association

public:
    // Constructor
    Order(CustomerServiceAgent* a = nullptr) {
        agent = a;
        itemCount = 0;
    }

    // Adding items
    void addItem(string name, double price) {
        if (itemCount < 10) {
            items[itemCount] = new Item(name, price);
            itemCount++;
        }
        else {
            cout << "Order is full, can't add more items!" << endl;
        }
    }

    double getTotalPrice() const {
        double total = 0;
        for (int i = 0; i < itemCount; i++) {
            total += items[i]->getPrice();
        }
        return total;
    }

    // Getter for agent
    CustomerServiceAgent* getAgent() {
        return agent;
    }

    // Overload + operator and add total prices
    double operator+(const Order& other) {
        return this->getTotalPrice() + other.getTotalPrice();
    }

    // Destructor
    ~Order() {
        cout << "Destroying Order handled by: "
            << (agent ? agent->getAgentName() : "No Agent") << endl;

        for (int i = 0; i < itemCount; i++) {
            delete items[i];
        }
    }
};

////////////////////////////////////////////////////

int main() {
    string name1;
    cout << "enter name of 1st agent: ";
    cin >> name1;
	// association
    CustomerServiceAgent* a1 = new CustomerServiceAgent(name1);
    string name2;
    cout << "enter name of 2nd agent: ";
    cin >> name2;
    CustomerServiceAgent* a2 = new CustomerServiceAgent(name2);
    
    // Orders assigned to agents
    Order o1(a1);
    Order o2(a2);

    // Add items (composition)
	double price1, price2, price3, price4;
	cout << "enter price of Laptop: ";
	cin >> price1;
	cout << "enter price of Mouse: ";
	cin >> price2;
	cout << "enter price of Mobile: ";
	cin >> price3;
	cout << "enter price of Charger: ";
	cin >> price4;
    o1.addItem("Laptop", price1);
    o1.addItem("Mouse", price2);

    o2.addItem("Mobile", price3);
    o2.addItem("Charger", price4);

    // Show totals
    cout << "Order 1 total: " << o1.getTotalPrice() << endl;
    cout << "Order 2 total: " << o2.getTotalPrice() << endl;

    //overloading testing
    double combined = o1 + o2;
    cout << "Combined total of both orders: " << combined << endl;

    // deleting agents
    delete a1;
    delete a2;

    return 0;
}
