// Seive of Eratosthenes



// finding prime numbers by making an array and marking multiples of a number.
// note that we start marking from the square of that number as the numbers previous to
// the square of the number are already marked by previous iterations.

#include<iostream>
#include<cmath>
using namespace std;

void primeSieve(int n) {
    int prime[n + 1] = {0};

    for (int i = 2; i <= n; i++) {

        // if it is unmarked, mark it and all its multiples from
        if (prime[i] == 0) {
            for (int j = i*i; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {
            cout << i << " ";
        }
    }

}


void seivePrimeFactorization(int n) {

    // gets stack overflow if n is too high, use vector -> https://stackoverflow.com/questions/1847789/segmentation-fault-on-large-array-sizes
    int spf[500] = {0};

    for (int i = 2; i <= n; i++) {
        spf[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i*i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    while (n != 1) {
        cout << spf[n] << " ";
        n = n / spf[n];
    }

}


int main() {

    int n;
    cin >> n;

    //primeSieve(n);
    seivePrimeFactorization(n);

}