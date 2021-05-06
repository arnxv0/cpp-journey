#include<iostream>
using namespace std;

void selectionSort(int* arr, int size) {

    for (int i = 0; i < size; i++) {

        int minPos = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minPos]) {
                minPos = j;
            }
        }
        swap(arr[i], arr[minPos]);
        
    }

}


int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, n);

    for (int j = 0; j < n; j++) {
        cout << arr[j] << " ";
    }
}