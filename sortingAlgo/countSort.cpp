// Counting Sort:-

// Pros:
// -Time Complexity O(N)
// - Compareless sorting

// Cons:
// -Limited Usage i.e for int
// -Memory Consuption

// Uses:
// - Sort numbers
// - find counts of letter from string
// - remove duplicate from string
// - find kth smallest or biggest element from array within O(N) time.

#include<iostream>
using namespace std;

void countSort(int arr[], int n) {
    int maxEle = arr[0];

    for (int i = 0; i < n; i++) {
        maxEle = max(maxEle, arr[i]);
    }

    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 0; i <= maxEle; i++) {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

}


int main() {

    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};

    countSort(arr, 9);

    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }

    return 0;

};
