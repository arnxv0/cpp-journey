#include<iostream>
using namespace std;


// time complexity O(log₂n)
int binarySearch(int arr[], int size, int key) {
    int startIndex = 0;
    int endIndex = size;
    while (startIndex <= endIndex) {
        int mid = (startIndex + endIndex) / 2;
        if (arr[mid] > key) {
            endIndex = mid;
        } else if (arr[mid] < key) {
            startIndex = mid;
        } else {
            return mid;
        }
    }
    return -1;
}


int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;
    cout << binarySearch(arr, n, key);

    return 0;

}