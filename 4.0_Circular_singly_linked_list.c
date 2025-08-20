#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL; // Global head pointer

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to count nodes
int countNodes() {
    if (head == NULL) return 0;
    Node* temp = head;
    int count = 0;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Insert at given position (with validation)
void insert(int value, int position) {
    int length = countNodes();

    if (position < 1 || position > length + 1) {
        printf("Invalid position! List size = %d\n", length);
        return;
    }

    Node* newNode = createNode(value);

    if (head == NULL) { // Empty list
        head = newNode;
        newNode->next = head;
        return;
    }

    if (position == 1) { // Insert at front
        Node* temp = head;
        while (temp->next != head) // Traverse to last node
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    } else { // Insert at intermediate/end
        Node* temp = head;
        int i;
        for (i = 1; i < position - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Delete at given position
void deleteNode(int position) {
    int length = countNodes();
    if (length == 0) {
        printf("List is empty!\n");
        return;
    }
    if (position < 1 || position > length) {
        printf("Invalid position! List size = %d\n", length);
        return;
    }

    Node* temp = head;

    if (position == 1) { // Delete first node
        if (head->next == head) { // Only one node
            free(head);
            head = NULL;
            return;
        }
        Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
    } else { // Delete intermediate/end
        Node* prev = NULL;
        int i;
        for (i = 1; i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Search element
void search(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element %d not found!\n", key);
}

// Reverse the list
void reverse() {
    if (head == NULL || head->next == head) return;

    Node *prev = head, *curr = head->next, *nextNode;

    // Traverse until we reach head again
    while (curr != head) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Fix last node (head->next should point to new last)
    head->next = prev;
    head = prev;  // update head to new first node
}
// Main menu
int main() {
    int choice, value, position;

    do {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Reverse\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            insert(value, position);
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteNode(position);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Enter element to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 5:
            reverse();
            printf("List reversed.\n");
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
