#include <stdio.h>
#include <stdlib.h>

// Definition of a node in singly linked list
typedef struct Node
{
    int data;            // Data part of node
    struct Node *link;   // Pointer to next node
} Node;

// Global head pointer to keep track of start of list
Node *head = NULL;

// Function to count number of nodes in the list
int countNodes()
{
    int count = 0;
    Node *temp = head;
    if (head == NULL)       // If list is empty
        return 0;
    while (temp != NULL)    // Traverse until end
    {
        count++;
        temp = temp->link;
    }
    return count;
}

// Function to create a new node dynamically
Node *createNode(int ele)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ele;    // Assign data
    newNode->link = NULL;   // Initialize link as NULL
    return newNode;
}

// Function to insert a node at given position
void insert(int data, int pos)
{
    int length = countNodes();
    if (pos < 1 || pos > length + 1)   // Check for valid position
    {
        printf("Invalid Position, List size is %d\n", length);
        return;
    }

    Node *newNode = createNode(data);

    if (pos == 1)   // Insert at beginning
    {
        newNode->link = head;
        head = newNode;
    }
    else            // Insert at any other position
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)   // Move to node before position
        {
            temp = temp->link;
        }
        newNode->link = temp->link;  // Link new node
        temp->link = newNode;        // Update previous node link
    }
}

// Function to delete a node from given position
void deleteNode(int pos)
{
    if (head == NULL)    // Empty list check
    {
        printf("List is empty\n");
        return;
    }

    int length = countNodes();
    if (pos < 1 || pos > length)   // Check valid position
    {
        printf("Invalid Position, List size is %d\n", length);
        return;
    }

    if (pos == 1)   // Delete head node
    {
        Node *temp = head;
        head = temp->link;
        free(temp);
        temp = NULL;
    }
    else            // Delete from middle/end
    {
        Node *prev = head;
        for (int i = 1; i < pos - 1; i++)   // Move to node before position
        {
            prev = prev->link;
        }

        Node *delNode = prev->link;   // Node to be deleted
        prev->link = delNode->link;   // Bypass deleted node
        free(delNode);                // Free memory
    }
}

// Function to display all nodes in the list
void display()
{
    if (head == NULL)    // Empty list
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)   // Traverse through list
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverse()
{
    Node *prev = NULL;
    Node *next = NULL;
    while (head != NULL)   // Traverse through list
    {
        next = head->link;   // Store next node
        head->link = prev;   // Reverse pointer
        prev = head;         // Move prev forward
        head = next;         // Move head forward
    }
    head = prev;   // Update head to new first node
}

// Driver code with menu
int main()
{
    int choice, data, pos;

    // Infinite loop for menu-driven program
    while (1)
    {
        // Print menu
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Reverse\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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

        case 4: // Reverse list
            reverse();
            printf("List reversed.\n");
            break;

        case 5: // Exit program
            printf("Exiting...\n");
            exit(0);
            break;

        default: // Invalid menu option
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
