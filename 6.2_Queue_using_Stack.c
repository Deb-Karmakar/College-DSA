#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push element into stack
void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++s->top] = data;
}

// Pop element from stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Peek top element
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

// Queue structure using 2 stacks
typedef struct {
    Stack s1, s2;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// Enqueue operation
void enqueue(Queue *q, int data) {
    push(&q->s1, data);
    printf("%d enqueued.\n", data);
}

// Dequeue operation
int dequeue(Queue *q) {
    int x;
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue is empty!\n");
        return -1;
    }
    // If s2 is empty, move all elements from s1 to s2
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            x = pop(&q->s1);
            push(&q->s2, x);
        }
    }
    return pop(&q->s2);
}

// Peek front element
int peekQueue(Queue *q) {
    int x;
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue is empty!\n");
        return -1;
    }
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            x = pop(&q->s1);
            push(&q->s2, x);
        }
    }
    return peek(&q->s2);
}

int main() {
    Queue q;
    initQueue(&q);

    int choice, value;

    while (1) {
        printf("\n--- Queue using Stacks ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                value = peekQueue(&q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
