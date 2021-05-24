// Dutch national flag sort
// https://www.youtube.com/watch?v=2C4CQ32961Y&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=50

#include<iostream>
using namespace std;

void swap(int arr[], int a, int b) {
    int j = arr[a];
    arr[a] = arr[b];
    arr[b] = j;
}

void dnfSort(int arr[], int n) {
    int high = n - 1;
    int low = 0;
    int mid = 0;

    while (high >= mid) {
        if (arr[mid] == 0) {
            swap(arr, low, mid);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else if (arr[mid] == 2) {
            swap(arr, high, mid);
            high--;
        }
    }
}


int main() {
    int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};

    dnfSort(arr, 9);

    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }

    return 0;  
}