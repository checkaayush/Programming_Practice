#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

/*Recursive tree height calculation implementation.*/
int treeHeight(struct node* root) {
    
    if (root == NULL) {
        return 0;
    } 
    
    int lDepth = treeHeight(root -> left);
    int rDepth = treeHeight(root -> right);

    return max(lDepth, rDepth) + 1;
} 

int main() {
    
    struct node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    
    printf("Height of tree: %d\n", treeHeight(root));

    return 0;
}