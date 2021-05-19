// Time Complexity: O(2^n)
// Space Complexity: O(2^n)


#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int size) {
    if (x < size && y < size && arr[x][y] == 1) {
        return true;
    }

    return false; 
} 

bool ratInMaze(int **arr, int x, int y, int size, int** solArr) {

    if (x == (size - 1) && y == (size - 1)) {
        solArr[x][y] = 1;
        return true;
    } 
    
    if (isSafe(arr, x, y, size)) {
        solArr[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, size, solArr)) {
            return true;
        }

        if (ratInMaze(arr, x, y + 1, size, solArr)) {
            return true;
        }

        solArr[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    int size;
    cin >> size;
    
    int** arr = new int*[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }


    int** solArr = new int*[size];
    for (int i = 0; i < size; i++) {
        solArr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            solArr[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, size, solArr)) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }

}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1

// 1 0 0 0 0 
// 1 1 1 1 0 
// 0 0 0 1 0 
// 0 0 0 1 1 
// 0 0 0 0 1
