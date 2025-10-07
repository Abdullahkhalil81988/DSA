#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};

class Bst
{
private:
    Node *root;

public:
    Bst()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);

        // case 1: tree is empty
        if (root == nullptr)
        {
            root = newNode;
            cout << "value inserted at root: " << val << endl;
            return;
        }

        // case 2: find correct position
        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;

            if (val < current->data)
                current = current->left;
            else if (val > current->data)
                current = current->right;
            else
            {
                // cout << "duplicate value not allowed!\n";
                delete newNode;
                return;
            }
        }

        // attach new node to left or right
        if (val < parent->data)
        {
            parent->left = newNode;
            // cout << "value inserted at left of " << parent->data << endl;
        }
        else
        {
            parent->right = newNode;
            // cout << "value inserted at right of " << parent->data << endl;
        }
    }
    void inOrder(Node *node)
    {
        if (node == nullptr)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // pre-order traversal (root → left → right)
    void preOrder(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // post-order traversal (left → right → root)
    void postOrder(Node *node)
    {
        if (node == nullptr)
            return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
    // menu functions for easy access
    void inOrderTraversal()
    {
        cout << "in-order traversal: ";
        inOrder(root);
        cout << endl;
    }

    void preOrderTraversal()
    {
        cout << "pre-order traversal: ";
        preOrder(root);
        cout << endl;
    }

    void postOrderTraversal()
    {
        cout << "post-order traversal: ";
        postOrder(root);
        cout << endl;
    }
    void printTree(Node *ptr, int space) const
    {
        if (ptr == nullptr)
            return;
        const int INDENT = 6; // spacing per level

        // increase distance between levels
        space += INDENT;

        // print right child first
        printTree(ptr->right, space);

        // print current node after space
        cout << endl;
        for (int i = INDENT; i < space; ++i)
            cout << ' ';
        cout << ptr->data << "\n";

        // print left child
        printTree(ptr->left, space);
    }

    // Wrapper for printTree
    void printTreeWrapper()
    {
        printTree(root, 0);
    }
    void deleteValue(int val)
    {
        Node *current = root;
        Node *parent = nullptr;

        // find node to delete
        while (current != nullptr && current->data != val)
        {
            parent = current;
            if (val < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (current == nullptr)
        {
            cout << "value not found!\n";
            return;
        }
        // case 1: no children
        if (current->left == nullptr && current->right == nullptr)
        {
            if (current != root)
            {
                if (parent->left == current)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
            else
            {
                root = nullptr;
            }
            delete current;
        }

        // case 2: one child
        else if (current->left == nullptr || current->right == nullptr)
        {
            Node *child = (current->left) ? current->left : current->right;
            if (current != root)
            {
                if (current == parent->left)
                    parent->left = child;
                else
                    parent->right = child;
            }
            else
            {
                root = child;
            }
            delete current;
        }

        // case 3: two children
        else
        {
            Node *successorParent = current;
            Node *successor = current->right;

            // find smallest in right subtree
            while (successor->left != nullptr)
            {
                successorParent = successor;
                successor = successor->left;
            }

            // copy successor's data
            current->data = successor->data;

            // delete successor node
            if (successorParent->left == successor)
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;

            delete successor;
        }

        cout << "value deleted successfully!"<<val<<endl;;
    }
};

int main()
{
    Bst bst;

    bst.insert(3);
    bst.insert(1);
    bst.insert(2);
    bst.insert(4);
    bst.insert(16);
    bst.insert(17);
    bst.insert(10);
    bst.insert(5);

    bst.printTreeWrapper();

    bst.inOrderTraversal();
    bst.preOrderTraversal();
    bst.postOrderTraversal();
    bst.deleteValue(5);
    bst.printTreeWrapper();
    bst.deleteValue(16);
    bst.printTreeWrapper();
    bst.deleteValue(2);
    bst.printTreeWrapper();

    return 0;
}
