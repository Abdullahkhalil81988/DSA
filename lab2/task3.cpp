#include<iostream>
using namespace std;

class Node {
public:
  int data;
  Node* next;
  Node(int val ){
    data = val;
    next = nullptr;
  }
};
class linkedlist{
    private:
    Node* head;
    public:
    linkedlist(){
        head = nullptr;

    }
// insert at head 
    void insert_head(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Node with value " << val << " inserted at head." << endl;
    
    }
        // insert at any posotion 
    void insertAtPosition(int val, int position) {
        if (position < 1) {
            cout << "Position should be >= 1" << endl;
            return;
        }
        
        if (position == 1) {
            insert_head(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        
        // traverse to position-1
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node with value " << val << " inserted at position " << position << endl;
    }
    // ddisplay the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    // delete last node
    void deleteLastNode() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }
        
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Last node deleted" << endl;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = nullptr;
        cout << "Last node deleted" << endl;
    }
// ccount nodes
    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
 // destructor to free memoory
    ~linkedlist() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main(){
    linkedlist list;
    int choice,value,position;
    while (true)
    {
       cout<<"1. insert at head"<<endl;
       cout<<"2. insert at any position"<<endl;
       cout<<"3. display the list"<<endl;
       cout<<"4. delete last node"<<endl;
       cout<<"5. count nodes"<<endl;
       cout<<"6. exit"<<endl;
       cout<<"Enter your choice: ";
       cin>>choice;
       
       switch (choice)
       {
       case 1:
           cout << "Enter value to insert at head: ";
           cin >> value;
           list.insert_head(value);
           break;
       case 2:
           cout << "Enter value to insert: ";
           cin >> value;
           cout << "Enter position (1-based): ";
           cin >> position;
           list.insertAtPosition(value, position);
           break;
       case 3:
           list.display();
           break;
       case 4:
           list.deleteLastNode();
           break;
       case 5:
           cout << "Number of nodes: " << list.countNodes() << endl;
           break;
       case 6:
           cout << "Exiting..." << endl;
           return 0;
       default:
           cout << "Invalid choice! Please try again." << endl;
       }
    }
}
// code completed 
