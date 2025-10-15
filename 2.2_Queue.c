#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Queue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
void initQueue(Queue *q);
void enqueueRear(Queue *q, int value);
int dequeueFront(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void displayQueue(Queue *q);
void displayMenu();

int main() {
    Queue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue Rear
                if (!isFull(&q)) {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueueRear(&q, value);
                    printf("%d enqueued at rear.\n", value);
                } else {
                    printf("Queue is full. Cannot enqueue.\n");
                }
                break;

            case 2: // Dequeue Front
                if (!isEmpty(&q)) {
                    value = dequeueFront(&q);
                    printf("Dequeued from front: %d\n", value);
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;

            case 3: // Check Empty
                printf(isEmpty(&q) ? "Queue is empty\n" : "Queue is not empty\n");
                break;

            case 4: // Check Full
                printf(isFull(&q) ? "Queue is full\n" : "Queue is not full\n");
                break;

            case 5: // Display Queue
                displayQueue(&q);
                break;

            case 6: // Exit
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("\n");
    }
}

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return (q->front > q->rear);
}

// Check if queue is full
int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

// Enqueue at rear
void enqueueRear(Queue *q, int value) {
    if (isFull(q)) return;
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue from front
int dequeueFront(Queue *q) {
    if (isEmpty(q)) return -1;
    int value = q->items[q->front];
    q->front++;
    return value;
}

// Display queue elements
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Display menu
void displayMenu() {
    printf("===== QUEUE MENU =====\n");
    printf("1. Enqueue Rear\n");
    printf("2. Dequeue Front\n");
    printf("3. Check if Empty\n");
    printf("4. Check if Full\n");
    printf("5. Display Queue\n");
    printf("6. Exit\n");
}
