#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // fixed size for the queue

// Define Node structure with typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
int count = 0;  // track current size

// Enqueue operation
void enqueue(int value) {
    if (count >= MAX_SIZE) {
        printf("Queue Overflow! Cannot enqueue %d (limit = %d).\n", value, MAX_SIZE);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    count++;
    printf("%d enqueued to queue.\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Nothing to dequeue.\n");
        return;
    }

    Node* temp = front;
    printf("%d dequeued from queue.\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;  // queue becomes empty
    }

    free(temp);
    count--;
}

// isEmpty operation
void isEmpty() {
    if (front == NULL)
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty. Current size = %d\n", count);
}

// Menu driven main
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. isEmpty\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
