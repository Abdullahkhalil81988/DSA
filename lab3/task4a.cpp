#include <iostream>
using namespace std;

// node class represents a single element in the linked list
class Node {
private:
    int data;
    Node* next;

public:
    Node(int val) {
        data = val;
        next = nullptr;
    }

    int getData() const {
        return data;
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* nextNode) {
        next = nextNode;
    }
};

// inserts a new node with the given value into the linked list
Node* insert(Node* head, int value) {
    if (head == nullptr) {
        return new Node(value);
    }
    head->setNext(insert(head->getNext(), value));
    return head;
}

// displays the linked list elements
void display(Node* head) {
    if (head == nullptr) {
        return;
    }
    cout << head->getData() << " ";
    display(head->getNext());
}

int main() {
    Node* head = nullptr;
    int n, value;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insert(head, value);
    }
    
    cout << "Original List: ";
    display(head);
    cout << endl;
    
    cout << "Enter value to insert: ";
    cin >> value;
    head = insert(head, value);

    cout << "List after insertion: ";
    display(head);
    cout << endl;

    return 0;
}