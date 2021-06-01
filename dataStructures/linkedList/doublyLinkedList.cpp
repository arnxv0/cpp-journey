#include <iostream>

class node {
    public:
        int data;
        node* next;
        node* prev;
    
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node** pHead, int val) {
    node* newNode = new node(val);

    if (*pHead == NULL) {
        *pHead = newNode;
    } else {
        newNode->next = *pHead;
        (*pHead)->prev = newNode;
        *pHead = newNode;
    }
}

void insertAtTail(node** pHead, int val) {
    node* newNode = new node(val);
    node* head = *pHead;
    
    if (head == NULL) {
        *pHead = newNode;
    } else {
        while (head->next != NULL) {
            head = head->next;
        }

        newNode->prev = head;
        head->next = newNode;
    }
}

void deleteAtHead(node** pHead) {

    node* head = *pHead;

    if (head != NULL) {
        if (head->next != NULL) {
            head->next->prev = NULL;
        }

        *pHead = head->next;
        delete head;
    }

}

void deleteNode(node** pHead, int val) {
    node* head = *pHead;
    
    if (head == NULL) {
        return;
    } else if (head->data == val) {
        deleteAtHead(pHead);
    } else {
        while (head != NULL && head->data != val) {
            head = head->next;
        }

        if (head != NULL) {
            if (head->next != NULL) {
                head->next->prev = head->prev;
            }

            head->prev->next = head->next;
            delete head;
        }

    }
}

void display(node* head) {

    if (head == NULL) {
        std::cout << "Empty List" << std::endl;
        return;
    }

    while (head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }

    std::cout << std::endl;

}

int main() {

    node* head = NULL;

    insertAtHead(&head, 4);
    deleteNode(&head, 4);
    display(head);

    return 0;
}