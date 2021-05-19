// https://www.youtube.com/watch?v=1OkZKjxRokU&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=45

#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int size) {
    for (int i = 0; i < x; i ++) {
        if (arr[i][y] == 1) {
            return false;
        }
    }

    int row = x;
    int col = y;
    while (row >= 0 && col >= 0) {
        if (arr[row][col] == 1) {
            return false;
        }

        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < size) {
        if (arr[row][col] == 1) {
            return false;
        }

        row--;
        col++;
    }

    return true;
}

bool nQueen(int** arr, int x, int size) {
    if (x >= size) {
        return true;
    }

    for(int col = 0; col < size; col++) {
        if (isSafe(arr, x, col, size)) {
            arr[x][col] = 1;

            if (nQueen(arr, x + 1, size)) {
                return true;
            }

            arr[x][col] = 0;

        }
    }

    return false;
}


int main() {
    int size;
    cin >> size;

    int** arr = new int*[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            arr[i][j] = 0;
        }
    }
    
    if (nQueen(arr, 0, size)) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

} 

// 4
// 0 1 0 0 
// 0 0 0 1 
// 1 0 0 0 
// 0 0 1 0