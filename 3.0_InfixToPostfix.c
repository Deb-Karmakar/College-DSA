#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for characters (operators)
char stackOp[MAX];
int topOp = -1;

// Stack for integers (operands)
int stackVal[MAX];
int topVal = -1;

// Stack operations for operators
void pushOp(char c) {
    stackOp[++topOp] = c;
}

char popOp() {
    return stackOp[topOp--];
}

char peekOp() {
    return stackOp[topOp];
}

// Stack operations for values
void pushVal(int val) {
    stackVal[++topVal] = val;
}

int popVal() {
    return stackVal[topVal--];
}

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char token;
    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if (isspace(token))
            continue;

        // If token is operand, add to postfix
        if (isdigit(token)) {
            postfix[k++] = token;
            postfix[k++] = ' ';
        }
        // If token is '(', push to stack
        else if (token == '(') {
            pushOp(token);
        }
        // If token is ')', pop until '('
        else if (token == ')') {
            while (topOp != -1 && peekOp() != '(') {
                postfix[k++] = popOp();
                postfix[k++] = ' ';
            }
            popOp(); // Remove '('
        }
        // If token is an operator
        else if (isOperator(token)) {
            while (topOp != -1 && precedence(peekOp()) >= precedence(token)) {
                postfix[k++] = popOp();
                postfix[k++] = ' ';
            }
            pushOp(token);
        }
    }

    // Pop remaining operators
    while (topOp != -1) {
        postfix[k++] = popOp();
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    char *p = postfix;
    int num;

    while (*p != '\0') {
        while (*p == ' ')
            p++;

        if (*p == '\0')
            break;

        if (isdigit(*p)) {
            num = 0;
            while (isdigit(*p)) {
                num = num * 10 + (*p - '0');
                p++;
            }
            pushVal(num);
        }
        else if (isOperator(*p)) {
            int val2 = popVal();
            int val1 = popVal();
            switch (*p) {
                case '+': pushVal(val1 + val2); break;
                case '-': pushVal(val1 - val2); break;
                case '*': pushVal(val1 * val2); break;
                case '/': pushVal(val1 / val2); break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < val2; j++)
                        result *= val1;
                    pushVal(result);
                    break;
                }
            }
            p++;
        }
        else {
            p++;
        }
    }

    return popVal();
}

// Main driver program
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%[^\n]", infix); // Read input until newline

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
