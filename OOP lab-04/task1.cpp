#include<iostream>
using namespace std;
int function(int number) {
	if (number == 0) { return 1; }
	else if (number < 0) { return 0; }
	else {
		return function(number - 1);
	}
}
int main() {
	int n;
	cout << "enter any number" << endl;
	cin >> n;
	cout << "SUBSTRINGS ARE = " << function(n);




	return 0;
}