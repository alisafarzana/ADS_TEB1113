#include <iostream>
using namespace std;

// Structure defining a single node in the tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Class handling the Binary Search Tree logic
class BinarySearchTree {
private:
    Node* root;

    // Recursive helper function to insert a value
    Node* insertHelper(Node* currentNode, int val) {
        if (currentNode == nullptr) {
            return new Node(val);
        }

        if (val < currentNode->data) {
            currentNode->left = insertHelper(currentNode->left, val);
        } else if (val > currentNode->data) {
            currentNode->right = insertHelper(currentNode->right, val);
        }

        return currentNode;
    }

    // Recursive helper function to search for a value
    bool searchHelper(Node* currentNode, int val) {
        if (currentNode == nullptr) {
            return false;
        }

        if (currentNode->data == val) {
            return true;
        }

        if (val < currentNode->data) {
            return searchHelper(currentNode->left, val);
        }

        return searchHelper(currentNode->right, val);
    }

    // Recursive helper function for In-order traversal (Left, Root, Right)
    void inorderHelper(Node* currentNode) {
        if (currentNode == nullptr) {
            return;
        }

        inorderHelper(currentNode->left);
        cout << currentNode->data << " ";
        inorderHelper(currentNode->right);
    }

    // Recursive helper function to clean up dynamic memory
    void clearTree(Node* currentNode) {
        if (currentNode == nullptr) {
            return;
        }
        clearTree(currentNode->left);
        clearTree(currentNode->right);
        delete currentNode;
    }

public:
    // Constructor
    BinarySearchTree() {
        root = nullptr;
    }

    // Destructor to prevent memory leaks
    ~BinarySearchTree() {
        clearTree(root);
    }

    // Public method to insert a value
    void insert(int val) {
        root = insertHelper(root, val);
    }

    // Public method to search a value
    bool search(int val) {
        return searchHelper(root, val);
    }

    // Public method to print the tree elements in sorted order
    void displayInorder() {
        inorderHelper(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Inserting items
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Displaying the tree elements (Will output in ascending order)
    cout << "In-order Traversal: ";
    bst.displayInorder();

    // Searching for elements
    int searchKey = 40;
    if (bst.search(searchKey)) {
        cout << searchKey << " is found in the BST." << endl;
    } else {
        cout << searchKey << " is not found in the BST." << endl;
    }

    return 0;
}
