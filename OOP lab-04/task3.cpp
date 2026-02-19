//#include<iostream>
//using namespace std;
//int billcalculation(int* arr, int size, int index, double discount) {
//	if (index >= size) { return 0; }
//	if (index >= 10) {
//		discount = 100;
//	}
//	double bill = arr[index] * (1 - (discount / 100));
//	return bill + billcalculation(arr, size, index+1, discount+10);
//}
//
//
//
//int main() {
//	int size;
//	cout << "enter number of items" << endl;
//	cin >> size;
//	int* arr = new int[size];
//	cout << "entr price if items" << endl;
//	for (int i = 0; i < size; i++) {
//		cin >> arr[i];
//	}
//	int index = 0;
//	int discount = 10;
//	cout<<"AFTER DISCOUNT = "<<billcalculation(arr, size, index, discount);
//
//
//
//
//	return 0;
//}