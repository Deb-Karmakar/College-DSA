#include <stdio.h>
#include <stdlib.h>

// Definition of a node
typedef struct Node
{
    int data;
    struct Node *link;
} Node;

Node *head = NULL; // Global head pointer

// Function to count number of nodes in circular list
int countNodes()
{
    if (head == NULL) // Empty list
        return 0;

    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->link;
    } while (temp != head); // Stop when back at head
    return count;
}

// Function to create a new node
Node *createNode(int ele)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->link = NULL;
    return newNode;
}

// Insert a node at given position
void insert(int data, int pos)
{
    int length = countNodes();
    if (pos < 1 || pos > length + 1)
    {
        printf("Invalid Position, List size is %d\n", length);
        return;
    }

    Node *newNode = createNode(data);

    if (head == NULL) // Case: first node
    {
        head = newNode;
        newNode->link = head; // Point to itself
    }
    else if (pos == 1) // Insert at beginning
    {
        Node *last = head;
        while (last->link != head) // Find last node
            last = last->link;

        newNode->link = head;
        head = newNode;
        last->link = head; // Maintain circular link
    }
    else // Insert at given position (middle/end)
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->link;

        newNode->link = temp->link;
        temp->link = newNode;
    }
}

// Delete node at given position
void deleteNode(int pos)
{
    int length = countNodes();
    if (head == NULL) // Empty list
    {
        printf("List is empty\n");
        return;
    }
    if (pos < 1 || pos > length)
    {
        printf("Invalid Position, List size is %d\n", length);
        return;
    }

    if (pos == 1) // Delete head
    {
        Node *last = head;
        while (last->link != head) // Find last node
            last = last->link;

        Node *temp = head;
        if (head->link == head) // Only one node
        {
            head = NULL;
        }
        else
        {
            head = head->link;   // Move head
            last->link = head;   // Fix circular link
        }
        free(temp);
    }
    else // Delete middle/end node
    {
        Node *prev = head;
        for (int i = 1; i < pos - 1; i++)
            prev = prev->link;

        Node *delNode = prev->link;
        prev->link = delNode->link;
        free(delNode);
    }
}

// Display all nodes in circular list
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != head); // Stop when back at head
    printf("\n");
}

// Reverse the circular linked list
void reverse()
{
    if (head == NULL || head->link == head) // Empty or single node
        return;

    Node *prev = NULL, *curr = head, *next = NULL;
    Node *last = head;

    // Find last node
    while (last->link != head)
        last = last->link;

    do
    {
        next = curr->link;
        curr->link = prev ? prev : last; // First node points to last
        prev = curr;
        curr = next;
    } while (curr != head);

    head = prev; // Update head
}

// Search for an element in the list
void search(int key)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    int pos = 1;
    int found = 0;

    do
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break; // Stop after first occurrence
        }
        temp = temp->link;
        pos++;
    } while (temp != head);

    if (!found)
        printf("Element %d not found in the list\n", key);
}

// Menu-driven program
int main()
{
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Reverse\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insert(data, pos);
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteNode(pos);
            break;

        case 3:
            display();
            break;

        case 4:
            reverse();
            printf("List reversed.\n");
            break;

        case 5:
            printf("Enter element to search: ");
            scanf("%d", &data);
            search(data);
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
