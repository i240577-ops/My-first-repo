#include <iostream>
using namespace std;

bool subset(int arr[], int n, int target) {
    if (target == 0) return true;   
    if (n == 0) return false;       
    if (subset(arr, n - 1, target))
        return true;

    if (arr[n - 1] <= target && subset(arr, n - 1, target - arr[n - 1]))
        return true;

    return false;
}

int main() {
    int size, target;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter elements of array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    if (subset(arr, size, target))
        cout << "Subset with sum " << target << " exists.\n";
    else
        cout << "No subset found.\n";

    delete[] arr; // free allocated memory
    return 0;
}
