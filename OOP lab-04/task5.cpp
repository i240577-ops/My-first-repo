#include<iostream>
using namespace std;
void func(const char* word,int size) {
	if (size == 0) {
		return;
	}
	else {
		cout << word[size-1];
		func(word, size - 1);
	}


}
int main() {
	int length;
	cout << "enter the length of the string" << endl;
	cin >> length;
	cout << "enter the string" << endl;
	char* name = new char[length];
	for (int i = 0; i < length; i++) {
		cin>>name[i];

	}
	name[length] = '\0';
	func(name, length);
	




	return 0;
}