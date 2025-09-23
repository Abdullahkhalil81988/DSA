#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = NULL;
    }   
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);   
        if (head == NULL) {
            head = newNode;
            return;
        }  
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = newNode;
    }
    
    void printForward(Node* head) {
        if (head == NULL) {
            return;
        }
        cout << head->data << " ";
        printForward(head->next);
    } 
    void printReverse(Node* head) {
        if (head == NULL) {
            return;
        }
        printReverse(head->next);
        cout << head->data << " ";
    }
    // wrapper class to access private head in printing
    void printForward() {
        printForward(head);
        cout << endl;
    }
    
    void printReverse() {
        printReverse(head);
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    
    cout << "Forward printing: ";
    list.printForward();
    
    cout << "Reverse printing: ";
    list.printReverse();
    
    return 0;
}