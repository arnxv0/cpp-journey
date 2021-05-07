#include<iostream>
using namespace std;

int main() {
    int size, givenSum;
    cin >> size >> givenSum;
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int startP = 0, endP = 0, mySum = arr[0];

    while(mySum != givenSum && endP < size) {
        if (mySum > givenSum) {
            mySum -= arr[startP];
            startP++;
        } else if (mySum < givenSum) {
            endP++;
            mySum += arr[endP];
        }
    }

    if (mySum == givenSum) {
        cout << startP + 1 << " " << endP + 1;
        return 0;
    } else {
            cout << -1;
        return 0;
    }

}