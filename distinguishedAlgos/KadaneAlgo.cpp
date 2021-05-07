// To find the maximum contiguous subarray sum in constant time

// https://www.youtube.com/watch?v=0JYgnhnZFcE&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=25
// at 14:00
// pattern /|/|/|/|/|/|
// for circular list :- maximun subarray sum = total sum of array - sum of non-contributing elemets

#include<iostream>
using namespace std;

int kadaneAlgo(int* arr, int size) {
    int currentSumArray[size];
    int maxSum = INT_MIN;

    currentSumArray[0] = max(0, arr[0]);

    for (int i = 1; i < size; i++) {
        currentSumArray[i] = max(0, currentSumArray[i - 1] + arr[i]);
        maxSum = max(maxSum, currentSumArray[i]);
    }

    return maxSum;
}

void circularSubArray(int* arr, int size) {
    int totalSum = 0;
    int currentSumArray[size];
    int maxSum = INT_MIN;

    // reversing sign to calculate sum of non-contributing elemets
    currentSumArray[0] = max(0, (- arr[0]));
    totalSum += arr[0];

    for (int i = 1; i < size; i++) {
        totalSum += arr[i];
        currentSumArray[i] = max(0, currentSumArray[i - 1] + ( -arr[i]));
        maxSum = max(maxSum, currentSumArray[i]);
    }

    // Because we inverted the signs before and found the sum of non-contributing elemets, we end
    // up adding them.
    cout << totalSum - (- maxSum);

}

#include<iostream>
using namespace std;

int main() {
    int size;
    cin >> size;
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    circularSubArray(arr, size);

}