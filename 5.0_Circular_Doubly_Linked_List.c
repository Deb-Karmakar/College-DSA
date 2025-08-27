#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to count nodes
int countNodes() {
    if (head == NULL) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Insert at position (1-based index)
void insertAtPosition(int data, int pos) {
    int n = countNodes();
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! List size = %d\n", n);
        return;
    }

    Node* newNode = createNode(data);

    if (head == NULL) { // First node
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    if (pos == 1) { // Insert at front
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Insert in middle or end
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    Node* nextNode = temp->next;
    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = newNode;
    nextNode->prev = newNode;
}

// Delete at position
void deleteAtPosition(int pos) {
    int n = countNodes();
    if (n == 0) {
        printf("List is empty!\n");
        return;
    }
    if (pos < 1 || pos > n) {
        printf("Invalid position! List size = %d\n", n);
        return;
    }

    if (pos == 1) { // Delete head
        if (head->next == head) { // only one node
            free(head);
            head = NULL;
            return;
        }
        Node* last = head->prev;
        Node* temp = head;
        head = head->next;
        last->next = head;
        head->prev = last;
        free(temp);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    free(temp);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
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

// Reverse list
void reverse() {
    if (head == NULL || head->next == head) return;

    Node* current = head;
    Node* temp = NULL;

    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // move backward since swapped
    } while (current != head);

    head = temp->prev; // update head
    printf("List reversed successfully!\n");
}

// Menu
int main() {
    int choice, data, pos, key;
    while (1) {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
        printf("1. Insert at Position\n");
        printf("2. Delete at Position\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Reverse\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 5:
                reverse();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
