#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int rows, columns;
    cin>>rows>>columns;

    if (rows > 2 && columns > 2) {
        for (int i = 0; i < columns; i++) {
            cout<<"* ";
        }

        cout<<endl;

        for (int j = 0; j < rows - 2; j++) {
            cout<<"* ";

            for(int k = 0; k < columns -2; k++) {
                cout<<"  ";
            }

            cout<<"* ";

            cout<<endl;
        }

        for (int i = 0; i < columns; i++) {
            cout<<"* ";
        }

        cout<<endl;
    }


}