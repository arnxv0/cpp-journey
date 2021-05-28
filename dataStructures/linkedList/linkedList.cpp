// ** vs *&
// https://stackoverflow.com/questions/20846904/in-c-what-is-this-for-node-head/20847005
// https://en.wikipedia.org/wiki/Reference_(C%2B%2B)

#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;

        node(int val) {
            data = val;
            next = NULL;
        }
};

void insertAtTail(node** pHead, int val) {

    node* n = new node(val);

    if (*pHead == NULL) {
        *pHead = n;
        return;
    }

    node* temp = *pHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;

}

void insertAtHead(node** pHead, int val) {

    node* head = *pHead;
    node* n = new node(val);

    if (head == NULL) {
        *pHead = n;
    } else {
        n->next = *pHead;
        *pHead = n;
    }

}

void display(node* head) {

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;

}

bool search(node* head, int key) {
    while(head != NULL) {
        if (head->data == key) {
            return true;
        }
        head = head->next;
    }

    return false;
}

int main() {

    node* head = NULL;

    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtHead(&head, 4);

    display(head);
    cout << search(head, 2) << endl;
    display(head);

    return 0;

}