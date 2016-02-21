#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Assumption: Leaf nodes are at height 0

typedef struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->left = node->right = NULL;
    node->data = data;
    node->height = 0; // New node is initially added at leaf
    return node;
}

int height(Node* root) {
    
    if (root == NULL)
        return -1;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return 1 + max(lHeight, rHeight); 
}

int getBalanceFactor(Node* node) {
    // BF = Height of left subtree - Height of right subtree
    return height(node->left) - height(node->right);
}

Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    // Return new root
    return y;
}

Node* rightRotate(Node* x) {

    Node* y = x->left;
    Node* T2 = y->right;

    // Perform rotation
    y->right = x;
    x->left = T2;

    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    // Return new root
    return y;
}

Node* insert(Node* root, int key) {
    // Steps:
    // 1. Normal BST insertion
    // 2. Update height of current node
    // 3. Find BF of current node
    // 4. Identify case
    // 3. Balance using rotations and return current node
    
    if (root == NULL)
        return newNode(key);

    // Normal BST insertion (recur)
    if (root->data > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    // Update Height of current node
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    root->height = 1 + max(lHeight, rHeight);

    // Get Balance Factor
    int balFactor = lHeight - rHeight;

    // There are 4 cases:
    // 1. Left Left Case
    if (balFactor > 1 && key < root->left->data) {
        return rightRotate(root);
    }

    // 2. Right Right Case
    if (balFactor < -1 && key > root->right->data) {
        return leftRotate(root);
    }

    // 3. Left Right Case
    if (balFactor > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 4. Right Left Case
    if (balFactor < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}   

void preOrder(Node* root) {
    
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);

}

int main() {
    
    Node* root = NULL;
    
    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
 
    /* The constructed AVL Tree would be
                30
               /  \
             20   40
            /  \     \
           10  25    50
    */
 
    printf("Pre order traversal of the constructed AVL tree is \n");
    preOrder(root);
    return 0;
}