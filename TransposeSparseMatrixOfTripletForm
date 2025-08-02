#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int val;
} Triplet;

// Function to convert matrix to sparse triplet representation
Triplet *toSparse(int **matrix, int rows, int cols, int *nonZero)
{
    int count = 0;

    // Count non-zero elements
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0)
                count++;

    *nonZero = count;

    // Allocate memory for sparse matrix
    Triplet *sparse = (Triplet *)malloc((count + 1) * sizeof(Triplet));

    // First row contains metadata
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].val = count;

    int k = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0)
            {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].val = matrix[i][j];
                k++;
            }

    return sparse;
}

// Function to transpose sparse matrix
Triplet *transposeSparse(Triplet *sparse)
{
    int rows = sparse[0].row;
    int cols = sparse[0].col;
    int count = sparse[0].val;

    Triplet *trans = (Triplet *)malloc((count + 1) * sizeof(Triplet));
    trans[0].row = cols;
    trans[0].col = rows;
    trans[0].val = count;

    int k = 1;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 1; j <= count; j++)
        {
            if (sparse[j].col == i)
            {
                trans[k].row = sparse[j].col;
                trans[k].col = sparse[j].row;
                trans[k].val = sparse[j].val;
                k++;
            }
        }
    }

    return trans;
}

// Function to display a sparse matrix
void displaySparse(Triplet *sparse)
{
    printf("Row Col Val\n");
    for (int i = 0; i <= sparse[0].val; i++)
        printf("%3d %3d %3d\n", sparse[i].row, sparse[i].col, sparse[i].val);
}

int main()
{
    int rows, cols;
    int **matrix;

    // Take input from user
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate 2D matrix
    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter elements of matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    int nonZero;
    Triplet *sparse = toSparse(matrix, rows, cols, &nonZero);
    Triplet *transpose = transposeSparse(sparse);

    printf("\nOriginal Sparse Matrix:\n");
    displaySparse(sparse);

    printf("\nTransposed Sparse Matrix:\n");
    displaySparse(transpose);

    // Memory usage comparison
    int originalSize = rows * cols * sizeof(int);
    int sparseSize = 3 * (nonZero + 1) * sizeof(int);
    printf("\nMemory Used by Original Matrix = %d bytes\n", originalSize);
    printf("Memory Used by Sparse Matrix   = %d bytes\n", sparseSize);

    if (sparseSize < originalSize)
        printf("Triplet format is advantageous.\n");
    else
        printf("Triplet format is not advantageous.\n");

    // Free memory
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    free(sparse);
    free(transpose);

    return 0;
}
