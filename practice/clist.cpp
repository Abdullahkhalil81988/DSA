#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class circularlist {
public:
    Node* head;
    Node* tail;
    circularlist() {
        head = tail = nullptr;
    }
    void inserthead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void inserttail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
        
    }
void deleteAtHead () {
    if (head == nullptr) return;
    else if (head == tail) { // single node
        delete head;
        head = tail = nullptr;
    } else {
        // 2 or more nodes
        Node* temp = tail;
        head = head->next;
        tail->next = head;
        temp->next = nullptr;
        delete temp;
    }
}
};

int main() {
    circularlist cl;
    cl.inserthead(1);
    cl.inserthead(2);
    cl.inserttail(3);
    cl.printList();
    return 0;
}