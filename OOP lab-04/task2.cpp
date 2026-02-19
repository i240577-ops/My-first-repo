#include<iostream>
using namespace std;
int function(int number) {
	if (number == 0) { return 1; }
	else if (number < 0) { return 0; }
	else {
		return function(number - 1) + function(number - 2);
	}
}
int main() {
	int n;
	cout << "enter any number" << endl;
	cin >> n;
	cout <<"number of ways are = " <<function(n);




	return 0;
}