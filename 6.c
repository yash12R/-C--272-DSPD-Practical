#include <stdio.h>
#include <stdlib.h>

// Structure for BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to search an element in BST
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("NULL (Not Found)\n");
        return;
    }
    if (root->data == key) {
        printf("Found\n");
        return;
    }
    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Function to delete a leaf node in BST
struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        // Node found, check if it’s a leaf
        if (root->left == NULL && root->right == NULL) {
            printf("Leaf node %d deleted.\n", root->data);
            free(root);
            return NULL;
        } else {
            printf("Node %d is not a leaf, cannot delete.\n", root->data);
        }
    }
    return root;
}

// Function to display BST (Inorder Traversal)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function with menu
int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n\n----- BINARY SEARCH TREE MENU -----\n");
        printf("1. Search an element\n");
        printf("2. Insert an element\n");
        printf("3. Delete a leaf element\n");
        printf("4. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to search: ");
            scanf("%d", &value);
            printf("Search result: ");
            search(root, value);
            break;

        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Element %d inserted.\n", value);
            printf("Current BST (Inorder): ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Enter leaf element to delete: ");
            scanf("%d", &value);
            root = deleteLeaf(root, value);
            printf("Current BST (Inorder): ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
