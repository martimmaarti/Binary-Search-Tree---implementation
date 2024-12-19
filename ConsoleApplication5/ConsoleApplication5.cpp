

#include <iostream>
using namespace std;

// Node structure for a Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the BST
Node* insertNode(Node* root, int data)
{
    if (root == nullptr) { // If the tree is empty, return a
        // new node
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // return the (unchanged) node pointer
    return root;
}

// Function to search a given key in a given BST
Node* searchNode(Node* root, int key)
{
    // Base case: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    // Key is smaller than root's key, search in the left subtree
    if (key < root->data) {
        return searchNode(root->left, key);
    }

    // Key is larger than root's key, search in the right subtree
    return searchNode(root->right, key);
}

void printTreeStructure(Node* node, int indent = 0, char prefix = 'R') {
    if (node == nullptr) return;

    // Print right subtree first (top-down approach)
    if (node->right) {
        printTreeStructure(node->right, indent + 4, 'R');
    }

    // Print current node
    if (indent > 0) {

        for (int i = 0; i < indent - 4; i++) {
            cout << ".";
        }
        //       cout << string(indent - 4, ' ');
        cout << (prefix == 'R' ? "----" : "----");
    }
    cout << node->data << endl;

    // Print left subtree
    if (node->left) {
        printTreeStructure(node->left, indent + 4, 'L');
    }
}

// Main function to demonstrate the operations of BST
int main()
{

    Node* root = nullptr;
    // create a BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 35);
    root = insertNode(root, 80);

    // Print the inorder traversal of a BST
    cout << "Structure of the given Binary Search "
        "Tree is: " << endl;
    printTreeStructure(root);
    cout << endl;

    // Search a key in BST
    Node* found = searchNode(root, 25);

    // check if the key is found or not
    if (found != nullptr) {
        cout << "Node 25 found in the BST." << endl;
    }
    else {
        cout << "Node 25 not found in the BST." << endl;
    }

    return 0;
}
