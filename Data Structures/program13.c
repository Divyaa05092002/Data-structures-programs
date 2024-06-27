#include <stdio.h>
#include <stdlib.h>
// Define a node structure for the binary search tree
struct Node {
int data;
struct Node* left;
struct Node* right;
};
// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (!newNode) {
printf("Memory allocation error\n");
exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert an element into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function for inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function to demonstrate the creation and traversal of the binary search tree
int main() {
    struct Node* root = NULL;
    int elements[] = {2, 5, 1, 3, 9, 0, 6};
    int n = sizeof(elements) / sizeof(elements[0]);

    // Insert elements into the BST
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    // Perform inorder traversal
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Perform preorder traversal
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Perform postorder traversal
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

