#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// node structure for avl tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// helper function to get height of a node
int height(Node* n) {
    return n ? n->height : -1;
}

// helper function to create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->data = key;
    node->left = node->right = nullptr;
    node->height = 0;
    return node;
}

// right rotation (ll rotation)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// left rotation (rr rotation)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// get balance factor of a node
int getBalance(Node* n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

// insert a node in avl tree
Node* insert(Node* root, int key) {
    // normal bst insert
    if (!root) return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else {
        cout << "duplicate key " << key << " ignored\n";
        return root;
    }

    // update height
    root->height = 1 + max(height(root->left), height(root->right));

    // check balance
    int balance = getBalance(root);

    // ll case
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // rr case
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // lr case
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // rl case
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // return the (possibly updated) root
    return root;
}

// pre-order traversal to print tree
void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Utility function to print the tree structure
void printTreeUtil(Node *ptr, int space)
{
    if (ptr == nullptr)
        return;
    const int INDENT = 6; // spacing per level

    // increase distance between levels
    space += INDENT;

    // print right child first
    printTreeUtil(ptr->right, space);

    // print current node after space
    cout << endl;
    for (int i = INDENT; i < space; ++i)
        cout << ' ';
    cout << ptr->data << "\n";

    // print left child
    printTreeUtil(ptr->left, space);
}

int main() {
    Node* root = nullptr;

    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        cout << "\ninserting " << arr[i] ;
        root = insert(root, arr[i]);
        cout << "preorder after insertion: ";
        preOrder(root);
        cout << "\n";
        printTreeUtil(root, 0);
    }

    return 0;
}
