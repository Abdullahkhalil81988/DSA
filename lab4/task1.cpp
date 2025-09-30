#include <iostream>
using namespace std;

// node 
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularList {
private:
    Node* tail;
public:
    CircularList() : tail(nullptr) {}

    // insert node at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        Node* temp = tail;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = tail;
    }

    // function to display circular linked list
    void display() const {
        if (!tail) return;
        Node* temp = tail;
        do {
            cout << temp->data << " → ";
            temp = temp->next;
        } while (temp != tail);
        cout << endl;
    }

    // zigzag rearrangement
    void zigzagRearrange() {
        if (!tail || tail->next == tail) return; // empty or 1 node

        Node* curr = tail;
        bool lessThan = true; // true means "<", false means ">"

        // make one complete traversal of the list
        do {
            Node* nextNode = curr->next;

            // check and enforce the zigzag pattern
            if (lessThan) { 
                if (curr->data > nextNode->data) {
                    swap(curr->data, nextNode->data);
                }
            } else { 
                if (curr->data < nextNode->data) {
                    swap(curr->data, nextNode->data);
                }
            }
            
            lessThan = !lessThan; // toggle the condition
            curr = curr->next;    // move to next node
        } while (curr != tail);   // stop when we come back to tail
    }
};

int main() {
    CircularList clist;

    clist.insertEnd(4);
    clist.insertEnd(3);
    clist.insertEnd(7);
    clist.insertEnd(8);
    clist.insertEnd(6);
    clist.insertEnd(2);
    clist.insertEnd(1);

    cout << "Original circular list:\n";
    clist.display();

    clist.zigzagRearrange();

    cout << "Rearranged circular list:\n";
    clist.display();

    return 0;
}
