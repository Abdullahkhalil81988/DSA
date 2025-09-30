#include <iostream>
using namespace std;


int main() {
   class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
    }

   };
   class circularlist{
    public:
    Node* head;
    Node* tail;
    circularlist() {
        head = tail = NULL;
    }
    void inserthead(int val){
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = head;
            head = newNode;
            tail->next =head;
           
        }
        else{
            Node* newNode= new  Node(val);
            newNode->next = head;
            head = newNode;
            tail->next = newNode;

        }
    }

    void printList() {
        if (head == NULL) {
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
   };
    return 0;
}