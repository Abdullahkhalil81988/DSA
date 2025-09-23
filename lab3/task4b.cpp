#include <iostream>
using namespace std;

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

Node* deleteValue(Node* head, int value) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->getData() == value) {
        Node* temp = head->getNext();
        delete head;
        return temp;
    }

    head->setNext(deleteValue(head->getNext(), value));
    return head;
}

Node* insert(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
    }
    temp->setNext(newNode);
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
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

    cout << "Enter value to delete: ";
    cin >> value;
    head = deleteValue(head, value);

    cout << "List after deletion: ";
    display(head);
    cout << endl;

    return 0;
}