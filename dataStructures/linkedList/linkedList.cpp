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

void deleteNode(node** pHead, int key) {
    node* head = *pHead;

    if (head == NULL) {
        return;
    } else if (head->data == key) {
        node* temp = *pHead;
        *pHead = temp->next;
        delete temp;
        return;
    }

    while (head->next != NULL) {
        if (head->next->data == key) {
            break;
        }

        head = head->next;
    }

    if (head->next != NULL) {
        node* temp = head->next;
        head->next = head->next->next;
        delete temp;
    }
}

void reverseList(node** pHead) {
    node* head = *pHead;

    if (head == NULL || head->next == NULL) {
        return;
    }

    head = head->next;
    node* prev = NULL;
    node* curr = *pHead;

    while (head != NULL) {
        curr->next = prev;
        prev = curr;
        curr = head;
        head = head->next;
    }

    curr->next = prev;
    *pHead = curr;

}

void reverseKNodes(node** pHead, int k) {
    node* head = *pHead;

    if (head == NULL || head->next == NULL) {
        return;
    }

    head = head->next;
    node* prev = NULL;
    node* curr = *pHead;

    while (head != NULL && k > 1) {
        curr->next = prev;
        prev = curr;
        curr = head;
        head = head->next;
        k--;
    }

    node* x = *pHead;
    x->next = head;
    curr->next = prev;
    *pHead = curr;

}

bool detectCycleFloyed(node* head) {
    node* slow = head;

    while (head->next != NULL) {
        if (slow == head) {
            return true;
        }

        head = head->next->next;
        slow = slow->next;
    }

    return false;
}

// Proof https://www.youtube.com/watch?v=Fj1ywT9ETQk&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=62
// 10:00
void removeCycle(node* head) {
    node* slow = head;
    node* fast = head;

    while (fast->next != NULL) {
        if (slow == fast) {

            fast = head;
            while (fast->next != slow->next) {
                fast = fast->next;
                slow = slow->next;
            }

            slow->next = NULL;
            return;
        }

        fast = fast->next->next;
        slow = slow->next;
    }
}

int main() {

    node* head = NULL;

    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);
    insertAtHead(&head, 0);

    display(head);
    
    reverseKNodes(&head, 4);

    display(head);

    return 0;

}