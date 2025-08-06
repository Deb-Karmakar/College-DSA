#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Dequeue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Dequeue;

// Function prototypes
void initDequeue(Dequeue *dq);
void enqueueRear(Dequeue *dq, int value);
void enqueueFront(Dequeue *dq, int value);
int dequeueRear(Dequeue *dq);
int dequeueFront(Dequeue *dq);
int isEmpty(Dequeue *dq);
int isFull(Dequeue *dq);
void displayMenu();
void displayDequeue(Dequeue *dq);

int main() {
    Dequeue dq;
    initDequeue(&dq);
    int choice, value;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isFull(&dq)) {
                    printf("Enter value to enqueue at rear: ");
                    scanf("%d", &value);
                    enqueueRear(&dq, value);
                } else {
                    printf("Dequeue is full. Cannot enqueue at rear.\n");
                }
                break;

            case 2:
                if (!isFull(&dq)) {
                    printf("Enter value to enqueue at front: ");
                    scanf("%d", &value);
                    enqueueFront(&dq, value);
                } else {
                    printf("Dequeue is full. Cannot enqueue at front.\n");
                }
                break;

            case 3:
                if (!isEmpty(&dq)) {
                    value = dequeueRear(&dq);
                    printf("Dequeued from rear: %d\n", value);
                } else {
                    printf("Dequeue is empty. Cannot dequeue from rear.\n");
                }
                break;

            case 4:
                if (!isEmpty(&dq)) {
                    value = dequeueFront(&dq);
                    printf("Dequeued from front: %d\n", value);
                } else {
                    printf("Dequeue is empty. Cannot dequeue from front.\n");
                }
                break;

            case 5:
                printf(isEmpty(&dq) ? "Dequeue is empty\n" : "Dequeue is not empty\n");
                break;

            case 6:
                printf(isFull(&dq) ? "Dequeue is full\n" : "Dequeue is not full\n");
                break;

            case 7:
                displayDequeue(&dq);
                break;

            case 8:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}

// Initialize the dequeue
void initDequeue(Dequeue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if dequeue is full
int isFull(Dequeue *dq) {
    return ((dq->front == 0 && dq->rear == MAX_SIZE - 1) ||
            (dq->rear + 1) % MAX_SIZE == dq->front);
}

// Check if dequeue is empty
int isEmpty(Dequeue *dq) {
    return (dq->front == -1);
}

// Enqueue at rear
void enqueueRear(Dequeue *dq, int value) {
    if (isFull(dq)) return;

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }

    dq->items[dq->rear] = value;
    printf("Enqueued %d at rear.\n", value);
}

// Enqueue at front
void enqueueFront(Dequeue *dq, int value) {
    if (isFull(dq)) return;

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    dq->items[dq->front] = value;
    printf("Enqueued %d at front.\n", value);
}

// Dequeue from front
int dequeueFront(Dequeue *dq) {
    if (isEmpty(dq)) return -1;

    int value = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % MAX_SIZE;
    }

    return value;
}

// Dequeue from rear
int dequeueRear(Dequeue *dq) {
    if (isEmpty(dq)) return -1;

    int value = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return value;
}

// Display menu
void displayMenu() {
    printf("===== DEQUEUE MENU =====\n");
    printf("1. Enqueue Rear\n");
    printf("2. Enqueue Front\n");
    printf("3. Dequeue Rear\n");
    printf("4. Dequeue Front\n");
    printf("5. Check if Empty\n");
    printf("6. Check if Full\n");
    printf("7. Display Dequeue\n");
    printf("8. Exit\n");
}

// Display the dequeue contents
void displayDequeue(Dequeue *dq) {
    if (isEmpty(dq)) {
        printf("Dequeue is empty.\n");
        return;
    }

    printf("Dequeue elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->items[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}
