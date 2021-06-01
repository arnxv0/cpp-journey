#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;
    
    node (int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node** pHead, int val) {

    node* head = *pHead;
    node* newNode = new node(val);


    if (head == NULL) {
        *pHead = newNode;
        newNode->next = newNode;
        return;
    } else {
        newNode->next = head;
        while (head->next != *pHead) {
            head = head->next;
        }

        head->next = newNode;
        *pHead = newNode;
    }

}

void insertAtTail (node** pHead, int val) {
    node* newNode = new node(val);
    node* head = *pHead;

    if (head == NULL) {
        *pHead = newNode;
        newNode->next = newNode;
        return;
    } else {
        while (head->next != *pHead) {
            head = head->next;
        }

        newNode->next = head->next;
        head->next = newNode;
    }
}

void deleteAtHead(node** pHead) {
    node* head = *pHead;

    if (head == NULL) {
        return;
    } else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        if (head->next == head) {
            head->next = NULL;
            delete head;
            *pHead = NULL;
            return;
        } else {
            temp->next = head->next;
            *pHead = head->next;
            delete head;
            return;
        }
    }
}

void deleteNode(node** pHead, int val) {
    node* head = *pHead;

    if (head == NULL) {
        return;
    } else if (head->data == val) {
        deleteAtHead(pHead);
    } else {
        while (head->next->data != val && head->next->next != *pHead) {
            head = head->next;
        }

        if (head->next->data == val) {
            node* temp = head->next;
            head->next = temp->next;
            delete temp;
            return;
        }
    }
}

void displayList(node* head) {

    node* temp = head;

    if (head == NULL) {
        std::cout << "Empty List" << std::endl;
        return;
    }

    while (temp->next != head) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << temp->data << " ";

    std::cout << std::endl;
}

int main(){

    node* head = NULL;

    displayList(head);
    insertAtHead(&head, 5);
    displayList(head);
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 6);
    displayList(head);

    deleteAtHead(&head);
    displayList(head);
    deleteNode(&head, 2);
    deleteNode(&head, 3);
    deleteNode(&head, 4);
    displayList(head);

    deleteAtHead(&head);
    deleteAtHead(&head);
    displayList(head);

}