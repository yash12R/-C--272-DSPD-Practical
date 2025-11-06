#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
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

// Function to insert a node in the binary tree (level-wise for simplicity)
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    int choice;
    printf("Insert %d to left(1) or right(2) of %d? ", value, root->data);
    scanf("%d", &choice);

    if (choice == 1)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

// Traversal Functions
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Search Function
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    if (root->data == key) {
        printf("Found\n");
        return;
    }

    if (root->left != NULL)
        search(root->left, key);
    if (root->right != NULL)
        search(root->right, key);
}

// Main Function
int main() {
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Tree is empty.\n");
        return 0;
    }

    printf("Enter value for root node: ");
    scanf("%d", &value);
    root = createNode(value);

    for (int i = 1; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);
    search(root, key);

    return 0;
}
