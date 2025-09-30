#include <iostream>
#include <string>
using namespace std;

// class for circular linked list
class CircularLinkedList {
private:
    // node structure as an inner class
    class Node {
    public:
        string data;
        Node* next;
        
        Node(string val) : data(val), next(nullptr) {}
    };
    
    Node* head;
    int size; // track size of list
    
public:
    // constructor
    CircularLinkedList() : head(nullptr), size(0) {}
    
    // destructor to free memory
    ~CircularLinkedList() {
        if (!head) return;
        
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
    
    // insert node at end
    void insertEnd(const string& val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head; // point to itself to make it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        size++;
    }
    
    // display the circular linked list
    void display() const {
        if (!head) {
            cout << "Empty list" << endl;
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head) cout << " → ";
        } while (temp != head);
        cout << endl;
    }
    
    // get node at specific position
    Node* getNodeAt(int position) const {
        if (!head || position >= size) return nullptr;
        
        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        return temp;
    }
    
    // function to check if the list is a palindrome without using vectors
    bool isPalindrome() const {
        // empty list is palindrome
        if (!head) return true;
        
        // single node list is palindrome
        if (head->next == head) return true;
        
        // compare nodes from front and back
        for (int i = 0; i < size / 2; i++) {
            Node* front = getNodeAt(i);
            Node* back = getNodeAt(size - 1 - i);
            
            if (front->data != back->data) {
                return false;
            }
        }
        
        return true;
    }
    
    // get size of the list
    int getSize() const {
        return size;
    }
};

// function to create a list with number values and check if it's palindrome
void testNumbersPalindrome() {
    CircularLinkedList list;
    
    // create list: 10 → 20 → 30 → 20 → 10
    list.insertEnd("10");
    list.insertEnd("20");
    list.insertEnd("30");
    list.insertEnd("20");
    list.insertEnd("10");
    
    cout << "numbers list: ";
    list.display();
    cout << "is palindrome: " << (list.isPalindrome() ? "yes" : "no") << endl;
}

// function to create a list with word values and check if it's palindrome
void testWordsPalindrome() {
    CircularLinkedList list;
    
    // create list: "cat" → "dog" → "cat"
    list.insertEnd("cat");
    list.insertEnd("dog");
    list.insertEnd("cat");
    
    cout << "words list: ";
    list.display();
    cout << "is palindrome: " << (list.isPalindrome() ? "yes" : "no") << endl;
}

// function to create a list with mixed values and check if it's palindrome
void testMixedNonPalindrome() {
    CircularLinkedList list;
    
    // create list: "a" → "b" → "c" → "d"
    list.insertEnd("a");
    list.insertEnd("b");
    list.insertEnd("c");
    list.insertEnd("d");
    
    cout << "mixed list: ";
    list.display();
    cout << "is palindrome: " << (list.isPalindrome() ? "yes" : "no") << endl;
}

// function to test an empty list
void testEmptyList() {
    CircularLinkedList list;
    
    cout << "empty list: ";
    list.display();
    cout << "is palindrome: " << (list.isPalindrome() ? "yes" : "no") << endl;
}

// function to test a single node list
void testSingleNodeList() {
    CircularLinkedList list;
    list.insertEnd("single");
    
    cout << "single node list: ";
    list.display();
    cout << "is palindrome: " << (list.isPalindrome() ? "yes" : "no") << endl;
}

int main() {
    cout << "\n testing numbers palindrome " << endl;
    testNumbersPalindrome();
    
    cout << "\n testing words palindrome" << endl;
    testWordsPalindrome();
    
    cout << "\n testing mixed non-palindrome " << endl;
    testMixedNonPalindrome();
    
    cout << "\n testing empty list " << endl;
    testEmptyList();
    
    cout << "\n testing single node list " << endl;
    testSingleNodeList();
    
    return 0;
}