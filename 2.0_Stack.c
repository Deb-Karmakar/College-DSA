#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
int peek(Stack *s);
void displayMenu();

int main() {
    Stack stack;
    initStack(&stack);
    
    int choice, value;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Push
                if (!isFull(&stack)) {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(&stack, value);
                    printf("Pushed %d to the stack\n", value);
                } else {
                    printf("Stack is full. Cannot push.\n");
                }
                break;
            
            case 2: // Pop
                if (!isEmpty(&stack)) {
                    value = pop(&stack);
                    printf("Popped value: %d\n", value);
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;
            
            case 3: // Check if Full
                if (isFull(&stack)) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            
            case 4: // Check if Empty
                if (isEmpty(&stack)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            
            case 5: // Peek
                if (!isEmpty(&stack)) {
                    value = peek(&stack);
                    printf("Top element: %d\n", value);
                } else {
                    printf("Stack is empty. No top element.\n");
                }
                break;
            
            case 6: // Exit
                printf("Exiting program.\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Push an element to the stack
void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->top++;
        s->items[s->top] = value;
    }
}

// Pop an element from the stack
int pop(Stack *s) {
    if (!isEmpty(s)) {
        int value = s->items[s->top];
        s->top--;
        return value;
    }
    return -1; // Indicates error
}

// Check if stack is full
int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Check if stack is empty
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// Peek at the top element
int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1; // Indicates error
}

// Display menu options
void displayMenu() {
    printf("Stack Operations Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Check if Full\n");
    printf("4. Check if Empty\n");
    printf("5. Peek\n");
    printf("6. Exit\n");
}