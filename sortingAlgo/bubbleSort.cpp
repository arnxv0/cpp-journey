#include<iostream>
using namespace std;

void bubbleSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j ++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    for (int j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }
}