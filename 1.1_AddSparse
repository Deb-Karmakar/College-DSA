#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} Triplet;

void inputSparse(Triplet *sparse, int count) {
    printf("Enter the non-zero elements (row col value):\n");
    for (int i = 1; i <= count; i++) {
        printf("Element %d: ", i);
        scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].val);
    }
}

// Display the sparse matrix
void displaySparse(Triplet *sparse) {
    printf("Row Col Val\n");
    for (int i = 0; i <= sparse[0].val; i++) {
        printf("%3d %3d %3d\n", sparse[i].row, sparse[i].col, sparse[i].val);
    }
}

// Function to add two sparse matrices
Triplet* addSparse(Triplet *a, Triplet *b) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("Error: Matrix dimensions do not match.\n");
        return NULL;
    }

    int i = 1, j = 1, k = 1;
    int totalA = a[0].val;
    int totalB = b[0].val;

    Triplet *sum = (Triplet *)malloc((totalA + totalB + 1) * sizeof(Triplet));
    sum[0].row = a[0].row;
    sum[0].col = a[0].col;

    while (i <= totalA && j <= totalB) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            sum[k++] = a[i++];
        } else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            sum[k++] = b[j++];
        } else {
            int added = a[i].val + b[j].val;
            if (added != 0) {
                sum[k].row = a[i].row;
                sum[k].col = a[i].col;
                sum[k].val = added;
                k++;
            }
            i++;
            j++;
        }
    }

    while (i <= totalA) sum[k++] = a[i++];
    while (j <= totalB) sum[k++] = b[j++];

    sum[0].val = k - 1;
    return sum;
}

int main() {
    int rows, cols, countA, countB;

    // Input for Matrix A
    printf("Enter number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter number of non-zero elements in Matrix A: ");
    scanf("%d", &countA);
    Triplet *A = (Triplet *)malloc((countA + 1) * sizeof(Triplet));
    A[0].row = rows;
    A[0].col = cols;
    A[0].val = countA;
    inputSparse(A, countA);

    // Input for Matrix B
    printf("\nEnter number of non-zero elements in Matrix B: ");
    scanf("%d", &countB);
    Triplet *B = (Triplet *)malloc((countB + 1) * sizeof(Triplet));
    B[0].row = rows;
    B[0].col = cols;
    B[0].val = countB;
    inputSparse(B, countB);

    // Add matrices
    Triplet *sum = addSparse(A, B);

    if (sum) {
        printf("\nMatrix A in Triplet Form:\n");
        displaySparse(A);

        printf("\nMatrix B in Triplet Form:\n");
        displaySparse(B);

        printf("\nSum of Matrices in Triplet Form:\n");
        displaySparse(sum);
        free(sum);
    }

    free(A);
    free(B);
    return 0;
}
