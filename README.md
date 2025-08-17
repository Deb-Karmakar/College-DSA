# College-DSA

## Overview
This repository contains comprehensive Data Structures and Algorithms (DSA) implementations for 3rd semester computer science coursework. The programs are written in C and cover fundamental data structures including sparse matrices, polynomials, stacks, and deques with interactive menu-driven interfaces and complete CRUD operations.

## Contents

### 1. Sparse Matrix Operations

#### `1.0_TransposeSparseMatrixOfTripletForm.c`
**Purpose**: Implementation of sparse matrix transpose using triplet representation

**Features**:
- Convert regular matrix to sparse triplet format
- Transpose sparse matrix efficiently using column-wise traversal
- Memory usage comparison between regular and sparse representations
- Dynamic memory allocation with proper deallocation
- Comprehensive memory management

**Key Functions**:
- `toSparse()`: Converts a regular matrix to sparse triplet representation
- `transposeSparse()`: Transposes a sparse matrix in triplet form
- `displaySparse()`: Displays sparse matrix in triplet format

**Input**: Matrix dimensions and elements
**Output**: Original and transposed sparse matrices with memory usage analysis
**Time Complexity**: O(cols × nnz) where nnz is number of non-zero elements

#### `1.1_AddSparse.c`
**Purpose**: Addition of two sparse matrices in triplet representation

**Features**:
- Input sparse matrices directly in triplet form
- Efficient addition algorithm using merge-sort technique
- Handles matrices with different sparsity patterns
- Automatic elimination of zero results after addition
- Dimension validation before operations

**Key Functions**:
- `inputSparse()`: Takes input for sparse matrix in triplet format
- `addSparse()`: Adds two sparse matrices using optimized merge algorithm
- `displaySparse()`: Displays sparse matrix results

**Input**: Two sparse matrices in triplet format
**Output**: Sum of the two matrices in triplet representation
**Time Complexity**: O(m + n) where m and n are non-zero elements in each matrix

#### `1.2_Add_Mul_Poly.c`
**Purpose**: Polynomial addition and multiplication operations

**Features**:
- Input polynomials as a set of terms (coefficient, exponent)
- Efficient addition and multiplication algorithms for polynomials
- Handles polynomials with various terms and degrees
- Like terms combination in multiplication results
- Support for negative coefficients and zero degree terms

**Key Functions**:
- `inputPolynomial()`: Takes input for a polynomial's terms
- `addPolynomials()`: Adds two polynomials with exponent comparison
- `multiplyPolynomials()`: Multiplies two polynomials with term combination
- `displayPolynomial()`: Displays polynomial in readable format
- `compareExpo()`: Utility function for exponent comparison

**Input**: Two polynomial expressions with coefficients and exponents
**Output**: The sum and product of the two polynomial expressions
**Time Complexity**: Addition O(m + n), Multiplication O(m × n) + O(k²) for combining terms

### 2. Linear Data Structures

#### `2.0_Stack.c`
**Purpose**: Complete stack implementation with menu-driven interface

**Features**:
- Array-based stack implementation with fixed size (MAX_SIZE = 5)
- Interactive menu-driven interface
- Complete stack operations with error handling
- Overflow and underflow detection
- Real-time status checking

**Key Functions**:
- `initStack()`: Initializes stack with top = -1
- `push()`: Adds element to top of stack
- `pop()`: Removes and returns top element
- `peek()`: Returns top element without removal
- `isFull()`: Checks if stack is at maximum capacity
- `isEmpty()`: Checks if stack is empty
- `displayMenu()`: Shows interactive menu options

**Menu Options**:
1. Push - Add element to stack
2. Pop - Remove top element
3. Check if Full - Verify stack capacity
4. Check if Empty - Verify if stack is empty
5. Peek - View top element
6. Exit - Terminate program

**Time Complexity**: All operations O(1)
**Space Complexity**: O(n) where n is MAX_SIZE

#### `2.1_Deque.c`
**Purpose**: Double-ended queue (Deque) implementation with circular array

**Features**:
- Circular array-based deque implementation (MAX_SIZE = 5)
- Insertion and deletion from both ends
- Interactive menu-driven interface with 8 operations
- Advanced circular indexing with modular arithmetic
- Complete error handling and status checking
- Real-time deque content display

**Key Functions**:
- `initDequeue()`: Initializes deque with front = rear = -1
- `enqueueRear()`: Adds element at rear end
- `enqueueFront()`: Adds element at front end
- `dequeueRear()`: Removes element from rear end
- `dequeueFront()`: Removes element from front end
- `isEmpty()`: Checks if deque is empty
- `isFull()`: Checks if deque is at capacity using circular logic
- `displayDequeue()`: Shows all elements in order
- `displayMenu()`: Interactive menu display

**Menu Options**:
1. Enqueue Rear - Add element at rear
2. Enqueue Front - Add element at front  
3. Dequeue Rear - Remove from rear
4. Dequeue Front - Remove from front
5. Check if Empty - Verify empty status
6. Check if Full - Verify full status
7. Display Dequeue - Show all elements
8. Exit - Terminate program

**Time Complexity**: All operations O(1)
**Space Complexity**: O(n) where n is MAX_SIZE

#### `2.2_Queue.c`
**Purpose**: Linear queue (FIFO) implementation with menu-driven interface

**Features**:
- Array-based linear queue implementation with fixed size (MAX_SIZE = 5)
- Interactive menu-driven interface with 6 operations
- First-In-First-Out (FIFO) principle implementation
- Complete error handling for overflow and underflow conditions
- Real-time queue status checking and display
- Linear array implementation with front and rear pointers

**Key Functions**:
- `initQueue()`: Initializes queue with front = 0, rear = -1
- `enqueueRear()`: Adds element at rear end of queue
- `dequeueFront()`: Removes and returns element from front end
- `isEmpty()`: Checks if queue is empty (front > rear)
- `isFull()`: Checks if queue is at maximum capacity (rear == MAX_SIZE - 1)
- `displayQueue()`: Shows all elements from front to rear
- `displayMenu()`: Interactive menu display

**Menu Options**:
1. Enqueue Rear - Add element at rear
2. Dequeue Front - Remove element from front
3. Check if Empty - Verify empty status
4. Check if Full - Verify full status
5. Display Queue - Show all elements in order
6. Exit - Terminate program

**Time Complexity**: All operations O(1)
**Space Complexity**: O(n) where n is MAX_SIZE
**Note**: Linear implementation may waste space after dequeue operations

#### `2.3_CircularQueue.c`
**Purpose**: Circular queue (FIFO) implementation with efficient space utilization

**Features**:
- Array-based circular queue implementation with fixed size (MAX_SIZE = 5)
- Interactive menu-driven interface with 6 operations
- Circular array implementation using modular arithmetic
- Efficient space utilization - no memory wastage after dequeue
- Advanced circular indexing for front and rear pointers
- Complete error handling and boundary condition management
- Real-time queue content display with circular traversal

**Key Functions**:
- `initQueue()`: Initializes circular queue with front = rear = -1
- `enqueueRear()`: Adds element at rear using circular indexing
- `dequeueFront()`: Removes element from front with circular logic
- `isEmpty()`: Checks if queue is empty (front == -1)
- `isFull()`: Checks if queue is full using circular formula ((rear + 1) % MAX_SIZE == front)
- `displayQueue()`: Shows all elements using circular traversal
- `displayMenu()`: Interactive menu display

**Menu Options**:
1. Enqueue Rear - Add element at rear
2. Dequeue Front - Remove element from front
3. Check if Empty - Verify empty status
4. Check if Full - Verify full status
5. Display Queue - Show all elements in circular order
6. Exit - Terminate program

**Time Complexity**: All operations O(1)
**Space Complexity**: O(n) where n is MAX_SIZE
**Advantage**: Better space utilization compared to linear queue

### 3. Linked List Implementations and Expression Evaluation

#### `3.0_InfixToPostfix.c`
**Purpose**: Convert infix expressions to postfix notation and evaluate the result

**Features**:
- Complete infix to postfix conversion using operator precedence rules
- Postfix expression evaluation with stack-based algorithm
- Support for all basic arithmetic operators (+, -, *, /, ^)
- Handles parentheses for expression grouping
- Multi-digit number support in expressions
- Comprehensive operator precedence management
- Automatic whitespace handling and formatting

**Key Functions**:
- `infixToPostfix()`: Converts infix expression to postfix using Shunting Yard algorithm
- `evaluatePostfix()`: Evaluates postfix expression using stack-based approach
- `precedence()`: Returns operator precedence for correct conversion
- `isOperator()`: Checks if character is a valid arithmetic operator
- `pushOp()` / `popOp()` / `peekOp()`: Stack operations for operators
- `pushVal()` / `popVal()`: Stack operations for operand values

**Input**: Infix arithmetic expression with numbers, operators, and parentheses
**Output**: Postfix expression and final evaluated result
**Time Complexity**: O(n) where n is the length of the expression
**Space Complexity**: O(n) for the stack storage

**Operator Precedence**:
1. `^` (Exponentiation) - Highest precedence (3)
2. `*`, `/` (Multiplication, Division) - Medium precedence (2)
3. `+`, `-` (Addition, Subtraction) - Lowest precedence (1)
4. `(`, `)` (Parentheses) - Override precedence rules

**Example**:
- Input: `3 + 4 * 2 / (1 - 5) ^ 2`
- Postfix: `3 4 2 * 1 5 - 2 ^ / +`
- Result: `3`

## Compilation and Execution

### Prerequisites
- GCC compiler or any standard C compiler
- Terminal/Command Prompt access

### Compilation
```bash
# Sparse Matrix Operations
gcc -o transpose 1.0_TransposeSparseMatrixOfTripletForm.c
gcc -o addsparse 1.1_AddSparse.c
gcc -o polynomial 1.2_Add_Mul_Poly.c

# Linear Data Structures
gcc -o stack 2.0_Stack.c
gcc -o deque 2.1_Deque.c
gcc -o queue 2.2_Queue.c
gcc -o circularqueue 2.3_CircularQueue.c

# Expression Conversion and Evaluation
gcc -o infixtopostfix 3.0_InfixToPostfix.c
gcc -o linkedlist 3.1_singly_linked_list.c
```

### Execution
```bash
# Sparse Matrix Programs
./transpose
./addsparse
./polynomial

# Linear Data Structure Programs
./stack
./deque
./queue
./circularqueue

# Expression Conversion and Linked List Programs
./infixtopostfix
./linkedlist
```

## Program Usage

### 1. Transpose Sparse Matrix (`1.0_TransposeSparseMatrixOfTripletForm.c`)
1. Enter matrix dimensions (rows and columns)
2. Input matrix elements row by row
3. View original sparse representation
4. View transposed sparse matrix
5. Compare memory usage between regular and sparse representations

### 2. Add Sparse Matrices (`1.1_AddSparse.c`)
1. Enter matrix dimensions for both matrices
2. Input number of non-zero elements for Matrix A
3. Enter triplet values (row, column, value) for Matrix A
4. Input number of non-zero elements for Matrix B
5. Enter triplet values for Matrix B
6. View the sum of both matrices in triplet representation

### 3. Polynomial Operations (`1.2_Add_Mul_Poly.c`)
1. Enter number of non-zero terms for Polynomial A
2. Input each term as coefficient and exponent
3. Enter number of non-zero terms for Polynomial B
4. Input each term as coefficient and exponent
5. View both polynomials in standard form
6. View the sum of both polynomials
7. View the product of both polynomials

### 4. Stack Operations (`2.0_Stack.c`)
**Interactive Menu-Driven Program**
- Choose from 6 menu options
- Perform push/pop operations
- Check stack status (full/empty)
- View top element without removal
- Real-time feedback for all operations
- Automatic error handling for overflow/underflow

### 5. Deque Operations (`2.1_Deque.c`)
**Interactive Menu-Driven Program**
- Choose from 8 comprehensive menu options
- Insert/remove elements from both front and rear
- Check deque status (full/empty)
- Display all elements in current order
- Advanced circular array implementation
- Complete error handling and validation

### 6. Queue Operations (`2.2_Queue.c`)
**Interactive Menu-Driven Program**
- Choose from 6 menu options for FIFO operations
- Perform enqueue/dequeue operations
- Check queue status (full/empty)
- Display all elements in queue order
- Real-time feedback for all operations
- Automatic error handling for overflow/underflow
- Linear array implementation with potential space wastage after dequeue

### 7. Circular Queue Operations (`2.3_CircularQueue.c`)
**Interactive Menu-Driven Program**
- Choose from 6 menu options for efficient FIFO operations
- Perform enqueue/dequeue operations with circular indexing
- Check queue status (full/empty) using circular logic
- Display all elements in circular queue order
- Advanced circular array implementation for optimal space utilization
- Complete error handling and validation
- No memory wastage - efficient space reuse after dequeue operations

### 8. Infix to Postfix Conversion (`3.0_InfixToPostfix.c`)
**Direct Expression Processing Program**
1. Enter an infix arithmetic expression (e.g., `3 + 4 * 2 / (1 - 5) ^ 2`)
2. Program automatically converts to postfix notation using Shunting Yard algorithm
3. Displays the postfix expression with proper spacing
4. Evaluates the postfix expression using stack-based evaluation
5. Shows the final numerical result

**Supported Operations**:
- Basic arithmetic: `+`, `-`, `*`, `/`, `^`
- Parentheses for grouping: `(`, `)`
- Multi-digit numbers
- Proper operator precedence handling
- Whitespace tolerance in input

**Example Usage**:
- Input: `3 + 4 * 2 / (1 - 5) ^ 2`
- Output Postfix: `3 4 2 * 1 5 - 2 ^ / +`
- Final Result: `3`

### 9. Singly Linked List Operations (`3.1_singly_linked_list.c`)
**Interactive Menu-Driven Program**
- Choose from 4 menu options for dynamic list operations
- Insert nodes at any position in the list
- Delete nodes from any position in the list
- Display the complete linked list with pointer visualization
- Real-time feedback for all operations
- Automatic error handling for invalid positions
- Dynamic memory management with proper allocation and deallocation

**Example Operations**:
1. Insert data 10 at position 1 → Creates first node
2. Insert data 20 at position 2 → Adds node at end  
3. Insert data 15 at position 2 → Inserts between existing nodes
4. Display → Shows: `List: 10 -> 15 -> 20 -> NULL`
5. Delete position 2 → Removes node with data 15
6. Display → Shows: `List: 10 -> 20 -> NULL`

#### `3.1_singly_linked_list.c`
**Purpose**: Complete implementation of a singly linked list with menu-driven interface

**Features**:
- Dynamic memory allocation for nodes using malloc()
- Comprehensive node insertion at any position
- Node deletion from any position with memory management
- Interactive menu-driven interface with 4 operations
- Complete error handling for boundary conditions
- Memory leak prevention with proper free() calls
- Real-time linked list visualization

**Key Functions**:
- `insert()`: Inserts a node at any specified position
- `deleteNode()`: Removes a node from any specified position
- `display()`: Shows all elements in the list with pointer visualization
- `main()`: Interactive menu interface with user input handling

**Menu Options**:
1. Insert - Add a new node at specified position
2. Delete - Remove a node from specified position
3. Display - Show the complete linked list
4. Exit - Terminate program

**Time Complexity**:
- Insertion: O(n) in worst case (inserting at end), O(1) for front insertion
- Deletion: O(n) in worst case (deleting from end), O(1) for front deletion
- Display: O(n) where n is the number of nodes

**Space Complexity**: O(n) where n is the number of nodes

## Data Structures

### Triplet Representation

The programs use a triplet structure to represent sparse matrices:
```c
typedef struct {
    int row;    // Row index
    int col;    // Column index
    int val;    // Value at (row, col)
} Triplet;
```

The first element (index 0) stores metadata:
- `row`: Total number of rows in original matrix
- `col`: Total number of columns in original matrix
- `val`: Number of non-zero elements

### Polynomial Term Representation

Polynomials are represented using a term structure:
```c
typedef struct {
    int coeff;  // Coefficient of the term
    int expo;   // Exponent of the term
} Term;
```

This allows efficient storage of polynomials by only storing non-zero terms, similar to sparse matrix representation.

### Stack Structure

The stack is implemented using a structure with array and top pointer:
```c
typedef struct {
    int items[MAX_SIZE];  // Array to store stack elements
    int top;             // Index of top element (-1 for empty)
} Stack;
```

### Deque Structure

The double-ended queue uses circular array implementation:
```c
typedef struct {
    int items[MAX_SIZE];  // Circular array for storage
    int front;           // Index of front element
    int rear;            // Index of rear element
} Dequeue;
```

### Queue Structure

The linear queue is implemented using a structure with array and front/rear pointers:
```c
typedef struct {
    int items[MAX_SIZE];  // Array to store queue elements
    int front;           // Index of front element (initialized to 0)
    int rear;            // Index of rear element (initialized to -1)
} Queue;
```

### Linked List Node Structure

The singly linked list uses a node structure with data and next pointer:
```c
typedef struct Node {
    int data;           // Data part of the node (stores an integer)
    struct Node* next;  // Pointer to the next node
} Node;
```

### Circular Queue Structure

The circular queue uses circular array implementation with efficient space utilization:
```c
typedef struct {
    int items[MAX_SIZE];  // Circular array for storage
    int front;           // Index of front element (-1 for empty)
    int rear;            // Index of rear element (-1 for empty)
} CircularQueue;
```

## Advantages of Data Structure Implementations

### Sparse Matrix Benefits
1. **Memory Efficiency**: Only stores non-zero elements
2. **Computational Efficiency**: Operations only on non-zero elements
3. **Storage Optimization**: Significant space savings for matrices with many zeros

### Stack Benefits
1. **LIFO Operations**: Perfect for function calls, expression evaluation
2. **O(1) Complexity**: All operations in constant time
3. **Simple Implementation**: Easy to understand and implement

### Deque Benefits
1. **Flexible Operations**: Insert/delete from both ends
2. **Circular Implementation**: Efficient space utilization
3. **O(1) Operations**: All operations in constant time
4. **Versatile**: Can function as both stack and queue

### Queue Benefits
1. **FIFO Operations**: Perfect for task scheduling, breadth-first search
2. **O(1) Complexity**: All operations in constant time
3. **Simple Implementation**: Easy to understand and implement
4. **Real-world Applications**: Print queues, process scheduling

### Circular Queue Benefits
1. **Space Efficiency**: No memory wastage, optimal array utilization
2. **FIFO Operations**: Maintains queue properties with better space management
3. **O(1) Operations**: All operations in constant time
4. **Continuous Operations**: Can handle continuous enqueue/dequeue cycles efficiently
5. **Memory Optimization**: Reuses array space that linear queue wastes

### Linked List Benefits
1. **Dynamic Size**: Grows and shrinks at runtime without fixed size limitations
2. **Efficient Insertions/Deletions**: O(1) time complexity for front operations
3. **Memory Efficiency**: Allocates memory as needed, no pre-allocation required
4. **No Memory Wastage**: Only allocates memory for actual elements
5. **Implementation Flexibility**: Basis for more complex data structures
6. **No Overflow**: Limited only by system memory, not by predefined size

## Learning Objectives

### Core Concepts
- Understanding sparse matrix representation and triplet format
- Dynamic memory allocation and deallocation in C
- Efficient algorithms for matrix and polynomial operations
- Memory usage analysis and optimization techniques
- Time and space complexity analysis

### Data Structure Mastery
- Implementation of linear data structures (Stack, Queue, Deque, Linked List)
- Understanding LIFO (Last In First Out) principle for stacks
- Circular array implementation for deques
- Dynamic memory allocation and pointer manipulation for linked lists
- Menu-driven programming and user interface design
- Error handling and boundary condition management

### Algorithm Design
- Merge algorithm for sparse matrix addition
- Column-wise traversal for matrix transpose
- Polynomial arithmetic with term combination
- Circular indexing with modular arithmetic

## Academic Context

These implementations are part of 3rd semester Data Structures and Algorithms coursework, demonstrating:
- Advanced array manipulation
- Efficient data representation techniques
- Algorithm optimization for sparse data
- Practical applications of theoretical concepts

## Author
College DSA coursework implementations

## Note
These programs are educational implementations designed for learning DSA concepts. They include comprehensive input validation and memory management practices suitable for academic study.
