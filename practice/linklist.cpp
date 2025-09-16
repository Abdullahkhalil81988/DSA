#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class list{
public:
    node* head;
    node* tail;

    list(){
        head = tail = NULL;
    }

    void pushfront(int val){
        node* newnode = new node(val);
        if (head == NULL){
            head = tail = newnode;
            return;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }

    void display(){
        node* temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl; // Add newline for better output
    }
    void pushback(int val){
        node* newnode = new node(val);
        if (head==NULL)
        {
           head = tail = newnode;
           return;
        }
        else{
        tail->next = newnode;
        tail = newnode;
        }
    }
};

int main(){
    list ll;
    ll.pushfront(1);
    ll.pushfront(2);
    ll.pushfront(3);
    ll.pushback(5);
   ll.display();
    
    return 0;
}