// Check whether given binary tree is BST

#include <cstdio>
#include <climits>
#include <cstdlib>

typedef struct Node {
    int data;
    Node* left;
    Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Method 1: Keeping track of the narrowing min and max allowed values
bool isBSTUtil(Node* node, int min, int max) {
    
    // Empty tree is BST
    if (node == NULL)
        return true;

    if (node->data < min || node->data > max)
        return false;

    return isBSTUtil(node->left, min, node->data - 1) && // Allow only distinct values
           isBSTUtil(node->right, node->data + 1, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Method 2: Using Inorder traversal
// bool isBSTUtil(Node* node) {
    
//     // Base condition: Empty tree is BST
//     if (node == NULL)
//         return true;

//     static Node* prev = NULL;

//     if (!isBSTUtil(node->left))
//         return false;

//     if (prev != NULL && node->data >= prev->data)
//         return false;

//     prev = node;

//     if (!isBSTUtil(node->right))
//         return false;

//     return true;    
// }

// bool isBST(Node* root) {
//     return isBSTUtil(root);
// }

/* Driver program to test above functions*/
int main()
{
    Node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4); 
     
    if(isBST(root))
        printf("Is BST\n");
    else
        printf("Not a BST\n");
         
    return 0;
} 