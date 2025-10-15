#include <iostream>

// Simple BST template definition for demonstration
template <typename T>
class Bst {
public:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    Node* root;
    Bst() : root(nullptr) {}

    void insert(T val) {
        root = insertRec(root, val);
    }

    void DisplayInOrder() {
        inOrder(root);
        std::cout << std::endl;
    }

    void PostOrder() {
        postOrder(root);
        std::cout << std::endl;
    }

    void PreOrder() {
        preOrder(root);
        std::cout << std::endl;
    }

private:
    Node* insertRec(Node* node, T val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insertRec(node->left, val);
        else if (val > node->data)
            node->right = insertRec(node->right, val);
        return node;
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node* node) {
        if (!node) return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }

    void preOrder(Node* node) {
        if (!node) return;
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Helper function to calculate depth of a specific value
    int findDepth(Node* node, T value, int depth) {
        if (!node) return -1;
        
        if (node->data == value)
            return depth;
            
        int leftDepth = findDepth(node->left, value, depth + 1);
        if (leftDepth != -1)
            return leftDepth;
            
        return findDepth(node->right, value, depth + 1);
    }

    // Helper function to calculate maximum depth
    int maxDepth(Node* node) {
        if (!node) return -1;
        
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        
        return 1 + std::max(leftDepth, rightDepth);
    }

public:
    // Calculate depth of a specific value
    int getDepth(T value) {
        return findDepth(root, value, 0);
    }

    // Calculate maximum depth of the tree
    int getMaxDepth() {
        return maxDepth(root);
    }
};

int main()
{
    Bst<int> tree;

    // Insert some values to create a tree
    tree.insert(50);           // root (depth 0)
    tree.insert(30);           // depth 1
    tree.insert(70);           // depth 1
    tree.insert(20);           // depth 2
    tree.insert(40);           // depth 2
    tree.insert(60);           // depth 2
    tree.insert(80);           // depth 2

    std::cout << "InOrder traversal: ";
    tree.DisplayInOrder();
    
    std::cout << "PostOrder traversal: ";
    tree.PostOrder();
    
    std::cout << "PreOrder traversal: ";
    tree.PreOrder();

    // Test depth calculations
    std::cout << "\nDepth of nodes:" << std::endl;
    std::cout << "Depth of root (50): " << tree.getDepth(50) << std::endl;   // Should be 0
    std::cout << "Depth of 30: " << tree.getDepth(30) << std::endl;          // Should be 1
    std::cout << "Depth of 20: " << tree.getDepth(20) << std::endl;          // Should be 2
    std::cout << "Depth of non-existent value (100): " << tree.getDepth(100) << std::endl;  // Should be -1

    std::cout << "\nMaximum depth of tree: " << tree.getMaxDepth() << std::endl;  // Should be 2

    return 0;
}
