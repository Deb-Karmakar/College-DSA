# College-DSA

## Overview
This repository contains Data Structures and Algorithms (DSA) implementations for 3rd semester computer science coursework. The programs are written in C and focus on sparse matrix operations and other fundamental DSA concepts.

## Contents

### 1. Sparse Matrix Operations

#### `1_TransposeSparseMatrixOfTripletForm`
**Purpose**: Implementation of sparse matrix transpose using triplet representation

**Features**:
- Convert regular matrix to sparse triplet format
- Transpose sparse matrix efficiently
- Memory usage comparison between regular and sparse representations
- Dynamic memory allocation for matrices

**Key Functions**:
- `toSparse()`: Converts a regular matrix to sparse triplet representation
- `transposeSparse()`: Transposes a sparse matrix in triplet form
- `displaySparse()`: Displays sparse matrix in triplet format

**Input**: Matrix dimensions and elements
**Output**: Original and transposed sparse matrices with memory usage analysis

#### `1.1_AddSparse`
**Purpose**: Addition of two sparse matrices in triplet representation

**Features**:
- Input sparse matrices directly in triplet form
- Efficient addition algorithm for sparse matrices
- Handles matrices with different sparsity patterns
- Automatic elimination of zero results

**Key Functions**:
- `inputSparse()`: Takes input for sparse matrix in triplet format
- `addSparse()`: Adds two sparse matrices
- `displaySparse()`: Displays sparse matrix results

**Input**: Two sparse matrices in triplet format
**Output**: Sum of the two matrices in triplet representation

## Compilation and Execution

### Prerequisites
- GCC compiler or any standard C compiler
- Terminal/Command Prompt access

### Compilation
```bash
# Compile sparse matrix transpose program
gcc -o transpose 01_TransposeSparseMatrixOfTripletForm

# Compile sparse matrix addition program
gcc -o addsparse 02_AddSparse
```

### Execution
```bash
# Run transpose program
./transpose

# Run addition program
./addsparse
```

## Program Usage

### Transpose Sparse Matrix
1. Enter matrix dimensions (rows and columns)
2. Input matrix elements row by row
3. View original sparse representation
4. View transposed sparse matrix
5. Compare memory usage

### Add Sparse Matrices
1. Enter matrix dimensions for both matrices
2. Input number of non-zero elements for Matrix A
3. Enter triplet values (row, column, value) for Matrix A
4. Input number of non-zero elements for Matrix B
5. Enter triplet values for Matrix B
6. View the sum of both matrices

## Data Structure: Triplet Representation

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

## Advantages of Sparse Matrix Representation

1. **Memory Efficiency**: Only stores non-zero elements
2. **Computational Efficiency**: Operations only on non-zero elements
3. **Storage Optimization**: Significant space savings for matrices with many zeros

## Learning Objectives

- Understanding sparse matrix representation
- Dynamic memory allocation in C
- Efficient algorithms for matrix operations
- Memory usage analysis and optimization
- Time complexity considerations for sparse data structures

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
