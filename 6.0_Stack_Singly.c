#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // fixed size for the stack

// Define Node structure with typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;
int count = 0;  // track current size

void push(int value) {
    if (count >= MAX_SIZE) {
        printf("Stack Overflow! Cannot push %d (limit = %d).\n", value, MAX_SIZE);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    count++;
    printf("%d pushed to stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    Node* temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
    count--;
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void isEmpty() {
    if (top == NULL)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty. Current size = %d\n", count);
}

// Menu driven main
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
