#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;

    for (int r = 1; r <= 2*n; r++) {
        for (int c = 1; c <= 2*n; c++) {
            if (r <= n) {
                if (c <= r || c > (2*n - r)) {
                    cout<<"* ";
                } else {
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
}