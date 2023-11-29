#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build a binary tree using recursive input
// Returns the root of the built tree
node* buildTree() {
    cout << "Enter the data for the node (-1 for NULL):" << endl;

    int data;
    cin >> data;

    // Base case: if the entered data is -1, return NULL (no node is created)
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the entered data
    node* root = new node(data);

    // Recursively build the left and right subtrees
    cout << "Enter the data to insert in the left of " << data << endl;
    root->left = buildTree();
    cout << "Enter the data to insert in the right of " << data << endl;
    root->right = buildTree();

    return root;
}

// Function to perform level order traversal of a binary tree
// Parameters:
//   root: Pointer to the root of the binary tree
void levelOrderTraversal(node* root) {
    // Create a queue for level order traversal
    queue<node*> q;

    // Enqueue the root node
    q.push(root);
    // Use NULL as a separator for levels
    q.push(NULL);

    // Continue traversal until the queue is empty
    while (!q.empty()) {
        // Dequeue a node
        node* temp = q.front();
        q.pop();

        // Check if the node is NULL (level separator)
        if (temp == NULL) {
            cout << endl;

            // If the queue is not empty, enqueue another NULL to mark the end of the next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            // Print the data of the current node
            cout << temp->data << " ";

            // Enqueue the left child if it exists
            if (temp->left) {
                q.push(temp->left);
            }

            // Enqueue the right child if it exists
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Function to perform inorder traversal of a binary tree
// Parameters:
//   root: Pointer to the root of the binary tree
void inorder(node* root) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    inorder(root->left);
    // Print the data of the current node
    cout << root->data << " ";
    // Traverse the right subtree
    inorder(root->right);
}

// Function to perform preorder traversal of a binary tree
// Parameters:
//   root: Pointer to the root of the binary tree
void preOrder(node* root) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Print the data of the current node
    cout << root->data << " ";
    // Traverse the left subtree
    preOrder(root->left);
    // Traverse the right subtree
    preOrder(root->right);
}

// Function to perform postorder traversal of a binary tree
// Parameters:
//   root: Pointer to the root of the binary tree
void postOrder(node* root) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    postOrder(root->left);
    // Traverse the right subtree
    postOrder(root->right);
    // Print the data of the current node
    cout << root->data << " ";
}

int main() {

    node* root = NULL;

    // Creating a tree
    root = buildTree();

    cout << "Level Order Traversal" << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal is: " << endl;
    inorder(root);

    cout << endl;

    cout << "Preorder Traversal is: " << endl;
    preOrder(root);

    cout << endl;

    cout << "PostOrder Traversal is " << endl;
    postOrder(root);

    return 0;
}
