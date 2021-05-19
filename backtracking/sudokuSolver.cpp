// incomplete

#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int curNum) {
    for (int row = 0; row < 9; row ++) {
        if (arr[row][y] == curNum) {
            return false;
        }
    }

    for (int col = 0; col < 9; col ++) {
        if (arr[x][col] == curNum) {
            return false;
        }
    }

    // check in the block
    int blockX = (x + 1) / 3;
    int blockY = (x + 1) / 3;
    for(int i = blockX*3; i < blockX*3 + 3; i++) {
        for(int j = blockY*3; j < blockY*3 + 3; j++) {
            if (arr[i][j] == curNum) {
                return false;
            }
        }
    }
    
    return true;

}

int main() {
    int** arr = new int*[9];
    for (int i = 0; i < 9; i++) {
        arr[i] = new int[9];
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }
}