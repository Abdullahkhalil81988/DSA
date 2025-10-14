#include <iostream>
using namespace std;

template <class T>
class Node {
    public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T val ){
        data = val;
        left = right = NULL;

    }

};
template <class T>
class Bst{
    private:
    Node<T>* root;
    public:
    Bst(){
        root = NULL;
    }
    void Search(T val){
        Node<T>* loc = NULL;   // location pointer
        Node<T>* ploc = NULL;  // parent location pointer
     if (root == NULL) {
            cout << "Tree is empty.\n";
            cout << "loc = NULL, ploc = NULL\n";
            return;
        }
       Node<T>* temp = root;
       while (temp != NULL)
       {
            if (temp->data == val) {
                loc = temp;
                break;
            }
            ploc = temp;  // store parent before moving
            if (val < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
       if (loc == NULL && ploc == NULL)
            cout << "Value not found. Tree is empty.\n";
        else if (loc == NULL && ploc != NULL)
            cout << "Value not found. Should be child of node " << ploc->data <<endl;
        else if (loc != NULL && ploc == NULL)
            cout << "Value found in root node: " << loc->data <<endl;
        else
            cout << "Value found: " << loc->data << ", Parent: " << ploc->data << endl;
       
    

    }
    
// Helper: Insert function to test Search
    void Insert(T val) {
        Node<T>* newNode = new Node<T>(val);

        if (root == NULL) {
            root = newNode;
            return;
        }

        Node<T>* temp = root;
        Node<T>* parent = NULL;

        while (temp != NULL) {
            parent = temp;
            if (val < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (val < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
};

int main() {
    Bst<int> tree;
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
     tree.Search(60);  
    tree.Search(50);  
    tree.Search(25);  
    tree.Search(100); 
}
