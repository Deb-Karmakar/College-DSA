#include <stdio.h>   // For input-output functions (printf, scanf)
#include <stdlib.h>  // For malloc(), free(), exit()

// Define Node type with typedef (cleaner syntax)
typedef struct Node {
    int data;           // Data part of the node (stores an integer)
    struct Node* next;  // Pointer to the next node
} Node;

// Global pointer 'head' which always points to the first node of the list
Node* head = NULL;

// ==================== INSERT FUNCTION ====================
void insert(int data, int pos) {
    // Create a new node using dynamic memory allocation
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;   // Assign the given data
    newNode->next = NULL;   // Initially, its 'next' is NULL

    // Case 1: Insert at the front (position = 1)
    if (pos == 1) {
        newNode->next = head;  // New node points to current head
        head = newNode;        // Update head to point to new node
        return;
    }

    // Case 2: Insert at given position (not front)
    Node* temp = head;

    // Traverse to (pos-1)-th node
    // Example: Insert at pos=3 → stop at pos=2
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    // If we reached NULL before reaching (pos-1), position is invalid
    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode); // Free allocated memory to avoid memory leak
        return;
    }

    // Adjust pointers to insert new node
    newNode->next = temp->next;  // New node points to the next node
    temp->next = newNode;        // Previous node points to new node
}

// ==================== DELETE FUNCTION ====================
void deleteNode(int pos) {
    // If list is empty
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;

    // Case 1: Delete from front (position = 1)
    if (pos == 1) {
        head = head->next;       // Move head to the next node
        printf("Deleted: %d\n", temp->data); // Print deleted data
        free(temp);              // Free the old head node
        return;
    }

    // Case 2: Delete from given position
    Node* prev = NULL;

    // Traverse to 'pos'-th node
    // Example: Delete pos=3 → stop at node 3
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;        // Keep track of previous node
        temp = temp->next;  // Move to next node
    }

    // If pos is invalid (temp became NULL)
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    // Adjust pointers to unlink 'temp' node
    prev->next = temp->next;  // Previous node points to node after 'temp'

    printf("Deleted: %d\n", temp->data); // Print deleted data
    free(temp); // Free the memory of deleted node
}

// ==================== DISPLAY FUNCTION ====================
void display() {
    Node* temp = head;

    // If list is empty
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    // Traverse the list and print each node's data
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;  // Move to next node
    }
    printf("NULL\n"); // Mark the end of the list
}

// ==================== MAIN FUNCTION ====================
int main() {
    int choice, data, pos;

    // Infinite loop for menu-driven program
    while (1) {
        // Print menu
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert node
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insert(data, pos);
                break;

            case 2: // Delete node
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteNode(pos);
                break;

            case 3: // Display list
                display();
                break;

            case 4: // Exit program
                exit(0);

            default: // Invalid menu option
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
