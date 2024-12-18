#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}
    void insert(int value) {
        root = insertRec(root, value);
    }

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) return new Node(value);
        if (value < node->data) node->left = insertRec(node->left, value);
        else node->right = insertRec(node->right, value);
        return node;
    }

    bool search(int value) {
        return searchRec(root, value);
    }

    bool searchRec(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        return (value < node->data) ? searchRec(node->left, value) : searchRec(node->right, value);
    }

    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

    Node* deleteRec(Node* root, int value) {
        if (root == nullptr) return root;

        if (value < root->data) root->left = deleteRec(root->left, value);
        else if (value > root->data) root->right = deleteRec(root->right, value);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        while (node && node->left != nullptr) node = node->left;
        return node;
    }

    // Display tree (Inorder)
    void display() {
        inorder(root);
        cout << endl;
    }

    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.deleteNode(value);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value)) cout << value << " found.\n";
            else cout << value << " not found.\n";
            break;
        case 4:
            cout << "Inorder Traversal: ";
            tree.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
