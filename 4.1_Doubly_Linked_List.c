#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a Doubly Linked List
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

// Function to count nodes
int countNodes()
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at a given position
void insert(int data, int pos)
{
    int length = countNodes();
    if (pos < 1 || pos > length + 1)
    {
        printf("Invalid Position, List size is %d\n", length);
        return;
    }

    Node *newNode = createNode(data);

    if (pos == 1)
    {
        // Insert at beginning
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    }
    else
    {
        // Insert at any other position
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// Function to delete a node at a given position
void deleteNode(int pos)
{
    int length = countNodes();
    if (pos < 1 || pos > length)
    {
        printf("Invalid Position, List size is %d\n", length);
        return;
    }

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 1)
    {
        // Delete the first node
        Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
    else
    {
        Node *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        if (curr->next != NULL)
            curr->next->prev = curr->prev;
        free(curr);
    }
}

// Function to reverse the DLL
void reverse()
{
    Node *curr = head;
    Node *temp = NULL;

    while (curr != NULL)
    {
        // Swap next and prev for each node
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev; // Move to the next node (originally prev)
    }

    if (temp != NULL)
        head = temp->prev; // New head is the previous tail
}

// Function to display the list
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search an element
void search(int key)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}

int main()
{
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
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
