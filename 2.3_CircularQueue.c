#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Queue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

// Function prototypes
void initQueue(CircularQueue *q);
void enqueueRear(CircularQueue *q, int value);
int dequeueFront(CircularQueue *q);
int isEmpty(CircularQueue *q);
int isFull(CircularQueue *q);
void displayQueue(CircularQueue *q);
void displayMenu();

int main() {
    CircularQueue q;
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
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

// Check if queue is full
int isFull(CircularQueue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

// Enqueue at rear
void enqueueRear(CircularQueue *q, int value) {
    if (isFull(q)) return;

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->items[q->rear] = value;
}

// Dequeue from front
int dequeueFront(CircularQueue *q) {
    if (isEmpty(q)) return -1;

    int value = q->items[q->front];

    if (q->front == q->rear) {
        // Only one element, reset queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }

    return value;
}

// Display queue elements
void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

// Display menu
void displayMenu() {
    printf("===== CIRCULAR QUEUE MENU =====\n");
    printf("1. Enqueue Rear\n");
    printf("2. Dequeue Front\n");
    printf("3. Check if Empty\n");
    printf("4. Check if Full\n");
    printf("5. Display Queue\n");
    printf("6. Exit\n");
}
