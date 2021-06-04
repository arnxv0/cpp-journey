#include <iostream>
using namespace std;

#define n 100

class stack {
private:
    int* arr;
    int top;

public:
    stack() {
        arr = new int[n];
        top = -1;
    }

    void push(int x) {
        if (top == n - 1) {
            cout << "Stack overflow!" << endl;
        } else {
            top += 1;
            arr[top] = x;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "No elements to pop." << endl;
        } else {
            top--;
        }
    }

    int get_top() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.get_top() << endl;
    st.pop();
    cout << st.get_top() << endl;
    st.pop();
    st.pop();
    st.pop();
}