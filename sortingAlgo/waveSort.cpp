// O(n/2) or O(n)

#include<iostream>
using namespace std;

void swap(int arr[], int a, int b) {
    int j = arr[a];
    arr[a] = arr[b];
    arr[b] = j;
}

void waveSort(int arr[], int n) {
    for (int i = 1; i < n; i += 2) {
        if (arr[i] > arr[i - 1]) {
            swap(arr, i, i - 1);
        }

        if (i <= n - 2 && arr[i + 1] < arr[i]) {
            swap(arr, i, i + 1);
        }
    }
}

int main() {
    int arr[] = {1, 3, 4, 7, 5, 6, 2};

    waveSort(arr, 7);

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    return 0;  
}