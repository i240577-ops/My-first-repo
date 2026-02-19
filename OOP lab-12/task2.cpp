//#include<iostream>
//using namespace std;
//class Position {
//public:
//	int x, y, z;
//
//	Position(int x = 0, int y = 0, int z = 0) {
//		this->x = x;
//		this->y = y;
//		this->z = z;
//	}
//
//	void displayposition() {
//		cout << "Position = ("<< x << ", " << y << ", " << z << ")" << endl;
//	}
//};
//
//
//class Health {
//public:
//	int health;
//
//	Health(int h = 100) {
//		health = h;
//	}
//	void displayhealth() {
//		cout << "Health = " << health << endl;
//	}
//};
//
//
//
//class Character: public Position, public Health {
//public:
//	string name;
//
//	Character(string n, int x, int y, int z, int h): Position(x, y,z) , Health(h) {
//		name = n;
//	}
//	void display() {
//		cout << "Character Name: " << name << endl;
//		displayposition();
//		displayhealth();
//	}
//};
//int main() {
//	Character c1("Knight", 10, 20, 30, 85);
//
//	cout << "Character Details:" << endl;
//	c1.display();
//
//	return 0;
//}