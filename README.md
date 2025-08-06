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

## Learning Objectives

### Core Concepts
- Understanding sparse matrix representation and triplet format
- Dynamic memory allocation and deallocation in C
- Efficient algorithms for matrix and polynomial operations
- Memory usage analysis and optimization techniques
- Time and space complexity analysis

### Data Structure Mastery
- Implementation of linear data structures (Stack, Deque)
- Understanding LIFO (Last In First Out) principle for stacks
- Circular array implementation for deques
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
