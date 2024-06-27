
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct node {
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to insert a new node with given key in BST
struct node* insert(struct node* node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}

// Utility function to do in-order traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Utility function to find the minimum value node in a given BST
struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Utility function to delete a node with given key in BST
struct node* deleteNode(struct node* root, int key)
{
    // Base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver Code
int main()
{
    struct node* root = NULL;

    // Creating the initial tree
    int initial_elements[] = {18, 15, 40, 50, 30, 17, 41};
    int num_initial_elements = 7;
    for (int i = 0; i < num_initial_elements; i++) {
        root = insert(root, initial_elements[i]);
    }

    // Display the initial tree
    printf("Initial tree: \n ");
    inorder(root);
    printf("\n");

    // Insertions
    int insertions[] = {45, 19};
    int num_insertions = 2;
    for (int i = 0; i < num_insertions; i++) {
        root = insert(root, insertions[i]);
        printf("Tree after inserting %d: \n ", insertions[i]);
        inorder(root);
        printf("\n");
    }

    // Deletions
    int deletions[] = {15, 17, 41};
    int num_deletions = 3;
    for (int i = 0; i < num_deletions; i++) {
        root = deleteNode(root, deletions[i]);
        printf("Tree after deleting %d: \n", deletions[i]);
        inorder(root);
        printf("\n");
    }

    return 0;
}

