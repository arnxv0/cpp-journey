// find unique if every element is repeated 3 times except one element
// https://www.youtube.com/watch?v=WEpLyOc0bCE&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=35
// 15:00

#include<iostream>
using namespace std;

////////////////// does not work /////////////////
int findUnique(int arr[], int size) {

    for (int i = 0; i < size; i++) {

        if (arr[i] != 0) {

            for (int j = i + 1; j < size; j++) {

                if ((arr[i] ^ arr[j]) == 0) {
                    arr[j] = 0;
                    break;
                }

            }

        }

    }
    
    int uniq = 0;
    for (int k = 0; k < size; k++) {
        uniq = uniq ^ arr[k];
    }

    return uniq;

}


////////////// proper code //////////////////////////////
bool getBit(int n, int pos) {
    return ((n & (1<<pos)) != 0);
}

int setBit(int n, int pos) {
    return (n | (1<<pos));
}

int findUniqueTut(int arr[], int n) {
    
    int result = 0;

    for (int i = 0; i < 64; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (getBit(arr[j], i)) {
                sum++;
            }
        }

        if (sum % 3 != 0) {
            result = setBit(result, i);
        }
    }

    return result;
}


int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //cout << findUnique(arr, n) << endl;
    cout << findUniqueTut(arr, n) << endl;


}