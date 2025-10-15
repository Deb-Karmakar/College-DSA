#include <stdio.h>
#include <stdlib.h>

// Node definition for CDLL
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

// Count number of nodes
int countNodes()
{
    if (head == NULL)
        return 0;

    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

// Create a new node
Node *createNode(int ele)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert node at given position
void insert(int data, int pos)
{
    int length = countNodes();
    if (pos < 1 || pos > length + 1)
    {
        printf("Invalid Position, List size is %d\n", length);
        return;
    }

    Node *newNode = createNode(data);

    if (head == NULL) // First node
    {
        head = newNode;
        head->next = head->prev = head; // Circular doubly link
    }
    else if (pos == 1) // Insert at beginning
    {
        Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    else // Insert at middle or end
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        Node *nextNode = temp->next;
        newNode->next = nextNode;
        newNode->prev = temp;
        temp->next = newNode;
        nextNode->prev = newNode;
    }
}

// Delete node at given position
void deleteNode(int pos)
{
    int length = countNodes();
    if (head == NULL)
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
        if (head->next == head) // Only one node
        {
            free(head);
            head = NULL;
        }
        else
        {
            Node *last = head->prev;
            Node *temp = head;
            head = head->next;
            head->prev = last;
            last->next = head;
            free(temp);
        }
    }
    else // Delete other position
    {
        Node *temp = head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;

        Node *prevNode = temp->prev;
        Node *nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        free(temp);
    }
}

// Display list forward
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
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Reverse the CDLL
void reverse()
{
    if (head == NULL || head->next == head)
        return;

    Node *curr = head;
    Node *temp = NULL;

    do
    {
        // Swap next and prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev; // move to next node (which is prev now)
    } while (curr != head);

    head = head->prev; // Update head to last node
}

// Search for element
void search(int key)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    int pos = 1, found = 0;

    do
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    if (!found)
        printf("Element %d not found\n", key);
}

int main()
{
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
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
