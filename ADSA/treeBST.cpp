#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

bool isBSTUtil(struct node* node, int min, int max) {
    
    /* Empty tree is BST. */
    if (node == NULL)
        return true;

    if (node->data < min || node->data > max)
        return false;

    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

bool isBST(struct node* node) {
    return isBSTUtil(node, INT_MIN, INT_MAX);
}

struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

int main() {
    
    struct node* root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(4); 
     
    if(isBST(root))
        printf("Is BST.\n");
    else
        printf("Not a BST.\n");
    
    return 0;
}