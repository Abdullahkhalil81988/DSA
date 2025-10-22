#include <iostream>
#include <algorithm>
using namespace std;

// node structure for avl tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// helper function to get height of node
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

// right rotation (ll)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    // perform rotation
    x->right = y;
    y->left = t2;

    // update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// left rotation (rr)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    // perform rotation
    y->left = x;
    x->right = t2;

    // update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

// get balance factor
int getBalance(Node* n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

// find node with minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// insert function (same as before)
Node* insert(Node* root, int key) {
    if (!root) return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else {
        cout << "duplicate key " << key << " ignored\n";
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // ll
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // rr
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // lr
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // rl
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// delete node from avl tree
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    // normal bst delete
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // node with one or no child
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            // no child
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                // one child
                *root = *temp;
            }
            delete temp;
        } 
        // node with two children
        else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // if tree had only one node
    if (!root) return root;

    // update height
    root->height = 1 + max(height(root->left), height(root->right));

    // get balance factor
    int balance = getBalance(root);

    // check imbalance cases

    // ll
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // lr
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // rr
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // rl
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// preorder traversal
void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void printTreeUtil(Node*ptr, int space) 
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
        root = insert(root, arr[i]);
        cout << "inserted " << arr[i] << " > preorder: ";
        preOrder(root);
        cout << "\n";
    }

    int delArr[] = {50, 40, 30};
    int m = sizeof(delArr) / sizeof(delArr[0]);

    for (int i = 0; i < m; i++) {
        cout << "deleting " << delArr[i];
        root = deleteNode(root, delArr[i]);
        
        cout << "preorder after deletion: ";
        preOrder(root);
        cout << "\n";
        printTreeUtil(root, 0);

    }
    printTreeUtil(root, 0);
    

    return 0;
}
