#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;

    Node(T val)
    {
        data = val;
        left = right = NULL;
    }
};

template <class T>
class BST
{
private:
    Node<T> *root;

public:
    BST()
    {
        root = NULL;
    }

    void Search(T value, Node<T> *&loc, Node<T> *&ploc)
    {
        loc = NULL;
        ploc = NULL;

        if (root == NULL)
            return;

        Node<T> *temp = root;

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                loc = temp;
                return;
            }
            ploc = temp;
            if (value < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        loc = NULL;
    }
    void insert(T val)
    {
        Node<T> *loc, *ploc;
        Search(val, loc, ploc);
        // case1
        if (loc != NULL)
        {
            cout << "Value already exists" << endl;
            return;
        }
        Node<T> *newNode = new Node<T>(val);
        if (root == NULL)
        {
            root = newNode;
            cout << "Inserted " << val << " as root node.\n";
            return;
        }
        if (val < ploc->data) {
            ploc->left = newNode;
            cout << "Inserted " << val << " to left of " << ploc->data << ".\n";
        } else {
            ploc->right = newNode;
            cout << "Inserted " << val << " to right of " << ploc->data << ".\n";
        }
        
    }
    void InOrder(Node<T>* node) {
        if (node == NULL) return;
        InOrder(node->left);
        cout << node->data << " ";
        InOrder(node->right);
    }

    void DisplayInOrder() {
        cout << "InOrder Traversal: ";
        InOrder(root);
        cout << endl;
    }
};
int main() {
    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.DisplayInOrder();

    // Attempt duplicate insertions
    tree.insert(50);
    tree.insert(40);
}