#include <stdio.h>
#include <stdlib.h>

// Define the structure of a BST node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;  // unchanged root pointer
}

// Function for inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Helper function to find minimum value node
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int value, int *found) {
    if (root == NULL) {
        return NULL;  // value not found
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value, found);
    } 
    else if (value > root->data) {
        root->right = deleteNode(root->right, value, found);
    } 
    else {
        *found = 1;  // value found

        // Case 1 & 2: node has 0 or 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: node has 2 children
        Node* temp = findMin(root->right);
        root->data = temp->data; // copy inorder successor
        root->right = deleteNode(root->right, temp->data, found); // delete successor
    }
    return root;
}

// Main function with menu
int main() {
    Node* root = NULL;
    int choice, value, found;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert element\n");
        printf("2. Display inorder traversal\n");
        printf("3. Delete element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully.\n", value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                found = 0;
                root = deleteNode(root, value, &found);
                if (found)
                    printf("%d deleted successfully.\n", value);
                else
                    printf("Error: %d does not exist in the tree.\n", value);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
